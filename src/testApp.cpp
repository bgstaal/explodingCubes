#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(0, 0, 0);
	ofSetFrameRate(100.0f);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	
	rotationX = 0.0f;
	
	glEnable(GL_DEPTH_TEST);
	
	camera.setNearClip(0.1f);
	camera.setFarClip(100.0f);
	camera.setPosition(0.0f, 0.0f, 20.0f);
	
	light.enable();
	light.setPointLight();
	light.setPosition(0.0f, 0.0f, 0.0f);
	light.setScale(0.0f);
	light.setAmbientColor(ofFloatColor(0.0f, 0.0f, 0.0f, 1.0f));
	light.setDiffuseColor(ofFloatColor(1.0f, 1.0f, 1.0f));
	light.setSpecularColor(ofFloatColor(0.0f, 0.0f, 0.0f));
	
	for (int i = 0; i < NUM_OBJECTS; i++)
	{
		MyObj *obj = &objects[i];
		obj->size = ofRandom(.5f);
		//obj->setPosition(ofRandom(-2.0f, 2.0f), ofRandom(-2.0f, 2.0f), ofRandom(-4.0f, 4.0f));
		float velMax = .25;
		float velMin = velMax*-1;
		float x = ofRandom(velMin, velMax);
		float y = ofRandom(velMin, velMax);
		float z = ofRandom(velMin, velMax);
		
		
		obj->rotationSpeed = ofPoint(x*60, y*60, z*60);
		obj->velocity = ofPoint(x, y, z);
		
		float randNum = ofRandom(1.0);
		
		if (randNum > .9f)
		{
			obj->material.setDiffuseColor(ofFloatColor(1.0f, ofRandom(0.4, 0.9f), ofRandom(0.4, 0.8f)));
		}
		else if (randNum > .8f)
		{
			obj->material.setDiffuseColor(ofFloatColor(0.3f, ofRandom(0.5, 1.0f), ofRandom(0.4, 0.7f)));
		}
		else 
		{
			obj->material.setDiffuseColor(ofFloatColor(1.0f, 1.0f, 1.0f));
		}
		
		obj->material.setAmbientColor(ofFloatColor(0.0f, 0.0f, 0.0f));
		obj->material.setSpecularColor(ofFloatColor(0.0f, 0.0f, 0.0f));
	}
	
	bool started = false;
}

//--------------------------------------------------------------
void testApp::update()
{
 	float elapsedTime = ofGetElapsedTimef();
	float elapsedTimeSinceLastFrame = elapsedTime - prevTime;
	prevTime = elapsedTime;
	
	float delta = elapsedTimeSinceLastFrame*30;
	float decay = .997;
	
	if (started)
	{
		for (int i = 0; i < NUM_OBJECTS; i++)
		{
			MyObj *obj = &objects[i];
			obj->roll(obj->rotationSpeed.x*delta);
			obj->tilt(obj->rotationSpeed.y*delta);
			obj->move(obj->velocity.x*delta, obj->velocity.y*delta, obj->velocity.z*delta);
			obj->velocity.x *= decay;
			obj->velocity.y *= decay;
			obj->velocity.z *= decay;
			obj->rotationSpeed.x *= decay;
			obj->rotationSpeed.y *= decay;
			obj->rotationSpeed.z *= decay;
		}
		
		camera.move(0.0f, 0.0f, -0.04f*delta);
		sceneRotation.y += 1.0f*delta;
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	
	camera.begin();
		glPushMatrix();
	
			glRotatef(sceneRotation.y, 0.0f, 1.0f, 0.0f);
	
			//light.enable();
			glDisable(GL_COLOR_MATERIAL);
			light.draw();
			
			for (int i = 0; i < NUM_OBJECTS; i++)
			{
				MyObj *obj = &objects[i];
				
				obj->material.begin();
				obj->draw();
				obj->material.end();
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
void testApp::mousePressed(int x, int y, int button)
{
	started = true;
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