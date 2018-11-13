#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <array>
#include <queue>

#include "Task.h"
#include "Tag.h"
#include "Worker.h"
#include "Setting.h"

using namespace std;

class Task;			//+
class Processor;	//+
class Output;		//+
class Setting;		//+

/*TAG AND COMPARISONS*//*VERBATIM*/

/*Task*//*VERBATIM*/

/*Worker*/

/*preQueue*/
/*objArray*/


/*VERBATIM*/

int main(int argc, char *argv[])
{
	if(argc!=3){ // not as specified
		cerr << "Usage: " << argv[0] << " SOURCE DESTINATION" << endl;
		return 1;
	}
	
	Setting Project(argv[1]);
	Project.Work();
	Project.ExtractResults(argv[2]);
	return 0;
}
