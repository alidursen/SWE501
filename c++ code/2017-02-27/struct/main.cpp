#include <stdio.h>
#include <iostream>
using namespace std;

struct complex{
	double Re;
	double Im;
	
	//constructor
	complex(double inRe, double inIm){ Re=inRe; Im=inIm; }
	complex(){ Re=0; Im=0; }
	
	complex Conj(){ return complex(Re, -Im); }
	double NormSq(){ return (Re*Re)+(Im*Im); }
	
	void operator+=(complex &c2){ Re += c2.Re; Im += c2.Im; }
	void operator-=(complex &c2){ Re -= c2.Re; Im -= c2.Im; }
	void operator+=(double d1){ Re += d1; }
	void operator-=(double d1){ Re -= d1; }
	void operator*=(complex &c3){ Re = (Re*c3.Re)-(Im*c3.Im); Im = (Im*c3.Re)+(Re*c3.Im); }
	void operator*=(double d2){ Re *= d2; Im *= d2; }
	void operator/=(double d2){ Re /= d2; Im /= d2; }
	
	//void operator/=(complex &c3){ (*this) *= (c3.Conj()); (*this) *= (1 / (c3.NormSq() ) ); }
	
	
	//destructor
	~complex(){ cout << "Ending now: " << this << ";" << endl; } //turns out "this" is a pointer~~
};

void operator/=(complex &c1, complex &c2) {
	/*	complex divisor = c2.Conj();
			//divisor = Re - iIm;
		divisor /= c2.NormSq();
			//divisor = (Re - iIm)/(Re^2+Im^2);
		c1 *= divisor;	*/
			//c1 = [(c1.Re*Re + c1.Im*Im) +i(c1.Im*Re - c1.Re*Im)]/(Re^2+Im^2)
	//cout << "N1: " << c1.Re << " " << c1.Im << " N2: " << c2.Re <<" " << c2.Im << endl; //test line
	double temp = ((c1.Re*c2.Re)+(c1.Im*c2.Im)); //cout << c1.Re << endl; //test line
	c1.Im = ((c1.Im*c2.Re)-(c1.Re*c2.Im)); //cout << c1.Im << endl; //test line
	c1.Re = temp;
	c1 /= ((c2.Re*c2.Re)+(c2.Im*c2.Im));
}

ostream& operator<<(ostream &out, complex &u) {
	out << "(" << u.Re << ")+i(" << u.Im << ")";
	return out;
}
istream& operator>>(istream &in, complex &v) { 
	in >> v.Re ;
	in >> v.Im ;
	return in;
}
int main(){
	
	complex u(3, 4), uconj = u.Conj();
	double unormsq = u.NormSq();
	cout << "u is: " << u << endl;
	cout << "u conjugate and norm square, respectively, are: " << uconj << ", " << unormsq << endl;
	
	complex t(5, 12);
	cout << "t is: " << t << endl;
	cout << "Now will be performed: addition, multiplication, scalar multiplication:" << endl;
	cout << "(i.e. it'll print out (u+t), ((u+t)*t), ((u+t)*t)*4)" << endl;
	u += t; cout << u << " ";
	u *= t; cout << u << " ";
	u *= 4; cout << u << endl;
	
	complex q1(2, 3); complex q2(3, 4);
	q1 /= q2;
	cout << "Finally, (2+3i)/(3+4i) = " << q1 << endl;
	
	cout << "Now testing input taking:" << endl << "(Format: \"(Real) (Imaginary)i\")" << endl;
	cin >> t;
	cout << "t is now " << t << endl;
	
	return 0;
}