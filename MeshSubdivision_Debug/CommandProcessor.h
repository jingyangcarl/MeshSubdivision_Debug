#pragma once

#include "qthread.h"
#include "Command.h"

class CommandProcessor : public QThread
{
public:
	CommandProcessor();
	CommandProcessor(Command);
	~CommandProcessor();

private:
	Command command;
};

