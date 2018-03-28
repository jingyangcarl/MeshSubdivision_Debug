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

void MeshSubdivision_Debug::ShowMesh_5() {
	// Carl: show mesh_5 to QVTKWidget
	if (layoutStatus >= 5) {
		viewer_5->addPolygonMesh(mesh_5, "mesh_5");
		viewer_5->resetCamera();
		qvtkWidget_5->update();

		OutputTextEditFinished("Show Mesh_5 finished;");
	}
	else OutputTextEditError("QVTKWidget_5 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowMesh_6() {
	// Carl: show mesh_6 to QVTKWidget
	if (layoutStatus >= 6) {
		viewer_6->addPolygonMesh(mesh_6, "mesh_6");
		viewer_6->resetCamera();
		qvtkWidget_6->update();

		OutputTextEditFinished("Show Mesh_6 finished;");
	}
	else OutputTextEditError("QVTKWidget_6 hasn't been initialized;");
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

void MeshSubdivision_Debug::ClearMesh_5() {
	// Carl: clear mesh_5 to QVTKWidget
	if (layoutStatus >= 5) {
		viewer_5->removePolygonMesh("mesh_5");
		viewer_5->updateCamera();
		qvtkWidget_5->update();

		OutputTextEditFinished("Clear Mesh_5 finished;");
	}
	else OutputTextEditError("QVTKWidget_5 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearMesh_6() {
	// Carl: clear mesh_6 to QVTKWidget
	if (layoutStatus >= 6) {
		viewer_6->removePolygonMesh("mesh_6");
		viewer_6->updateCamera();
		qvtkWidget_6->update();

		OutputTextEditFinished("Clear Mesh_6 finished;");
	}
	else OutputTextEditError("QVTKWidget_6 hasn't been initialized;");
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
	if (layoutStatus >= 2) {
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
	if (layoutStatus >= 3) {
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
	if (layoutStatus >= 4) {
		viewer_4->addPointCloud(cloud_4, "cloud_4");
		viewer_4->resetCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Show Cloud_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_5() {
	// Carl: show cloud_5 to QVTKWidget
	if (layoutStatus >= 5) {
		viewer_5->addPointCloud(cloud_5, "cloud_5");
		viewer_5->resetCamera();
		qvtkWidget_5->update();

		OutputTextEditFinished("Show Cloud_5 finished;");
	}
	else OutputTextEditError("QVTKWidget_5 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowCloud_6() {
	// Carl: show cloud_6 to QVTKWidget
	if (layoutStatus >= 6) {
		viewer_6->addPointCloud(cloud_6, "cloud_6");
		viewer_6->resetCamera();
		qvtkWidget_6->update();

		OutputTextEditFinished("Show Cloud_6 finished;");
	}
	else OutputTextEditError("QVTKWidget_6 hasn't been initialized;");
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
	if (layoutStatus >= 2) {
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
	if (layoutStatus >= 3) {
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
	if (layoutStatus >= 4) {
		viewer_4->removePointCloud("cloud_4");
		viewer_4->updateCamera();
		qvtkWidget_4->update();

		OutputTextEditFinished("Clear Cloud_4 finished;");
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_5() {
	// Carl: clear cloud_5 to QVTKWidget
	if (layoutStatus >= 5) {
		viewer_5->removePointCloud("cloud_5");
		viewer_5->updateCamera();
		qvtkWidget_5->update();

		OutputTextEditFinished("Clear Cloud_5 finished;");
	}
	else OutputTextEditError("QVTKWidget_5 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ClearCloud_6() {
	// Carl: clear cloud_6 to QVTKWidget
	if (layoutStatus >= 6) {
		viewer_6->removePointCloud("cloud_6");
		viewer_6->updateCamera();
		qvtkWidget_6->update();

		OutputTextEditFinished("Clear Cloud_6 finished;");
	}
	else OutputTextEditError("QVTKWidget_6 hasn't been initialized;");
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_1() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_1->points.size(); i++) {
		if (keypointList_1.at(i)) {
			cloud_1->points[i].r = colorCloud_1.red();
			cloud_1->points[i].g = colorCloud_1.green();
			cloud_1->points[i].b = colorCloud_1.blue();
			cloud_1->points[i].a = colorCloud_1.alpha();
		}
	}
	viewer_1->updatePointCloud(cloud_1, "cloud_1");
	ShowCloud_1();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_1 "));
	content.append(QPair<QColor, QString>(colorCloud_1, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_2() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_2->points.size(); i++) {
		if (keypointList_2.at(i)) {
			cloud_2->points[i].r = colorCloud_2.red();
			cloud_2->points[i].g = colorCloud_2.green();
			cloud_2->points[i].b = colorCloud_2.blue();
			cloud_2->points[i].a = colorCloud_2.alpha();
		}
	}
	viewer_2->updatePointCloud(cloud_2, "cloud_2");
	ShowCloud_2();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_2 "));
	content.append(QPair<QColor, QString>(colorCloud_2, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_3() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_3->points.size(); i++) {
		if (keypointList_3.at(i)) {
			cloud_3->points[i].r = colorCloud_3.red();
			cloud_3->points[i].g = colorCloud_3.green();
			cloud_3->points[i].b = colorCloud_3.blue();
			cloud_3->points[i].a = colorCloud_3.alpha();
		}
	}
	viewer_3->updatePointCloud(cloud_3, "cloud_3");
	ShowCloud_3();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_3 "));
	content.append(QPair<QColor, QString>(colorCloud_3, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_4() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_4->points.size(); i++) {
		if (keypointList_4.at(i)) {
			cloud_4->points[i].r = colorCloud_4.red();
			cloud_4->points[i].g = colorCloud_4.green();
			cloud_4->points[i].b = colorCloud_4.blue();
			cloud_4->points[i].a = colorCloud_4.alpha();
		}
	}
	viewer_4->updatePointCloud(cloud_4, "cloud_4");
	ShowCloud_4();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_4 "));
	content.append(QPair<QColor, QString>(colorCloud_4, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_5() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_5->points.size(); i++) {
		if (keypointList_5.at(i)) {
			cloud_5->points[i].r = colorCloud_5.red();
			cloud_5->points[i].g = colorCloud_5.green();
			cloud_5->points[i].b = colorCloud_5.blue();
			cloud_5->points[i].a = colorCloud_5.alpha();
		}
	}
	viewer_5->updatePointCloud(cloud_5, "cloud_5");
	ShowCloud_5();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_5 "));
	content.append(QPair<QColor, QString>(colorCloud_5, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}

void MeshSubdivision_Debug::ShowKeypoint_6() {
	// Carl: show keypoint on cloud
	for (int i = 0; i < cloud_6->points.size(); i++) {
		if (keypointList_6.at(i)) {
			cloud_6->points[i].r = colorCloud_6.red();
			cloud_6->points[i].g = colorCloud_6.green();
			cloud_6->points[i].b = colorCloud_6.blue();
			cloud_6->points[i].a = colorCloud_6.alpha();
		}
	}
	viewer_6->updatePointCloud(cloud_6, "cloud_6");
	ShowCloud_6();

	QVector<QPair<QColor, QString>> content;
	content.append(QPair<QColor, QString>(QColor("gray"), "Show Cloud_6 "));
	content.append(QPair<QColor, QString>(colorCloud_6, "keypoint"));
	content.append(QPair<QColor, QString>(QColor("gray"), " finished;"));
	OutputTextEditColoredString(content);
	return;
}


void MeshSubdivision_Debug::ClearKeypoint_1() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_1->points.size(); i++) {
		cloud_1->points[i].r = 255;
		cloud_1->points[i].g = 255;
		cloud_1->points[i].b = 255;
		cloud_1->points[i].a = 255;
	}
	viewer_1->updatePointCloud(cloud_1, "cloud_1");
	qvtkWidget_1->update();
	OutputTextEditFinished("Clear Cloud_1 Keypoint finished;");
	return;
}

void MeshSubdivision_Debug::ClearKeypoint_2() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_2->points.size(); i++) {
		cloud_2->points[i].r = 255;
		cloud_2->points[i].g = 255;
		cloud_2->points[i].b = 255;
		cloud_2->points[i].a = 255;
	}
	viewer_2->updatePointCloud(cloud_2, "cloud_2");
	qvtkWidget_2->update();
	OutputTextEditFinished("Clear Cloud_2 Keypoint finished;");
	return;
}

void MeshSubdivision_Debug::ClearKeypoint_3() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_3->points.size(); i++) {
		cloud_3->points[i].r = 255;
		cloud_3->points[i].g = 255;
		cloud_3->points[i].b = 255;
		cloud_3->points[i].a = 255;
	}
	viewer_3->updatePointCloud(cloud_3, "cloud_3");
	qvtkWidget_3->update();
	OutputTextEditFinished("Clear Cloud_3 Keypoint finished;");
	return;
}

void MeshSubdivision_Debug::ClearKeypoint_4() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_4->points.size(); i++) {
		cloud_4->points[i].r = 255;
		cloud_4->points[i].g = 255;
		cloud_4->points[i].b = 255;
		cloud_4->points[i].a = 255;
	}
	viewer_4->updatePointCloud(cloud_4, "cloud_4");
	qvtkWidget_4->update();
	OutputTextEditFinished("Clear Cloud_4 Keypoint finished;");
	return;
}

void MeshSubdivision_Debug::ClearKeypoint_5() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_5->points.size(); i++) {
		cloud_5->points[i].r = 255;
		cloud_5->points[i].g = 255;
		cloud_5->points[i].b = 255;
		cloud_5->points[i].a = 255;
	}
	viewer_5->updatePointCloud(cloud_5, "cloud_5");
	qvtkWidget_5->update();
	OutputTextEditFinished("Clear Cloud_5 Keypoint finished;");
	return;
}

void MeshSubdivision_Debug::ClearKeypoint_6() {
	//Carl: clear keypoint on cloud
	for (int i = 0; i < cloud_6->points.size(); i++) {
		cloud_6->points[i].r = 255;
		cloud_6->points[i].g = 255;
		cloud_6->points[i].b = 255;
		cloud_6->points[i].a = 255;
	}
	viewer_6->updatePointCloud(cloud_6, "cloud_6");
	qvtkWidget_6->update();
	OutputTextEditFinished("Clear Cloud_6 Keypoint finished;");
	return;
}