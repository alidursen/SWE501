#ifndef SETTING_H
#define SETTING_H

#include <fstream>
#include "Prequeue.h"
#include "ObjArray.h"

class Setting{
	int nTask, nCPU, nOutput;
	TaskArray aTask;
	CPUArray aCPU;
	OutArray aOut;
	preQueue<Processor> pCq;
	preQueue<Output> pOq;
	std::priority_queue<Tag, std::vector<Tag>, myTimeComp> GlobalCounter;
public:
	Setting(char* fileloc);
	void Work();
	void ExtractResults(char* fileloc);
};

#endif