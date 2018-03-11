#include "MeshSubdivision_Debug.h"
#include <QtWidgets/QApplication>

// Carl: cancel the VTK warning report
#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MeshSubdivision_Debug w;
	w.show();
	return a.exec();
}
