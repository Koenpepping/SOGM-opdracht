//
//  Bitcrusher.h
//  GuitarEffects
//
//  Created by Koen Pepping on 01-08-14.
//
//

#ifndef __GuitarEffects__Bitcrusher__
#define __GuitarEffects__Bitcrusher__

#include "Amplifier.h"

class Bitcrusher : public Amplifier
{
    
    //Bitcrusher erft de functies setOnOff, isOn en Process van "amplifier"
    //de process functie wordt uiteraard overschreven in de bitcrusher class
    
    public:
        Bitcrusher();
        ~Bitcrusher();
    
        void setBitdepth(int NewBitdepth);
        int  getBitdepth();
    
    float process(float* buffer, int index); //processes the signal (other than that from amplifier)
    
    private:
        int Bitdepth;
        bool isOnOff;
};

#endif /* defined(__GuitarEffects__Bitcrusher__) */
