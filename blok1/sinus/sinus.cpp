#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES
// #define PI 3.14159265

using namespace std;
// sinewave plotter

int main()
{
double amplitude=0.5;
double frequency=880;
double samplerate=48000;

	for(int x=0; x<3; ++x) {
	cout << x << " > " << amplitude*sin(x*M_PI) <<endl;
	}
return 0;
}
