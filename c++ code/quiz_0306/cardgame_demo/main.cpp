#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <iomanip>
#include "card.h"
#include "deck.cpp"
using namespace std;

int main()
{
    cout << "Initializing deck." << endl; //test line
    Deck d1;
    cout << "Enter a number, from 1 to 52 (Out of range: Ace of Spades).\nSuit ranges are as follows:\n1-13: Spades; 14-26: Clubs; 27-39: Hearts; 40-52: Diamonds;" << endl;
    int t; cin >> t;
    Card wanted(t);
    cout << "Wanted card (" << wanted << ") initialized." << endl; //test line
    
    d1.shuffle();
    
    bool result = d1.deal(wanted);    
    
    if(result) cout << endl << "Player wins!" << endl;
    else cout << "Computer wins!" << endl;
    
    return 0;
}