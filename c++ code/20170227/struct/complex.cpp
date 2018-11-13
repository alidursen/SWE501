#include <stdio.h>
#include <iostream>
using namespace std;

struct complex{
	int x;
	int y;
	
	//constructor
	complex(int inX, int inY){ x=inX; y=inY; }
	complex(){ x=1; y=1; }
	
	int Area(){ return x*y; }
	
	//multByTwo in more general version
	void operator*=(int a){ x *= a; y *= a; }
	
	void operator+=(complex &exp){ x += exp.x; y += exp.y; }
	//having & or not means creating a copy or not. we want not.
	
	
	//destructor
	~complex(){ cout << "Bye from " << x << " and " << y << "!" << endl; }
};

//overflowing << operand for Rec types
//also see inside definition of Rec
ostream& operator<<(ostream &out, complex &u) {
	out << "(" << u.x << "/" << u.y << ")";
	return out;
}
istream& operator>>(istream &in, complex &ex) { 
	in >> ex.x ;
	in >> ex.y ;
	return in;
}



void multByTwo(complex &r){
	r.x *= 2;
	r.y *= 2;
	return;
}

/*void multByTwo(Rec u){
	u.x *= 2;
	u.y *= 2;
	return;
}*/


int main(int argc, char **argv){
	
	complex u(42, 36);
	cout << u.x << "/" << u.y << endl;
	u.x = 5;
	u.y = 7;
	cout << u.x << "/" << u.y << endl;
	complex t(13, 66);
	u += t;
	cout << u.x << "/" << u.y << endl;
	
	cout << u.Area() << endl;
	multByTwo(u);
	cout << u.x << " " << u.y << endl;
	
	
	complex w(0, 0);
	cin >> w;
}
