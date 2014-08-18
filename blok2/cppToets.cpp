#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define lengthOfSequence 8
#define defaultTransNum 0

int transposeNum = 0;
int numberOFOctaves = 1;

// toonladder is acht noten 0 is grondtoon 8 is octaaf.


//base class
class Instruments
{
	public:
	Instruments();
		int makeSequence(int length, int numOfOctaves, int index);
		int output(int length);
};

//afgeleide class
class Synth : public Instruments
{
	public:
	Synth();
	void setNumberofOctaves(int numOctaves);	
	void transpose(int plus);
	void noTranspose();
};

int main()
{	
  srand (time(NULL)); //initialize srand

Synth synth1; //eerste synth sequence
	synth1.noTranspose();
	synth1.setNumberofOctaves(3);
	synth1.output(lengthOfSequence);

Synth synth2; //tweede synth sequence
	synth2.transpose(3);
	synth2.setNumberofOctaves(1);
	synth2.output(lengthOfSequence);

Synth synth3; //derde synth sequence
	synth3.noTranspose();
	synth3.setNumberofOctaves(1);
	synth3.output(lengthOfSequence);

}

//instruments class:

Instruments::Instruments()
{
	
}

int Instruments::makeSequence(int length, int numOfOctaves, int index) //vul array met 8 random noten binnen numOfOctave
{
	int notes[length-1];

	for(int i=0; i<=length-1; i++)
	{
	notes[i] = ((rand() % ((numOfOctaves * 8) + 1)) + transposeNum);	
	}

return notes[index];
}

int Instruments::output(int length) //print array 
{
	for(int i=0; i<=length-1; i++)
	{
		Instruments synth1;
			cout << setfill(' ') << setw(2) <<	synth1.makeSequence(lengthOfSequence, numberOFOctaves , i) << " ";
	}
cout << endl;
return 0;
}

//synth class afgeleid

Synth::Synth()
{

}


void Synth::setNumberofOctaves(int numOctaves) // set number of octaves
{
 numberOFOctaves = numOctaves;
}

void Synth::transpose(int plus) //transposed de sequence met interval plus
{
	transposeNum = plus;
}

void Synth::noTranspose() //geen transpose aangeroepen
{
	transposeNum = defaultTransNum;
}

