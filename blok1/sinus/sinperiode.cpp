#include <iostream>
#include "math.h"

#define _USE_MATH_DEFINES

using namespace std;

int F = 480;
int SR = 48000;
int length = (SR / F);

int main()
{
	for(int x = 0; x <= length; x++)
	{
		double y = sin(x*2*M_PI*F/SR);
		cout << x << "\t" << y << endl;
	}
}
