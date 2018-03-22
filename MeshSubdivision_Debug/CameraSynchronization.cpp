#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::CameraSynToQVTKWidget_1() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_1->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}

void MeshSubdivision_Debug::CameraSynToQVTKWidget_2() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_2->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}

void MeshSubdivision_Debug::CameraSynToQVTKWidget_3() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_3->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}

void MeshSubdivision_Debug::CameraSynToQVTKWidget_4() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_4->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}

void MeshSubdivision_Debug::CameraSynToQVTKWidget_5() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_5->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}

void MeshSubdivision_Debug::CameraSynToQVTKWidget_6() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_6->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 6:
		viewer_6->setCameraParameters(camera);
		qvtkWidget_6->update();
		viewer_5->setCameraParameters(camera);
		qvtkWidget_5->update();
	case 4:
		viewer_4->setCameraParameters(camera);
		qvtkWidget_4->update();
		viewer_3->setCameraParameters(camera);
		qvtkWidget_3->update();
	case 2:
		viewer_2->setCameraParameters(camera);
		qvtkWidget_2->update();
	case 1:
		viewer_1->setCameraParameters(camera);
		qvtkWidget_1->update();
	default:
		break;
	}
	return;
}