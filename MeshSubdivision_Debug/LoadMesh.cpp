#include "MeshSubdivision_Debug.h"
#include <qfiledialog.h>
#include <qscrollbar.h>
#include "MeshLoader.h"

void MeshSubdivision_Debug::LoadMesh_1(QString pathMesh = "") {

	if (layoutStatus >= 1) {

		// Carl: clear mesh
		ClearMesh_1();

		// Carl: open the file
		QString tempPath = pathMesh_1;
		if (pathMesh == "") pathMesh_1 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 1"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_1 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_1;
		mesh_1 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_1, mesh_1, cloud_1);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_1.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_1.cloud.height*mesh_1.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_1.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_1 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_1 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_1 Load failed: [" + pathMesh_1 + "]");
			mesh_1 = tempMesh;
			pathMesh_1 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_1();
	}
	else OutputTextEditError("QVTKWidget_1 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::LoadMesh_2(QString pathMesh = "") {

	if (layoutStatus >= 2) {

		// Carl: clear mesh
		ClearMesh_2();

		// Carl: open the file
		QString tempPath = pathMesh_2;
		if (pathMesh == "") pathMesh_2 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 2"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_2 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_2;
		mesh_2 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_2, mesh_2, cloud_2);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_2.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_2.cloud.height*mesh_2.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_2.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_2 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_2 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_2 Load failed: [" + pathMesh_2 + "]");
			mesh_2 = tempMesh;
			pathMesh_2 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_2();
	}
	else OutputTextEditError("QVTKWidget_2 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::LoadMesh_3(QString pathMesh = "") {
	if (layoutStatus >= 3) {

		// Carl: clear mesh
		ClearMesh_3();

		// Carl: open the file
		QString tempPath = pathMesh_3;
		if (pathMesh == "") pathMesh_3 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 3"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_3 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_3;
		mesh_3 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_3, mesh_3, cloud_3);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_3.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_3.cloud.height*mesh_3.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_3.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_3 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_3 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_3 Load failed: [" + pathMesh_3 + "]");
			mesh_3 = tempMesh;
			pathMesh_3 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_3();
	}
	else OutputTextEditError("QVTKWidget_3 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::LoadMesh_4(QString pathMesh = "") {
	if (layoutStatus >= 4) {

		// Carl: clear mesh
		ClearMesh_4();

		// Carl: open the file
		QString tempPath = pathMesh_4;
		if (pathMesh == "") pathMesh_4 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 4"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_4 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_4;
		mesh_4 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_4, mesh_4, cloud_4);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_4.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_4.cloud.height*mesh_4.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_4.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_4 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_4 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_4 Load failed: [" + pathMesh_4 + "]");
			mesh_4 = tempMesh;
			pathMesh_4 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_4();
	}
	else OutputTextEditError("QVTKWidget_4 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::LoadMesh_5(QString pathMesh = "") {
	if (layoutStatus >= 5) {

		// Carl: clear mesh
		ClearMesh_5();

		// Carl: open the file
		QString tempPath = pathMesh_5;
		if (pathMesh == "") pathMesh_5 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 1"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_5 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_5;
		mesh_5 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_5, mesh_5, cloud_5);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_5.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_5.cloud.height*mesh_5.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_5.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_5 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_5 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_5 Load failed: [" + pathMesh_5 + "]");
			mesh_5 = tempMesh;
			pathMesh_5 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_5();
	}
	else OutputTextEditError("QVTKWidget_5 hasn't been initialized;");

	return;
}

void MeshSubdivision_Debug::LoadMesh_6(QString pathMesh = "") {
	if (layoutStatus >= 6) {

		// Carl: clear mesh
		ClearMesh_6();

		// Carl: open the file
		QString tempPath = pathMesh_6;
		if (pathMesh == "") pathMesh_6 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 6"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));
		else pathMesh_6 = pathMesh;

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_6;
		mesh_6 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_6, mesh_6, cloud_6);

		// Carl: set timer
		clock_t start, stop;
		start = clock();
		meshLoader.start();

		// Carl: lock textEdit and update info
		ui.textEdit_cmd->setEnabled(false);
		QTextCursor cursor = ui.textEdit_cmd->textCursor();
		ui.textEdit_cmd->setTextColor(QColor("green"));

		QString processInfo = "Mesh Loader Running - -";
		ui.textEdit_cmd->textCursor().insertText(processInfo);
		ui.textEdit_cmd->verticalScrollBar()->setValue(ui.textEdit_cmd->verticalScrollBar()->maximum());

		// Carl: loader will call run() as a thread;
		int timer(0), changeTime(30);
		while (meshLoader.isRunning() && ++timer) {
			// Carl: update processing information;
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			cursor.deletePreviousChar();
			if ((timer % (4 * changeTime)) / changeTime == 0)
				cursor.insertText("- -");
			else if ((timer % (4 * changeTime)) / changeTime == 1)
				cursor.insertText("\\ \\");
			else if ((timer % (4 * changeTime)) / changeTime == 2)
				cursor.insertText("| |");
			else if ((timer % (4 * changeTime)) / changeTime == 3)
				cursor.insertText("/ /");

			// Carl: call event process;
			QCoreApplication::processEvents();
		}

		// Carl: eliminate processing information
		for (int i = 0; i < processInfo.size(); i++)
			cursor.deletePreviousChar();

		// Carl: wait for the thread;
		stop = clock();
		meshLoader.wait();

		// Carl: output information
		if (!mesh_6.cloud.data.empty()) {
			// Carl: output timer
			QVector<QPair<QColor, QString>> output;
			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Loader running finished: "));
			output.append(QPair<QColor, QString>(QColor("green"), "[" + QString::number((double)(stop - start) / 1000) + "s]  "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh Info: "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Points: " + QString::number(mesh_6.cloud.height*mesh_6.cloud.width) + "] "));
			output.append(QPair<QColor, QString>(QColor("yellow"), "[Faces: " + QString::number(mesh_6.polygons.size()) + "] "));
			OutputTextEditColoredString(output);
			output.clear();

			output.append(QPair<QColor, QString>(QColor("gray"), "Mesh_6 Load finished: "));
			output.append(QPair<QColor, QString>(QColor("gray"), "[" + pathMesh_6 + "]"));
			OutputTextEditColoredString(output);
		}
		else {
			OutputTextEditError("Mesh_6 Load failed: [" + pathMesh_6 + "]");
			mesh_6 = tempMesh;
			pathMesh_6 = tempPath;
		}

		ui.textEdit_cmd->setEnabled(true);

		// Carl: show mesh
		ShowMesh_6();
	}
	else OutputTextEditError("QVTKWidget_6 hasn't been initialized;");

	return;
}