#define TWO_RING
#include "KeypointDetector.h"

KeypointDetector::KeypointDetector() {

}

bool KeypointDetector::LoadMeshFile(QString meshPath) {
	// Carl: Load mesh file and update normals;
	this->meshPath = meshPath;
	if (OpenMesh::IO::read_mesh(mesh, meshPath.toStdString())) {
		// Carl: request for update
		mesh.request_face_normals();
		mesh.request_vertex_normals();
		// Carl: update
		mesh.update_normals();
		return true;
	}
	else
		return false;
}

float KeypointDetector::GetAngle(float *gridPointcenter, float *p1, float *p2) {
	// Carl: get angle

	float x_n1 = p1[0] - gridPointcenter[0];
	float y_n1 = p1[1] - gridPointcenter[1];
	float z_n1 = p1[2] - gridPointcenter[2];

	float x_n2 = p2[0] - gridPointcenter[0];
	float y_n2 = p2[1] - gridPointcenter[1];
	float z_n2 = p2[2] - gridPointcenter[2];


	float normN1 = sqrt(x_n1*x_n1 + y_n1*y_n1 + z_n1*z_n1);
	float normN2 = sqrt(x_n2*x_n2 + y_n2*y_n2 + z_n2*z_n2);

	float alpha = acos((x_n1*x_n2 + y_n1*y_n2 + z_n1*z_n2) / (normN1 *normN2));

	return alpha;
}

float KeypointDetector::GetEuclidDistance(float *pointOfIntersection, float *gridPoint) {
	// Carl: get euclide distance
	float distX = pointOfIntersection[0] - gridPoint[0];
	float distY = pointOfIntersection[1] - gridPoint[1];
	float distZ = pointOfIntersection[2] - gridPoint[2];

	float dist = sqrt(distX*distX + distY*distY + distZ*distZ);

	return dist;
}

void KeypointDetector::GetFaceEquation(float &a, float &b, float &c, float &d, float *point) {
	// Carl: get plane equation
	float x1 = point[0];
	float y1 = point[1];
	float z1 = point[2];
	float x2 = point[3];
	float y2 = point[4];
	float z2 = point[5];
	float x3 = point[6];
	float y3 = point[7];
	float z3 = point[8];

	a = y1*z2 - y1*z3 - y2*z1 + y2*z3 + y3*z1 - y3*z2;
	b = x1*z3 + x2*z1 - x2*z3 - x3*z1 + x3*z2 - x1*z2;
	c = x1*y2 - x1*y3 - x2*y1 + x2*y3 + x3*y1 - x3*y2;
	d = x1*y3*z2 + x2*y1*z3 - x2*y3*z1 - x3*y1*z2 + x3*y2*z1 - x1*y2*z3;
}

void KeypointDetector::GetNormalizedVector(float &x, float &y, float &z) {
	// Carl: normalize the vector
	double abs = sqrt(x*x + y*y + z*z);
	x = x / abs;
	y = y / abs;
	z = z / abs;

	return;
}

