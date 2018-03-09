#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MeshSubdivision_Debug.h"

class MeshSubdivision_Debug : public QMainWindow
{
	Q_OBJECT

public:
	MeshSubdivision_Debug(QWidget *parent = Q_NULLPTR);

	// Carl: define slot functions
public slots:
	

private:
	Ui::MeshSubdivision_DebugClass ui;
};
