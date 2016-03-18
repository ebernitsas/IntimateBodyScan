//
//  kinectJoint.h
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/3/15.
//
//

#ifndef __soundscaping_v2_0__kinectJoint__
#define __soundscaping_v2_0__kinectJoint__

#include "ofMain.h"

class joint {
    
public:
    
    // constructor
    joint();
    
    // ---------------------
    // ------ PHYSICS ------
    // ---------------------
    
    // physics
    ofVec3f position;
    ofVec3f prevPosition;
    ofVec3f avgPosition;
    ofVec3f prevAvgPosition;
    
    ofVec3f velocity;
    ofVec3f prevVelocity;
    ofVec3f avgVelocity;
    ofVec3f prevAvgVelocity;
    
    ofVec3f acceleration;
    ofVec3f prevAcceleration;
    ofVec3f avgAcceleration;
    ofVec3f prevAvgAcceleration;
    
    // only update physics with these methods (these will also set the prevoius values)
    void setPosition(ofVec3f position_);
    void calcAvgPosition(ofVec3f newPosition_); // new position is the new position to add to the running average
    void setVelocity(ofVec3f velocity_);
    void calcAvgVelocity(ofVec3f newVelocity_);
    void setAcceleration(ofVec3f acceleration_);
    void calcAvgAcceleration(ofVec3f newAcceleration_);
    
    // for weighting the averages
    float avgWeight = 0.5; // 0.5 = equally weight new value with running average
    
    void setAllPhysics(ofVec3f position_, ofVec3f velocity_, ofVec3f acceleration_);
    
    void resetPhysics();
    
    // ---------------------
    // ------- HITS --------
    // ---------------------
    
    // hits
    map<string, bool> hits;

    bool getHit(string jointName);
    
    // ---------------------
    // ------- STATE -------
    // ---------------------
    
    // boolean to know if joint is actively being tracked / updated
    bool bActive = false;
    
    // reference to know how relevant this information is
    unsigned long lastUpdateTime = 0;
    
};

#endif /* defined(__soundscaping_v2_0__kinectJoint__) */
