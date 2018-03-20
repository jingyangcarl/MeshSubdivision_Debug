#include "MeshSubdivision_Debug.h"
#include <qfiledialog.h>
#include <qscrollbar.h>
#include "MeshLoader.h"

void MeshSubdivision_Debug::LoadMesh_1() {

	if (layoutStatus >= 1) {

		// Carl: clear mesh
		ClearMesh_1();

		// Carl: open the file
		QString tempPath = pathMesh_1;
		pathMesh_1 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 1"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_1;
		mesh_1 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_1, mesh_1, cloud_1, colorCloud_1);

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

void MeshSubdivision_Debug::LoadMesh_2() {

	if (layoutStatus >= 2) {

		// Carl: clear mesh
		ClearMesh_2();

		// Carl: open the file
		QString tempPath = pathMesh_2;
		pathMesh_2 = QFileDialog::getOpenFileName(this, tr("Select Mesh File for Mesh 2"), "../MeshFile", tr("Mesh Files(*.ply *.obj *.off)"));

		pcl::PolygonMesh tempMesh, empty;
		tempMesh = mesh_2;
		mesh_2 = empty;

		// Carl: initialization
		MeshLoader meshLoader(pathMesh_2, mesh_2, cloud_2, colorCloud_2);

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

void MeshSubdivision_Debug::LoadMesh_3() {

}

void MeshSubdivision_Debug::LoadMesh_4() {

}