#include "amplifier.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;


Amplifier::Amplifier()
{
    this->level = 1; // default
    this->buffersize = 256;
    buffer = new float[buffersize];
}

Amplifier::~Amplifier()
{
		delete buffer;
}

void Amplifier::show_params()
{
  cout << "Amplifier level: " << level << endl;
}

void Amplifier::set_level(float l)
{
    level = l;
}

void Amplifier::process_samples() // vermenigvuldigd alle input getallen
{
    for (int i = 0; i < buffersize; i++)
    {
	     buffer[i] *= level;
	  }

}

float* Amplifier::get_buffer()
{
	return buffer;
}
