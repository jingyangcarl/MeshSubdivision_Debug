#include "MeshSubdivisior.h"

void MeshSubdivisior::NeighborWeightedPointGuiding() {
	// Carl: new created points are decided by adjacent points

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: Face in One Ring

			// Carl: define handle for each vertex
			TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
			// Carl: define normal for each vertex
			TriMesh_ArrayKernelT<>::Normal normal1;
			TriMesh_ArrayKernelT<>::Normal normal2;
			TriMesh_ArrayKernelT<>::Normal normal3;

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1, point2, and point3 are the triangle vertices
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); normal1 = iMesh.normal(verHandle1); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); normal2 = iMesh.normal(verHandle2); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle(); normal3 = iMesh.normal(verHandle3);


			// Carl: point23 is not related to point1, so it will change every iteration
			// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
			TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2);
			TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3);
			TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1);

			// Carl: efface all the repeated points and faces
			// Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

		}
	}
	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();

	// Carl: recalculate position
	iMesh = oMesh;
	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
		// Carl: adjust point positions
		oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
	}
}

void MeshSubdivisior::NeighborWeightedFaceGuiding() {
	// Carl: the new created points are decided by the adjacent faces;
	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	TriMesh_ArrayKernelT<>::HalfedgeIter halfedgeIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: Face in One Ring

			// Carl: define handle for each vertex
			///  12Prime -- 1 -- 31Prime
			///      \     / \     /
			///       \   12  31  /
			///        \ /     \ /
			///         2- 23 - 3
			///          \     /
			///           \   /
			///            \ /
			///          23Prime 

			TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31Prime;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle12;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle23;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle31;
			TriMesh_ArrayKernelT<>::HalfedgeHandle nextHalfedgeHandle;

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1, point2, and point3 are the triangle vertices
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle();

			// Carl: get halfedge handles
			halfedgeHandle12 = iMesh.find_halfedge(verHandle1, verHandle2);
			halfedgeHandle23 = iMesh.find_halfedge(verHandle2, verHandle3);
			halfedgeHandle31 = iMesh.find_halfedge(verHandle3, verHandle1);

			// Carl: point12Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle12);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle12Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point12Prime = iMesh.point(verHandle12Prime);

			// Carl: point23Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle23);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle23Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point23Prime = iMesh.point(verHandle23Prime);

			// Carl: point31Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle31);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle31Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point31Prime = iMesh.point(verHandle31Prime);

			// Carl: point23 is not related to point1, so it will change every iteration
			// Carl: point12 and point31 are related to point1, so it will appear twice among all the iterations
			TriMesh_ArrayKernelT<>::Point point12 = GetMidPoint(point1, point2, point3, point12Prime);
			TriMesh_ArrayKernelT<>::Point point23 = GetMidPoint(point2, point3, point1, point23Prime);
			TriMesh_ArrayKernelT<>::Point point31 = GetMidPoint(point3, point1, point2, point31Prime);

			// Carl: efface all the repeated points and faces
			// Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}

			// Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}

			// Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}

			// Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, false);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}

		}

		// Carl: adjust point positions
		oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
	}

	// Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();
}

