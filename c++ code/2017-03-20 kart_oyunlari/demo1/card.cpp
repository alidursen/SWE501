#include "card.h"

const string SUIT_NAMES[4] = { "Spade", "Club", "Heart", "Diamond" };
ostream& operator<<(ostream& out, const suit& s){
    out << SUIT_NAMES[s];
    return out;
}

Card::Card(int input){
	if (input > 52 || input < 0) { r=1; s=Spade; }
	else if (input == 0) { r=0; s=Spade; } // null-Card
		else {s = static_cast<suit>((input-1)/13);
		r = ((input-1) % 13) + 1;}
};
Card::Card(){ r=1; s=Spade; };
Card::Card(suit in_s, int in_r){ 
	if(r<1 || r>13) { r=1; s=Spade; }
	else { r=in_r; s=in_s; } };

bool Card::isRankEqual(int in_r) { return (r==in_r); }
bool Card::isSuitEqual(suit in_s) { bool b = (s==in_s); return b; }
bool Card::operator==(Card &in_c) {
	bool result = (in_c.isSuitEqual(s) && in_c.isRankEqual(r));
	return result;
}
	
string Card::suitName() { return SUIT_NAMES[s]; }
string Card::rankName() {
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
int Card::rankValue() { return r; }

ostream& operator<<(ostream& out, Card& sdm){
    string sN = sdm.suitName(), rN = sdm.rankName();
	out << rN << " of " << sN << "s";
    return out;
}