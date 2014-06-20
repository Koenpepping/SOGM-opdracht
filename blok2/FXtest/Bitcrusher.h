#include "TestSine.h"
class Bitcrusher: public Sine
{
	public:
		Bitcrusher();
		~Bitcrusher();

		void Process(int bitdepth);
		void setBitdepth(int newBitdepth);
		
		float* ProcessedBuffer;

	private:
		int Bitdepth;
};

