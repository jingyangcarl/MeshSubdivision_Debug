#include "MeshSubdivisior.h"

MeshSubdivisior::MeshSubdivisior() {
	this->iMeshPath = "";
	this->oMeshPath = "";
}

bool MeshSubdivisior::LoadMeshFile(QString filePath) {
	// Carl: load mesh file and update normals;
	this->iMeshPath = filePath;
	if (OpenMesh::IO::read_mesh(iMesh, iMeshPath.toStdString())) {
		// Carl request for update;
		iMesh.request_face_normals();
		iMesh.request_vertex_normals();
		iMesh.request_halfedge_normals();
		// Carl: update
		iMesh.update_normals();
		// Carl: synchronize
		oMesh = iMesh;
		// Carl: get mesh scale;
		//GetMeshScale();
		return true;
	}
	else
		return false;
}

QString MeshSubdivisior::WriteMeshFile() {
	if (OpenMesh::IO::write_mesh(oMesh, oMeshPath.toStdString()))
		return oMeshPath;
	else
		return "";
}

void MeshSubdivisior::SetOutputMeshPath(QString oMeshPath) {
	this->oMeshPath = oMeshPath;
}
