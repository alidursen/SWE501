#ifndef TAG_H
#define TAG_H

#include <fstream>

class Task;

struct Tag{
	double time; int index; Task* locator; int currentLocation; double dProc; int vIndex;
};
std::ostream& operator<<(std::ostream& out, Tag& _t);

struct myTimeComp{ bool operator()(Tag &lhs, Tag &rhs); };
struct myCPUComp{ bool operator()(Tag &lhs, Tag &rhs); };

#endif