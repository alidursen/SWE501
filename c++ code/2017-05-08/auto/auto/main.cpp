#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

string mult_vect(vector<int> vect){
	string rslt = "";
	for(auto i: vect){
		for(auto j: vect){ rslt += (to_string(i*j) + "\t"); }
		rslt += "\n";
	}
	return rslt;
}

int main()
{
	vector<int> vect1 = {5, 12, 13};
	cout << mult_vect(vect1);
	return 0;
}
