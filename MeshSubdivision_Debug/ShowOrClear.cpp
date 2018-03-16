#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ShowMesh_1() {
	// Carl: show mesh_1 to QVTKWidget
	viewer_1->addPolygonMesh(mesh_1, "mesh_1");
	viewer_1->resetCamera();
	qvtkWidget_1->update();

	OutputTextEditFinished("Show Mesh_1 finished;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_1() {
	// Carl: clear mesh_1 to QVTKWidget
	viewer_1->removePolygonMesh("mesh_1");
	viewer_1->updateCamera();
	qvtkWidget_1->update();

	OutputTextEditFinished("Clear Mesh_1 finished;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_1() {
	// Carl: show cloud_1 to QVTKWidget
	viewer_1->addPointCloud(cloud_1, "cloud_1");
	viewer_1->resetCamera();
	qvtkWidget_1->update();

	OutputTextEditFinished("Show Cloud_1 finished;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_1() {
	// Carl: clear cloud_1 to QVTKWidget
	viewer_1->removePointCloud("cloud_1");
	viewer_1->updateCamera();
	qvtkWidget_1->update();

	OutputTextEditFinished("Clear Cloud_1 finished;");
	return;
}