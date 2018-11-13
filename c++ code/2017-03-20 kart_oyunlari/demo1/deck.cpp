#include "deck.h"

void Deck::construct(int i){
	int remaining = all = 52*i;
	deste = new Card*[all];
	for(int k=0; k<all; k++){ (deste[k]) = &ORIGINAL[k%52]; }
}
Deck::Deck(){ construct(1); }
Deck::Deck(int n){ construct(n); }

void Deck::shuffleAll(){ integrate(); shuffleRemaining(); }
void Deck::shuffleRemaining(){ 
	Card* temp; int i;
	srand (time(NULL));
	
	for(int k=remaining; k>1; k--){
		i = rand() % k;
		temp = deste[i];
		deste[i] = deste[k-1];
		deste[k-1] = temp;
	}
}

Card Deck::deal(){
	remaining--;
	return *(deste[remaining]);
}
void Deck::integrate(){ remaining = all; }

int Deck::totalCount(){ return all; }
int Deck::remainingCount(){ return remaining; }

bool Kilic(Deck d){
	cout << "You will now ask for a card. If that card is drawn on your turn, you win!\n" 
	<< "Enter a number, from 1 to 52 (Out of range: Ace of Spades).\n"
	<< "Suit ranges are as follows:\n"
	<< "1-13: Spades; 14-26: Clubs; 27-39: Hearts; 40-52: Diamonds;\n";
	int t; cin >> t; Card wanted(t);
	
	bool test, counter = false;
	cout << left << setw(24) << "Player" << setw(24) << "Computer" 
		 << "\n------------------------------------------------\n";
	do{
		counter = !counter;
		Card temp = d.deal();
		cout << temp << "\t\t";
		if(!counter) cout << endl;
		test = (temp == wanted);
	} while(!test);
	
    if(counter) cout << endl << "Player wins!\n";
    else cout << "Computer wins!\n";
	
	return counter;
}

bool Saat(Deck d){
	int ch = d.totalCount();
	if(ch != 52) { return false; }
	Card arrangement[13][4]; //arr0x: kings, arrtx: hour t
	Card current = d.deal(); arrangement[0][0] = Card(0);
	for(int i=1; i<52; i++){ arrangement[i%13][i/13] = d.deal(); }
	/*for(int i=0; i<13; i++){	//testline
			for(int j=0; j<4; j++){ cout << arrangement[i][j] << "\t\t"; }
			cout << endl;
		}*/
	for(int i=1; i<52; i++){
		int next = current.rankValue(); int nLoc = next %13; //standing for "nextLocation"
		//cout << "Next and nextLocation are, respectively: " << next << " - " << nLoc << endl; //testline
		if (!next) { cout << "You couldn't win.\n"; return false; }
		Card temp = current;
		current = arrangement[nLoc][3];
		for(int j=3; j>0; j--){
				//cout << arrangement[nLoc][j] << " - " << arrangement[nLoc][j-1] << endl; //testline
				arrangement[nLoc][j] = arrangement[nLoc][j-1]; 
			}
		arrangement[nLoc][0] = temp;
		
		//for(int i=0; i<13; i++){ cout << arrangement[i][3] << "\n"; } //testline
		//cout << endl << endl;
	}
	cout << "You won!" << endl;
	return true;
}