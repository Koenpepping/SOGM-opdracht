//
//  Amplifier.h
//  GuitarEffects
//
//  Created by Koen Pepping on 01-08-14.
//
//

#ifndef __GuitarEffects__Amplifier__
#define __GuitarEffects__Amplifier__

class Amplifier //Base class 
{
public:
    Amplifier();
    ~Amplifier();
    
    float process(float* buffer, int index); //processes the signal
    
    void setOnOff(bool OnOff); //turns the effect on/off

    bool IsOn();
    
    void setOutputVolume(float newOutputVolume);// to set output vulume
    
private:

    //variabelen
    float outputVolume;
    bool isOnOff;
};

#endif /* defined(__GuitarEffects__Amplifier__) */
