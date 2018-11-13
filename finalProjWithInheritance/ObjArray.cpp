#include "ObjArray.h"

template<class T> objArray<T>::objArray(){}
template<class T> objArray<T>::objArray(int n){
		size = n;
		vWorkTime.resize(size);
	}

template<class T> Tag wArray<T>::_receive(Tag const &_done){
		Tag _new = wArray<T>::pIq->top();
		_new.index = _done.index;
		_new.time = _done.time;
		return objArray<T>::vItems[_new.index].Work(_new);
	}
template<class T> bool wArray<T>::isIdle(){ return (wArray<T>::workingItemCount < objArray<T>::size); }
template<class T> Tag wArray<T>::activate(Tag &_tag){
	workingItemCount++;
	int i = 0;
	for(; i<objArray<T>::size; i++){ if(!( objArray<T>::vItems[i].isActive())) break;	}
	_tag.index = i;
	objArray<T>::vItems[i].Start(_tag.time);
	return objArray<T>::vItems[i].Work(_tag); }
template<class T> void wArray<T>::idle(Tag const &Tn){
		workingItemCount--;
		objArray<T>::vItems[Tn.index].Stop(Tn.time);	}
template<class T> void wArray<T>::getWorkTimes(){ 
	for(int i=0; i<objArray<T>::size; i++) objArray<T>::vWorkTime[i] = objArray<T>::vItems[i].Stop(0); }
template<class T> int wArray<T>::longestWorker(){
	double max = 0; int maxIndex = 0;
	for(int i=0; i<objArray<T>::size; i++){
		if(objArray<T>::vWorkTime[i]>max){
			max = objArray<T>::vWorkTime[i];
			maxIndex = i;
		}
	}
	return maxIndex+1; }
template<class T> wArray<T>::wArray() : objArray<T>(){ pIq = nullptr; }
template<class T> wArray<T>::wArray(int n, std::ifstream &ifs, preQueue<T>* _piq) : objArray<T>(n){
		pIq = _piq;
		for (int i = 0; i<objArray<T>::size; i++)
		{
			double _spec;
			ifs >> _spec;
			objArray<T>::vItems.push_back( T(_spec) );
		}
	}

TaskArray::TaskArray() : objArray<Task>(){}
TaskArray::TaskArray(int n, std::ifstream &ifs) : objArray<Task>(n){
	vWaitTime.resize(size);
	for(int i=0; i<size; i++){
		double t_arr, w_CPU, w_Out;
		ifs >> t_arr >> w_CPU >> w_Out;
		vItems.push_back( Task(t_arr, w_CPU, w_Out) );
	}
}
void TaskArray::TaskComplete(Tag &_tag){
	_tag.currentLocation = 6;
	int i = _tag.vIndex;
	vWaitTime[i] = vItems[i].WaitTime();
	vWorkTime[i] = vItems[i].TaskTime();
}
double TaskArray::maxWaitTime(){
	double max = 0;
	for(int i=0; i<size; i++){ if(vWaitTime[i] > max) max = vWaitTime[i]; }
	return max;
}
double TaskArray::avWaitTime(){
	double sum = 0;
	for(int i=0; i<size; i++){ sum += vWaitTime[i]; }
	return (sum/size);
}
double TaskArray::avTaskTime(){
	double sum = 0;
	for(int i=0; i<size; i++){ sum += vWorkTime[i]; }
	return (sum/size);
}
std::priority_queue<Tag, std::vector<Tag>, myTimeComp> TaskArray::GenerateQueue(){
		std::priority_queue<Tag, std::vector<Tag>, myTimeComp> que;
		for(int i=0; i<size; i++){
			Tag temp = vItems[i].initTag();
			temp.vIndex = i;
			que.push(temp);
		}
		return que;
	}

Tag CPUArray::receive(Tag const &Tn){
		Tag _new = wArray<Processor>::_receive(Tn);
		_new.currentLocation = 3;
		return _new; }
CPUArray::CPUArray(int n, std::ifstream &ifs, preQueue<Processor> *_pcq) : wArray<Processor>(n, ifs, _pcq){}
CPUArray::CPUArray() : wArray<Processor>(){}

Tag OutArray::receive(Tag const &Tn){
		Tag _new = wArray<Output>::_receive(Tn);
		_new.currentLocation = 5;
		return _new; }
Tag OutArray::repeat(Tag &again){ return vItems[again.index].Work(again); }
OutArray::OutArray(int n, std::ifstream &ifs, preQueue<Output> *_poq) : wArray<Output>(n, ifs, _poq){};
OutArray::OutArray() : wArray<Output>(){};