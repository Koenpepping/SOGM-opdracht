#include <iostream>
#include "math.h"

#define _USE_MATH_DEFINES

using namespace std;

int F = 480;
int SR = 48000;
int phase = 0;
int length = (SR / F);

int main()
{
	for(int i = 0; i <= length; i++)
	{
		double y = sin(i*2*M_PI*F/SR + phase);
		cout << i << " " << y << endl;
	}
}
