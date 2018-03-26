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
	void SignalOutputTextEditHelp(QString);
	void SignalLoadMesh_1();
	void SignalLoadMesh_2();
	void SignalLoadMesh_3();
	void SignalLoadMesh_4();
	void SignalLoadMesh_5();
	void SignalLoadMesh_6();
	void SignalShowMesh_1();
	void SignalShowMesh_2();
	void SignalShowMesh_3();
	void SignalShowMesh_4();
	void SignalShowMesh_5();
	void SignalShowMesh_6();
	void SignalClearMesh_1();
	void SignalClearMesh_2();
	void SignalClearMesh_3();
	void SignalClearMesh_4();
	void SignalClearMesh_5();
	void SignalClearMesh_6();
	void SignalShowCloud_1();
	void SignalShowCloud_2();
	void SignalShowCloud_3();
	void SignalShowCloud_4();
	void SignalShowCloud_5();
	void SignalShowCloud_6();
	void SignalClearCloud_1();
	void SignalClearCloud_2();
	void SignalClearCloud_3();
	void SignalClearCloud_4();
	void SignalClearCloud_5();
	void SignalClearCloud_6();
	void SignalChangeToLayout_1();
	void SignalChangeToLayout_2();
	void SignalChangeToLayout_4();
	void SignalChangeToLayout_6();

};

