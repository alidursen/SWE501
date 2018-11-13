#include <iostream>
#include <string>
using namespace std;

void cycle(int* A, int size, int cycLength){
    //for i<size, *(A+i) = (i+1)st element
    //if direction == right, A = B[size-length] + C[length] turns to C + B
    //if direction == left, length = 1 implies size-1 to right //decided to solve direction issue outside the function... wanted to call function recursively but didn't work. most probably because of my reliance on modulus
    
    int i;
    //cout << "Variables are: size= " << size << ", length = " << cycLength << endl;    //testline
    cycLength %= size; //now we have: 0<=length<size
    if(cycLength<0) cycLength += size; //thanks stupid modulus of this particular implementation...
    //cout << "Length after mod is: " << cycLength << endl; //testline
    
    if(cycLength == 0) return; //kill if we "cycle for" 0
    
    int temp[cycLength];
    for(i=0; i< (size - cycLength); i++){ 
        temp[i] = *(A+i); 
        //cout << temp[i] << " ";   //testline
    }
    for(i=0; i<cycLength; i++){ *(A+i) = *(A+i+size-cycLength); }
    for(i=cycLength; i<size; i++){ *(A+i)=temp[i-cycLength]; }
    return;
}



int main(){
    const int SIZE = 8;
    int Array[SIZE]={ 3, 48, 59, 6, 18987, 5685, 868, 1024 };
    bool direction;
    int cycLength;
    cout << "Our array is as follows:";
    for(int i=0; i<SIZE; i++){ cout << " " << Array[i]; }
    cout << ";" << endl;
    cout << "How many steps to move? Then leave a space and enter 0 for right, 1 for left:" << endl;
    cin >> cycLength >> direction;
    if(direction) cycLength *= -1;
    cycle(Array, SIZE, cycLength);
    cout << "Now our array is:";
    for(int i=0; i<SIZE; i++){ cout << " " << Array[i]; }
    cout << ";" << endl;

    return 0;    
}