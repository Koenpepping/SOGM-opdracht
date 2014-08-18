#pragma once

#include "ofMain.h"
#include "Amplifier.h"
#include "Bitcrusher.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioIn(float *input, int bufferSize, int nChannels);
        void audioOut(float *output, int bufferSize, int nChannels);
        ofSoundStream soundStream;
    
    float* inputbuffer;
    
    ofxUICanvas *gui0, *gui1, *gui2;
    void guiEvent(ofxUIEventArgs &e);
		
    Amplifier amp;
    Bitcrusher bitcrusher;
    
};
