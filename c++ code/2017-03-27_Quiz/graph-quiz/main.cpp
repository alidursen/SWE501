#include "graph.h"
#include <stdio.h>

int main()
{
	/*Graph g("test.txt");
	g.printGraph();
	
	//begintest
	cout << g.degreeIn(2) << " " << g.degreeOut(2) << endl;
	cout << g.isNeighborDownStream(0, 2) << endl;
	g.addEdge(0, 2);
	cout << g.isNeighborDownStream(0, 2) << g.isNeighborUpStream(2, 0) << endl;*/
	//endtest
	
	//connectedtest
	Graph h(8);
	h.addEdge(0,7); h.addEdge(7,2); h.addEdge(2,3); h.addEdge(3,1); h.addEdge(2,4);
	h.addEdge(4,5); h.addEdge(4,6); h.addEdge(2,5); h.addEdge(0,5); h.addEdge(0,1);
	h.printGraph();
	//cout << h.isReachable(0,6) << endl << h.isReachable(1,6) << endl;
	bool b1 = h.betterBFSReachable(0,6); cout << "is 0 connected to 6: " << b1 << endl;
	bool b2 = h.betterBFSReachable(1,6); cout << "is 1 connected to 6: " << b2 << endl;
	//connectedtest
	
	//BFS == DFS test
	/*for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			bool b = ( h.betterBFSReachable(i,j) == h.DFSReachable(i,j) );
			cout << "reachable(" << i << "," << j << "): " << h.betterBFSReachable(i,j) << "\t"; 
			cout << "BFS == DFS on (" << i << "," << j << "): " << b << endl;
		}
	}*/
	//BFS == DFS test
	
	return 0;
}
