#pragma once

#include <qstring.h>

class CommandAnalyser
{
public:
	CommandAnalyser();
	CommandAnalyser(QString);
	~CommandAnalyser();

	bool isCommand();

private:
	QString input;
	QString output;
};

