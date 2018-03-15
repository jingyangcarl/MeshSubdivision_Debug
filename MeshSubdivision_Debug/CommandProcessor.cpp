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
	emit MsgSignalFinished("finished");
}
