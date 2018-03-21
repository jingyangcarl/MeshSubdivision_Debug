#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ShowMesh_1() {
	// Carl: show mesh_1 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_1->addPolygonMesh(mesh_1, "mesh_1");
		viewer_1->resetCamera();
		qvtkWidget_1->update();

		OutputTextEditFinished("Show Mesh_1 finished;");
	}
	else OutputTextEditError("QVTKWidget_1 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::ShowMesh_2() {
	// Carl: show mesh_2 to QVTKWidget
	if (layoutStatus >= 2) {
		viewer_2->addPolygonMesh(mesh_2, "mesh_2");
		viewer_2->resetCamera();
		qvtkWidget_2->update();

		OutputTextEditFinished("Show Mesh_2 finished;");
	}
	else OutputTextEditError("QVTKWidget_2 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowMesh_3() {
	// Carl: show mesh_3 to QVTKWidget
	if (layoutStatus >= 3) {
		viewer_3->addPolygonMesh(mesh_3, "mesh_3");
		viewer_3->resetCamera();
		qvtkWidget_3->update();

		OutputTextEditFinished("Show Mesh_3 finished;");
	}
	else OutputTextEditError("QVTKWidget_3 hasn't been initialized;");
	return;
}


void MeshSubdivision_Debug::ShowMesh_4() {
	// Carl: show mesh_4 to QVTKWidget
	if (layoutStatus >= 4) {
		viewer_4->addPolygonMesh(mesh_4, "mesh_4");
		viewer_4->resetCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Show Mesh_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_1() {
	// Carl: clear mesh_1 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_1->removePolygonMesh("mesh_1");
		viewer_1->updateCamera();
		qvtkWidget_1->update();

		OutputTextEditFinished("Clear Mesh_1 finished;");
	}
	else OutputTextEditError("QVTKWidget_1 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_2() {
	// Carl: clear mesh_2 to QVTKWidget
	if (layoutStatus >= 2) {
		viewer_2->removePolygonMesh("mesh_2");
		viewer_2->updateCamera();
		qvtkWidget_2->update();

		OutputTextEditFinished("Clear Mesh_2 finished;");
	}
	else OutputTextEditError("QVTKWidget_2 hasn't been initialized;");
	return;
}


void MeshSubdivision_Debug::ClearMesh_3() {
	// Carl: clear mesh_3 to QVTKWidget
	if (layoutStatus >= 3) {
		viewer_3->removePolygonMesh("mesh_3");
		viewer_3->updateCamera();
		qvtkWidget_3->update();

		OutputTextEditFinished("Clear Mesh_3 finished;");
	}
	else OutputTextEditError("QVTKWidget_3 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_4() {
	// Carl: clear mesh_4 to QVTKWidget
	if (layoutStatus >= 4) {
		viewer_4->removePolygonMesh("mesh_4");
		viewer_4->updateCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Clear Mesh_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_1() {
	// Carl: show cloud_1 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_1->addPointCloud(cloud_1, "cloud_1");
		viewer_1->resetCamera();
		qvtkWidget_1->update();

		OutputTextEditFinished("Show Cloud_1 finished;");
	}
	else OutputTextEditError("QVTKWidget_1 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_2() {
	// Carl: show cloud_2 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_2->addPointCloud(cloud_2, "cloud_2");
		viewer_2->resetCamera();
		qvtkWidget_2->update();

		OutputTextEditFinished("Show Cloud_2 finished;");
	}
	else OutputTextEditError("QVTKWidget_2 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_3() {
	// Carl: show cloud_3 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_3->addPointCloud(cloud_3, "cloud_3");
		viewer_3->resetCamera();
		qvtkWidget_3->update();

		OutputTextEditFinished("Show Cloud_3 finished;");
	}
	else OutputTextEditError("QVTKWidget_3 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_4() {
	// Carl: show cloud_4 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_4->addPointCloud(cloud_4, "cloud_4");
		viewer_4->resetCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Show Cloud_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_1() {
	// Carl: clear cloud_1 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_1->removePointCloud("cloud_1");
		viewer_1->updateCamera();
		qvtkWidget_1->update();

		OutputTextEditFinished("Clear Cloud_1 finished;");
	}
	else OutputTextEditError("QVTKWidget_1 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_2() {
	// Carl: clear cloud_2 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_2->removePointCloud("cloud_2");
		viewer_2->updateCamera();
		qvtkWidget_2->update();

		OutputTextEditFinished("Clear Cloud_2 finished;");
	}
	else OutputTextEditError("QVTKWidget_2 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_3() {
	// Carl: clear cloud_3 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_3->removePointCloud("cloud_3");
		viewer_3->updateCamera();
		qvtkWidget_3->update();

		OutputTextEditFinished("Clear Cloud_3 finished;");
	}
	else OutputTextEditError("QVTKWidget_3 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_4() {
	// Carl: clear cloud_4 to QVTKWidget
	if (layoutStatus >= 1) {
		viewer_4->removePointCloud("cloud_4");
		viewer_4->updateCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Clear Cloud_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}