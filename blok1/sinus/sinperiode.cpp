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
*/

int  z = 1;  

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
				double fundamental = (sin(x*2*M_PI*F/SR)); // fundamental harmonic

				for(int i = 2; i <= NUM_OF_HARMONICS; i++)
					{
						fundamental = (fundamental + ((amp/i)*(sin(x*2*M_PI*(F*i)/SR)))); //adds harmonics to the fundamental sinewave
						y = fundamental;
					}
				cout << x << "\t" << y << endl; 
			}
	}
}
