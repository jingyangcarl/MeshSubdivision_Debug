#include "MeshSubdivision_Debug.h"
#include <vtkRenderWindow.h>
#include <pcl\io\ply_io.h>


void MeshSubdivision_Debug::InitializeLayout_1() {
	// Carl: initialize the framework including 1 QVTKWidget

	ShowMesh_1();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	
	ui.gridLayout->setColumnStretch(0, 3);
	ui.gridLayout->setColumnStretch(1, 1);

	OutputTextEditFinished("Layout_1 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget() {
	// Carl: initialzie all QVTKWidget

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeQVTKWidget_3();
	InitializeQVTKWidget_4();
	InitializeQVTKWidget_5();
	InitializeQVTKWidget_6();

	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_1() {
	// Carl: initialize the QVTKWidget_1
	
	qvtkWidget_1 = new QVTKWidget();
	viewer_1.reset(new pcl::visualization::PCLVisualizer("Viewer_1", false));
	qvtkWidget_1->SetRenderWindow(viewer_1->getRenderWindow());
	viewer_1->setupInteractor(qvtkWidget_1->GetInteractor(), qvtkWidget_1->GetRenderWindow());
	qvtkWidget_1->update();

	OutputTextEditFinished("QVTKWidget_1 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_2() {
	// Carl: initialize the QVTKWidget_2

	qvtkWidget_2 = new QVTKWidget();
	viewer_2.reset(new pcl::visualization::PCLVisualizer("Viewer_2", false));
	qvtkWidget_2->SetRenderWindow(viewer_2->getRenderWindow());
	viewer_2->setupInteractor(qvtkWidget_2->GetInteractor(), qvtkWidget_2->GetRenderWindow());
	qvtkWidget_2->update();

	OutputTextEditFinished("QVTKWidget_2 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_3() {
	// Carl: initialize the QVTKWidget_3

	qvtkWidget_3 = new QVTKWidget();
	viewer_3.reset(new pcl::visualization::PCLVisualizer("Viewer_3", false));
	qvtkWidget_3->SetRenderWindow(viewer_3->getRenderWindow());
	viewer_3->setupInteractor(qvtkWidget_3->GetInteractor(), qvtkWidget_3->GetRenderWindow());
	qvtkWidget_3->update();

	OutputTextEditFinished("QVTKWidget_3 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_4() {
	// Carl: initialize the QVTKWidget_4

	qvtkWidget_4 = new QVTKWidget();
	viewer_4.reset(new pcl::visualization::PCLVisualizer("Viewer_4", false));
	qvtkWidget_4->SetRenderWindow(viewer_4->getRenderWindow());
	viewer_4->setupInteractor(qvtkWidget_4->GetInteractor(), qvtkWidget_4->GetRenderWindow());
	qvtkWidget_4->update();

	OutputTextEditFinished("QVTKWidget_4 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_5() {
	// Carl: initialize the QVTKWidget_5

	qvtkWidget_5 = new QVTKWidget();
	viewer_5.reset(new pcl::visualization::PCLVisualizer("Viewer_5", false));
	qvtkWidget_5->SetRenderWindow(viewer_5->getRenderWindow());
	viewer_5->setupInteractor(qvtkWidget_5->GetInteractor(), qvtkWidget_5->GetRenderWindow());
	qvtkWidget_5->update();

	OutputTextEditFinished("QVTKWidget_5 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeQVTKWidget_6() {
	// Carl: initialize the QVTKWidget_6

	qvtkWidget_6 = new QVTKWidget();
	viewer_6.reset(new pcl::visualization::PCLVisualizer("Viewer_6", false));
	qvtkWidget_6->SetRenderWindow(viewer_6->getRenderWindow());
	viewer_6->setupInteractor(qvtkWidget_6->GetInteractor(), qvtkWidget_6->GetRenderWindow());
	qvtkWidget_6->update();

	OutputTextEditFinished("QVTKWidget_6 initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeMesh() {
	// Carl: initialize meshes

	InitializeMesh_1();
	InitializeMesh_2();
	InitializeMesh_3();
	InitializeMesh_4();
	InitializeMesh_5();
	InitializeMesh_6();

	return;
}

void MeshSubdivision_Debug::InitializeMesh_1() {
	// Carl: initialize mesh 1

	pathMesh_1 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_1 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_1.toStdString(), mesh_1);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_1.setRed(((int)(512 * rand() / (RAND_MAX + 1.0f)) % 16) * ((int)(512 * rand() / (RAND_MAX + 1.0f))));
	colorCloud_1.setGreen(((int)(512 * rand() / (RAND_MAX + 1.0f)) % 16) * ((int)(512 * rand() / (RAND_MAX + 1.0f))));
	colorCloud_1.setBlue(((int)(512 * rand() / (RAND_MAX + 1.0f)) % 16) * ((int)(512 * rand() / (RAND_MAX + 1.0f))));
	colorCloud_1.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_1.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_1.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_1.cloud, *cloud_1);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_1->points.size(); i++) {
			cloud_1->points[i].r = 255;
			cloud_1->points[i].g = 255;
			cloud_1->points[i].b = 255;
			cloud_1->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_1 load finished;");
	}
	else OutputTextEditError("Mesh_1 load failed;");
}

void MeshSubdivision_Debug::InitializeMesh_2() {
	// Carl: initialize mesh 1

	pathMesh_2 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_2 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_2.toStdString(), mesh_2);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_2.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_2.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_2.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_2.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_2.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_2.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_2.cloud, *cloud_2);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_2->points.size(); i++) {
			cloud_2->points[i].r = 255;
			cloud_2->points[i].g = 255;
			cloud_2->points[i].b = 255;
			cloud_2->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_2 load finished;");
	}
	else OutputTextEditError("Mesh_2 load failed;");
}

void MeshSubdivision_Debug::InitializeMesh_3() {
	// Carl: initialize mesh 1

	pathMesh_3 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_3 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_3.toStdString(), mesh_3);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_3.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_3.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_3.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_3.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_3.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_3.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_3.cloud, *cloud_3);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_3->points.size(); i++) {
			cloud_3->points[i].r = 255;
			cloud_3->points[i].g = 255;
			cloud_3->points[i].b = 255;
			cloud_3->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_3 load finished;");
	}
	else OutputTextEditError("Mesh_3 load failed;");
}

