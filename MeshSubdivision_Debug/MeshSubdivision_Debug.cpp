#include "MeshSubdivision_Debug.h"

MeshSubdivision_Debug::MeshSubdivision_Debug(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Carl: do something

	// Carl: initialize the framework
	InitializeLayout_1();

	// Carl: install eventfilter
	ui.textEdit_cmd->installEventFilter(this);

	ChangeToLayout_2();
	ChangeToLayout_4();
	//ChangeToLayout_1();

}