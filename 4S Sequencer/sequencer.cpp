#include <iostream>

using namespace std;

#define NUM_OF_STEPS 15
#define NUM_OF_SAMPLES 2

		int sequence[NUM_OF_STEPS][NUM_OF_SAMPLES]; // memory per step which samples need to be triggered and which don't
		int BPM = 120;
		int samplecounter = 0;
		int step = 0; // which step are we
		int placeInBuffer = 0; // where in this block does the next step needs to be triggered?
		bool trigger = false; // Is the next step triggered in this block?

class Sequencer
{
	public:
	Sequencer();
	~Sequencer();
	void clock(int bpm, int Samplerate); 
	void getTriggerInfo(int step, int sample);
	void setTriggerInfo(int step, int sample, bool onOff); // to set which sample on which step is on or off
	void setBPM(int newBPM);
	int getBPM();
};



int main()
{
	Sequencer sequence1;
	sequence1.setTriggerInfo(1, 1, true);
	sequence1.getTriggerInfo(1, 1);
	sequence1.setBPM(100);
	cout << sequence1.getBPM() <<endl;;
}

// Constructor Destructor
//------------------------------------------------------------------
Sequencer::Sequencer()
{
		for(int i=0; i<=NUM_OF_STEPS; i++)
		{
				for(int x=0; x<=NUM_OF_SAMPLES; x++)
				{
						sequence[i][x] = 0;
				}	
		}
}

Sequencer::~Sequencer()
{	
}

// Clock
//------------------------------------------------------------------

void Sequencer::clock(int Samplerate, int buffersize) //NIET AF
{
	int sampleInterval = ((Samplerate / (BPM / 60)) / 4);

	samplecounter += buffersize;

	if(samplecounter > sampleInterval) //NIET AF
	{
			placeInBuffer = (sampleInterval - (samplecounter - buffersize));
			step = ((step + 1) % (NUM_OF_STEPS + 1));
			samplecounter -= sampleInterval;
			trigger = true;
	}
	else trigger = false;	
}

// Triggerinfo
//------------------------------------------------------------------

void Sequencer::setTriggerInfo(int step, int sample, bool onOff) //set step+samplenumber on true or false
{
		for(int i=0; i<=NUM_OF_STEPS; i++)
		{
			if(i == step)
			{
				for(int x=0; x<=NUM_OF_SAMPLES; x++)
				{
					if(x == sample)
						sequence[i][x] = onOff;
				}
			}
		}	
}

void Sequencer::getTriggerInfo(int step, int sample) //get trigger true/false
{
		cout << sequence[step][sample] <<endl;	
}

// BPM
//------------------------------------------------------------------

void Sequencer::setBPM(int newBPM)
{
	BPM = newBPM;
}

int Sequencer::getBPM()
{
	return BPM;
}	

//------------------------------------------------------------------





