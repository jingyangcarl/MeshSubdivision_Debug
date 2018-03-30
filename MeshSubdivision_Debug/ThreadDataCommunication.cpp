#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::SendMeshPath(int meshIndex) {
	switch (meshIndex) {
	case 1: emit SignalSendMeshPath(pathMesh_1); break;
	case 2: emit SignalSendMeshPath(pathMesh_2); break;
	case 3: emit SignalSendMeshPath(pathMesh_3); break;
	case 4: emit SignalSendMeshPath(pathMesh_4); break;
	case 5: emit SignalSendMeshPath(pathMesh_5); break;
	case 6: emit SignalSendMeshPath(pathMesh_6); break;
	}

	return;
}

void MeshSubdivision_Debug::GetKeypointList_1(QVector<bool> keypointList) {
	this->keypointList_1 = keypointList;
}

void MeshSubdivision_Debug::GetKeypointList_2(QVector<bool> keypointList) {
	this->keypointList_2 = keypointList;
}

void MeshSubdivision_Debug::GetKeypointList_3(QVector<bool> keypointList) {
	this->keypointList_3 = keypointList;
}

void MeshSubdivision_Debug::GetKeypointList_4(QVector<bool> keypointList) {
	this->keypointList_4 = keypointList;
}

void MeshSubdivision_Debug::GetKeypointList_5(QVector<bool> keypointList) {
	this->keypointList_5 = keypointList;
}

void MeshSubdivision_Debug::GetKeypointList_6(QVector<bool> keypointList) {
	this->keypointList_6 = keypointList;
}

void MeshSubdivision_Debug::ProcessCommand(QString input) {
	// Carl: slot function to deal with instructions
	commandAnalyser = new CommandAnalyser(input);
	commandProcessor->SetCommand(commandAnalyser->Analyse());
	commandProcessor->start();
	ui.textEdit_cmd->setEnabled(false);

	while (commandProcessor->isRunning())
		QCoreApplication::processEvents();

	commandProcessor->wait();
	ui.textEdit_cmd->setEnabled(true);
	ui.textEdit_cmd->setFocus();
	return;
}