void MeshSubdivision_Debug::InitializeMesh_4() {
	// Carl: initialize mesh 1

	pathMesh_4 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_4 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_4.toStdString(), mesh_4);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_4.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_4.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_4.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_4.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_4.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_4.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_4.cloud, *cloud_4);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_4->points.size(); i++) {
			cloud_4->points[i].r = 255;
			cloud_4->points[i].g = 255;
			cloud_4->points[i].b = 255;
			cloud_4->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_4 load finished;");
	}
	else OutputTextEditError("Mesh_4 load failed;");
}

void MeshSubdivision_Debug::InitializeMesh_5() {
	// Carl: initialize mesh 1

	pathMesh_5 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_5 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_5.toStdString(), mesh_5);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_5.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_5.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_5.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_5.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_5.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_5.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_5.cloud, *cloud_5);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_5->points.size(); i++) {
			cloud_5->points[i].r = 255;
			cloud_5->points[i].g = 255;
			cloud_5->points[i].b = 255;
			cloud_5->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_5 load finished;");
	}
	else OutputTextEditError("Mesh_5 load failed;");
}

void MeshSubdivision_Debug::InitializeMesh_6() {
	// Carl: initialize mesh 1

	pathMesh_6 = "../MeshFile/footbones.ply";

	// Carl: clear the mesh;
	pcl::PolygonMesh emptyMesh;
	mesh_6 = emptyMesh;

	// Carl: read mesh from mesh path
	pcl::io::loadPLYFile(pathMesh_6.toStdString(), mesh_6);

	// Carl: choose a color
	srand(time(NULL));
	colorCloud_6.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_6.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_6.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_6.setAlpha((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_6.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_6.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_6.cloud, *cloud_6);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_6->points.size(); i++) {
			cloud_6->points[i].r = 255;
			cloud_6->points[i].g = 255;
			cloud_6->points[i].b = 255;
			cloud_6->points[i].a = 255;
		}

		OutputTextEditFinished("Mesh_6 load finished;");
	}
	else OutputTextEditError("Mesh_6 load failed;");
}

