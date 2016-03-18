//
//  kinectGestures.h
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/6/15.
//
//

#ifndef __soundscaping_v2_0__kinectGestures__
#define __soundscaping_v2_0__kinectGestures__

#include "ofMain.h"
#include "kinectJoint.h"

class gesture {
    
public:
    
//    map<string, joint>* skeleton;
    // pointer to store address of original skeleton
    
//    gesture(map<string, joint> skeleton_);
    // pass original object to function (i.e. <skeleton>)
    
    // call this function to update the gesture each frame
    void updateGesture(map<string, joint> skeleton_);
    
    void setGestureState(bool bState);
    // holds current and previous state of gesture (ON or OFF)
    bool gestureState = false;
    bool prevGestureState = false;
    // flags to hold switch from on to off and vice versa

    bool getFlagON();
    bool getFlagOFF();
    
    unsigned long timeZero;
    
    
    // AVAILABLE GESTURES:
    void handsTogether(map<string, joint> skeleton_);
    unsigned long lastGestureOnTime;
    
//    // MODULAR SYSTEM OF AVAILABLE GESTURES
//    void createGestureByProximity(map<string, joint> skeleton_, string jointA_, string jointB_);
//    void createGestureByHeight(map<string, joint> skeleton_, string jointHigh, string jointLow, ofVec3f projectedAxis);
//    void createGestureByDirection(map<string, joint> skeleton_, string jointA, string jointB, ofVec3f direction);
////    void (*createGesture)(map<string, joint> skeleton_, string jointA_, string jointB_, ofVec3f vecOfInterest);
//    string jointA;
//    string jointB;
    
private:
    
    bool flagON = false;
    bool flagOFF = false;
    
    
};

#endif /* defined(__soundscaping_v2_0__kinectGestures__) */
