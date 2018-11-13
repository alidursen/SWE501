#include <iostream>
#include <stdio.h>
#include "card.h"
#include "deck.h"

int main(int argc, char **argv)
{
	Deck deneme1;
	deneme1.shuffleAll();
	Kilic(deneme1);
	
	deneme1.integrate();
	cout << "Integration successful." << endl;
	
	Saat(deneme1);
	
	return 0;
}