void MeshSubdivision_Debug::InitializeTextEdit_CMD() {
	// Carl: initialize the textfield

	QPalette palette = ui.textEdit_cmd->palette();
	palette.setColor(QPalette::Base, Qt::black);
	palette.setColor(QPalette::Text, Qt::white);
	ui.textEdit_cmd->setPalette(palette);

	QTextCursor cursor = ui.textEdit_cmd->textCursor();
	cursor.movePosition(QTextCursor::Start);
	ui.textEdit_cmd->setTextCursor(cursor);

	ui.textEdit_cmd->setTextColor(QColor("gray"));
	ui.textEdit_cmd->textCursor().insertText(">> ");
	textEditRecordLenth += 3;

	OutputTextEditFinished("TextEdit_CMD initialization finished;");
	return;
}

void MeshSubdivision_Debug::InitializeEventFilter() {
	// Carl: initialize eventfilter for widgets;

	ui.textEdit_cmd->installEventFilter(this);
	qvtkWidget_1->installEventFilter(this);
	qvtkWidget_2->installEventFilter(this);
	qvtkWidget_3->installEventFilter(this);
	qvtkWidget_4->installEventFilter(this);
	qvtkWidget_5->installEventFilter(this);
	qvtkWidget_6->installEventFilter(this);

	return;
}

