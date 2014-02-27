#include "tremolo.h"
#include <iostream>
#include <math.h>

using namespace std;

Tremolo::Tremolo() : Amplifier()
{
    rate = 3675;
    depth = 1.0;
	  Amplifier::Amplifier();
		phase = 0.0;
}

void Tremolo::set_rate(float r)
{
    rate = r;
}

void Tremolo::set_depth(float d)
{
    depth = d;
}

void Tremolo::show_params()
{
    cout << "Tremolo level: " << level << endl;
    cout << "Tremolo rate: " << rate << endl;
    cout << "Tremolo depth: " << depth<< endl;
}

void Tremolo::process_samples()
{
	 for (int i = 0; i < buffersize; i++)
    {
      buffer[i] *= (sin(2*M_PI (* (float)i / SAMPLERATE * rate + phase) * ) + 1) / 2 * depth + 1 - depth;
  	}

		phase += (float)buffersize / SAMPLERATE * rate;
		if (phase > 1.0) phase -= 1.0;
}
