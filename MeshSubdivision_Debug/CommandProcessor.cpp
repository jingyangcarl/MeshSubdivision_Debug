#include "CommandProcessor.h"

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

void CommandProcessor::run() {

	if (command.predicate == "load") {
		if (command.object == "mesh") {
			if (command.complement == "1") emit SignalLoadMesh_1();
			else if (command.complement == "2") emit SignalLoadMesh_2();
			else if (command.complement == "3") emit SignalLoadMesh_3();
			else if (command.complement == "4") emit SignalLoadMesh_4();
			else emit SignalOutputTextEditError("There isn't parameter " + command.complement + " for \"" + command.object + "\"");
		}
		else SignalOutputTextEditError("There isn't parameter " + command.object + " for \"" + command.predicate + "\"");
	}
	else if (command.predicate == "show") {
		if (command.object == "error") emit SignalOutputTextEditError(command.complement);
		else if (command.object == "help") {
			if (command.complement == "note") {
				emit SignalOutputTextEditHelp("--------------- NOTE ---------------");
				emit SignalOutputTextEditHelp("NOTE: () default parameter");
				emit SignalOutputTextEditHelp("NOTE: [] nondefault parameter");
			}
			else if (command.complement == "key") {
				emit SignalOutputTextEditHelp("--------------- KEY ---------------");
				emit SignalOutputTextEditHelp("KEY_W :: line mesh mode");
				emit SignalOutputTextEditHelp("KEY_S :: face mesh mode");
				emit SignalOutputTextEditHelp("KEY_P :: point cloud mode");
				emit SignalOutputTextEditHelp("KEY_G :: show coordinate system");
				emit SignalOutputTextEditHelp("KEY_R :: reset camera");
				emit SignalOutputTextEditHelp("KEY_F :: focus on the point");
				emit SignalOutputTextEditHelp("KEY_J :: screenshot");
				emit SignalOutputTextEditHelp("KEY_+ :: increase point size");
				emit SignalOutputTextEditHelp("KEY_- :: decrease point size");
			}
			else if (command.complement == "instruction") {
				emit SignalOutputTextEditHelp("----------- INSTRUCTION -----------");
				emit SignalOutputTextEditHelp("change layout [1/2/4]");
				emit SignalOutputTextEditHelp("clear mesh [1/2/3/4]");
				emit SignalOutputTextEditHelp("load mesh [1/2/3/4]");
				emit SignalOutputTextEditHelp("show help (key/instruction)");
				emit SignalOutputTextEditHelp("show mesh [1/2/3/4]");
			}
			else if (command.complement == "") {

			}
			else {

			}
		}
		else if (command.object == "mesh") {
			if (command.complement == "1") emit SignalShowMesh_1();
			else if (command.complement == "2") emit SignalShowMesh_2();
			else if (command.complement == "3") emit SignalShowMesh_3();
			else if (command.complement == "4") emit SignalShowMesh_4();
			else emit SignalOutputTextEditError("There isn't parameter " + command.complement + " for \"" + command.object + "\"");
		}
	}
	else if (command.predicate == "clear") {
		if (command.object == "mesh") {
			if (command.complement == "1") emit SignalClearMesh_1();
			else if (command.complement == "2")	emit SignalClearMesh_2();
			else if (command.complement == "3")	emit SignalClearMesh_3();
			else if (command.complement == "4")	emit SignalClearMesh_4();
			else emit SignalOutputTextEditError("There isn't parameter " + command.complement + " for \"" + command.object + "\"");
		}
	}
	else if (command.predicate == "change") {
		if (command.object == "layout") {
			if (command.complement == "1") emit SignalChangeToLayout_1();
			else if (command.complement == "2") emit SignalChangeToLayout_2();
			else if (command.complement == "4") emit SignalChangeToLayout_4();
			else emit SignalOutputTextEditError("There isn't parameter " + command.complement + " for \"" + command.object + "\"");
		}
		else emit SignalOutputTextEditError("There isn't parameter " + command.object + " for \"" + command.predicate +"\"");
	}
	else emit SignalOutputTextEditError("There isn't instruction " + command.predicate);
}
