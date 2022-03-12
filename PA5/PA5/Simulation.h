#pragma once

#include "Data.h"
#include "Queue.h"
#include "QueueNode.h"
#include "TestApp.h"


void runLauncher(void);

class Launcher {
public:
	int menu();

	void simulation(void); 
};