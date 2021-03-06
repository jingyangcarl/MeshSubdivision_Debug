#include "CommandProcessor.h"
#include "KeypointDetector.h"
#include "MeshSubdivisior.h"

CommandProcessor::CommandProcessor() {
}

CommandProcessor::CommandProcessor(Command command) {
	this->command = command;
}

CommandProcessor::~CommandProcessor() {
}

void CommandProcessor::SetCommand(Command command) {
	this->command = command;
}

void CommandProcessor::GetMeshPath(QString pathMesh) {
	this->pathMesh = pathMesh;
}

void CommandProcessor::GetLayoutStatus(int layoutStatus) {
	this->layoutStatus = layoutStatus;
}

void CommandProcessor::run() {

	if (command.predicate == "change") {
		if (command.object == "layout") {
			if (command.complement == "1") emit SignalChangeToLayout_1();
			else if (command.complement == "2") emit SignalChangeToLayout_2();
			else if (command.complement == "4") emit SignalChangeToLayout_4();
			else if (command.complement == "6") emit SignalChangeToLayout_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate +"\"");
	}
	else if (command.predicate == "clear") {
		if (command.object == "cloud") {
			if (command.complement == "1") emit SignalClearCloud_1();
			else if (command.complement == "2") emit SignalClearCloud_2();
			else if (command.complement == "3") emit SignalClearCloud_3();
			else if (command.complement == "4") emit SignalClearCloud_4();
			else if (command.complement == "5") emit SignalClearCloud_5();
			else if (command.complement == "6") emit SignalClearCloud_6();
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("clear cloud 1");
				if (layoutStatus >= 2) emit SignalAddCommand("clear cloud 2");
				if (layoutStatus >= 3) emit SignalAddCommand("clear cloud 3");
				if (layoutStatus >= 4) emit SignalAddCommand("clear cloud 4");
				if (layoutStatus >= 5) emit SignalAddCommand("clear cloud 5");
				if (layoutStatus >= 6) emit SignalAddCommand("clear cloud 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "keypoint") {
			if (command.complement == "1") emit SignalClearKeypoint_1();
			else if (command.complement == "2") emit SignalClearKeypoint_2();
			else if (command.complement == "3") emit SignalClearKeypoint_3();
			else if (command.complement == "4") emit SignalClearKeypoint_4();
			else if (command.complement == "5") emit SignalClearKeypoint_5();
			else if (command.complement == "6") emit SignalClearKeypoint_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "mesh") {
			if (command.complement == "1") emit SignalClearMesh_1();
			else if (command.complement == "2")	emit SignalClearMesh_2();
			else if (command.complement == "3")	emit SignalClearMesh_3();
			else if (command.complement == "4")	emit SignalClearMesh_4();
			else if (command.complement == "5") emit SignalClearMesh_5();
			else if (command.complement == "6") emit SignalClearMesh_6();
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("clear mesh 1");
				if (layoutStatus >= 2) emit SignalAddCommand("clear mesh 2");
				if (layoutStatus >= 3) emit SignalAddCommand("clear mesh 3");
				if (layoutStatus >= 4) emit SignalAddCommand("clear mesh 4");
				if (layoutStatus >= 5) emit SignalAddCommand("clear mesh 5");
				if (layoutStatus >= 6) emit SignalAddCommand("clear mesh 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate + "\"");
	}
	else if (command.predicate == "detect") {
		if (command.object == "mesh") {

			KeypointDetector keypointDetector;
			QVector<bool> keypointList;
			// Carl: get path
			if (command.complement == "1") emit SignalGetMeshPath(1);
			else if (command.complement == "2") emit SignalGetMeshPath(2);
			else if (command.complement == "3") emit SignalGetMeshPath(3);
			else if (command.complement == "4") emit SignalGetMeshPath(4);
			else if (command.complement == "5") emit SignalGetMeshPath(5);
			else if (command.complement == "6") emit SignalGetMeshPath(6);
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("detect mesh 1");
				if (layoutStatus >= 2) emit SignalAddCommand("detect mesh 2");
				if (layoutStatus >= 3) emit SignalAddCommand("detect mesh 3");
				if (layoutStatus >= 4) emit SignalAddCommand("detect mesh 4");
				if (layoutStatus >= 5) emit SignalAddCommand("detect mesh 5");
				if (layoutStatus >= 6) emit SignalAddCommand("detect mesh 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");

			// Carl: load mesh
			emit SignalOutputTextEditFinished("Load mesh to KeypointDetector;");
			if (keypointDetector.LoadMeshFile(pathMesh)) {
				emit SignalOutputTextEditFinished("Load mesh finished;");
				emit SignalOutputTextEditProcessing("Detecting");
				keypointList = keypointDetector.KeypointDetection();
				if(!keypointList.empty()) emit SignalOutputTextEditFinished("Detection finished;");
				else emit SignalOutputTextEditError("Detection failed");
			}
			else emit SignalOutputTextEditError("Load mesh failed;");

			if (command.complement == "1") emit SignalSendKeypointList_1(keypointList), emit SignalShowKeypoint_1();
			else if (command.complement == "2") emit SignalSendKeypointList_2(keypointList), emit SignalShowKeypoint_2();
			else if (command.complement == "3") emit SignalSendKeypointList_3(keypointList), emit SignalShowKeypoint_3();
			else if (command.complement == "4") emit SignalSendKeypointList_4(keypointList), emit SignalShowKeypoint_4();
			else if (command.complement == "5") emit SignalSendKeypointList_5(keypointList), emit SignalShowKeypoint_5();
			else if (command.complement == "6") emit SignalSendKeypointList_6(keypointList), emit SignalShowKeypoint_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate + "\"");
	}
	else if (command.predicate == "load") {
		if (command.object == "mesh") {
			if (command.complement == "1") emit SignalLoadMesh_1("");
			else if (command.complement == "2") emit SignalLoadMesh_2("");
			else if (command.complement == "3") emit SignalLoadMesh_3("");
			else if (command.complement == "4") emit SignalLoadMesh_4("");
			else if (command.complement == "5")	emit SignalLoadMesh_5("");
			else if (command.complement == "6")	emit SignalLoadMesh_6("");
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate + "\"");
	}
	else if (command.predicate == "show") {
		
		if (command.object == "cloud") {
			if (command.complement == "1") emit SignalShowCloud_1();
			else if (command.complement == "2") emit SignalShowCloud_2();
			else if (command.complement == "3") emit SignalShowCloud_3();
			else if (command.complement == "4") emit SignalShowCloud_4();
			else if (command.complement == "5") emit SignalShowCloud_5();
			else if (command.complement == "6") emit SignalShowCloud_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "cloud status") {
			if (command.complement == "1") emit SignalShowCloudStatus_1();
			else if (command.complement == "2") emit SignalShowCloudStatus_2();
			else if (command.complement == "3") emit SignalShowCloudStatus_3();
			else if (command.complement == "4") emit SignalShowCloudStatus_4();
			else if (command.complement == "5") emit SignalShowCloudStatus_5();
			else if (command.complement == "6") emit SignalShowCloudStatus_6();
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("show cloud status 1");
				if (layoutStatus >= 2) emit SignalAddCommand("show cloud status 2");
				if (layoutStatus >= 3) emit SignalAddCommand("show cloud status 3");
				if (layoutStatus >= 4) emit SignalAddCommand("show cloud status 4");
				if (layoutStatus >= 5) emit SignalAddCommand("show cloud status 5");
				if (layoutStatus >= 6) emit SignalAddCommand("show cloud status 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "error") emit SignalOutputTextEditError(command.complement);
		else if (command.object == "help") {
			if (command.complement == "instruction") {
				emit SignalOutputTextEditHelp("----------- INSTRUCTION -----------");
				emit SignalOutputTextEditHelp("change layout [1/2/4]");
				emit SignalOutputTextEditHelp("clear cloud (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("clear keypoint [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("clear mesh (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("detect mesh (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("load mesh [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("show cloud [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("show cloud status (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("show help (instruction/key/note)");
				emit SignalOutputTextEditHelp("show keypoint [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("show mesh [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("show mesh status (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("show status (1/2/3/4/5/6/all)");
				emit SignalOutputTextEditHelp("subdivide butterfly [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide catmull [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide efp [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide feature [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide loop [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide setup");
				emit SignalOutputTextEditHelp("subdivide sqrt3 [1/2/3/4/5/6]");
				emit SignalOutputTextEditHelp("subdivide sqrt3lgt [1/2/3/4/5/6]");
			}
			else if (command.complement == "key") {
				emit SignalOutputTextEditHelp("--------------- KEY ---------------");
				emit SignalOutputTextEditHelp("KEY_F :: focus on the point");
				emit SignalOutputTextEditHelp("KEY_G :: show coordinate system");
				emit SignalOutputTextEditHelp("KEY_J :: screenshot");
				emit SignalOutputTextEditHelp("KEY_P :: point cloud mode");
				emit SignalOutputTextEditHelp("KEY_R :: reset camera");
				emit SignalOutputTextEditHelp("KEY_S :: face mesh mode");
				emit SignalOutputTextEditHelp("KEY_W :: line mesh mode");
				emit SignalOutputTextEditHelp("KEY_+ :: increase point size");
				emit SignalOutputTextEditHelp("KEY_- :: decrease point size");
			}
			else if (command.complement == "note") {
				emit SignalOutputTextEditHelp("--------------- NOTE ---------------");
				emit SignalOutputTextEditHelp("NOTE: () default parameter");
				emit SignalOutputTextEditHelp("NOTE: [] nondefault parameter");
			}
			else if (command.complement == "") {
				emit SignalAddCommand("show help instruction");
				emit SignalAddCommand("show help key");
				emit SignalAddCommand("show help note");
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "keypoint") {
			if (command.complement == "1") emit SignalShowKeypoint_1();
			else if (command.complement == "2") emit SignalShowCloud_2();
			else if (command.complement == "3") emit SignalShowCloud_3();
			else if (command.complement == "4") emit SignalShowCloud_4();
			else if (command.complement == "5") emit SignalShowCloud_5();
			else if (command.complement == "6") emit SignalShowCloud_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "mesh") {
			if (command.complement == "1") emit SignalShowMesh_1();
			else if (command.complement == "2") emit SignalShowMesh_2();
			else if (command.complement == "3") emit SignalShowMesh_3();
			else if (command.complement == "4") emit SignalShowMesh_4();
			else if (command.complement == "5") emit SignalShowMesh_5();
			else if (command.complement == "6") emit SignalShowMesh_6();
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "mesh status") {
			if (command.complement == "1") emit SignalShowMeshStatus_1();
			else if (command.complement == "2") emit SignalShowMeshStatus_2();
			else if (command.complement == "3") emit SignalShowMeshStatus_3();
			else if (command.complement == "4") emit SignalShowMeshStatus_4();
			else if (command.complement == "5") emit SignalShowMeshStatus_5();
			else if (command.complement == "6") emit SignalShowMeshStatus_6();
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("show mesh status 1");
				if (layoutStatus >= 2) emit SignalAddCommand("show mesh status 2");
				if (layoutStatus >= 3) emit SignalAddCommand("show mesh status 3");
				if (layoutStatus >= 4) emit SignalAddCommand("show mesh status 4");
				if (layoutStatus >= 5) emit SignalAddCommand("show mesh status 5");
				if (layoutStatus >= 6) emit SignalAddCommand("show mesh status 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else if (command.object == "status") {
			if (command.complement == "1") emit SignalShowMeshStatus_1(), emit SignalShowCloudStatus_1();
			else if (command.complement == "2") emit SignalShowMeshStatus_2(), emit SignalShowCloudStatus_2();
			else if (command.complement == "3") emit SignalShowMeshStatus_3(), emit SignalShowCloudStatus_3();
			else if (command.complement == "4") emit SignalShowMeshStatus_4(), emit SignalShowCloudStatus_4();
			else if (command.complement == "5") emit SignalShowMeshStatus_5(), emit SignalShowCloudStatus_5();
			else if (command.complement == "6") emit SignalShowMeshStatus_6(), emit SignalShowCloudStatus_6();
			else if (command.complement == "all" || command.complement == "") {
				emit SignalGetLayoutStatus();
				if (layoutStatus >= 1) emit SignalAddCommand("show status 1");
				if (layoutStatus >= 2) emit SignalAddCommand("show status 2");
				if (layoutStatus >= 3) emit SignalAddCommand("show status 3");
				if (layoutStatus >= 4) emit SignalAddCommand("show status 4");
				if (layoutStatus >= 5) emit SignalAddCommand("show status 5");
				if (layoutStatus >= 6) emit SignalAddCommand("show status 6");
				return;
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate + "\"");
	}
	else if (command.predicate == "subdivide") {

		MeshSubdivisior meshSubdivisior;
		QString oMeshPath = "./oMesh_" + command.complement + ".ply";

		if (command.object == "setup") {
			emit SignalGetLayoutStatus();
			if (layoutStatus >= 6) {
				emit SignalAddCommand("subdivide butterfly 1");
				emit SignalAddCommand("subdivide catmull 2");
				emit SignalAddCommand("subdivide efp 3");
				emit SignalAddCommand("subdivide feature 4");
				emit SignalAddCommand("subdivide loop 5");
				emit SignalAddCommand("subdivide sqrt3 6");
				emit SignalOutputTextEditNotice("1: butterfly, 2: catmull, 3: efp, 4: feature, 5: loop, 6: sqrt3;");
				return;
			}
		}

		if (command.complement == "1") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(1);
		else if (command.complement == "2") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(2);
		else if (command.complement == "3") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(3);
		else if (command.complement == "4") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(4);
		else if (command.complement == "5") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(5);
		else if (command.complement == "6") meshSubdivisior.SetOutputMeshPath(oMeshPath), emit SignalGetMeshPath(6);
		else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");

		emit SignalOutputTextEditFinished("Load mesh to MeshSubdivisior;");
		if (meshSubdivisior.LoadMeshFile(pathMesh)) {
			emit SignalOutputTextEditFinished("Load mesh finished;");

			// Carl: subdivision
			emit SignalOutputTextEditProcessing("Subdividing");
			if (command.object == "butterfly") meshSubdivisior.MeshSubdivisionModifiedButterFlyT();
			else if (command.object == "catmull") meshSubdivisior.MeshSubdivisionCatmullClarkT();
			else if (command.object == "efp") meshSubdivisior.MeshSubdivisionEdgePreserved();
			else if (command.object == "loop") meshSubdivisior.MeshSubdivisiorLoopT();
			else if (command.object == "sqrt3") meshSubdivisior.MeshSubdivisionSqrt3T();
			else if (command.object == "sqrt3lgt") meshSubdivisior.MeshSubdivisionSqrt3InterpolatingSubdividerLabsikGreinerT();
			else if (command.object == "feature") {

				// Carl: detect keypoint first
				KeypointDetector keypointDetector;
				QVector<bool> keypointList;

				if (keypointDetector.LoadMeshFile(pathMesh)) {
					keypointList = keypointDetector.KeypointDetection();
					if (keypointList.empty()) emit SignalOutputTextEditError("Detection failed");
				}
				else emit SignalOutputTextEditError("Load mesh failed;");

				meshSubdivisior.MeshSubdivisionFeaturePreserved(keypointList);
			}
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.object + "\" for \"" + command.predicate + "\"");
			emit SignalOutputTextEditFinished("Subdivision finished;");

			// Carl: write mesh
			meshSubdivisior.WriteMeshFile();
			
			// Carl: reload mesh
			if (command.complement == "1") emit SignalLoadMesh_1(oMeshPath);
			else if (command.complement == "2") emit SignalLoadMesh_2(oMeshPath);
			else if (command.complement == "3") emit SignalLoadMesh_3(oMeshPath);
			else if (command.complement == "4") emit SignalLoadMesh_4(oMeshPath);
			else if (command.complement == "5") emit SignalLoadMesh_5(oMeshPath);
			else if (command.complement == "6") emit SignalLoadMesh_6(oMeshPath);
			else emit SignalOutputTextEditError("There isn't parameter \"" + command.complement + "\" for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("Load mesh failed;");

	}
	else emit SignalOutputTextEditError("There isn't an instruction \"" + command.predicate + "\"");
}
