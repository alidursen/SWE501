#ifndef OBJARRAY_H
#define OBJARRAY_H

#include <vector>
#include <queue>

#include "Task.h"
#include "Worker.h"
#include "Prequeue.h"

template <class T> class objArray{
protected:
	std::vector<T> vItems;
	std::vector<double> vWorkTime; //standing for total time in TaskArray
	int size = 0;
public:
	objArray();
	objArray(int n);
};

template <class T> class wArray : public objArray<T>{
protected:
	int workingItemCount = 0;
	preQueue<T>* pIq;
	Tag _receive(Tag const &_done);
public:
	bool isIdle();
	Tag activate(Tag &_tag);
	void idle(Tag const &Tn);
	void getWorkTimes();
	int longestWorker();

	wArray();
	wArray(int n, std::ifstream &ifs, preQueue<T>* _piq);
};

class TaskArray : public objArray<Task>{
	std::vector<double> vWaitTime;
public:
	void TaskComplete(Tag &_tag);

	double maxWaitTime();
	double avWaitTime();
	double avTaskTime();

	std::priority_queue<Tag, std::vector<Tag>, myTimeComp> GenerateQueue();

	TaskArray();
	TaskArray(int n, std::ifstream &ifs);
};

class CPUArray : public wArray<Processor>{
public:
	Tag receive(Tag const &Tn);
		
	CPUArray(int n, std::ifstream &ifs, preQueue<Processor> *_pcq);
	CPUArray();
};

class OutArray : public wArray<Output>{
public:
	Tag receive(Tag const &Tn);
	Tag repeat(Tag &again);

	OutArray(int n, std::ifstream &ifs, preQueue<Output> *_poq);
	OutArray();
};

#endif