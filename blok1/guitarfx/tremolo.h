// tremolo.h

#ifndef __TREMOLO_H
#define __TREMOLO_H

#include "amplifier.h"

class Tremolo : public Amplifier
{
public:
    Tremolo();
    void set_rate(float r);
    void set_depth(float d);
    void show_params();
    void process_samples();
		
private:
    float rate, depth, phase;
		
};

#endif
