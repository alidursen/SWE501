#ifndef TASK_H
#define TASK_H

#include <iostream>
#include "Tag.h"

class Task{
	double TIME[4] = {0, -1, -2, -3}; //stands for entry time into first queue, into CPU, into second queue, job completion
	double DEMAND[2] = {0, 0};
	double STATS[4] = {0, 0, 0, 0}; //stands for time spent in Q1, in CPU, in Output, in Q2
	double C_time = 0, O_rem = 0;
	bool _iscomplete = false;
public:
	bool isComplete();
	double WaitTime();
	double TaskTime();
	void Complete(double tn);
	double CPUFetched(double t0, double freq);
	double OutFetched(double t0, double quant);
	Tag initTag();
	Task(double t_arrival, double dem_CPU, double dem_O);
};

#endif