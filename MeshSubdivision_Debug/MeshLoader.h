#pragma once
#include "qthread.h"
#include <qcolor.h>
#include <pcl\io\ply_io.h>
#include <pcl\io\obj_io.h>

class MeshLoader : 	public QThread
{
	Q_OBJECT

public:
	MeshLoader(QString, pcl::PolygonMesh &, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &);
	~MeshLoader();

private:
	// Carl: pointer to data structure
	QString meshPath;
	pcl::PolygonMesh &mesh;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &meshCloud;


protected:
	void run();

signals:
	void SignalOutputTextEditFinished(QString);
	void SignalOutputTextEditError(QString);

	void SignalShowMesh_1();
	void SignalClearMesh_1();
};

