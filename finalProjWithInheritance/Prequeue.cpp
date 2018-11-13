#include "Prequeue.h"

template<class T> void QueueWithComparison<T>::_receive(Tag &_tag){
	QueueWithComparison<T>::_que.push(_tag);
	if(QueueWithComparison<T>::_que.size()>maxL) maxL = _que.size(); }
template<class T> Tag QueueWithComparison<T>::top(){
	Tag rslt = QueueWithComparison<T>::_que.top();
	QueueWithComparison<T>::_que.pop(); return rslt; }
template<class T> bool QueueWithComparison<T>::empty(){ return QueueWithComparison<T>::_que.empty(); }
template<class T> int QueueWithComparison<T>::maxLength(){ return QueueWithComparison<T>::maxL; }

void preQueue<Processor>::receive(Tag &_tag){
	_tag.currentLocation = 2;
	QueueWithComparison<myCPUComp>::_receive(_tag);
	}

void preQueue<Output>::receive(Tag &_tag){
	_tag.currentLocation = 4;
	QueueWithComparison<myTimeComp>::_receive(_tag); }