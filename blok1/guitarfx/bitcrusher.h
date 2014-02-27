// bitcrusher.h

#ifndef __BITCRUSHER_H
#define __BITCRUSHER_H

#include "amplifier.h"

class Bitcrusher : public Amplifier
{
public:
    Bitcrusher();
		void set_resolution();
    void show_params();
    void process_samples();
		
private:

};

#endif
