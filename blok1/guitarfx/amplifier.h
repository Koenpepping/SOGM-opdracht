#ifndef _AMPLIFIER_H_
#define _AMPLIFIER_H_

#define SAMPLERATE 44100




class Amplifier
{
public:
  Amplifier(); // constructor
	~Amplifier();
    void show_params();
    void set_level(float l);
    void process_samples();
		float* get_buffer();

protected:
    float level;
    float* buffer;
    int buffersize;
		
    
// array  float buffer[BUFFERSIZE]
};

#endif
