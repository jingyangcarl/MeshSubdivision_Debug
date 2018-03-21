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

	// Carl: mesh path
	QString pathMesh_1;
	QString pathMesh_2;
	QString pathMesh_3;
	QString pathMesh_4;

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

	// Carl: cloud color
	QColor colorCloud_1;
	QColor colorCloud_2;
	QColor colorCloud_3;
	QColor colorCloud_4;

	// Carl: eventfilter
	bool eventFilter(QObject *, QEvent *);

	// Carl: textEditlength
	int textEditRecordLenth = 0;

	// Carl: layout status
	int layoutStatus = 1;
	QSize layoutSize;

	// Carl: command analyser and processor
	CommandAnalyser *commandAnalyser = new CommandAnalyser();
	CommandProcessor *commandProcessor = new CommandProcessor();

private slots:
	/******************** Initialization.cpp ********************/
	void InitializeLayout_1();
	void InitializeQVTKWidget();
	void InitializeQVTKWidget_1();
	void InitializeQVTKWidget_2();
	void InitializeQVTKWidget_3();
	void InitializeQVTKWidget_4();
	void InitializeMesh();
	void InitializeMesh_1();
	void InitializeMesh_2();
	void InitializeMesh_3();
	void InitializeMesh_4();
	void InitializeTextEdit_CMD();
	void InitializeEventFilter();
	void InitializeSlotSignal();

	/******************** ChangeLayout.cpp ********************/
	void ChangeToLayout_1();
	void ChangeToLayout_2();
	void ChangeToLayout_4();

	/******************** OutputTextEdit.cpp ********************/
	void OutputTextEditFinished(QString);		// Carl: grey
	void OutputTextEditProcessing(QString);		// Carl: blue
	void OutputTextEditNotice(QString);			// Carl: green
	void OutputTextEditHelp(QString);			// Carl: orange
	void OutputTextEditError(QString);			// Carl: red
	void OutputTextEditColoredString(QVector<QPair<QColor, QString>>);

	/******************** LoadMesh.cpp ********************/
	void LoadMesh_1();
	void LoadMesh_2();
	void LoadMesh_3();
	void LoadMesh_4();

	/******************** ShowOrClear.cpp ********************/
	void ShowMesh_1();
	void ShowMesh_2();
	void ShowMesh_3();
	void ShowMesh_4();
	void ClearMesh_1();
	void ClearMesh_2();
	void ClearMesh_3();
	void ClearMesh_4();
	void ShowCloud_1();
	void ShowCloud_2();
	void ShowCloud_3();
	void ShowCloud_4();
	void ClearCloud_1();
	void ClearCloud_2();
	void ClearCloud_3();
	void ClearCloud_4();

	/******************** CameraSynchronization.cpp ********************/
	void CameraSynToQVTKWidget_1();
	void CameraSynToQVTKWidget_2();
	void CameraSynToQVTKWidget_3();
	void CameraSynToQVTKWidget_4();

};
