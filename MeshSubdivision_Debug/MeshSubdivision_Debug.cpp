#include "MeshSubdivision_Debug.h"

MeshSubdivision_Debug::MeshSubdivision_Debug(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Carl: do something

	// Carl: initialize the framework
	InitializeTextEdit_CMD();
	InitializeQVTKWidget();
	InitializeMesh();
	InitializeLayout_1();

	// Carl: initialize connections between slot and signals;
	InitializeSlotSignal();

	// Carl: install eventfilter
	InitializeEventFilter();


	//ChangeToLayout_2();

	OutputTextEditNotice("Please enter \"show help instruction\"");


}