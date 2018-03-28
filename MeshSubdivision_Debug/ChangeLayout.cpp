#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ChangeToLayout_1() {
	// Carl: change to layout with one QVTKWidget and one TextEdit

	// Carl: clear background
	switch (layoutStatus) {
	case 6:
		ClearMesh_5();
		ClearMesh_6();
		ClearCloud_5();
		ClearCloud_6();
	case 4:
		ClearMesh_3();
		ClearMesh_4();
		ClearCloud_3();
		ClearCloud_4();
	case 2:
		ClearMesh_2();
		ClearCloud_2();
	case 1:
		ClearMesh_1();
		ClearCloud_1();
	default:
		break;
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);
	ui.gridLayout_widget->removeWidget(qvtkWidget_5);
	ui.gridLayout_widget->removeWidget(qvtkWidget_6);
	qvtkWidget_1->hide();
	qvtkWidget_2->hide();
	qvtkWidget_3->hide();
	qvtkWidget_4->hide();
	qvtkWidget_5->hide();
	qvtkWidget_6->hide();

	InitializeQVTKWidget_1();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->update();

	// Carl: update
	layoutStatus = 1;
	ShowMesh_1();
	
	OutputTextEditFinished("Layout_1 initialization finished;");
	return;
}

void MeshSubdivision_Debug::ChangeToLayout_2() {
	// Carl: change to layout with two QVTKWidget and one TextEdit

	// Carl: clear background
	switch (layoutStatus) {
	case 6:
		ClearMesh_5();
		ClearMesh_6();
		ClearCloud_5();
		ClearCloud_6();
	case 4:
		ClearMesh_3();
		ClearMesh_4();
		ClearCloud_3();
		ClearCloud_4();
	case 2:
		ClearMesh_2();
		ClearCloud_2();
	case 1:
		ClearMesh_1();
		ClearCloud_1();
	default:
		break;
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);
	ui.gridLayout_widget->removeWidget(qvtkWidget_5);
	ui.gridLayout_widget->removeWidget(qvtkWidget_6);
	qvtkWidget_1->hide();
	qvtkWidget_2->hide();
	qvtkWidget_3->hide();
	qvtkWidget_4->hide();
	qvtkWidget_5->hide();
	qvtkWidget_6->hide();

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	ui.gridLayout_widget->update();

	// Carl: update
	layoutStatus = 2;
	ShowMesh_1();
	ShowMesh_2();

	OutputTextEditFinished("Layout_2 initialization finished;");
	return;
}

void MeshSubdivision_Debug::ChangeToLayout_4() {
	// Carl: change to layout with four QVTKWidget and one TextEdit

	// Carl: clear background
	switch (layoutStatus) {
	case 6:
		ClearMesh_5();
		ClearMesh_6();
		ClearCloud_5();
		ClearCloud_6();
	case 4:
		ClearMesh_3();
		ClearMesh_4();
		ClearCloud_3();
		ClearCloud_4();
	case 2:
		ClearMesh_2();
		ClearCloud_2();
	case 1:
		ClearMesh_1();
		ClearCloud_1();
	default:
		break;
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);
	ui.gridLayout_widget->removeWidget(qvtkWidget_5);
	ui.gridLayout_widget->removeWidget(qvtkWidget_6);
	qvtkWidget_1->hide();
	qvtkWidget_2->hide();
	qvtkWidget_3->hide();
	qvtkWidget_4->hide();
	qvtkWidget_5->hide();
	qvtkWidget_6->hide();

	for (int i = 0; i < ui.gridLayout_widget->count(); i++) {
		delete ui.gridLayout_widget->itemAt(i);
	}

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeQVTKWidget_3();
	InitializeQVTKWidget_4();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	ui.gridLayout_widget->addWidget(qvtkWidget_3, 1, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_4, 1, 1);
	ui.gridLayout_widget->update();

	// Carl: update
	layoutStatus = 4;
	ShowMesh_1();
	ShowMesh_2();
	ShowMesh_3();
	ShowMesh_4();

	OutputTextEditFinished("Layout_4 initialization finished;");
	return;
}

void MeshSubdivision_Debug::ChangeToLayout_6() {
	// Carl: change to layout with four QVTKWidget and one TextEdit

	// Carl: clear background
	switch (layoutStatus) {
	case 6:
		ClearMesh_5();
		ClearMesh_6();
		ClearCloud_5();
		ClearCloud_6();
	case 4:
		ClearMesh_3();
		ClearMesh_4();
		ClearCloud_3();
		ClearCloud_4();
	case 2:
		ClearMesh_2();
		ClearCloud_2();
	case 1:
		ClearMesh_1();
		ClearCloud_1();
	default:
		break;
	}

	// Carl: rebuild layout
	ui.gridLayout_widget->removeWidget(qvtkWidget_1);
	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);
	ui.gridLayout_widget->removeWidget(qvtkWidget_5);
	ui.gridLayout_widget->removeWidget(qvtkWidget_6);
	qvtkWidget_1->hide();
	qvtkWidget_2->hide();
	qvtkWidget_3->hide();
	qvtkWidget_4->hide();
	qvtkWidget_5->hide();
	qvtkWidget_6->hide();

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeQVTKWidget_3();
	InitializeQVTKWidget_4();
	InitializeQVTKWidget_5();
	InitializeQVTKWidget_6();
	InitializeEventFilter();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	ui.gridLayout_widget->addWidget(qvtkWidget_3, 0, 2);
	ui.gridLayout_widget->addWidget(qvtkWidget_4, 1, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_5, 1, 1);
	ui.gridLayout_widget->addWidget(qvtkWidget_6, 1, 2);
	ui.gridLayout_widget->update();

	// Carl: update
	layoutStatus = 6;
	ShowMesh_1();
	ShowMesh_2();
	ShowMesh_3();
	ShowMesh_4();
	ShowMesh_5();
	ShowMesh_6();

	OutputTextEditFinished("Layout_6 initialization finished;");
	return;
}