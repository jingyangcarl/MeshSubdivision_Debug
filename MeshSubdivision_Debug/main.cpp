#include "MeshSubdivision_Debug.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MeshSubdivision_Debug w;
	w.show();
	return a.exec();
}
