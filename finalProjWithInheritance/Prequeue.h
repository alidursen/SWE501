#ifndef PREQUEUE_H
#define PREQUEUE_H

#include <queue>
#include "Tag.h"
#include "Worker.h"

template <class R> class QueueWithComparison{
protected:
	std::priority_queue<Tag, std::vector<Tag>, R> _que;
	int maxL = 0;
	void _receive(Tag &_tag);
public:
	Tag top();
	bool empty();
	int maxLength();
};

template <class T> class preQueue{};
/*template <class T> class preQueue{
	template <class Q> preQueue(QueueWithComparison<Q> &_Q){
		
	}
};*/
//template <Processor T> class preQueue:public QueueWithComparison<myCPUComp>{
template<> class preQueue<Processor> : public QueueWithComparison<myCPUComp>{
public:
	void receive(Tag &_tag);
};
template<> class preQueue<Output> : public QueueWithComparison<myTimeComp>{
public:
	void receive(Tag &_tag);
};

#endif