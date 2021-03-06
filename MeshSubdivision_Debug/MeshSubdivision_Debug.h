#pragma once

#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>
#include "ui_MeshSubdivision_Debug.h"
#include <qlist.h>

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
	QVTKWidget *qvtkWidget_5;
	QVTKWidget *qvtkWidget_6;

	// Carl: pcl viewers
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_1;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_2;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_3;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_4;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_5;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_6;

	// Carl: mesh path
	QString pathMesh_1;
	QString pathMesh_2;
	QString pathMesh_3;
	QString pathMesh_4;
	QString pathMesh_5;
	QString pathMesh_6;

	// Carl: define mesh cloud
	pcl::PolygonMesh mesh_1;
	pcl::PolygonMesh mesh_2;
	pcl::PolygonMesh mesh_3;
	pcl::PolygonMesh mesh_4;
	pcl::PolygonMesh mesh_5;
	pcl::PolygonMesh mesh_6;

	// Carl: keypoint list
	QVector<bool> keypointList_1;
	QVector<bool> keypointList_2;
	QVector<bool> keypointList_3;
	QVector<bool> keypointList_4;
	QVector<bool> keypointList_5;
	QVector<bool> keypointList_6;

	// Carl: cloud data;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_1;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_2;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_3;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_4;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_5;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_6;

	// Carl: cloud color
	QColor colorCloud_1;
	QColor colorCloud_2;
	QColor colorCloud_3;
	QColor colorCloud_4;
	QColor colorCloud_5;
	QColor colorCloud_6;

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
	QList<QString> commandList;
	int currentCommandIndex = 0;

private slots:
	/******************** Initialization.cpp ********************/
	void InitializeLayout_1();
	void InitializeQVTKWidget();
	void InitializeQVTKWidget_1();
	void InitializeQVTKWidget_2();
	void InitializeQVTKWidget_3();
	void InitializeQVTKWidget_4();
	void InitializeQVTKWidget_5();
	void InitializeQVTKWidget_6();
	void InitializeMesh();
	void InitializeMesh_1();
	void InitializeMesh_2();
	void InitializeMesh_3();
	void InitializeMesh_4();
	void InitializeMesh_5();
	void InitializeMesh_6();
	void InitializeTextEdit_CMD();
	void InitializeEventFilter();
	void InitializeSlotSignal();

	/******************** ChangeLayout.cpp ********************/
	void ChangeToLayout_1();
	void ChangeToLayout_2();
	void ChangeToLayout_4();
	void ChangeToLayout_6();

	/******************** OutputTextEdit.cpp ********************/
	void OutputTextEditError(QString);			// Carl: red
	void OutputTextEditFinished(QString);		// Carl: grey
	void OutputTextEditHelp(QString);			// Carl: orange
	void OutputTextEditNotice(QString);			// Carl: blue
	void OutputTextEditProcessing(QString);		// Carl: green
	void OutputTextEditColoredString(QVector<QPair<QColor, QString>>);

	/******************** LoadMesh.cpp ********************/
	void LoadMesh_1(QString);
	void LoadMesh_2(QString);
	void LoadMesh_3(QString);
	void LoadMesh_4(QString);
	void LoadMesh_5(QString);
	void LoadMesh_6(QString);

	/******************** ShowOrClear.cpp ********************/
	void ShowMesh_1();
	void ShowMesh_2();
	void ShowMesh_3();
	void ShowMesh_4();
	void ShowMesh_5();
	void ShowMesh_6();
	void ShowMeshStatus_1();
	void ShowMeshStatus_2();
	void ShowMeshStatus_3();
	void ShowMeshStatus_4();
	void ShowMeshStatus_5();
	void ShowMeshStatus_6();
	void ClearMesh_1();
	void ClearMesh_2();
	void ClearMesh_3();
	void ClearMesh_4();
	void ClearMesh_5();
	void ClearMesh_6();
	void ShowCloud_1();
	void ShowCloud_2();
	void ShowCloud_3();
	void ShowCloud_4();
	void ShowCloud_5();
	void ShowCloud_6();
	void ShowCloudStatus_1();
	void ShowCloudStatus_2();
	void ShowCloudStatus_3();
	void ShowCloudStatus_4();
	void ShowCloudStatus_5();
	void ShowCloudStatus_6();
	void ClearCloud_1();
	void ClearCloud_2();
	void ClearCloud_3();
	void ClearCloud_4();
	void ClearCloud_5();
	void ClearCloud_6();
	void ShowKeypoint_1();
	void ShowKeypoint_2();
	void ShowKeypoint_3();
	void ShowKeypoint_4();
	void ShowKeypoint_5();
	void ShowKeypoint_6();
	void ClearKeypoint_1();
	void ClearKeypoint_2();
	void ClearKeypoint_3();
	void ClearKeypoint_4();
	void ClearKeypoint_5();
	void ClearKeypoint_6();

	/******************** CameraSynchronization.cpp ********************/
	void CameraSynToQVTKWidget_1();
	void CameraSynToQVTKWidget_2();
	void CameraSynToQVTKWidget_3();
	void CameraSynToQVTKWidget_4();
	void CameraSynToQVTKWidget_5();
	void CameraSynToQVTKWidget_6();

	/******************** ThreadDataCommunication.cpp ********************/
	void SendMeshPath(int);
	void SendLayoutStatus();
	void GetKeypointList_1(QVector<bool>);
	void GetKeypointList_2(QVector<bool>);
	void GetKeypointList_3(QVector<bool>);
	void GetKeypointList_4(QVector<bool>);
	void GetKeypointList_5(QVector<bool>);
	void GetKeypointList_6(QVector<bool>);
	void AddCommand(QString);

signals:
	void SignalSendMeshPath(QString);
	void SignalSendLayoutStatus(int);

};
