#pragma once

#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include "ui_MeshSubdivision_Debug.h"

#include <pcl\point_cloud.h>
#include <pcl\visualization\pcl_visualizer.h>

#include "CommandAnalyser.h"
#include "CommandProcessor.h"

class MeshSubdivision_Debug : public QMainWindow
{
	Q_OBJECT

public:
	MeshSubdivision_Debug(QWidget *parent = Q_NULLPTR);

	// Carl: define slot functions
private slots:
	

private:
	Ui::MeshSubdivision_DebugClass ui;

	// Carl: QVTKWidget
	QVTKWidget *qvtkWidget_1;
	QVTKWidget *qvtkWidget_2;
	QVTKWidget *qvtkWidget_3;
	QVTKWidget *qvtkWidget_4;

	// Carl: pcl viewers
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_1;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_2;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_3;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_4;

	// Carl: define mesh cloud
	pcl::PolygonMesh mesh_1;
	pcl::PolygonMesh mesh_2;
	pcl::PolygonMesh mesh_3;
	pcl::PolygonMesh mesh_4;

	// Carl: cloud data;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_1;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_2;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_3;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_4;

	// Carl: eventfilter
	bool eventFilter(QObject *, QEvent *);

	// Carl: textEditlength
	int textEditRecordLenth = 0;

	// Carl: command analyser and processor
	CommandAnalyser *commandAnalyser = new CommandAnalyser();
	CommandProcessor *commandProcessor = new CommandProcessor();

private slots:
	/******************** Initialization.cpp ********************/
	void InitializeLayout_1();
	void InitializeQVTKWidget_1();
	void InitializeQVTKWidget_2();
	void InitializeQVTKWidget_3();
	void InitializeQVTKWidget_4();
	void InitializeTextEdit_CMD();
	void InitializeSlotSignal();

	/******************** ChangeLayout.cpp ********************/
	int layoutStatus = 1;
	void ChangeToLayout_1();
	void ChangeToLayout_2();
	void ChangeToLayout_4();

	/******************** OutputTextEdit.cpp ********************/
	void OutputTextEditFinished(QString);		// Carl: grey
	void OutputTextEditProcessing(QString);		// Carl: blue
	void OutputTextEditNotice(QString);			// Carl: green
	void OutputTextEditWarning(QString);		// Carl: orange
	void OutputTextEditError(QString);			// Carl: red
	void OutputTextEditColoredString(QColor, QString);

	/******************** LoadMesh.cpp ********************/
	void LoadMesh_1();
	void LoadMesh_2();
	void LoadMesh_3();
	void LoadMesh_4();

};
