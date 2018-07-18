#pragma once

#include "ofMain.h"
#include "ofxBezierSurface.h"
#include "Cube.h"
#include "Material.h"
#include "ofxgamecamera.h"
#include "ofxjoystick.h"
#include "Swarm.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawAxes();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxBezierSurface surface;
        ofImage img;
        ofTexture texture;
        ofXml xml;
        std::vector<Cube*> cubes;
        std::vector<Material*> materials;
        int counter;
        ofFbo fbo;
        ofxGameCamera cam3;
            ofxJoystick joy_;
            bool tex;
            ofTrueTypeFont verdana;

             swarm nodeSwarm;
             bool mode;
              bool mode1;

    
};