double KeypointDetector::GetMeshScale() {
	// Carl: get mesh scale
	/* to calculate the minimum coordinates and form point min and max
	which is a box that will contains the entire mesh; */

	OpenMesh::TriMesh_ArrayKernelT<>::Point temp;
	OpenMesh::TriMesh_ArrayKernelT<>::Point min = mesh.point(mesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::Point max = mesh.point(mesh.vertices_begin());
	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {
		temp = mesh.point(*verIter);
		min[0] = temp[0] < min[0] ? temp[0] : min[0];
		min[1] = temp[1] < min[1] ? temp[1] : min[1];
		min[2] = temp[2] < min[2] ? temp[2] : min[2];
		max[0] = temp[0] > max[0] ? temp[0] : max[0];
		max[1] = temp[1] > max[1] ? temp[1] : max[1];
		max[2] = temp[2] > max[2] ? temp[2] : max[2];
	}

	return OpenMesh::Vec3f(max - min).norm();
}

void KeypointDetector::GetPointofIntersection(float a, float b, float c, float d, float *pointOfIntersection, float *point, float *normal) {
	// Carl: get point intersection
	float x, y, z;
	float xn = normal[0];
	float yn = normal[1];
	float zn = normal[2];
	float x0 = point[0];
	float y0 = point[1];
	float z0 = point[2];

	x = (x0 * (b*yn + c*zn) - xn*(b*y0 + c*z0 + d)) / (a* xn + b* yn + c*zn);
	y = (y0 * (a*xn + c*zn) - yn*(a*x0 + c*z0 + d)) / (a* xn + b* yn + c*zn);
	z = (z0 * (a*xn + b*yn) - zn*(a*x0 + b*y0 + d)) / (a* xn + b* yn + c*zn);

	pointOfIntersection[0] = x;
	pointOfIntersection[1] = y;
	pointOfIntersection[2] = z;
}

bool KeypointDetector::ImbThresholdDetection(OpenMesh::Vec3f grid2D[3][3], std::vector<OpenMesh::FaceHandle> faceList, OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle vertexHandle, OpenMesh::TriMesh_ArrayKernelT<> &mesh) {
	struct point3D {
		float x;
		float y;
		float z;
	};

	typedef OpenMesh::TriMesh_ArrayKernelT<>	MVMesh;
	typedef std::vector<OpenMesh::FaceHandle>	FaceList;
	typedef std::vector<point3D>				ArrayList3;
	typedef std::vector<float>							 ArrayList;



	float vertexPoint[3];
	float gridPointcenter[3];
	MVMesh::Point pVertex = mesh.point(vertexHandle);
	MVMesh::VertexFaceIter vf_it;
	MVMesh::VertexVertexIter vv_it = mesh.vv_begin(vertexHandle);
	int OneRingVertexNum = 0;


	//当前网格顶点的坐标
	vertexPoint[0] = pVertex[0];
	vertexPoint[1] = pVertex[1];
	vertexPoint[2] = pVertex[2];

	//切平面的中心点
	gridPointcenter[0] = grid2D[1][1][0];
	gridPointcenter[1] = grid2D[1][1][1];
	gridPointcenter[2] = grid2D[1][1][2];

	//计算与网格顶点垂直方向切平面的方程 ax + by +cz + d = 0
	float a, b, c, d;
	float point[9] = { grid2D[0][0][0], grid2D[0][0][1], grid2D[0][0][2],
		grid2D[0][2][0], grid2D[0][2][1], grid2D[0][2][2],
		grid2D[2][2][0], grid2D[2][2][1], grid2D[2][2][2] };
	a = b = c = d = 0;

	//得到且平面的方程
	GetFaceEquation(a, b, c, d, point);
	float pointOfIntersection[3] = { 0, 0, 0 };

	ArrayList3 faceNormalPointList;

	MVMesh::ConstVertexFaceIter v_it = mesh.cvf_iter(vertexHandle);

	for (vv_it; vv_it != mesh.vv_end(vertexHandle); ++vv_it)
		//for(vf_it = mesh_.vf_iter(vertexHandle);vf_it;++vf_it)
	{
		OneRingVertexNum++;
	}

	//计算顶点领域面法向量与切平面的交点
	for (FaceList::iterator it = faceList.begin(); it != faceList.end(); ++it)
	{
		OpenMesh::FaceHandle fh = *it;

		//获取当前三角面上的法向量
		const MVMesh::Normal fn = mesh.calc_face_normal(fh);
		float fnormal[3];
		fnormal[0] = fn[0];
		fnormal[1] = fn[1];
		fnormal[2] = fn[2];

		GetPointofIntersection(a, b, c, d, pointOfIntersection, vertexPoint, fnormal);

		point3D p;
		p.x = pointOfIntersection[0];
		p.y = pointOfIntersection[1];
		p.z = pointOfIntersection[2];

		faceNormalPointList.push_back(p);
	}

	ArrayList faceNormalAngleList;

	omp_lock_t lock;
	float p1[3], p2[3];

	for (ArrayList3::iterator it = faceNormalPointList.begin(); it != faceNormalPointList.end(); it++)
	{
		ArrayList3::iterator it2;

#pragma omp single nowait 
		{
			if (it == faceNormalPointList.end() - 1)
			{
				it2 = faceNormalPointList.begin();
			}
			else
			{
				it2 = it + 1;
			}
			float currentAngle;
			point3D pp1 = *it;
			point3D pp2 = *it2;

			p1[0] = pp1.x;
			p1[1] = pp1.y;
			p1[2] = pp1.z;
			p2[0] = pp2.x;
			p2[1] = pp2.y;
			p2[2] = pp2.z;

			currentAngle = GetAngle(vertexPoint, gridPointcenter, p1);
			faceNormalAngleList.push_back(currentAngle);
		}
	}
	std::sort(faceNormalAngleList.begin(), faceNormalAngleList.end());
	//maxDiff
	float TMP = 0;
	int count = 0;

	//faceNormalAngleList：夹角的list
	for (ArrayList::iterator it = faceNormalAngleList.begin(); it != faceNormalAngleList.end(); it++)
	{
		if (it == faceNormalAngleList.end() - 1)
		{
			break;
		}
		TMP = *it;

		//如果夹角大于0.5(3.14为π)，进行计数

		//idea：排序后算出最大的maxdiff，然后TMP大于MAXDIFF来计算(这招效果不行)
		//比较好的经验值：0.45
		if (TMP > 0.392)
		{
			count++;
		}
	}

	//夹角大于0.5的数量
	if (count >= (faceNormalAngleList.size() / 2))
	{
		faceNormalAngleList.clear();
		return true;
	}
	else
	{
		faceNormalAngleList.clear();
		return false;
	}
}

QVector<bool> KeypointDetector::KeypointDetection() {

	OpenMesh::TriMesh_ArrayKernelT<>::VertexIter verIter;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexVertexIter verVerIter;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexFaceIter verFaceIter;
	OpenMesh::TriMesh_ArrayKernelT<>::Point point;
	OpenMesh::TriMesh_ArrayKernelT<>::Normal normal;
	OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle verHandle;
	QVector<bool> isKeypoints;
	bool isKeypoint;

	double meshScale = GetMeshScale();

	for (verIter = mesh.vertices_begin(); verIter != mesh.vertices_end(); verIter++) {

		verHandle = *verIter;

		if (mesh.is_boundary(verIter.handle())) {
			isKeypoints.push_back(false);
			continue;
		}

		point = mesh.point(*verIter);
		normal = mesh.normal(*verIter);

		float normalX = normal[0] * 1000;
		float normalY = normal[1] * 1000;
		float normalZ = normal[2] * 1000;
		float normalFloat[3] = { normalX, normalY, normalZ };

		float xX = 1.0f;
		float xY = 1.0f;
		float xZ = (0 - (xX*normalX + xY*normalY)) / normalZ;

		float yX = normalY * xZ - xY * normalZ;
		float yY = normalZ * xX - xZ * normalX;
		float yZ = normalX * xY - xX * normalY;

		GetNormalizedVector(xX, xY, xZ);
		GetNormalizedVector(yX, yY, xZ);

		float vectorX[3] = { xX, xY, xZ };
		float vectorY[3] = { yX, yY, yZ };

		OpenMesh::Vec3f grid2D[3][3];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				grid2D[i][j][0] = point[0] + normal[0] * 0.2 + (i - 1) * xX * meshScale + (j - 1) * yX * meshScale;
				grid2D[i][j][1] = point[1] + normal[1] * 0.2 + (i - 1) * xY * meshScale + (j - 1) * yY * meshScale;
				grid2D[i][j][2] = point[2] + normal[2] * 0.2 + (i - 1) * xZ * meshScale + (j - 1) * yZ * meshScale;
			}
		}

		std::vector<OpenMesh::FaceHandle> faceList;

		for (verFaceIter = mesh.vf_iter(*verIter); verFaceIter; verFaceIter++) {
			// Carl: One ring
			OpenMesh::TriMesh_ArrayKernelT<>::FaceHandle faceHandle = verFaceIter;
			OpenMesh::TriMesh_ArrayKernelT<>::ConstFaceVertexIter faceVerIter = mesh.cfv_iter(faceHandle);

			const OpenMesh::TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter);	faceVerIter++;
			const OpenMesh::TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter);	faceVerIter++;
			const OpenMesh::TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter);

			faceList.push_back(faceHandle);

