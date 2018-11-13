#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

enum suit{ Spade, Club, Heart, Diamond };

class Card{
	int r; suit s;
	
public:
	Card(int input);
	Card();
	Card(suit in_s, int in_r);
	
	bool isRankEqual(int in_r);
	bool isSuitEqual(suit in_s);
	bool operator==(Card &in_c);
	
	string suitName();
	string rankName();
	int rankValue();
};

ostream& operator<<(ostream& out, Card& sdm);

#endif