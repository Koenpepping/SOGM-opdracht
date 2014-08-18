/**********************************************************************
*          Copyright (c) 2013, Hogeschool voor de Kunsten Utrecht
*                      Hilversum, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : guitarfx.cpp
*  System name   : guitarfx
* 
*  Description   : main file for guitarfx
*
*  Author        : Marc_G
*  E-mail        : marcg@dinkum.nl
*
**********************************************************************/

#include <iostream>
#include "audio_io.h"
#include "amplifier.h"
#include "tremolo.h"
#include "bitcrusher.h"

using namespace std;

#define MODE 1
#define SAMPLERATE 44100
#define NOC	1
#define FPB 256

int main()
{

	Audio_IO audiostream;

	audiostream.set_mode(AUDIO_IO_READWRITE);
  audiostream.set_samplerate(SAMPLERATE); // constante aanmaken
  audiostream.set_nrofchannels(NOC);	// constante aanmaken
  audiostream.set_framesperbuffer(FPB); // constante aanmaken

  audiostream.initialise();
  audiostream.list_devices();

	int device;
	cout << "\nGive input device number: ";
  cin >> device;
  audiostream.set_input_device(device);

  cout << "Give output device number: ";
  cin >> device;
  audiostream.set_output_device(device);

  audiostream.start_server();

		Amplifier* amp;
		
		switch(MODE)
		{
			default: amp = new Amplifier();
			case 0: amp = new Amplifier();
			case 1: amp = new Tremolo();
			case 2: amp = new Bitcrusher();
		}

		while(true)
		{
			audiostream.read(amp->get_buffer());
			amp->process_samples();
			audiostream.write(amp->get_buffer());
		}

		audiostream.finalise();
	
		return 0;
} // main()

