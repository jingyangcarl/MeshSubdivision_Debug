#include "MeshSubdivision_Debug.h"

void MeshSubdivision_Debug::SendMeshPath(int meshIndex) {
	switch (meshIndex) {
	case 1: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_1 : ""); break;
	case 2: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_2 : ""); break;
	case 3: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_3 : ""); break;
	case 4: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_4 : ""); break;
	case 5: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_5 : ""); break;
	case 6: emit SignalSendMeshPath(meshIndex <= layoutStatus ? pathMesh_6 : ""); break;
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

void MeshSubdivision_Debug::AddCommand(QString input) {
	// Carl: slot function to deal with instructions

	commandList.push_back(input);

	return;
}