#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ShowMesh_1() {
	// Carl: show mesh_1 to QVTKWidget
	viewer_1->addPolygonMesh(mesh_1, "mesh_1");
	viewer_1->resetCamera();
	qvtkWidget_1->update();

	OutputTextEditFinished("Show Mesh_1 finished;");
	return;
}

void MeshSubdivision_Debug::ShowMesh_2() {
	// Carl: show mesh_2 to QVTKWidget
	viewer_2->addPolygonMesh(mesh_2, "mesh_2");
	viewer_2->resetCamera();
	qvtkWidget_2->update();

	OutputTextEditFinished("Show Mesh_2 finished;");
	return;
}

void MeshSubdivision_Debug::ShowMesh_3() {
	// Carl: show mesh_3 to QVTKWidget
	viewer_3->addPolygonMesh(mesh_3, "mesh_3");
	viewer_3->resetCamera();
	qvtkWidget_3->update();

	OutputTextEditFinished("Show Mesh_3 finished;");
	return;
}


void MeshSubdivision_Debug::ShowMesh_4() {
	// Carl: show mesh_4 to QVTKWidget
	viewer_4->addPolygonMesh(mesh_4, "mesh_4");
	viewer_4->resetCamera();
	qvtkWidget_4->update();

	OutputTextEditFinished("Show Mesh_4 finished;");
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

void MeshSubdivision_Debug::ClearMesh_2() {
	// Carl: clear mesh_2 to QVTKWidget
	viewer_2->removePolygonMesh("mesh_2");
	viewer_2->updateCamera();
	qvtkWidget_2->update();

	OutputTextEditFinished("Clear Mesh_2 finished;");
	return;
}


void MeshSubdivision_Debug::ClearMesh_3() {
	// Carl: clear mesh_3 to QVTKWidget
	viewer_3->removePolygonMesh("mesh_3");
	viewer_3->updateCamera();
	qvtkWidget_3->update();

	OutputTextEditFinished("Clear Mesh_3 finished;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_4() {
	// Carl: clear mesh_4 to QVTKWidget
	viewer_4->removePolygonMesh("mesh_4");
	viewer_4->updateCamera();
	qvtkWidget_4->update();

	OutputTextEditFinished("Clear Mesh_4 finished;");
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