void MeshSubdivision_Debug::InitializeSlotSignal() {
	// Carl: initialize connections between slot and signals;

	// Carl: connection for OutputTextEdit
	connect(commandProcessor, SIGNAL(SignalOutputTextEditFinished(QString)), this, SLOT(OutputTextEditFinished(QString)));
	connect(commandProcessor, SIGNAL(SignalOutputTextEditError(QString)), this, SLOT(OutputTextEditError(QString)));
	connect(commandProcessor, SIGNAL(SignalOutputTextEditHelp(QString)), this, SLOT(OutputTextEditHelp(QString)));

	// Carl: connection for LoadMesh
	connect(commandProcessor, SIGNAL(SignalLoadMesh_1()), this, SLOT(LoadMesh_1()));
	connect(commandProcessor, SIGNAL(SignalLoadMesh_2()), this, SLOT(LoadMesh_2()));
	connect(commandProcessor, SIGNAL(SignalLoadMesh_3()), this, SLOT(LoadMesh_3()));
	connect(commandProcessor, SIGNAL(SignalLoadMesh_4()), this, SLOT(LoadMesh_4()));
	connect(commandProcessor, SIGNAL(SignalLoadMesh_5()), this, SLOT(LoadMesh_5()));
	connect(commandProcessor, SIGNAL(SignalLoadMesh_6()), this, SLOT(LoadMesh_6()));

	// Carl: connection for ShowMesh
	connect(commandProcessor, SIGNAL(SignalShowMesh_1()), this, SLOT(ShowMesh_1()));
	connect(commandProcessor, SIGNAL(SignalShowMesh_2()), this, SLOT(ShowMesh_2()));
	connect(commandProcessor, SIGNAL(SignalShowMesh_3()), this, SLOT(ShowMesh_3()));
	connect(commandProcessor, SIGNAL(SignalShowMesh_4()), this, SLOT(ShowMesh_4()));
	connect(commandProcessor, SIGNAL(SignalShowMesh_5()), this, SLOT(ShowMesh_5()));
	connect(commandProcessor, SIGNAL(SignalShowMesh_6()), this, SLOT(ShowMesh_6()));

	// Carl: connection for ClearMesh
	connect(commandProcessor, SIGNAL(SignalClearMesh_1()), this, SLOT(ClearMesh_1()));
	connect(commandProcessor, SIGNAL(SignalClearMesh_2()), this, SLOT(ClearMesh_2()));
	connect(commandProcessor, SIGNAL(SignalClearMesh_3()), this, SLOT(ClearMesh_3()));
	connect(commandProcessor, SIGNAL(SignalClearMesh_4()), this, SLOT(ClearMesh_4()));
	connect(commandProcessor, SIGNAL(SignalClearMesh_5()), this, SLOT(ClearMesh_5()));
	connect(commandProcessor, SIGNAL(SignalClearMesh_6()), this, SLOT(ClearMesh_6()));

	// Carl: connection for ShowCloud
	connect(commandProcessor, SIGNAL(SignalShowCloud_1()), this, SLOT(ShowCloud_1()));
	connect(commandProcessor, SIGNAL(SignalShowCloud_2()), this, SLOT(ShowCloud_2()));
	connect(commandProcessor, SIGNAL(SignalShowCloud_3()), this, SLOT(ShowCloud_3()));
	connect(commandProcessor, SIGNAL(SignalShowCloud_4()), this, SLOT(ShowCloud_4()));
	connect(commandProcessor, SIGNAL(SignalShowCloud_5()), this, SLOT(ShowCloud_5()));
	connect(commandProcessor, SIGNAL(SignalShowCloud_6()), this, SLOT(ShowCloud_6()));

	// Carl: connection for ClearCloud
	connect(commandProcessor, SIGNAL(SignalClearCloud_1()), this, SLOT(ClearCloud_1()));
	connect(commandProcessor, SIGNAL(SignalClearCloud_2()), this, SLOT(ClearCloud_2()));
	connect(commandProcessor, SIGNAL(SignalClearCloud_3()), this, SLOT(ClearCloud_3()));
	connect(commandProcessor, SIGNAL(SignalClearCloud_4()), this, SLOT(ClearCloud_4()));
	connect(commandProcessor, SIGNAL(SignalClearCloud_5()), this, SLOT(ClearCloud_5()));
	connect(commandProcessor, SIGNAL(SignalClearCloud_6()), this, SLOT(ClearCloud_6()));

	// Carl: connection for ShowKeypoint
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_1()), this, SLOT(ShowKeypoint_1()));
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_2()), this, SLOT(ShowKeypoint_2()));
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_3()), this, SLOT(ShowKeypoint_3()));
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_4()), this, SLOT(ShowKeypoint_4()));
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_5()), this, SLOT(ShowKeypoint_5()));
	connect(commandProcessor, SIGNAL(SignalShowKeypoint_6()), this, SLOT(ShowKeypoint_6()));

	// Carl: connection for ClearKeypoint
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_1()), this, SLOT(ClearKeypoint_1()));
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_2()), this, SLOT(ClearKeypoint_2()));
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_3()), this, SLOT(ClearKeypoint_3()));
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_4()), this, SLOT(ClearKeypoint_4()));
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_5()), this, SLOT(ClearKeypoint_5()));
	connect(commandProcessor, SIGNAL(SignalClearKeypoint_6()), this, SLOT(ClearKeypoint_6()));

	// Carl: connection for ChangeToLayout
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_1()), this, SLOT(ChangeToLayout_1()));
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_2()), this, SLOT(ChangeToLayout_2()));
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_4()), this, SLOT(ChangeToLayout_4()));
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_6()), this, SLOT(ChangeToLayout_6()));

	// Carl: connection for data
	// Carl: the parameter Qt::DirectConnection is to make sure the communication between two threads is synchronized
	connect(commandProcessor, SIGNAL(SignalGetMeshPath(int)), this, SLOT(SendMeshPath(int)), Qt::DirectConnection);
	connect(this, SIGNAL(SignalSendMeshPath(QString)), commandProcessor, SLOT(GetMeshPath(QString)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_1(QVector<bool>)), this, SLOT(GetKeypointList_1(QVector<bool>)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_2(QVector<bool>)), this, SLOT(GetKeypointList_2(QVector<bool>)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_3(QVector<bool>)), this, SLOT(GetKeypointList_3(QVector<bool>)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_4(QVector<bool>)), this, SLOT(GetKeypointList_4(QVector<bool>)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_5(QVector<bool>)), this, SLOT(GetKeypointList_5(QVector<bool>)), Qt::DirectConnection);
	connect(commandProcessor, SIGNAL(SignalSendKeypointList_6(QVector<bool>)), this, SLOT(GetKeypointList_6(QVector<bool>)), Qt::DirectConnection);
}