#ifdef TWO_RING

			OpenMesh::TriMesh_ArrayKernelT<>::FaceFaceIter faceFaceIter;
			for (faceFaceIter = mesh.ff_iter(faceHandle); faceFaceIter; faceFaceIter++) {
				// Carl: Two ring
				OpenMesh::TriMesh_ArrayKernelT<>::FaceHandle faceHandle2 = faceFaceIter;
				OpenMesh::TriMesh_ArrayKernelT<>::ConstFaceVertexIter faceVerIter2 = mesh.cfv_iter(faceHandle2);

				const OpenMesh::TriMesh_ArrayKernelT<>::Point point1 = mesh.point(faceVerIter2); faceVerIter2++;
				const OpenMesh::TriMesh_ArrayKernelT<>::Point point2 = mesh.point(faceVerIter2); faceVerIter2++;
				const OpenMesh::TriMesh_ArrayKernelT<>::Point point3 = mesh.point(faceVerIter2);

				faceList.push_back(faceHandle2);
			}

#endif // TWO_RING

			// Carl: efface the same elements;
			for (std::vector<OpenMesh::FaceHandle>::iterator iter = faceList.begin(); iter != faceList.end(); iter++) {
				std::vector<OpenMesh::FaceHandle>::const_iterator iterInside = faceList.end();
				iterInside--;
				for (iterInside; iterInside != iter; iterInside--) {
					if ((*iter) == (*iterInside))
						iterInside = faceList.erase(iterInside);
				}
			}

		}

		isKeypoint = ImbThresholdDetection(grid2D, faceList, verHandle, mesh);
		isKeypoints.push_back(isKeypoint);
	}

	return isKeypoints;
}

