#pragma once

#include "ofMain.h"
#include "kinectOsc.h"
#include "ofxOsc.h"
#include "kinectJoint.h"
#include "gestureRecognition.h"
#include "ofxGui.h"
#include "ofxCsv.h"

using namespace wng;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    kinectRecorder kin;
    gestureProcessor gst;
    
    ofParameter<bool> reset;

    ofParameterGroup generalControls;

    ofxPanel panel;
    
    ofEasyCam cam;
    
    ofPlanePrimitive plane;
    
    ofxCsv csv;
    
    ofTrueTypeFont		font;
    
    
    ofMesh mesh;
    ofEasyCam easyCam;
    
    bool faceActivated;
    bool faceActivatedChanged;
    
    int minX = 10000;
    int maxX = 0;
    int minY = 10000;
    int maxY = 0;
    int minZ = 10000;
    int maxZ = 0;
    
    float transp;
    int rangeZ;
    ofImage image;
    
    string fileName = "kinectData.csv";


};
