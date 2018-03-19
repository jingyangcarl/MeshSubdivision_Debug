#include "MeshLoader.h"
#include <qfileinfo.h>

MeshLoader::~MeshLoader() {

}

MeshLoader::MeshLoader(QString meshPath, pcl::PolygonMesh & mesh, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &meshCloud, QColor cloudColor)
	: meshPath(meshPath), mesh(mesh), meshCloud(meshCloud), cloudColor(cloudColor) {

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
		for (int i = 0; i < meshCloud->points.size(); i++) {
			meshCloud->points[i].r = cloudColor.red();
			meshCloud->points[i].g = cloudColor.green();
			meshCloud->points[i].b = cloudColor.blue();
		}

		emit SignalOutputTextEditFinished("Mesh load finished;");
	}
	else emit SignalOutputTextEditError("Mesh load failed");


}
