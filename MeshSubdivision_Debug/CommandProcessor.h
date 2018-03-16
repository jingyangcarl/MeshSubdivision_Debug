#pragma once

#include "qthread.h"
#include "Command.h"

class CommandProcessor : public QThread
{
	Q_OBJECT

public:
	CommandProcessor();
	CommandProcessor(Command);
	~CommandProcessor();
	void SetCommand(Command);

private:
	Command command;

protected:
	void run();

signals:
	void SignalOutputTextEditFinished(QString);
	void SignalOutputTextEditError(QString);
	void SignalLoadMesh_1();
	void SignalLoadMesh_2();
	void SignalLoadMesh_3();
	void SignalLoadMesh_4();
	void SignalChangeToLayout_1();
	void SignalChangeToLayout_2();
	void SignalChangeToLayout_4();

};

