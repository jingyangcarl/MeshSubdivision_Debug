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
