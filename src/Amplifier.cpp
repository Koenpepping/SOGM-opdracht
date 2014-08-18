//
//  Amplifier.cpp
//  GuitarEffects
//
//  Created by Koen Pepping on 01-08-14.
//
//

#include "Amplifier.h"

//costructor destructor:
//-----------------------------------------------
Amplifier::Amplifier()
{

}

Amplifier::~Amplifier()
{
}

//Set volume function:
//-----------------------------------------------
void Amplifier::setOutputVolume(float newOutputVolume)
{
    outputVolume = newOutputVolume;
}


//Process
//-----------------------------------------------
float Amplifier::process(float* buffer, int index)
{
    if(isOnOff)
    {
    buffer[index] *= outputVolume;
    }
    return buffer[index];
}

//OnOff:
//-----------------------------------------------
void Amplifier::setOnOff(bool OnOff)
{
    isOnOff = OnOff;
}

bool Amplifier::IsOn()
{
    return isOnOff;
}