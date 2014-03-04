// bitcrusher.h

#ifndef __BITCRUSHER_H
#define __BITCRUSHER_H

#include "amplifier.h"

class Bitcrusher : public Amplifier
{
public:
    Bitcrusher();
    void show_params();
    void process_samples();
		void set_resolution();
//	void set_reduction
		
private:
		int resolution;
//	int reduction

};

#endif
