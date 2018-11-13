#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <ostream>
using namespace std;

enum suit{ Spade, Club, Heart, Diamond };
const string SUIT_NAMES[4] = { "Spade", "Club", "Heart", "Diamond" };
ostream& operator<<(ostream& out, const suit& s){
    out << SUIT_NAMES[s];
    return out;
}

class Card{
public:
	Card();
	Card(int input);
	Card(suit in_s, int in_r);
	
	bool isRankEqual(int in_r) const;
	bool isSuitEqual(suit in_s) const;
	bool operator==(Card &in_c) const;
	
	string suitName() const;
	string rankName() const;
}

ostream& operator<<(ostream& out, Card& sdm){
    string sN = sdm.suitName(), rN = sdm.rankName();
	out << rN << " of " << sN << "s";
    return out;
}

#endif