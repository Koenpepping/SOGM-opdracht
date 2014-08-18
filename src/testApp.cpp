#include "testApp.h"

#define BUFFERSIZE 256
#define NUM_OF_CHANNELS 2
#define SAMPLERATE 44100


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 100, 200);
    
    //Audio:
    //-------------------------------------------------
    
    ofSoundStreamSetup(NUM_OF_CHANNELS, NUM_OF_CHANNELS, SAMPLERATE, BUFFERSIZE, 4);
    
    soundStream.start();
    
    amp.setOnOff(true); //amplifier is always on
    
    inputbuffer = new float[BUFFERSIZE*NUM_OF_CHANNELS]; //new input buffer
    
    for(int i=0; i<BUFFERSIZE*NUM_OF_CHANNELS; i++) //initialize input buffer
    {
        inputbuffer[i] = 0.f;
    }
    
    //GUI:
    //-------------------------------------------------
//gui0
    gui0 = new ofxUICanvas();
    
    gui0->addSlider("volume", 0.0, 1.0, 0.5, 70, 20);
    
    ofAddListener(gui0->newGUIEvent,this,&testApp::guiEvent);
    gui0->autoSizeToFitWidgets();
    
//gui1 bitcrusher
    gui1 = new ofxUICanvas();
    gui1->addLabel("Bitcrusher");
    gui1->setPosition(0, 40);
    
    gui1->addIntSlider("Bitdepth", 2, 8, 8, 70, 20);
    gui1->addToggle("Biton", false, 20, 20);
    
    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
    gui1->autoSizeToFitWidgets();
    
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e){
    
	string name = e.widget->getName();
    //amp
    if(name == "volume")
    {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
        amp.setOutputVolume(slider->getScaledValue());
    }
    //bitcrusher
    if(name == "Bitdepth")
    {
		ofxUIIntSlider *slider = (ofxUIIntSlider *) e.widget;
        bitcrusher.setBitdepth(slider->getScaledValue());
    }
    
    if(name == "Biton"){ //toggle Biton turns the effect on/off
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        bitcrusher.setOnOff(toggle->getValue());
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
}
//--------------------------------------------------------------
void testApp::audioIn(float *input, int bufferSize, int nChannels){
    
    for(int i=0; i<nChannels; i++)
    {
        for(int x=0; x<bufferSize; x++)
        {
            inputbuffer[x*nChannels+i] = input[x*nChannels+i]; //fill input buffer with *input
            
        //bitcrusher
            if(bitcrusher.IsOn()) //toggle Biton turns the effect on/off
            {
            inputbuffer[x*nChannels+i] = bitcrusher.process(inputbuffer, (x*nChannels+i));
            }
        }
    }
    
}
//--------------------------------------------------------------
void testApp::audioOut(float *output, int bufferSize, int nChannels){
    for(int i=0; i<nChannels; i++)
    {
        for(int x=0; x<bufferSize; x++)
        {
            output[x*nChannels+i] = 0.f; //initialize output
            output[x*nChannels+i] = inputbuffer[x*nChannels+i]; //fill output with input buffer
            amp.process(output, (x*nChannels+i));
        }
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::exit(){
    soundStream.stop();
    delete inputbuffer;
}
