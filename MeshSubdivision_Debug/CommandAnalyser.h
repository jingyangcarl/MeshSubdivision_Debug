#pragma once

#include <qstring.h>
#include "Command.h"

class CommandAnalyser
{
public:
	CommandAnalyser();
	CommandAnalyser(QString);
	~CommandAnalyser();

	// Carl: analyse if the input is a command or not;
	Command Analyse();

private:
	QString input;
	Command command;

};

