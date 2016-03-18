//
//  soundLine.h
//  soundscaping_v2_0
//
//  Created by Ben Snell on 12/13/15.
//
//

#ifndef __soundscaping_v2_0__soundLine__
#define __soundscaping_v2_0__soundLine__

#include "ofMain.h"

class soundLine {
    
public:
    
    ofPolyline rawLine;         // stores the raw line
    ofPolyline resampledLine;   // stores the resampled line
    vector<int> times;          // stores the time for each point
    int duration;               // stores the total duration of the recording
    unsigned long startTime;    // relative to the app elapsed time
    
    void reset();
    
    // call when done adding to polyline --> this resamples the line and smoothes it
    void resampleLine(bool bSmooth);
    
    // once a soundline is made, it keeps looping and the position changes with the position of the original recording -- calling this will return the current time within the track
    int getCurrentPlaybackTime();
    
    ofVec3f getCurrentPlaybackPoint();
    
    // returns the distance (unscaled) to the current playback point (dependent on this time) from the position provided
    float getDistToPlaybackPoint(ofVec3f jointPosition);
    
};

#endif /* defined(__soundscaping_v2_0__soundLine__) */
