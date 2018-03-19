#include "MeshSubdivision_Debug.h"
#include <qfiledialog.h>

void MeshSubdivision_Debug::LoadMesh_1() {

	QString tempPath = pathMesh_1;
	pathMesh_1 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 1"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));

	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tempCloud, empty;

}

void MeshSubdivision_Debug::LoadMesh_2() {

}

void MeshSubdivision_Debug::LoadMesh_3() {

}

void MeshSubdivision_Debug::LoadMesh_4() {

}