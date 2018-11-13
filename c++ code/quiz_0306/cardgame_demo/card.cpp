#include <iostream>
#include <string>
#include "card.h"
using namespace std;

class Card{
    //data
    int r; suit s;
    
    //constructors
    public:
        Card(int input){
            if (input > 52 || input < 1) { r=1; s=Spade; }
            else {s = static_cast<suit>((input-1)/13);
            r = ((input-1) % 13) + 1;}
        };
        Card(){ r=1; s=Spade; };
        Card(suit in_s, int in_r){ 
			if(r<1 || r>13) { r=1; s=Spade; }
			else { r=in_r; s=in_s; } };
        
    //checking if cards match
	public:
		bool isRankEqual(int in_r) const { return (r==in_r); }
		bool isSuitEqual(suit in_s) const { return (s==in_s); }
        bool operator==(Card &in_c) const {
			bool result = (in_c.isSuitEqual(s) && in_c.isRankEqual(r));
			return result;
		}
		/*bool isEqual(Card &in_c){ 
			bool result = (in_c.isSuitEqual(s) && in_c.isRankEqual(r));
			return (r == in_c.r) && (s == in_c.s); }*/
		
		//sort of getters
		string suitName() const { return SUIT_NAMES[s]; }
		string rankName() const {
			string rslt;
			switch(r){
				case 1: rslt = "Ace"; break;
				case 11: rslt = "Jack"; break;
				case 12: rslt = "Queen"; break;
				case 13: rslt = "King"; break;
				default: rslt = to_string(r);
			}
			return rslt;
		}
};
/*ostream& operator<<(ostream& out, Card& sdm){
    string sN = sdm.suitName(), rN = sdm.rankName();
	out << rN << " of " << sN << "s";
    return out;
}*/
