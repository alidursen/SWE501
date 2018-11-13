#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void reverse(int* A, int size){
	int temp;
	for(int i = 0; i < size/2; i++){
		temp = *(A+i);
		*(A+i) = *(A+size-1-i);
		*(A+size-1-i) = temp;

	}
}

int main(int argc, char **argv)
{
	int arr[6]={8, 42, 64, 31, 53, 6};
	reverse(arr, sizeof(arr)/sizeof(int));
	for(int i = 0; i < 6; i++){
		cout << arr[i] << endl;
	}
	return 0;
}
