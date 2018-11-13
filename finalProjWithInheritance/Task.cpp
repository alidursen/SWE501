#include "Task.h"

bool Task::isComplete(){ return _iscomplete; }
double Task::WaitTime(){ if(_iscomplete) return STATS[0]+STATS[3]; }
double Task::TaskTime(){ if(_iscomplete) return TIME[3]-TIME[0]; }
	
void Task::Complete(double tn){
		if(tn<TIME[2]){ std::cout << "Trouble@Task.Complete()" << std::endl; return; }
		TIME[3] = tn;
		STATS[0] = TIME[1]-TIME[0];
		STATS[1] = C_time;
		STATS[2] = DEMAND[1];
		STATS[3] = TIME[3]-(TIME[2]+STATS[2]);
		_iscomplete = true;
	}
		
double Task::CPUFetched(double t0, double freq){
		TIME[1] = t0;
		C_time = DEMAND[0]/freq;
		TIME[2] = TIME[1] + C_time;
		return TIME[2];
	}
double Task::OutFetched(double t0, double quant){
		if(O_rem>quant){ O_rem -= quant; return t0+quant; }
		else { double end = t0+O_rem; O_rem = 0; Complete(end); return end; }
	}
		
Tag Task::initTag(){
		Tag _temp = { TIME[0], 0, this, 1, DEMAND[0], 0 };
		return _temp;
	}
		
Task::Task(double t_arrival, double dem_CPU, double dem_O){
		TIME[0] = t_arrival;
		DEMAND[0] = dem_CPU;
		DEMAND[1] = dem_O;
		O_rem = dem_O;
	}