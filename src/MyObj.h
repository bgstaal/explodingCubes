#pragma once

#include "ofMain.h"

class MyObj : public ofNode 
{
	public:
		virtual void customDraw();
		ofPoint rotationSpeed;
		ofPoint velocity;
		float size;
		ofMaterial material;
};

