#ifndef TestSine_h_
#define TestSine_h_

#include "Bitcrusher.h"

int main()
{
	Bitcrusher Bc1;

	Bc1.Sinewave(1.f);
	Bc1.Process(3);
	Bc1.output(2, Bc1.ProcessedBuffer, Bc1.buffersize);
}

#endif
