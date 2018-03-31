#include "MeshSubdivisior.h"

TriMesh_ArrayKernelT<>::Point MeshSubdivisior::GetMidPoint(TriMesh_ArrayKernelT<>::Point point1, TriMesh_ArrayKernelT<>::Point point2) {
	// Carl: get midpoint between point1 and point2;
	/// Position:	point1 --- mid --- point2
	/// Weight:		0.5 ------ mid ------ 0.5

	double midX = (point1[0] + point2[0]) / 2.0;
	double midY = (point1[1] + point2[1]) / 2.0;
	double midZ = (point1[2] + point2[2]) / 2.0;

	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisior::GetMidPoint(TriMesh_ArrayKernelT<>::Point endPoint1, TriMesh_ArrayKernelT<>::Point endPoint2, TriMesh_ArrayKernelT<>::Point sidePoint1, TriMesh_ArrayKernelT<>::Point sidePoint2) {
	// Carl: get midpoint between endPoint1, endPoint2, sidePoint1, and sidePoint2
	/// Position:       sidePoint1
	///                /          \
	///               /            \
	///              /              \
	///         endPoint1 - mid - endPoint2
	///              \              /
	///               \            /
	///                \          /
	///                 sidePoint2
	/// Weight:            1/8
	///                /          \
	///               /            \
	///              /              \
	///             3/8 --- mid --- 3/8
	///              \              /
	///               \            /
	///                \          /
	///                    1/8

	double midX = (3.0 * endPoint1[0] + 3.0 * endPoint2[0] + sidePoint1[0] + sidePoint2[0]) / 8.0;
	double midY = (3.0 * endPoint1[1] + 3.0 * endPoint2[1] + sidePoint1[1] + sidePoint2[1]) / 8.0;
	double midZ = (3.0 * endPoint1[2] + 3.0 * endPoint2[2] + sidePoint1[2] + sidePoint2[2]) / 8.0;

	return TriMesh_ArrayKernelT<>::Point(midX, midY, midZ);
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisior::GetOneRingBasePoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 2, and 3

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
		// Carl: Face in One Ring

		// Carl: define handle for each vertex
		TriMesh_ArrayKernelT<>::VertexHandle verHandle1;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle2;
		TriMesh_ArrayKernelT<>::VertexHandle verHandle3;
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

		// Carl: point1, point2, and point3 are the triangle vertices
		const TriMesh_ArrayKernelT<>::Point point1 = iMesh.point(faceVerIter);
		verHandle1 = faceVerIter.handle(); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point2 = iMesh.point(faceVerIter);
		verHandle2 = faceVerIter.handle(); faceVerIter++;
		const TriMesh_ArrayKernelT<>::Point point3 = iMesh.point(faceVerIter);
		verHandle3 = faceVerIter.handle();

		// Carl: efface all the repeated points and faces
		// Carl: make sure that the point is unique
		std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;

		// Carl: point1
		iter = oneRingVertexMap.find(point1);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point1, verHandle1));

		// Carl: point2
		iter = oneRingVertexMap.find(point2);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point2, verHandle2));

		// Carl: point3
		iter = oneRingVertexMap.find(point3);
		if (iter == oneRingVertexMap.end())
			oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point3, verHandle3));

	}

	// Carl: remove itself;
	oneRingVertexMap.erase(iMesh.point(vertHandle));

	return oneRingVertexMap;
}

std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> MeshSubdivisior::GetOneRingMiddlePoints(int pointHandle) {
	// Carl: get points within one ring neighbor including part of subdivided points
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// this function is used to find out all the points including 12, and 31

	TriMesh_ArrayKernelT<>::VertexHandle vertHandle = iMesh.vertex_handle(pointHandle);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> oneRingVertexMap;

	for (TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter = iMesh.vf_iter(vertHandle); verFaceIter; verFaceIter++) {
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
		// Carl: faceVertex;
		TriMesh_ArrayKernelT<>::FaceVertexIter faceVerIter = iMesh.cfv_iter(verFaceIter);

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

		if (point1 == iMesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}
		else if (point2 == iMesh.point(vertHandle)) {

			// Carl: point12
			iter = oneRingVertexMap.find(point12);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point12, verHandle12));

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

		}
		else if (point3 == iMesh.point(vertHandle)) {

			// Carl: point23
			iter = oneRingVertexMap.find(point23);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point23, verHandle23));

			// Carl: point31
			iter = oneRingVertexMap.find(point31);
			if (iter == oneRingVertexMap.end())
				oneRingVertexMap.insert(std::pair<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>(point31, verHandle31));

		}

	}

	return oneRingVertexMap;
}

TriMesh_ArrayKernelT<>::Point MeshSubdivisior::PointNeighborWeightedAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> neighbor, TriMesh_ArrayKernelT<>::Point point) {
	// Carl: using neighbors position infor to get new point position
	/// We use a weighted centroid for triangular surfaces
	/// the centroid takes 1/4 of the vertex being repositioned plus 3/8 of the two neighboring vertices.
	/// suppose the original triangel is 1 --- 2 --- 3 --- 1, and 1 is given vertex
	/// after subdivide, the edge will have the format 1 --- 12 --- 2 --- 23 --- 3 --- 31 --- 1
	/// in this triangle, the weight of vertex 1 is 1/4, while the weight of 2 and 3 are 3/8 and 3/8 respectively
	/// reference http://www.holmes3d.net/graphics/subdivision/
	/// reference http://blog.csdn.net/lafengxiaoyu/article/details/51524302
	/// reference http://blog.csdn.net/bugrunner/article/details/6249417
	/// if the amount of neighbor faces are N, then the weight of centroid should be (1 - N * beta) and that for other neighbor vertices are (beta);
	/// notive the centroid calculation for triangels is not uniform and depends upon which vertex the centroid is being accumulated into.

	TriMesh_ArrayKernelT<>::Point position(0.0, 0.0, 0.0);

	// Carl: beta version 1: from A Factored Approach to Subdivision Surfaces
	//double beta = (5.0/3.0 - 8.0/3.0 * ((3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size())) * (3.0/8.0 + 1.0/4.0 * cos(2.0*M_PI/neighbor.size())))) / neighbor.size();

	// Carl: beta version 2: from http://blog.csdn.net/bugrunner/article/details/6249417
	double beta = (5.0 / 8.0 - (3.0 / 8.0 + 1.0 / 4.0 * cos(2.0*M_PI / neighbor.size())) * (3.0 / 8.0 + 1.0 / 4.0 * cos(2.0*M_PI / neighbor.size()))) / neighbor.size();

	// Carl: beta version 3: from OpenMesh
	//double beta = (40.0 - (3.0 + 2.0*cos(2.0*M_PI/neighbor.size())) * (3.0 + 2.0*cos(2.0*M_PI / neighbor.size()))) / (neighbor.size() * 64.0);

	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>::iterator iter;
	for (iter = neighbor.begin(); iter != neighbor.end(); iter++)
		position += (*iter).first * beta;

	position += (1 - neighbor.size() * beta) * point;

	return position;
}