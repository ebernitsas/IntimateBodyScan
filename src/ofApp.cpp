#include "ofApp.h"



int row= 0;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableDepthTest();
    cam.setDistance(8000);
    cam.setFarClip(20000);
    
    // start kinect, open ports
    kin.setupKinect();
    
    // this "linking" should prevent having to pass it in below...
    gst.linkSkeleton(kin.skeleton, kin.activeSkeleton);
    

    
    generalControls.setName("General Controls");
    generalControls.add(reset.set("Reset", false));

    panel.setup();
    panel.add(generalControls);

    plane.set(4000., 4000.);
    plane.setPosition(0, 0, 0);
    

    
    //csv.createFile(ofToDataPath(fileName));
    
    font.load("DIN.otf", 14);
    
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    
    image.load(ofToDataPath("fingerprint.png"));
    image.resize(15,15);
    csv.loadFile(ofToDataPath("kinectData.csv"));
    ofSetColor(100,0,0);
    
    
    
    
    faceActivatedChanged = false;
    faceActivated = true;
    
    
    rangeZ = maxZ - minZ;
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // request all joints from max every 2 sec
    kin.requestAllJoints(2);
    
    // update the physics and hits of all joints
    kin.updateAllJoints();
    
    // re-evaluate the state of the skeleton / joints (actively being tracked?)
    kin.updateState();
    
    // process gestures and notify max of begin / end of recording
    gst.processSkeleton(kin.skeleton, kin.activeSkeleton);
    
    // update spatialized audio --> send to max volume levels for each buffer
    gst.playLineSpace(kin.skeleton, kin.activeSkeleton);
    
    
    if (!faceActivated && faceActivatedChanged == true){
        for (int i = 0; i < csv.numRows; i++){
            if (csv.getInt(i,2) > maxX) maxX = csv.getInt(i,2);
            if (csv.getInt(i,2) < minX) minX = csv.getInt(i,2);
            if (csv.getInt(i,1) > maxY) maxY = csv.getInt(i,1);
            if (csv.getInt(i,1) < minY) minY = csv.getInt(i,1);
            if (csv.getInt(i,0) > maxZ) maxZ = csv.getInt(i,0);
            if (csv.getInt(i,0) < minZ) minZ = csv.getInt(i,0);
            
            ofVec3f vert((csv.getInt(i,2)-500)/2,(csv.getInt(i,1)+900)/2, csv.getInt(i,0));
            mesh.addVertex(vert);
            
            mesh.addColor(ofFloatColor(0.5, 0.0, 0.0, 0.5)); // Red
            
        }
        
    }
    
    else if (faceActivatedChanged) mesh.load(ofToDataPath("face.ply"));
    
    faceActivatedChanged = false;
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString("press p for points", 30, 60);
    ofDrawBitmapString("press x for scribble", 30, 70);
    ofDrawBitmapString("press l for lines", 30, 80);
    
    if (faceActivated == true){
        ofColor centerColor = ofColor(255, 255, 255);
        ofColor edgeColor(0, 0, 0);
        ofColor red(100,0,0);
        ofSetColor(100,0,0);
        //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
        glPointSize(5);
        
        easyCam.begin();
        ofPushMatrix();
        ofScale(1, -1, -1);
        ofTranslate(0, 0, -1000);
        ofEnableDepthTest();
        //ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
        mesh.enableColors();
        mesh.addColor(red);
        
        mesh.draw();
        ofPopMatrix();
        easyCam.end();
        
        ofDrawBitmapString("face", 30, 45);
    }
    
    
    else {
        ofColor centerColor = ofColor(85, 78, 68);
        ofColor edgeColor(0, 0, 0);
        //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
        glPointSize(6);
        easyCam.begin();
        ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
        mesh.draw();
        ofPopMatrix();
        easyCam.end();
        
        ofDrawBitmapString("full body", 30, 45);
        
    }
    

    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'a' || key == 'A'){
        int x = kin.skeleton["lefthand"].avgPosition.x;
        int y = kin.skeleton["lefthand"].avgPosition.y;
        int z = kin.skeleton["lefthand"].avgPosition.z;
        
        csv.setInt(row, 0, x);
        csv.setInt(row, 1, y);
        csv.setInt(row, 2, z);
        row++;
        
    }
    
    if (key == 's'){
        csv.saveFile(ofToDataPath("kinectData.csv"));
    }
    
    if (key == 'x'){
        mesh.setMode(OF_PRIMITIVE_LINE_STRIP_ADJACENCY);
    }
    if (key == 'l'){
        mesh.setMode(OF_PRIMITIVE_LINES);
    }
    
    if (key == 'p') {
        mesh.setMode(OF_PRIMITIVE_POINTS);
        
    }
    
    if (key == 'f'){
        mesh.clear();
        if (faceActivated == false) faceActivated = true;
        else faceActivated = false;
        faceActivatedChanged = true;
        
    }
    

//    if (key == 'f') ofToggleFullscreen();
//    
//    // reset the system
//    if (key == 'r') {
//        gst.resetSystem();
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
