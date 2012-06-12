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
	camera.setPosition(0.0f, 0.0f, 20.0f);
	
	light.enable();
	light.setSpotlight();
	
	light.setPosition(0.0f, 0.0f, 0.0f);
	light.setScale(0.0f);
	light.setAmbientColor(ofFloatColor(0.0f, 0.0f, 0.0f, 1.0f));
	light.setDiffuseColor(ofFloatColor(1.0f, 1.0f, 1.0f));
	light.setSpecularColor(ofFloatColor(1.0f, 1.0f, 0.0f));
	
	for (int i = 0; i < NUM_OBJECTS; i++)
	{
		MyObj *obj = &objects[i];
		obj->size = ofRandom(.5f);
		obj->setPosition(ofRandom(-2.0f, 2.0f), ofRandom(-2.0f, 2.0f), ofRandom(-4.0f, 4.0f));
		obj->rotationSpeed = ofPoint(ofRandom(-2.0f, 2.0f), ofRandom(-2.0f, 2.0f), ofRandom(-4.0f, 4.0f));
		obj->velocity = ofPoint(ofRandom(-.1f, .1f), ofRandom(-.1f, .1f), ofRandom(-.1f, .1f));
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < NUM_OBJECTS; i++)
	{
		MyObj *obj = &objects[i];
		obj->roll(obj->rotationSpeed.x);
		obj->tilt(obj->rotationSpeed.y);
		obj->move(obj->velocity.x, obj->velocity.y, obj->velocity.z);
	}
	
	sceneRotation.y += 0.3f;
	camera.move(0.0f, 0.0f, -0.1f);
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofSetColor(1, 0, 0);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	camera.begin();
	
	glPushMatrix();
	glRotatef(sceneRotation.y, 0.0f, 1.0f, 0.0f);
	
	light.enable();
	light.draw();
	
	ofSetColor(255, 255, 255);
	//myObj.draw();
	for (int i = 0; i < NUM_OBJECTS; i++)
	{
		objects[i].draw();
	}
	glPopMatrix();
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