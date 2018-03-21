#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ChangeToLayout_1() {
	// Carl: change to layout with one QVTKWidget and one TextEdit

	// Carl: clear background
	if (layoutStatus == 1) {
		ClearMesh_1();
	}
	else if (layoutStatus == 2) {
		ClearMesh_1();
		ClearMesh_2();
	}
	else if (layoutStatus == 4) {
		ClearMesh_1();
		ClearMesh_2();
		ClearMesh_3();
		ClearMesh_4();
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);

	InitializeQVTKWidget_1();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);

	// Carl: update
	ShowMesh_1();

	
	layoutStatus = 1;
	OutputTextEditFinished("Layout_1 initialization finished;");
	return;
}

void MeshSubdivision_Debug::ChangeToLayout_2() {
	// Carl: change to layout with two QVTKWidget and one TextEdit

	// Carl: clear background
	if (layoutStatus == 1) {
		ClearMesh_1();
	}
	else if (layoutStatus == 2) {
		ClearMesh_1();
		ClearMesh_2();
	}
	else if (layoutStatus == 4) {
		ClearMesh_1();
		ClearMesh_2();
		ClearMesh_3();
		ClearMesh_4();
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);

	// Carl: update
	ShowMesh_1();
	ShowMesh_2();

	layoutStatus = 2;
	OutputTextEditFinished("Layout_2 initialization finished;");
	return;
}

void MeshSubdivision_Debug::ChangeToLayout_4() {
	// Carl: change to layout with four QVTKWidget and one TextEdit

	// Carl: clear background
	if (layoutStatus == 1) {
		ClearMesh_1();
	}
	else if (layoutStatus == 2) {
		ClearMesh_1();
		ClearMesh_2();
	}
	else if (layoutStatus == 4) {
		ClearMesh_1();
		ClearMesh_2();
		ClearMesh_3();
		ClearMesh_4();
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeQVTKWidget_3();
	InitializeQVTKWidget_4();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	ui.gridLayout_widget->addWidget(qvtkWidget_3, 1, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_4, 1, 1);

	// Carl: update
	ShowMesh_1();
	ShowMesh_2();
	ShowMesh_3();
	ShowMesh_4();

	layoutStatus = 4;
	OutputTextEditFinished("Layout_4 initialization finished;");
	return;
}