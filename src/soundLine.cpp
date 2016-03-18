//
//  soundLine.cpp
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/13/15.
//
//

#include "soundLine.h"

void soundLine::reset() {
    
    rawLine.clear();
    resampledLine.clear();
    times.clear();
    duration = 0;
    
}

// ----------------------------------------------------------------------

void soundLine::resampleLine(bool bSmooth) {
    
    int pointCount = times.size(); // keep count the same
    ofPolyline newLine = rawLine.getResampledByCount(pointCount);
    
    if (bSmooth) {
        
        newLine = newLine.getSmoothed(15, 0.5);
    }
    
    resampledLine = newLine;
}

// ----------------------------------------------------------------------

int soundLine::getCurrentPlaybackTime() {
    
    unsigned long thisTime = ofGetElapsedTimeMillis() - startTime;
    int playbackTime = (int)(thisTime % duration);
    
    return playbackTime;
}

// ----------------------------------------------------------------------

ofVec3f soundLine::getCurrentPlaybackPoint() {
    
    int playbackTime = getCurrentPlaybackTime();

    float amtThruLine = (float)playbackTime / (float)duration;

    ofVec3f playbackPoint = resampledLine.getPointAtPercent(amtThruLine);

    return playbackPoint;
}

// ----------------------------------------------------------------------

float soundLine::getDistToPlaybackPoint(ofVec3f jointPosition) {
    
//    int playbackTime = getCurrentPlaybackTime();
//    
//    float amtThruLine = (float)playbackTime / (float)duration;
//    
//    ofVec3f playbackPoint = resampledLine.getPointAtPercent(amtThruLine);
//    
//    float distToPt = playbackPoint.distance(jointPosition);
    
    float distToPt = jointPosition.distance(getCurrentPlaybackPoint());
    
    return distToPt;
}
