#include <iostream>
#include "TestSine.h"
#include "math.h"

#define _USE_MATH_DEFINES

#ifndef Bitcrusher_h_
#define Bitcrusher_h_

#define F 480 //frequency of the sine
#define SR 48000	//samplerate

using namespace std;

Sine::Sine()
{
	amp = 1.f;
	sinebuffer = new float[buffersize]; 
	buffersize = 100; 

	for(int x=0; x<buffersize; x++)
	{
		sinebuffer[x] =0.f; //initialize sinebuffer
	}
}

Sine::~Sine()
{
	delete sinebuffer;
}

void Sine::Sinewave(float amplitude) //fill buffer with sine
{	
	for(int x=0; x<buffersize; x++)
	{
		sinebuffer[x] = amplitude * (sin(x*2*M_PI*F/SR));
	}
}

void Sine::output(int periods, float* outputBuffer, int buffersize)
{
		
		int periodNUM = buffersize * periods;
		for(int s=0; s<periodNUM; s++) //s = sample index
		{
			cout << s << "\t" << outputBuffer[s % buffersize] <<endl;
		}
}

#endif
