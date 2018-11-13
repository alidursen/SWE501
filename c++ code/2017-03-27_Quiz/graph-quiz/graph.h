#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <thread>
using namespace std;

class Graph{
	vector< list<int> > outlist;
	vector< list<int> > inlist;
	int nodes;
	
public:
	Graph(int n);
	Graph(string filelocation);
	
	void printGraph();
	void listEdge(vector< list<int> > &a);
	int degreeNode(list<int> &a);
	void degreesGraph(vector< list<int> > &a);
	
	/*ödev*/
	int degreeIn(int vertex);
	int degreeOut(int vertex);
	bool isNeighborDownStream(int center, int target);
	bool isNeighborUpStream(int center, int target);
	bool isReachable(int beginning, int target);
	bool betterBFSReachable(int beginning, int target);
	bool DFSReachable(int beginning, int target);
	void addEdge(int from, int to);
};

#endif