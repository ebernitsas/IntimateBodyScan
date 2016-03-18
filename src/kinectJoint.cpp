//
//  kinectJoint.cpp
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/3/15.
//
//

#include "kinectJoint.h"

// constructor
// How do you pass a name into joint while being able to construct a map elsewhere outside of this class using map<string, joint> ?
joint::joint() {
    
    // why won't this work?
//    hits = {{"up", false}, {"down", false}, {"left", false}, {"right", false}, {"forward", false}, {"back", false}};
    
    // initialize map with all values to false
    string hitNames[6] = { "up", "down", "left", "right", "forward", "back" };
    for (int i = 0; i < 6; i++) {
        
//        hits.insert(std::pair<string, bool>(hitNames[i], false));
//        m_deck.insert(std::pair<int, Card>(0, Card(Card::NOVALUE, Card::NOFACE)));
        
        hits[hitNames[i]] = false;
    }
    
    resetPhysics();
}

// -------------------------------------------------------------------

// destructive retrieval of hits
bool joint::getHit(string jointName) {
    
    if (hits[jointName] == true) {
        hits[jointName] = false;
        return true;
    } else {
        return false;
    }
}

// -------------------------------------------------------------------

void joint::resetPhysics() {
    
    position = ofVec3f(0, 0, 0);
    prevPosition = ofVec3f(0, 0, 0);
    avgPosition = ofVec3f(0, 0, 0);
    prevAvgPosition = ofVec3f(0, 0, 0);
    
    velocity = ofVec3f(0, 0, 0);
    prevVelocity = ofVec3f(0, 0, 0);
    avgVelocity = ofVec3f(0, 0, 0);
    prevAvgVelocity = ofVec3f(0, 0, 0);
    
    acceleration = ofVec3f(0, 0, 0);
    prevAcceleration = ofVec3f(0, 0, 0);
    avgAcceleration = ofVec3f(0, 0, 0);
    prevAvgAcceleration = ofVec3f(0, 0, 0);
}

// -------------------------------------------------------------------

void joint::setPosition(ofVec3f position_) {
    
    // set previous position
    prevPosition = position;
    
    // set position
    position = position_;
    
    // update the lastUdpateTime
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

void joint::calcAvgPosition(ofVec3f newPosition_) {
    
    prevAvgPosition = avgPosition;
    
    avgPosition = avgPosition * (1. - avgWeight) + newPosition_ * avgWeight;
    
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

void joint::setVelocity(ofVec3f velocity_) {
    
    prevVelocity = velocity;
    
    velocity = velocity_;
    
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

void joint::calcAvgVelocity(ofVec3f newVelocity_) {
    
    prevAvgVelocity = avgVelocity;
    
    avgVelocity = avgVelocity * (1. - avgWeight) + newVelocity_ * avgWeight;
    
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

void joint::setAcceleration(ofVec3f acceleration_) {
    
    prevAcceleration = acceleration;
    
    acceleration = acceleration_;
    
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

void joint::calcAvgAcceleration(ofVec3f newAcceleration_) {
    
    prevAvgAcceleration = avgAcceleration;
    
    avgAcceleration = avgAcceleration * (1. - avgWeight) + newAcceleration_ * avgWeight;
    
    lastUpdateTime = ofGetElapsedTimeMillis();
}

// -------------------------------------------------------------------

// set all new values and averages for a joint
void joint::setAllPhysics(ofVec3f position_, ofVec3f velocity_, ofVec3f acceleration_) {
    
    setPosition(position_);
    calcAvgPosition(position_);
    
    setVelocity(velocity_);
    calcAvgVelocity(velocity_);
    
    setAcceleration(acceleration_);
    calcAvgAcceleration(acceleration_);
    
}



