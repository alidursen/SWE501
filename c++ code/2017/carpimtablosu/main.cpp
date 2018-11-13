#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
	int k, l;
	for(k=0; k<11; k++){
		for(l=0; l<11; l++){
			cout << setw(6);
			cout << k*l;
		}
		cout << endl;
	}
	return 0;
}
