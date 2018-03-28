#pragma once

#include "keypointdetector_global.h"
#include <OpenMesh\Core\IO\reader\PLYReader.hh>
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <omp.h>
#include "qstring.h"
#include "qvector.h"

class KEYPOINTDETECTOR_EXPORT KeypointDetector 
{

public:
	KeypointDetector();
	bool LoadMeshFile(QString);
	// Carl: start detection;
	QVector<bool> KeypointDetection();

private:
	OpenMesh::TriMesh_ArrayKernelT<> mesh;
	QString meshPath;

	// Carl & FKY: get angle
	float GetAngle(float *, float *, float *);
	// Carl & FKY: get euclide distance
	float GetEuclidDistance(float *, float *);
	// Carl & FKY: get plane equation
	void GetFaceEquation(float &, float &, float &, float &, float *);
	// Carl & FKY: normalize the vector
	void GetNormalizedVector(float &, float &, float &);
	// Carl & FKY: get mesh scale
	double GetMeshScale();
	// Carl & FKY: get point intersection
	void GetPointofIntersection(float, float, float, float, float *, float *, float *);
	// Carl & FKY: detect the imbalanced threshold for given points;
	bool ImbThresholdDetection(OpenMesh::Vec3f grid2D[3][3], std::vector<OpenMesh::FaceHandle>, OpenMesh::TriMesh_ArrayKernelT<>::VertexHandle, OpenMesh::TriMesh_ArrayKernelT<> &);
};
