//
//  kinectGestures.cpp
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/6/15.
//
//

#include "kinectGestures.h"

//
//// just update the state of the gesture (don't do any debugging here)
//void gesture::updateGesture(map<string, joint> skeleton_) {
//    
//    // find the distance from the right hand to the left hand
//    float dist = skeleton_["righthand"].position.distance(skeleton_["lefthand"].position);
////    cout << "dist " << dist;
//    
//    // update the gesture states
//    float distanceOnThreshold = 125.;
//    float distanceOffThreshold = 300.;
//    if (dist < distanceOnThreshold && dist > 0) { // cull out distances of zero
//        gestureState = true;
//        
////        cout << "   gesture state is ON";
//        
//    } else if (dist > distanceOffThreshold) {
//        gestureState = false;
//        
////        cout << "    gesture state is OFF";
//    }
//    
//    // update the flags
//    if (gestureState && !prevGestureState) {
//        flagON = true;
//        
////        cout << "    flag ON";
//        
//    } else if (!gestureState && prevGestureState) {
//        flagOFF = true;
//        
////        cout << "    flag OFF";
//    }
//    
////    cout << "this gesture state " << gestureState << "  prev gesture state " << prevGestureState << endl;
//
//    
////    cout << "    prev gest state used to be " << prevGestureState;
//    
//    prevGestureState = gestureState;
//    
////    cout << ", but now it's " << prevGestureState << endl;
//
//}


// just update the state of the gesture (don't do any debugging here)
void gesture::updateGesture(map<string, joint> skeleton_) {
    
    float leftHandHeight = skeleton_["lefthand"].position.y;
    float headHeight = skeleton_["head"].position.y;
    
    // update the gesture states
    if (leftHandHeight > (headHeight + 100.)) { // cull out distances of zero
        gestureState = true;
        
    } else if (leftHandHeight < (headHeight - 100.)){
        gestureState = false;
    }
    
    // update the flags
    if (gestureState && !prevGestureState) {
        flagON = true;
        
    } else if (!gestureState && prevGestureState) {
        flagOFF = true;
        
    }
    
    prevGestureState = gestureState;
    
}

//gesture::gesture(map<string, joint> skeleton_) {
//    
//    // get address of original skeleton and store it in a pointer
//    skeleton = &skeleton_;
//}

//// closeness of jointA and jointB
//void gesture::createGestureByProximity(map<string, joint> skeleton_, string jointA_, string jointB_) {
//    
//    jointA = jointA_;
//    jointB = jointB_;
////        createGesture = &createGestureByProximity;
//    
//    
//    
//    
//    
//    
//}
//
//// jointA further along projected axis than jointB
//void gesture::createGestureByHeight(map<string, joint> skeleton_, string jointA, string jointB, ofVec3f projectedAxis) {
//    
//    
//
//
//    
//}
//
//// direction is from jointA to jointB (ray AB)
//void gesture::createGestureByDirection(map<string, joint> skeleton_, string jointA, string jointB, ofVec3f direction) {
//    
//    
//    
//    
//}

// -----------------------------------------------------------------------

// just update the state of the gesture (don't do any debugging here)
//void gesture::updateGesture(map<string, joint> skeleton_) {
//    
//    if (skeleton_["righthand"].position.distance(skeleton_["lefthand"].position) < 100. && !gestureState) {
//    
//        setGestureState(true);
//    
//    } else if (skeleton_["righthand"].position.distance(skeleton_["lefthand"].position) > 100. && gestureState) {
//        
//        setGestureState(false);
//        
//    }
//    
//    prevGestureState = gestureState;
//
////    cout << "current Gstate " << gestureState << "   prev Gstate " << prevGestureState << "   flag on is " << flagON << "   flag off is " << flagOFF << endl;
//    
//    
//
//    
//}


//void gesture::updateGesture(map<string, joint> skeleton_, bool activeSkeleton_) {
//    
//    activeSkeleton__ = activeSkeleton_;
//    
//    handsTogether(skeleton_);
//    
//    lastGestureOnTime = ofGetElapsedTimeMillis();
//    
//}
//
//// -----------------------------------------------------------------------
//
//void gesture::handsTogether(map<string, joint> skeleton_) {
//    
//    if (skeleton_["righthand"].position.distance(skeleton_["lefthand"].position) < 100. && !gestureState) {
//        
//        setGestureState(true);
//        
//    }
//    if ((ofGetElapsedTimeMillis() > (lastGestureOnTime + 3000))){
//        
//        setGestureState(false);
//    }
//}

// -----------------------------------------------------------------------

//void gesture::setGestureState(bool bState) {
//    
//    gestureState = bState;
//    
//    // change appropriate flags
//    if (gestureState && !prevGestureState) {
//        
//        flagON = true;
//        
//    } else if (!gestureState && prevGestureState) {
//        
//        flagOFF = true;
//        
//    }
//}

// -----------------------------------------------------------------------

bool gesture::getFlagON() {
    
    bool tempFlag = flagON;
    flagON = false;
    
    
//    cout << "temp flag is " << ofToString(tempFlag) << endl;
    return tempFlag;
}

// -----------------------------------------------------------------------

bool gesture::getFlagOFF() {
    
    bool tempFlag = flagOFF;
    flagOFF = false;

    return tempFlag;
}


