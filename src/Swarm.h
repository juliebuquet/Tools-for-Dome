#pragma once

#include "ofParameterGroup.h"
#include "ofParameter.h"
#include "ofMain.h"

#define SPRING_CONSTANT 0.1f
#define MAX_VELOCITY 30.0f

// This 'swarm' object demonstrates a simple particle system
//  with 'simple harmonic motion'
class swarm : public ofNode {
	struct particle {
		ofVec3f position;
		ofVec3f velocity;
		ofColor color;

        ofParameterGroup parameters;
         ofParameter<ofVec3f> pos;
         ofParameter<ofVec3f> Origine;



	};

	public:
		swarm();
        void init(int nParticles, float positionDispersion, float velocityDispersion, string name, ofVec3f dome, ofVec3f dome1, ofVec3f dome2);
        void customDraw();
        void updatepos(ofVec3f pos);
		ofLight light;
		ofMaterial material;
         ofParameterGroup param;
         ofVec3f poscam;
         ofVec3f _dome;
         ofVec3f _dome_1;
         ofVec3f _dome_2;

	protected:
		// we call this update function ourselves
		//  at the beginning of customDraw
        void update();

		// objects
		vector<particle>particles;
};
