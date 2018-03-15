#include "CommandProcessor.h"

CommandProcessor::CommandProcessor() {
}

CommandProcessor::CommandProcessor(Command command) {
	this->command = command;
}

CommandProcessor::~CommandProcessor() {
}
