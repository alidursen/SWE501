#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <iomanip>

class Deck{
	Card ORIGINAL[52] = { 
		Card(1), Card(2), Card(3), Card(4), Card(5), Card(6), 
		Card(7), Card(8), Card(9), Card(10), Card(11), Card(12), Card(13), 
		Card(14), Card(15), Card(16), Card(17), Card(18), Card(19), 
		Card(20), Card(21), Card(22), Card(23), Card(24), Card(25), Card(26), 
		Card(27), Card(28), Card(29), Card(30), Card(31), Card(32), 
		Card(33), Card(34), Card(35), Card(36), Card(37), Card(38), Card(39), 
		Card(40), Card(41), Card(42), Card(43), Card(44), Card(45), 
		Card(46), Card(47), Card(48), Card(49), Card(50), Card(51), Card(52) };
	Card** deste;
	int remaining, all;
	void construct(int i);

public:
	Deck(); Deck(int n);						//using construct()
	void shuffleAll(); void shuffleRemaining();	//using shuffle()
	Card deal(); void integrate();
	int totalCount(); int remainingCount();
};

bool Kilic(Deck d);
bool Saat(Deck e);

#endif