void MeshSubdivisior::NeighborWeightedGuiding(QVector<bool> keypointList) {
	// Carl: a combination of NeighborWeightedPointGuiding and NeighborWeighteFaceGuiding, controlled by keypoints;

	TriMesh_ArrayKernelT<>::VertexIter verIter;
	TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter;
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> vertexMap;

	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		// Carl: for each vertex

		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> middleNeighbors = GetOneRingMiddlePoints(verIter->idx());

		for (verFaceIter = iMesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: Face in One Ring

			// Carl: define handle for each vertex
			///  12Prime -- 1 -- 31Prime
			///      \     / \     /
			///       \   12  31  /
			///        \ /     \ /
			///         2- 23 - 3
			///          \     /
			///           \   /
			///            \ /
			///          23Prime 

			// Carl: define handle for each vertex
			TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle12Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle23Prime;
			TriMesh_ArrayKernelT<>::VertexHandle verHandle31Prime;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle12;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle23;
			TriMesh_ArrayKernelT<>::HalfedgeHandle halfedgeHandle31;
			TriMesh_ArrayKernelT<>::HalfedgeHandle nextHalfedgeHandle;

			faceVerIter = iMesh.cfv_iter(verFaceIter);

			// Carl: point1, point2, and point3 are the triangle vertices
			const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
			verHandle1 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
			verHandle2 = faceVerIter.handle(); faceVerIter++;
			const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
			verHandle3 = faceVerIter.handle();

			// Carl: get halfedge handles
			halfedgeHandle12 = iMesh.find_halfedge(verHandle1, verHandle2);
			halfedgeHandle23 = iMesh.find_halfedge(verHandle2, verHandle3);
			halfedgeHandle31 = iMesh.find_halfedge(verHandle3, verHandle1);

			// Carl: point12Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle12);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle12Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point12Prime = iMesh.point(verHandle12Prime);

			// Carl: point23Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle23);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle23Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point23Prime = iMesh.point(verHandle23Prime);

			// Carl: point31Prime
			nextHalfedgeHandle = iMesh.opposite_halfedge_handle(halfedgeHandle31);
			nextHalfedgeHandle = iMesh.next_halfedge_handle(nextHalfedgeHandle);
			verHandle31Prime = iMesh.to_vertex_handle(nextHalfedgeHandle);
			const TriMesh_ArrayKernelT<>::Point point31Prime = iMesh.point(verHandle31Prime);

			// Carl: point12, point23, or point31 will be the touching point to other vertex iteration
			/// the position depends on weather point1 and point23Prime are both keypoints, which leads the following situations
			/// if point1 and point23Prime are both keypoints, point23 should be calculated by point1, point2, point3, and point23Prime in each iteration
			/// else if point1 and point23Prime are both anti-keypoints, point23 should be calculated by point2, and point3 in each iteration.
			/// else if point1 are keypoint but point23Prime, point23 should be calculated by a weighted combination method of the last two situations.
			TriMesh_ArrayKernelT<>::Point point12, point23, point31;
			TriMesh_ArrayKernelT<>::Point point12Face = GetMidPoint(point1, point2, point3, point12Prime);
			TriMesh_ArrayKernelT<>::Point point23Face = GetMidPoint(point2, point3, point1, point23Prime);
			TriMesh_ArrayKernelT<>::Point point31Face = GetMidPoint(point3, point1, point2, point31Prime);
			TriMesh_ArrayKernelT<>::Point point12Point = GetMidPoint(point1, point2);
			TriMesh_ArrayKernelT<>::Point point23Point = GetMidPoint(point2, point3);
			TriMesh_ArrayKernelT<>::Point point31Point = GetMidPoint(point3, point1);
			double point12FaceWeight(0), point23FaceWeight(0), point31FaceWeight(0);
			double point12PointWeight(0), point23PointWeight(0), point31PointWeight(0);

			// Carl: within a couple of triangle, the weighted of vertices should be 
			///         1		|	N	||	1	|	2	|	3	|	4	|		P		|
			///        / \		-------------------------------------------------
			///       /   \		|	15	||	1	|	1	|	1	|	1	| 4/4*F + 0/4*P	|
			///      /     \	|	14	||	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	|
			///     2 --P-- 3	|	13	||	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	|
			///      \     /	|	12	||	1	|	1	|	0	|	0	| 2/4*F + 2/4*P	|
			///       \   /		|	11	||	1	|	0	|	1	|	1	| 3/4*F + 1/4*P	|
			///        \ /		|	10	||	1	|	0	|	1	|	0	| 2/4*F + 1/4*P	|
			///         4		|	9	||	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	|
			///					|	8	||	1	|	0	|	0	|	0	| 1/4*F + 3/4*P	|
			///					|	7	||	0	|	1	|	1	|	1	| 3/4*F + 1/4*P	|
			///		1 - key		|	6	||	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	|
			///		0 - unkey	|	5	||	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	|
			///					|	4	||	0	|	1	|	0	|	0	| 1/4*F + 3/4*P	|
			///					|	3	||	0	|	0	|	1	|	1	| 2/4*F + 2/4*P	|
			///					|	2	||	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	|
			///					|	1	||	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	|
			///					|	0	||	0	|	0	|	0	|	0	| 0/4*F + 4/4*P	|
			// Carl: within a iteration
			///  12' ---- 1 ---- 31'	|	N	||	1	|	2	|	3	|	12'	|	23'	|	31'	|		12		|		23		|		31		|
			///    \     / \     /		-------------------------------------------------------------------------------------------------
			///     \   12  31  /		|	63	||	1	|	1	|	1	|	1	|	1	|	1	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///      \ /     \ /		|	62	||	1	|	1	|	1	|	1	|	1	|	0	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///       2- 23 - 3			|	61	||	1	|	1	|	1	|	1	|	0	|	1	| 4/4*F + 0/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///        \     /			|	60	||	1	|	1	|	1	|	1	|	0	|	0	| 4/4*F + 0/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///         \   /			|	69	||	1	|	1	|	1	|	0	|	1	|	1	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///          \ /			|	58	||	1	|	1	|	1	|	0	|	1	|	0	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///          23'			|	57	||	1	|	1	|	1	|	0	|	0	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	56	||	1	|	1	|	1	|	0	|	0	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///			1 - key			|	55	||	1	|	1	|	0	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///			0 - unkey		|	54	||	1	|	1	|	0	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	53	||	1	|	1	|	0	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	52	||	1	|	1	|	0	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	51	||	1	|	1	|	0	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///							|	50	||	1	|	1	|	0	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	| 4/4*F + 0/4*P	|
			///							|	59	||	1	|	1	|	0	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	48	||	1	|	1	|	0	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	47	||	1	|	0	|	1	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	46	||	1	|	0	|	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	45	||	1	|	0	|	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	44	||	1	|	0	|	1	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	43	||	1	|	0	|	1	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	42	||	1	|	0	|	1	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	41	||	1	|	0	|	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	40	||	1	|	0	|	1	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	39	||	1	|	0	|	0	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	38	||	1	|	0	|	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	37	||	1	|	0	|	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	36	||	1	|	0	|	0	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	35	||	1	|	0	|	0	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	34	||	1	|	0	|	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	33	||	1	|	0	|	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	32	||	1	|	0	|	0	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	31	||	0	|	1	|	1	|	1	|	1	|	1	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	30	||	0	|	1	|	1	|	1	|	1	|	0	| 3/4*F + 1/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	29	||	0	|	1	|	1	|	1	|	0	|	1	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	28	||	0	|	1	|	1	|	1	|	0	|	0	| 3/4*F + 1/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	27	||	0	|	1	|	1	|	0	|	1	|	1	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	26	||	0	|	1	|	1	|	0	|	1	|	0	| 2/4*F + 2/4*P	| 3/4*F + 1/4*P	| 4/4*F + 0/4*P	|
			///							|	25	||	0	|	1	|	1	|	0	|	0	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	24	||	0	|	1	|	1	|	0	|	0	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	23	||	0	|	1	|	0	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	22	||	0	|	1	|	0	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	21	||	0	|	1	|	0	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	10	||	0	|	1	|	0	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	19	||	0	|	1	|	0	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	18	||	0	|	1	|	0	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	17	||	0	|	1	|	0	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	16	||	0	|	1	|	0	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	15	||	0	|	0	|	1	|	1	|	1	|	1	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	14	||	0	|	0	|	1	|	1	|	1	|	0	| 2/4*F + 2/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	13	||	0	|	0	|	1	|	1	|	0	|	1	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	12	||	0	|	0	|	1	|	1	|	0	|	0	| 2/4*F + 2/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	11	||	0	|	0	|	1	|	0	|	1	|	1	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	10	||	0	|	0	|	1	|	0	|	1	|	0	| 1/4*F + 3/4*P	| 2/4*F + 2/4*P	| 4/4*F + 0/4*P	|
			///							|	9	||	0	|	0	|	1	|	0	|	0	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	8	||	0	|	0	|	1	|	0	|	0	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	7	||	0	|	0	|	0	|	1	|	1	|	1	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	6	||	0	|	0	|	0	|	1	|	1	|	0	| 1/4*F + 3/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	5	||	0	|	0	|	0	|	1	|	0	|	1	| 1/4*F + 3/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	4	||	0	|	0	|	0	|	1	|	0	|	0	| 1/4*F + 3/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	3	||	0	|	0	|	0	|	0	|	1	|	1	| 0/4*F + 4/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	2	||	0	|	0	|	0	|	0	|	1	|	0	| 0/4*F + 4/4*P	| 1/4*F + 3/4*P	| 4/4*F + 0/4*P	|
			///							|	1	||	0	|	0	|	0	|	0	|	0	|	1	| 0/4*F + 4/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|
			///							|	0	||	0	|	0	|	0	|	0	|	0	|	0	| 0/4*F + 4/4*P	| 0/4*F + 4/4*P	| 4/4*F + 0/4*P	|

			// Carl: point12 weight
			point12FaceWeight = keypointList.at(verHandle1.idx()) + keypointList.at(verHandle2.idx()) + keypointList.at(verHandle3.idx()) + keypointList.at(verHandle12Prime.idx());
			point12PointWeight = !keypointList.at(verHandle1.idx()) + !keypointList.at(verHandle2.idx()) + !keypointList.at(verHandle3.idx()) + !keypointList.at(verHandle12Prime.idx());

			// Carl: point23 weight
			point23FaceWeight = keypointList.at(verHandle1.idx()) + keypointList.at(verHandle2.idx()) + keypointList.at(verHandle3.idx()) + keypointList.at(verHandle23Prime.idx());
			point23PointWeight = !keypointList.at(verHandle1.idx()) + !keypointList.at(verHandle2.idx()) + !keypointList.at(verHandle3.idx()) + !keypointList.at(verHandle23Prime.idx());

			// Carl: point31 weight
			point31FaceWeight = keypointList.at(verHandle1.idx()) + keypointList.at(verHandle2.idx()) + keypointList.at(verHandle3.idx()) + keypointList.at(verHandle31Prime.idx());
			point31PointWeight = !keypointList.at(verHandle1.idx()) + !keypointList.at(verHandle2.idx()) + !keypointList.at(verHandle3.idx()) + !keypointList.at(verHandle31Prime.idx());

			// Carl: get point12, point23, and point31
			point12 = (point12FaceWeight * point12Face + point12PointWeight * point12Point) / 4.0;
			point23 = (point23FaceWeight * point23Face + point23PointWeight * point23Point) / 4.0;
			point31 = (point31FaceWeight * point31Face + point31PointWeight * point31Point) / 4.0;


			// Carl: efface all the repeated points and faces
			// Carl: make sure that the point is unique
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

			// Carl: add generated points into the mesh
			// Carl: point12
			iter = vertexMap.find(point12);
			if (iter != vertexMap.end())
				verHandle12 = iter->second;
			else {
				verHandle12 = oMesh.add_vertex(point12);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));
			}/// Carl: point12

			 // Carl: point23
			iter = vertexMap.find(point23);
			if (iter != vertexMap.end())
				verHandle23 = iter->second;
			else {
				verHandle23 = oMesh.add_vertex(point23);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));
			}/// Carl: point23

			 // Carl: point31
			iter = vertexMap.find(point31);
			if (iter != vertexMap.end())
				verHandle31 = iter->second;
			else {
				verHandle31 = oMesh.add_vertex(point31);
				vertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));
			}/// Carl: point31

			 // Carl: get vertexhandle;
			if (!oMesh.status(verFaceIter).deleted()) {

				oMesh.delete_face(verFaceIter, true);
				oMesh.add_face(verHandle1, verHandle12, verHandle31);
				oMesh.add_face(verHandle2, verHandle23, verHandle12);
				oMesh.add_face(verHandle3, verHandle31, verHandle23);
				oMesh.add_face(verHandle12, verHandle23, verHandle31);

			}
		}/// Face in One Ring

		 // Carl: adjust point positions
		if (keypointList.at(verIter.handle().idx())) {
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
		}
		else {
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(middleNeighbors, iMesh.point(verIter));
		}
	}/// for each vertex

	 // Carl: Delete all elements that are marked as deleted form memory
	oMesh.garbage_collection();

	// Carl: recalculate position
	iMesh = oMesh;
	for (verIter = iMesh.vertices_begin(); verIter != iMesh.vertices_end(); verIter++) {
		if (verIter.handle().idx() >= keypointList.size()) {
			// Carl: added points
			std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> baseNeighbors = GetOneRingBasePoints(verIter->idx());
			oMesh.point(verIter) = PointNeighborWeightedAdjustment(baseNeighbors, iMesh.point(verIter));
		}
	}

}
