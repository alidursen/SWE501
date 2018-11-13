#include "card.h"

class Deck{
    array<Card, 52> b;
    array<Card*, 52> a;
    
    public:
        Deck(){
            cout << "Deck initialized." << endl; //test line
            for(int i=0; i<52; i++){
                b[i] = Card(i+1);
                a[i] = &b[i];
            }
            cout << "Deck filled." << endl; //test line
        };
        
        void shuffle(){
            Card* temp; int i;
            srand (time(NULL));
            
            for(int k=52; k>1; k--){
                i = rand() % k;
                temp = a[i];
                a[i] = a[k-1];
                a[k-1] = temp;
            }
	    cout << "Deck shuffled." << endl; //test line
        };
        
        bool deal(Card &wanted){
            int i=0;
            bool counter=false, test;
            cout << left << setw(24) << "Player" << setw(24) << "Computer" 
                << "\n------------------------------------------------\n";
            do{
                counter = !counter;
                //test = (*a[i]).isEqual(wanted);
				test = ((*a[i]) == wanted);
                cout << *a[i] << "\t\t";
                if(!counter) cout << "\n";
                i++;
            } while (!test);
            
            return counter;
        };
};
