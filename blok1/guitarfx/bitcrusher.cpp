#include "bitcrusher.h"
#include <iostream>
#include <math.h>

using namespace std;

Bitcrusher::Bitcrusher() : Amplifier()
{		
		resolution = 12; // nieuwe bitdepth
	  Amplifier::Amplifier();
}



void Bitcrusher::set_downsample(int d)
{
	downsample = d;
}

void Tremolo::show_params()
{
	cout << "resolutie: " << resolution << endl;
  cout << "downsample: " << downsample << endl;
  cout << "roof: " << roof << endl;

}


void Tremolo::process_samples()
{
	for(int i = 0; i < buffersize; i++)
		{
			//round i op een precision van (1 / (pow (2, (resolution - 1))))
		round	(buffer[i] *= 0.5 + 0.5) * (pow (2, (resolution - 1)))
		} 
}
