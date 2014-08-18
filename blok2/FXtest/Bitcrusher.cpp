#include "math.h"
#include "Bitcrusher.h"

Bitcrusher::Bitcrusher()
{
	Bitdepth = 8;
	ProcessedBuffer = new float[buffersize];
	for(int x=0; x<buffersize;	x++)
	{
		ProcessedBuffer[x] = 0.f;
	}

}

Bitcrusher::~Bitcrusher()
{
	delete ProcessedBuffer;	
}

void Bitcrusher::Process(int bitdepth) //process the samples with the bitcrusher
{
	for(int i=0; i<buffersize; i++)
	{ 
			int downdepth = pow(2.f, (bitdepth - 1.f));
			 ProcessedBuffer[i] = sinebuffer[i];
			 ProcessedBuffer[i] = ((roundf(ProcessedBuffer[i] * downdepth)) / downdepth);

			 
	}
}

void Bitcrusher::setBitdepth(int newBitdepth)	//sets the new bitdepth
{
	Bitdepth = newBitdepth;
}

