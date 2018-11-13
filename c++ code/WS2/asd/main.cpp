#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int arrSize = 7;
	int A[arrSize];
	for(int i = 0; i < arrSize; i++){
		A[i]=i*i-49*i+13;
		cout << A[i] ;
	}
	cout << endl;
	int B[arrSize];
	for(int i = 1; i <= arrSize; i++){
		B[arrSize-i] = A[i-1];
		A[i-1]++;
	}
	cout << "A:  " << "B:  " << endl;
	for(int i = 0; i < arrSize; i++){
		cout << A[i] << "  " << B[i] << endl;
	}

	return 0;
}
