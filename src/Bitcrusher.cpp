//
//  Bitcrusher.cpp
//  GuitarEffects
//
//  Created by Koen Pepping on 01-08-14.
//
//

#include "Bitcrusher.h"
#include "math.h"

//constructor destructor:
//-----------------------------------------------
Bitcrusher::Bitcrusher()
{
    Bitdepth = 8;
}

Bitcrusher::~Bitcrusher()
{
    
}

//set Bitdepth:
//-----------------------------------------------
void Bitcrusher::setBitdepth(int NewBitdepth)
{
    Bitdepth = NewBitdepth;
}

//process:
//-----------------------------------------------
float Bitcrusher::process(float* buffer, int index)
{
    int downdepth = pow(2.0, Bitdepth) - 1.0;

    buffer[index] = ((roundf(buffer[index] * downdepth)) / downdepth);
    
    return buffer[index];
}

