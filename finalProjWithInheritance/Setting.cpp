#include "Setting.h"


Setting::Setting(char* fileloc){
		std::ifstream inputFile;
		inputFile.open(fileloc, std::ifstream::in);
		inputFile >> nCPU;
		aCPU = CPUArray(nCPU, inputFile, &pCq);
		inputFile >> nOutput;
		aOut = OutArray(nOutput, inputFile, &pOq);
		inputFile >> nTask;
		aTask = TaskArray(nTask, inputFile);
		inputFile.close();
	}
	
void Setting::Work(){
		GlobalCounter = aTask.GenerateQueue(); //indices are 0, vIndices are not
		/*GlobalCounter counts all the tasks in aTask, aCPU, aOut
		//so if it's empty, all tasks are complete
		//which in turn means: DON'T PUT TASKS BACK IF THEY ARE COMPLETED!
		//which in turn allows us to assume: all the tasks inside are INCOMPLETE*/
		while(!(GlobalCounter.empty())){
			Tag current = GlobalCounter.top();
			GlobalCounter.pop();
			switch(current.currentLocation){ //where was topmost element located?
			/*once again, GlobalCurrent counts tags in arrays and not queues,
			//therefore we can assume all locations are 1, 3 or 5*/
				case 1: 
					if(aCPU.isIdle()) GlobalCounter.push( aCPU.activate(current) );
					/*there is an idle CPU
					//CPUArray.activate() accepts a tag that WAS in task array,
					//TRANSFORMS IT into a tag that IS in CPUArray and pushes back to GlobalCounter*/
					else pCq.receive(current);
					/*pCq.receive() accepts a tag that WAS in task array
					//TRANSFORMS IT into a tag that IS in pCq
					//doesn't return the tag*/
					break;
					
				case 3:
					/*now, time has come for an element to leave aCPU
					//which MEANS, it's also time to determine what is coming in*/
					if(!(pCq.empty())) GlobalCounter.push( aCPU.receive(current) );
					/*if there are elements in pCq, receive from there
					//why do we ignore elements in aTask? because a task in
					//motion cannot be in aTask, when they start moving, they'll either
					//directly go to aCPU, or to pCq
					//also, receive() DOES NOT change its variable*/
					else aCPU.idle(current);
					/*so now we see, aCPU.idle() accepts a tag: that tag is LEAVING the array
					//and since there are no more elements left waiting, it's time for that
					//CPU to go idle. note that, idle() DOES NOT change its variable*/
					
					//onwards to deciding where that tag leaving aCPU goes: directly to aOut or pOq?
					if(aOut.isIdle()) GlobalCounter.push( aOut.activate(current) );
					/*so now demand is: aOut.activate() accepts tags and
					//TRANSFORMS them into tags that are IN aOut
					//OR, we need to make sure that variables passed into it are
					//CERTAINLY in aOut*/
					else pOq.receive(current);
					/*similar to pCq.receive() above, it accepts and TRANSFORMS
					//and doesn't return any tag*/
					break;
					
				case 5:
					/*let's cut it short: first 2 lines: deciding where the tag leaving aOut is going
					//but FIRST we need to check if job is finished
					//if it's finished, we'll set currentLocation to 6, won't push it back,
					//receive new tag or simply go idle
					//if it's not finished, then we'll check pOq, if it's empty we'll repeat
					//if pOq is nonempty, then we'll put it to pOq and then get the next item
					//note that, "if empty we repeat" part is equivalent to
					//"put it to pOq and get the next item"
					//(actually, don't do that: we may get MaxQueueLength=1 in cases it's actually =0) 
					//therefore we can just say: "if not finished put to pOq, get the first item"
					//note that pOq doesn't care of tag's time, so we need to adjust time accordingly*/
					if((current.locator)->isComplete()){
						aTask.TaskComplete(current);
						if(pOq.empty()) aOut.idle(current);
						else GlobalCounter.push( aOut.receive(current) );
					}
					else {
						if(pOq.empty()) GlobalCounter.push( aOut.repeat(current) );
						else {
							pOq.receive(current);
							GlobalCounter.push( aOut.receive(current) );
						}
					}
					
					
					//OLD, INFINITELY-LOOPING VERSION
					/*if(!(pOq.empty())) GlobalCounter.push( aOut.receive(current) );
					
					else { aOut.idle(current); }
					
					if((current.locator)->isComplete()){ aTask.TaskComplete(current); }
					else if(!(pOq.empty())) pOq.receive(current);
					else GlobalCounter.push( aOut.repeat(current) );*/
					break;
				default: std::cout << "TROUBLE! at switch(currentLocation)" << std::endl; break;
			}
			
		}
		aCPU.getWorkTimes();
		aOut.getWorkTimes();
	}
	
void Setting::ExtractResults(char* fileloc){
		std::ofstream outputFile;
		outputFile.open(fileloc);
		outputFile << pCq.maxLength() << std::endl;
		outputFile << pOq.maxLength() << std::endl;
		outputFile << aCPU.longestWorker() << std::endl;
		outputFile << aOut.longestWorker() << std::endl;
		outputFile << aTask.avWaitTime() << std::endl;
		outputFile << aTask.maxWaitTime() << std::endl;
		outputFile << aTask.avTaskTime() << std::endl;
		outputFile.close();
	}