#include "Worker.h"
#include "Task.h"

void Worker::Start(double t0){ t_working = t0; _active = true; }
double Worker::Stop(double tn){ if(tn>t_working) activeTime += (tn - t_working); _active = false; return activeTime; }
bool Worker::isActive(){ return _active; }

Worker::Worker(double in){ if(in>0) specifier = in; }
Processor::Processor(double in) : Worker(in){}
Output::Output(double in) : Worker(in){}

Tag Processor::Work(Tag &_tag){
		_tag.time = (_tag.locator)->CPUFetched(_tag.time, specifier);
		return _tag;
	}
Tag Output::Work(Tag &_tag){
		_tag.time = (_tag.locator)->OutFetched(_tag.time, specifier);
		return _tag;
	}