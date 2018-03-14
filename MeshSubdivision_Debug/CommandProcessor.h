#pragma once
#include "qthread.h"

class CommandProcessor : public QThread
{
public:
	CommandProcessor();
	~CommandProcessor();
};

