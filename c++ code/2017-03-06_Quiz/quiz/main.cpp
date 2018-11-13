#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

struct vect{
	int values[100];
	int size=1;
	
	//constructor
	vect(int i){ size = i; }
	
	//operations
	void operator+=(vect &v2){
		if(size==v2.size){
			for(int i=0; i<size; i++){
				values[i]+=v2.values[i];
			}
		};
	}
		
	void random(){
		for(int i=0; i<size; i++) values[i] = rand()%101 -50;
	}
	
	void random(int r){
		for(int i=0; i<size; i++) values[i] = rand()%(2*r+1) -r ;
	}
};

int operator*(vect &v1, vect &v2){
	int result=0;
	if(v1.size==v2.size){
		for(int i=0; i<v1.size; i++){
			result += v1.values[i]*v2.values[i];
		}
	}
	return result;
}

ostream& operator<<(ostream &out, vect &v1){
	for(int i=0; i<v1.size; i++){
		out << v1.values[i] << ", ";
	}
	out << endl;
	return out;
}

int main()
{
	srand(time(NULL));
	
	vect ex1(4);
	ex1.random();
	cout<<ex1;
	vect ex2(4);
	ex2.random();
	cout << ex2;
	int vectproduct = (ex1*ex2);
	cout << vectproduct << endl; //working fine
	ex2.random(666);
	cout << ex2;
	ex1 += ex2; //working fine
	cout << ex1;
	
	return 0;
}
