#include "MeshLoader.h"
#include <qfileinfo.h>

MeshLoader::~MeshLoader() {

}

MeshLoader::MeshLoader(QString meshPath, pcl::PolygonMesh & mesh, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &meshCloud)
	: meshPath(meshPath), mesh(mesh), meshCloud(meshCloud) {

}

void MeshLoader::run() {
	QFileInfo fileInfo(meshPath);

	// Carl: read mesh from mesh path
	if (fileInfo.suffix() == "ply") pcl::io::loadPLYFile(meshPath.toStdString(), mesh);
	else if (fileInfo.suffix() == "obj") pcl::io::loadOBJFile(meshPath.toStdString(), mesh);
	else emit SignalOutputTextEditError("." + fileInfo.suffix() + " is not able to be loaded;");

	if (!mesh.cloud.data.empty()) {
		meshCloud.reset(new pcl::PointCloud<pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh.cloud, *meshCloud);
		// Carl: colored the cloud
		for (int i = 0; i < meshCloud->points.size(); i++) {
			meshCloud->points[i].r = 255;
			meshCloud->points[i].g = 255;
			meshCloud->points[i].b = 255;
			meshCloud->points[i].a = 255;
		}
		emit SignalOutputTextEditFinished("Mesh load finished;");
	}
	else emit SignalOutputTextEditError("Mesh load failed");


}
