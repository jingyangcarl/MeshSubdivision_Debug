#pragma once

#include "meshsubdivisior_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <Eigen\Dense>
#include <qstring.h>
#include <qvector.h>

using namespace OpenMesh;

class MESHSUBDIVISIOR_EXPORT MeshSubdivisior
{
private:
	struct Traits : public OpenMesh::DefaultTraits {
		// Carl: delete_face() Needs the Attributes::Status attribute for vertices, edges and faces.
		VertexAttributes(OpenMesh::Attributes::Status);
		FaceAttributes(OpenMesh::Attributes::Status);
		EdgeAttributes(OpenMesh::Attributes::Status);
	};

	// Carl: triangle mesh data;
	OpenMesh::TriMesh_ArrayKernelT<Traits> iMesh;
	OpenMesh::TriMesh_ArrayKernelT<Traits> oMesh;

	// Carl: mesh path;
	QString iMeshPath;
	QString oMeshPath;

public:
	// Carl: constructor
	MeshSubdivisior();
	// Carl: load mesh file
	bool LoadMeshFile(QString);
	// Carl: write mesh file
	QString WriteMeshFile();
	// Carl: set path;
	void SetOutputMeshPath(QString);

	/******************** MeshSubdivisorTool.cpp ********************/
	// Carl: subdivision tool
	void MeshSubdivisionCatmullClarkT();
	void MeshSubdivisiorLoopT();
	void MeshSubdivisionModifiedButterFlyT();
	void MeshSubdivisionSqrt3T();
	void MeshSubdivisionSqrt3InterpolatingSubdividerLabsikGreinerT();
	void MeshSubdivisionEdgePreserved();
	void MeshSubdivisionSmoothedEdgePreserved();
	void MeshSubdivisionFeaturePreserved(QVector<bool>);

	/******************** MainAlgorithm.cpp ********************/
	// Carl: import from previous project
	// Carl: project link: https://github.com/jingyangcarl/ImbalancedKeypoints_Debug
	void NeighborWeightedPointGuiding();
	void NeighborWeightedFaceGuiding();
	void NeighborWeightedGuiding(QVector<bool>);

	/******************** AssistAlgorithm.cpp ********************/
	// Carl: import from previous project
	// Carl: project link: https://github.com/jingyangcarl/ImbalancedKeypoints_Debug
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
	TriMesh_ArrayKernelT<>::Point GetMidPoint(TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::Point);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingBasePoints(int);
	std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle> GetOneRingMiddlePoints(int);
	TriMesh_ArrayKernelT<>::Point PointNeighborWeightedAdjustment(std::map<TriMesh_ArrayKernelT<>::Point, TriMesh_ArrayKernelT<>::VertexHandle>, TriMesh_ArrayKernelT<>::Point);


};
