//
//  gestureRecognition.h
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/6/15.
//
//

#ifndef __soundscaping_v2_0__gestureRecognition__
#define __soundscaping_v2_0__gestureRecognition__

#include "ofMain.h"
#include "kinectJoint.h"
#include "kinectGestures.h"
#include "ofxOsc.h"
//#include "soundParticle.h"
#include "soundLine.h"
#include "ofxGui.h"

class gestureProcessor {
    
public:
    
    // ---------------------
    // ---- CONSTRUCTION ---
    // ---------------------
    
    gestureProcessor();
    
    void linkSkeleton(map<string, joint> skeleton_, bool activeSkeleton_);
    // pass original object to function (i.e. <skeleton>)
    
    map<string, joint>* skeleton;
    // pointer to store address of original skeleton
    
    bool* activeSkeleton;
    
    // ---------------------
    // ------ GESTURES -----
    // ---------------------
    
    // process skeleton -- check for all gestures
    void processSkeleton(map<string, joint> skeleton_, bool activeSkeleton_);
    
    // gestures of interest (could eventually be a vector of them)
    gesture myGesture;
    
    // ---------------------
    // - GENERAL RECORDING -
    // ---------------------
    
    bool recordingState = false;
    unsigned long lastLineOnTime = 0; // ms
    unsigned long lastLineOffTime = 0;
    unsigned long bounceOnTime = 1000;
    unsigned long bounceOffTime = 500;
    unsigned long maxRecordingTime = 10000;
    
    // ---------------------
    // ---- LINE SPACE -----
    // ---------------------
    
    // determine whether to begin or end recording and send this to Max
    void updateLineSpace(map<string, joint> skeleton_, bool activeSkeleton_);
    
    string recordingJoint = "righthand";
    
    // send volumes of each buffer to max
    void playLineSpace(map<string, joint> skeleton_, bool activeSkeleton_);
    
    string playbackJoint = "righthand";
    
    soundLine thisLine;
    unsigned long timeZero;
    vector<soundLine> allLines;
    int bufferCounter = 1; // start with 1 not zero
    
    float maxDistance = 3000.;
    float volumeExponent = 4.;
    
    void drawAudioPaths();
    
    // ---------------------
    // ---- PIXEL SPACE ----
    // ---------------------
    
    void updatePixelSpace(gesture gestureOfInterest, map<string, joint> skeleton_, bool activeSkeleton_);

    ofVec3f spaceLowerCorner = ofVec3f(-1000., -1000., 2000.);
    float spaceSideLength = 2000.;
    int nSideDivisions = 4;
    
    map<int, ofVec3f> soundParticles;
    ofVec3f currentPoint;
    int currentBufferNumber = 0;

    void playAudioPixelSpace(map<string, joint> skeleton_, bool activeSkeleton_);
    
    // ---------------------
    // ------- TO MAX ------
    // ---------------------
    
    // communication to max
    ofxOscSender toMax;
    int maxPort = 1818;
    
    void resetSystem();
    
    // ---------------------
    // -------- GUI --------
    // ---------------------
    
//    ofParameterGroup gstControls;
//    ofParameter<float> volumeExponent;
//    ofParameter<float> maxDistance;
    
};

#endif /* defined(__soundscaping_v2_0__gestureRecognition__) */
