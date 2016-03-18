//
//  kinectOsc.h
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/2/15.
//
//

#ifndef __soundscaping_v2_0__kinectOsc__
#define __soundscaping_v2_0__kinectOsc__

#include "ofMain.h"
#include "ofxOsc.h"
#include "kinectJoint.h"
#include "kinectGestures.h"

class kinectRecorder { // more like a skeleton
    
public:
    
    kinectRecorder();
    
    // ---------------------
    // --- COMMUNICATION ---
    // ---------------------
    
    ofxOscReceiver receiver;
    int synapseIn = 12345; // could also use 12347
    
    ofxOscSender sender;
    int synapseOut = 12346;
    
    void setupKinect();
    
    // ---------------------
    // ---- JOINT DATA -----
    // ---------------------
    
    void updateAllJoints();
    map<string, joint> skeleton; // stores all joint information for one skeleton
    
    void requestAllJoints(int coordinateSystem = 2);
    // add the argument of the coordinate system to use for positions:
    // 1    _pos_body
    // 2    _pos_world
    // 3    _pos_screen
    
    unsigned long lastTime = -2000;
    
    string jointNames [15] = { "righthand", "lefthand", "rightelbow", "leftelbow", "rightfoot", "leftfoot", "rightknee", "leftknee", "head", "torso", "leftshoulder", "rightshoulder", "lefthip", "righthip", "closesthand" };
    
    // ---------------------
    // ------- STATE -------
    // ---------------------
    
    // updates states of joints (active or inactive) and of skeleton
    bool updateState(unsigned long maxTime = 1000);
    bool activeSkeleton = false;

    // ---------------------
    // ------ DRAWING ------
    // ---------------------
    
    void drawSkeleton();
    
    
};

#endif /* defined(__soundscaping_v2_0__kinectOsc__) */
