#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::CameraSynToQVTKWidget_1() {

	// Carl: get current camera
	pcl::visualization::Camera camera;
	viewer_1->getCameraParameters(camera);

	// Carl: set camera for other QVTKWidgets
	switch (layoutStatus) {
	case 4:
		viewer_4->setCameraParameters(camera);
		viewer_4->updateCamera();
		viewer_3->setCameraParameters(camera);
		viewer_3->updateCamera();
	case 2:
		viewer_2->setCameraParameters(camera);
		viewer_2->updateCamera();
	case 1:
		viewer_1->setCameraParameters(camera);
		viewer_1->updateCamera();
	default:
		break;
	}

	return;
}