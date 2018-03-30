#pragma once

#include "meshsubdivisior_global.h"
#include <OpenMesh\Core\IO\MeshIO.hh>
#include <OpenMesh\Core\Mesh\TriMesh_ArrayKernelT.hh>
#include <Eigen\Dense>
#include <qstring.h>

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

};
