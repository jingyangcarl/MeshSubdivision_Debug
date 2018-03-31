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
	QString pathMesh;

protected:
	void run();

signals:
	// Carl: signal to output 
	void SignalOutputTextEditFinished(QString);
	void SignalOutputTextEditProcessing(QString);
	void SignalOutputTextEditError(QString);
	void SignalOutputTextEditHelp(QString);
	// Carl: signal to load mesh
	void SignalLoadMesh_1(QString);
	void SignalLoadMesh_2(QString);
	void SignalLoadMesh_3(QString);
	void SignalLoadMesh_4(QString);
	void SignalLoadMesh_5(QString);
	void SignalLoadMesh_6(QString);
	// Carl: signal to show mesh
	void SignalShowMesh_1();
	void SignalShowMesh_2();
	void SignalShowMesh_3();
	void SignalShowMesh_4();
	void SignalShowMesh_5();
	void SignalShowMesh_6();
	// Carl: signal to clear mesh
	void SignalClearMesh_1();
	void SignalClearMesh_2();
	void SignalClearMesh_3();
	void SignalClearMesh_4();
	void SignalClearMesh_5();
	void SignalClearMesh_6();
	// Carl: signal to show cloud
	void SignalShowCloud_1();
	void SignalShowCloud_2();
	void SignalShowCloud_3();
	void SignalShowCloud_4();
	void SignalShowCloud_5();
	void SignalShowCloud_6();
	// Carl: signal to clear cloud
	void SignalClearCloud_1();
	void SignalClearCloud_2();
	void SignalClearCloud_3();
	void SignalClearCloud_4();
	void SignalClearCloud_5();
	void SignalClearCloud_6();
	// Carl: signal to show keypoint
	void SignalShowKeypoint_1();
	void SignalShowKeypoint_2();
	void SignalShowKeypoint_3();
	void SignalShowKeypoint_4();
	void SignalShowKeypoint_5();
	void SignalShowKeypoint_6();
	// Carl: signal to clear keypoint
	void SignalClearKeypoint_1();
	void SignalClearKeypoint_2();
	void SignalClearKeypoint_3();
	void SignalClearKeypoint_4();
	void SignalClearKeypoint_5();
	void SignalClearKeypoint_6();
	// Carl: signal to change layout 
	void SignalChangeToLayout_1();
	void SignalChangeToLayout_2();
	void SignalChangeToLayout_4();
	void SignalChangeToLayout_6();

	// Carl: signal to get data
	void SignalGetMeshPath(int);
	void SignalSendKeypointList_1(QVector<bool>);
	void SignalSendKeypointList_2(QVector<bool>);
	void SignalSendKeypointList_3(QVector<bool>);
	void SignalSendKeypointList_4(QVector<bool>);
	void SignalSendKeypointList_5(QVector<bool>);
	void SignalSendKeypointList_6(QVector<bool>);
	void SignalAddCommand(QString);

private slots:
	void GetMeshPath(QString);
};

