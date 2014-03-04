#include "bitcrusher.h"
#include <iostream>
#include <math.h>

using namespace std;

Bitcrusher::Bitcrusher() : Amplifier()
{		
		resolution = 12; // nieuwe bitdepth
	  Amplifier::Amplifier();
//	reduction
}



void Bitcrusher::set_resolution(int r)
{
	resolution = r;
}

void Bitcrusher::show_params()
{
	cout << "resolutie: " << resolution << endl;
}


void Bitcrusher::process_samples()
{
	int downdepth = pow(2.0, resolution) - 1.0;
//int reductedsample = samplerate / reduction;

	for(int i = 0; i < buffersize; i++)
		{
			//depth
			(buffer[i] += 1.0) *= downdepth ;	

			round (buffer[i]);

			(buffer[i] /= downdepth) -= 1.0;

			/*reduct

			if (reduction > 1) {
				for(int x = 0; x < reductedsample && x < buffersize; x++)
				{
					
				}

			*/

			buffer[i] *= level;
		} 
}
