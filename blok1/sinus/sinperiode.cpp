/*
Written by: Koen Pepping
						15-05-2014
*/


#include <iostream>
#include "math.h"

#define _USE_MATH_DEFINES

using namespace std;

#define NUM_OF_PERIODS 2 // sets the number of periods 
#define NUM_OF_HARMONICS 250 // sets the number of harmonics for the sawtooth 

int F = 480;
int SR = 48000;
int length = (SR / (F/NUM_OF_PERIODS));
float amp = 1;
double y;
int x;

/* 
if z = 0 this program will output a sinewave
if z = 1 this program will output a sawtooth
if z = 1 this program will output a square
*/

int  z = 4;  

int main()
{

if(z == 0) //sinewave
		{
			for(x = 0; x <= length; x++)
			{
				double fundamental = (sin(x*2*M_PI*F/SR));  
				y = fundamental;
				cout << x << "\t" << y << endl;
			}
		}

if(z == 1) //saw
	{
		for(x = 0; x <= length; x++) 			{
				double fundamental = (sin(x*2*M_PI*F/SR)); // fundamental sine
				for(int i = 2; i <= NUM_OF_HARMONICS; i++)
					{
						fundamental = (fundamental + ((amp/i)*(sin(x*2*M_PI*(F*i)/SR)))); //adds harmonics to the fundamental sinewave
						y = fundamental;
					}
				cout << x << "\t" << y << endl; 

			}
	}

if(z == 2) //square
	{
		for(x = 0; x <= length; x++) 			{
				double fundamental = (sin(x*2*M_PI*F/SR)); // fundamental sine

				for(int i = 3; i <= 79; i += 2) // + 2 for odd harmonics only 
					{
						fundamental = (fundamental + ((amp/i)*(sin(x*2*M_PI*(F*i)/SR)))); //adds odd harmonics to the fundamental sinewave
						y = fundamental;
					}
				cout << x << "\t" << y << endl; 
			}
	}

if(z == 3) //pulse WERKT NOG NIET
	{
		for(x = 0; x <= length; x++) 			
		{
				double fundamental = (sin(x*2*M_PI*F/SR)); // fundamental sine

				int a = 0;

				for(int i = 2; i <= 14; i++)
					{
						if((a % 3) == 2)
								{
									i += 1;
								}	
														
						fundamental = (fundamental + ((amp/i)*(sin(x*2*M_PI*(F*i)/SR)))); //adds odd harmonics to the fundamental sinewave
						y = fundamental;
							
						a++;
						//cout << i << endl;
					}
				cout << x << "\t" << y << endl; 					
		}
	}

if(z == 4) //triangle nog niet helemaal mooi maar voorlopig goed genoeg
	{
		for(x = 0; x <= length; x++) 			
		{
				double fundamental = (sin(x*2*M_PI*F/SR)); // fundamental sine
				int t = -1;
				for(int i = 3; i <= 127; i += 2)
					{											
						fundamental = (fundamental + ((t*(amp/pow(i, 2)))*(sin(x*2*M_PI*(F*i)/SR)))); 
//adds odd harmonics with amplitude 1/(harmonic^2) to the fundamental sinewave, also the phase of the added harmonics is multiplied by PI done with t = -1
						y = fundamental;
					}
				cout << x << "\t" << y << endl; 					
		}
	}

}
