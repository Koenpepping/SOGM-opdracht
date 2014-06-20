/* 
17-06-2014 Sine class to test digital audio effects
written by Koen Pepping 
*/

class Sine
{
	public:
	Sine();
	~Sine();

	void Sinewave(float amplitude); // fill sinebuffer
	void output(int periods, float* outputBuffer, int buffersize); // cout the x angle and the amplitude (y) of the buffer[] 
	int buffersize;

	float* sinebuffer;

	private:
	float amp;
};


