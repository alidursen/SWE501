//============================================================================
// Name        : floatrepr.cpp
// Author      : Ali Durþen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	//cout << "Hello!" << endl; // prints Hello!

	
	float /*tamsayi, kusurat, */input; //bu değerleri değiştirmemeye çalışıyorum, gerek varsa bir kopyalarını yaratıyorum~~
	string /*tamsayiS="", *//*kusuratS, */HWexponent="", HWprecision;
	//bool kusuratB24[24], kusuratB151[151];
	int exponent=127;
	//int i;	//declared outside, so if loop breaks we know the digits //bir noktada i'e tüm referansları comment out'ladığımı gördüm, i'i de attım~~
	
	cout << "Enter a number, non-integers accepted:" << endl;
	cin >> input;

	//sign
	bool HWsign = signbit(input); //was (input < 0);

	//special cases //there are some problems (technical?) that i don't fully grasp~~
	if (isnan(input))	{
		printf("Not a number."); return 0;}
	if (isinf(input))	{
		printf("Out-of-bounds is shown as: (%d-11111111-00000000000000000000000)\n(Hypens and parantheses added for readability. First digit is 0 for positive and 1 for negative out-of-bounds.)\n", HWsign); return 0;}
	if (!input)	{
		printf("0 is shown as: (0-00000000-00000000000000000000000)\n(Hypens and parantheses added for readability. -0 is technically possible to obtain, but not as input.)\n"); return 0;}
	if (!isnormal(input))	{
		printf("Subnormal."); return 0;}

	//printf("In the making...\n");

	input = abs(input);
	while(input >= 2)	{
		input /= 2;
		exponent++;
	}
	while(input < 1 && input > 0)	{
		input *= 2;
		exponent--;
	}
	printf("Exponent calculated to be: %d, that is, your number is between 2^%d and 2^%d.\n", exponent, exponent-127, exponent-126); //test line

	input--;
	for (int i = 0; i < 23; i++)
	{
		input *= 2;
		HWprecision += to_string(input >= 1);
		if(input >= 1) input--;
	}
	cout << "Mantissa is: " << HWprecision << endl; //test line

	//while(exponent != 0)	{ //we need exactly 8 digits~~
	for (int i = 0; i < 8; i++)	{
		HWexponent = to_string(exponent%2)+HWexponent;
		exponent /= 2;
	}
	cout << "Exponent is: " << HWexponent << endl; //test line
	
	//result is:
	printf("Your number, in IEEE 754 standard, is represented as:\n");
	cout << HWsign << HWexponent << HWprecision << endl;



	//good, but not good enough. disregard.

	/*
		kusurat = modf(input, &tamsayi);
			
		//tamsayı kısmının binary gösterimi, string olarak//
		int tK = static_cast<int>(tamsayi);
		while(tK != 0)	{
			tamsayiS = to_string(tK%2)+tamsayiS;
			tK = tK/2;
		}
		//bu modülün sonu

		//tamsayı kısmını kontrol kapısı. neden gerekli olduğu aşağıdaki paragrafta~~
		if(tamsayiS=="")	{
			tamsayiS="0";
		}
		//0 tamsayı vaziyetinin sonu, HWprecision (23 karakterlik string) ve exponent (0 ve 255 arası (noninclusive) bir int) belirlenmiş olmalı
		else	{
			exponent += (tamsayiS.size()-1);
			HWprecision = tamsayiS;
			HWprecision.erase(HWprecision.begin());

			if (HWprecision.size()>23)		{ HWprecision.erase(HWprecision.begin()+23, HWprecision.end());	}
			else {
			//küsüratın binary gösterimi, string olarak(?) //daha sonra bool array daha pratik geldi //pratikte eğer tamsayı kısmında 24 basamak varsa bunu hesaplamaya gerek yok
			//daha da pratik bakarsak tüm bu bool array'e de gerek yok... sadece HWprecision'a eklemek yeterli olacaktır
				float kusuratK = kusurat;
			/*	for (i = 0; i < 24; i++)	{
					kusuratK *= 2;
					kusuratB24[i] = (kusuratK>=1);
					if(kusuratB24[i]) kusuratK--;
					if(!kusuratK) break;
				}	*//*

				while(HWprecision.size()!=23)	{
					kusuratK *= 2;
					HWprecision += to_string(kusuratK>=1);
					if (kusuratK>=1) kusuratK--;
				}
			}

		}
		//>0 tamsayı vaziyetinin sonu, HWprecision (23 karakterlik string) ve exponent (0 ve 255 arası (noninclusive) bir int) belirlenmiş olmalı

		//exponent'in pozitif veya negatif bağlı olmasına göre küsuratı ele alışta farklılıklar olacak
		//eğer tamsayı kısmı varsa küsüratı 24 bit almak yeter de artar
		//eğer sayı (absolutely) 1'den küçükse o zaman 2^-128 exponent'e kadar dikkat etmek gerekir... bu da bize 128+23=151 bit gerektiği anlamına gelir
		//buna göre bool array'in boyu tamsayının 0 olup olmamasına göre değişecek
		//ve tabii exponent'in nasıl hesaplanacağı da
		//öyleyse bunu yukarıda tamsayiS'in kontrol edildiği kapıyla şekillendirebiliriz.
		
		
		
		
		
		cout << input << " = " << tamsayi << " + " << kusurat << endl;
		cout << "Sign was: " << HWsign << " (0: positive, 1: negative)" << endl;
		cout << "Integer part of (absolute) input in binary calculated to be: " << tamsayiS << endl;
		cout << "And mantissa is: " << HWprecision << endl;
		//cout << "Exponent calculated to be " << exponent << ", that is, your number is between 2^" << exponent-127 << " and 2^" << exponent-126 << "." << endl;
		//cout << "Fractional part of (absolute) input in binary calculated to be: " << endl;
		//for(int j = 0; j<i+1 && j<24; j++) { printf("%d", kusuratB[j]); }
	*/
	
	return 0;
}
