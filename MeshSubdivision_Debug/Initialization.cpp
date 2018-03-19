#include "MeshSubdivision_Debug.h"
#include <vtkRenderWindow.h>
#include <pcl\io\ply_io.h>


void MeshSubdivision_Debug::InitializeLayout_1() {
	// Carl: initialize the framework including 1 QVTKWidget

	InitializeTextEdit_CMD();
	InitializeQVTKWidget_1();
	InitializeMesh_1();
	ShowMesh_1();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	
	ui.gridLayout->setColumnStretch(0, 4);
	ui.gridLayout->setColumnStretch(1, 1);

	OutputTextEditFinished("Layout_1 initialization finished;");
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
	colorCloud_1.setRed((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_1.setGreen((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);
	colorCloud_1.setBlue((int)(512 * rand() / (RAND_MAX + 1.0f)) % 128 + 128);

	if (!mesh_1.cloud.data.empty()) {
		// Carl: read mesh succeed

		// Carl: initialize cloud
		cloud_1.reset(new pcl::PointCloud <pcl::PointXYZRGBA>);
		pcl::fromPCLPointCloud2(mesh_1.cloud, *cloud_1);

		// Carl: colored the cloud
		for (int i = 0; i < cloud_1->points.size(); i++) {
			cloud_1->points[i].r = colorCloud_1.red();
			cloud_1->points[i].g = colorCloud_1.green();
			cloud_1->points[i].b = colorCloud_1.blue();
		}

		OutputTextEditFinished("Mesh_1 load finished;");
	}
	else OutputTextEditError("Mesh_1 load failed;");
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

void MeshSubdivision_Debug::InitializeSlotSignal() {
	// Carl: initialize connections between slot and signals;

	// Carl: connection for OutputTextEdit
	connect(commandProcessor, SIGNAL(SignalOutputTextEditFinished(QString)), this, SLOT(OutputTextEditFinished(QString)));
	connect(commandProcessor, SIGNAL(SignalOutputTextEditError(QString)), this, SLOT(OutputTextEditError(QString)));

	// Carl: connection for LoadMesh
	connect(commandProcessor, SIGNAL(SignalLoadMesh_1()), this, SLOT(LoadMesh_1()));

	// Carl: connection for ChangeToLayout
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_1()), this, SLOT(ChangeToLayout_1()));
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_2()), this, SLOT(ChangeToLayout_2()));
	connect(commandProcessor, SIGNAL(SignalChangeToLayout_4()), this, SLOT(ChangeToLayout_4()));
}