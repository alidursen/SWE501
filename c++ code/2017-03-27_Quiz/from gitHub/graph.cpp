#include "graph.h"

	Graph::Graph(int n){
		nodes = n;
		inlist.resize(nodes);
		outlist.resize(nodes);
	}
	
	Graph::Graph(string fl){
		ifstream ifs;
		int s, t;

		ifs.open (fl, std::ifstream::in);
		ifs >> nodes;
		inlist.resize(nodes);
		outlist.resize(nodes);

		 ifs >> s >> t;
		 while (ifs.good()) {
			outlist[s].push_back(t);
			inlist[t].push_back(s);
			ifs >> s >> t;
		 }
		 ifs.close();
	}
	
	void Graph::listEdge(vector< list<int> > &a){
		for(unsigned int iv = 0; iv < a.size(); iv++){
			cout << "Edge(s) of vertex " << iv << ": ";
			for(list<int>::iterator il = a[iv].begin(); il != a[iv].end(); il++){
				cout << *il << " ";
			}
			cout << endl;
		}
	}

	int Graph::degreeNode(list<int> &a){
		int result=0;
		for(list<int>::iterator il = a.begin(); il != a.end(); il++){ result++; }
		return result;
	}

	void Graph::degreesGraph(vector< list<int> > &a){
		for(unsigned int i=0; i < a.size(); i++){ cout << "Degree of vertex " << i << ": " << degreeNode(a[i]) << endl; }
	}
	
	void Graph::printGraph(){
		cout << "****Outgoing****" << endl;
		listEdge(outlist);
		cout << "****Incoming****" << endl;
		listEdge(inlist);
	}
	
	/*ödev*/
	int Graph::degreeIn(int vertex){
		int result = degreeNode(inlist[vertex]);
		return result;
	}
	
	int Graph::degreeOut(int vertex){
		int result = degreeNode(outlist[vertex]);
		return result;
	}
	
	bool Graph::isNeighborDownStream(int center, int target){
		list<int> &t = outlist[center];
		for(list<int>::iterator il = t.begin(); il != t.end(); il++){
			if( (*il) == target) { return true; }
		}
		return false;
	}
	
	bool Graph::isNeighborUpStream(int center, int target){
		list<int> &t = inlist[center];
		for(list<int>::iterator il = t.begin(); il != t.end(); il++){
			if( (*il) == target) { return true; }
		}
		return false;

	}

	bool Graph::isReachable(int beginning, int target){
		bool connected[nodes][2];
		for(int i=0; i<nodes; i++){ connected[i][0] = connected[i][1] = false; }
		connected[beginning][0] = true;
		bool testable;
		do {
			for(int i=0; i<nodes; i++){
				if( connected[i][0] && !connected[i][1] ){
					for(int j=0; j<i; j++){ connected[j][0] = connected[j][0] || isNeighborDownStream(i, j); }
					for(int j=i+1; j<nodes; j++){ connected[j][0] = connected[j][0] || isNeighborDownStream(i, j); }
					connected[i][1] = true;
				}
				
				if( connected[target][0] ){ return true; }
			}
			
			testable = false;
			for(int i=0; i<nodes; i++){
				testable = testable || (connected[i][0] ^ connected[i][1]); }
			
		} while( testable );
		return false;
	}

	bool Graph::betterBFSReachable(int beginning, int target){
		bool connected[nodes]; for(int i=0; i<nodes; i++){ connected[i] = false; }
		list<int> nextinline;
		nextinline.push_back(beginning);
		while( !nextinline.empty() ){
			int firstelement = nextinline.front();
			nextinline.pop_front();
			if(!connected[firstelement]){
				connected[firstelement] = true;
				list<int> &ph = outlist[firstelement]; //easier to write, not really required
				for(list<int>::iterator il = ph.begin(); il != ph.end(); il++){
					if( target == (*il) ){ return true; }
						//equivalently, omit this and return connected[target]
						//since we omit this quick exit, will take longer, but get a more complete result
						//in case we want a list of ALL vertices reachable from ~~beginning~~
					if( !connected[(*il)] ){ nextinline.push_back( *il ); }
				}
			}
		}
		return false;
	}
	
	void Graph::addEdge(int from, int to){
		outlist[from].push_back(to);
		inlist[to].push_back(from);
	}
	
