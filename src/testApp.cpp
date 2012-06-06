#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0, 0, 0);
	ofSetFrameRate(100.0f);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	
	rotationX = 0.0f;
	
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	camera.setNearClip(0.1f);
	camera.setFarClip(100.0f);
	camera.setPosition(0.0f, 0.0f, 10.0f);
	
	 light.enable();
	 light.setDirectional();
	 light.setPosition(0.0f, 0.0f, 150.0f);
	 light.setAmbientColor(ofFloatColor(0.0f, 0.0f, 0.0f, 1.0f));
	 light.setDiffuseColor(ofFloatColor(1.0f, 1.0f, 1.0f));
	 light.setSpecularColor(ofFloatColor(1.0f, 1.0f, 0.0f));
}

//--------------------------------------------------------------
void testApp::update(){
	
	myObj.roll(1.0f);
	myObj.tilt(1.0f);
	myObj.move(0.001f, 0.0f, 0.0f);
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofSetColor(1, 0, 0);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	camera.begin();
	
	light.enable();
	light.draw();
	
	ofSetColor(255, 255, 255);
	myObj.draw();
	camera.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}