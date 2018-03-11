#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::ChangeToLayout_1() {
	// Carl: change to layout with one QVTKWidget and one TextEdit

	ui.gridLayout_widget->removeWidget(qvtkWidget_2);
	ui.gridLayout_widget->removeWidget(qvtkWidget_3);
	ui.gridLayout_widget->removeWidget(qvtkWidget_4);

	InitializeQVTKWidget_1();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);

}

void MeshSubdivision_Debug::ChangeToLayout_2() {
	// Carl: change to layout with two QVTKWidget and one TextEdit
	if (ui.gridLayout_widget->rowCount() == 1 && ui.gridLayout_widget->columnCount() == 1) {
		
		InitializeQVTKWidget_1();
		InitializeQVTKWidget_2();

		ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
		ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);

	}
	else if (ui.gridLayout_widget->rowCount() == 1 && ui.gridLayout_widget->columnCount() == 2) {
		
		InitializeQVTKWidget_1();
		InitializeQVTKWidget_2();

		ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
		ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	}
	else if (ui.gridLayout_widget->rowCount() == 2 && ui.gridLayout_widget->columnCount() == 2) {

		ui.gridLayout_widget->removeWidget(qvtkWidget_3);
		ui.gridLayout_widget->removeWidget(qvtkWidget_4);

		InitializeQVTKWidget_1();
		InitializeQVTKWidget_2();

	}
}

void MeshSubdivision_Debug::ChangeToLayout_4() {
	// Carl: change to layout with four QVTKWidget and one TextEdit

	InitializeQVTKWidget_1();
	InitializeQVTKWidget_2();
	InitializeQVTKWidget_3();
	InitializeQVTKWidget_4();

	ui.gridLayout_widget->addWidget(qvtkWidget_1, 0, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_2, 0, 1);
	ui.gridLayout_widget->addWidget(qvtkWidget_3, 1, 0);
	ui.gridLayout_widget->addWidget(qvtkWidget_4, 1, 1);

	
}