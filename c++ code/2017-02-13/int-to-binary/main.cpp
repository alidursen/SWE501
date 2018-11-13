#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
	int intIn, bitTemp, i;
	unsigned int intInUnsigned;
	string stringIn, stringOut="";
	
	cout << "Please enter an integer:" << endl;
	getline(cin, stringIn);
	intIn = std::stoi(stringIn);
	intInUnsigned = intIn;
	for(i=0; i<32; i++){
		bitTemp = intInUnsigned % 2;
		stringOut = std::to_string(bitTemp) + stringOut;
		intInUnsigned = intInUnsigned >> 1;
	}
	
	cout << "Your number is: " + stringOut << endl;
	return 0;
}