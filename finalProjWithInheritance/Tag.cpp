#include "Tag.h"

std::ostream& operator<<(std::ostream& out, Tag& _t){
	out << _t.time << " " << _t.currentLocation << " " << _t.index << " " << _t.dProc << " " << _t.vIndex << std::endl;
	return out; }

bool myTimeComp::operator() (Tag &lhs, Tag &rhs){
		if(lhs.time != rhs.time) return (lhs.time > rhs.time);
		else return (lhs.index > rhs.index); }
bool myCPUComp::operator() (Tag &lhs, Tag &rhs){
		if(lhs.dProc != rhs.dProc) return (lhs.dProc > rhs.dProc); 
		else return (lhs.index > rhs.index); }