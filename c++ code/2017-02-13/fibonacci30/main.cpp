#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	/*int i, fib[30]={};
	fib[0]=0;
	fib[1]=1;
	for(i=2; i<30; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(i=0; i<30; i++){
		cout << fib[i] << "  ";
	}*/
	
	//same result as previous, less memory consumption :)
	int f0=0, f1=1, f, i;
	cout << f0 << "  " << f1 << "  ";
	for(i=2; i<30; i++){
		f=f0+f1;
		cout << f << "  ";
		f0=f1;
		f1=f;
	}
	return 0;
}
