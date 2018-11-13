#ifndef WORKER_H
#define WORKER_H

#include "Tag.h"

class Worker{
protected:
	double specifier=0, activeTime=0, t_working = 0;
	bool _active = false;
public:
	void Start(double t0);
	double Stop(double tn);
	bool isActive();
	Worker(double in);
};

class Processor : public Worker{
public:
	Tag Work(Tag &_tag);
	Processor(double in);
};

class Output : public Worker{
public:
	Tag Work(Tag &_tag);
	Output(double in);
};

#endif