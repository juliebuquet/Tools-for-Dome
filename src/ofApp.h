#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOscQueryServer.h"
#include "CirclesRenderer.h"
#include "Material.h"
#include "Cube.h"
#include "Swarm.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGuiGroup.h"
#include "Camera.h"
#include "ofEasyCam.h"
#include "ofxgamecamera.h"
#include "ofxjoystick.h"
#include <vector>
//#include "SDL/SDL.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxCvColorImage.h"
#include "ofxCvGrayscaleImage.h"




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
          void drawAxes();
          void exit();

          //void update_Dome();



         void moveMouse(int x, int y);
		void keyPressed  (int key);

        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);

		
		void vSyncChanged(bool & vSync);

		ofxPanel gui;
		ofParameter<bool> vSync;
        ofParameter<int> VBAP;
		ofParameterGroup parameters;
		ofXml settings;
		CirclesRenderer renderer1,renderer2;
		ofTrueTypeFont font;
        ofVec3f view;
        ofVec3f base;
        ofVec3f base1;
        ofVec3f base2;
        ofParameter<ofVec3f> Origine;
        ofParameter<float> RotX;
        ofParameter<float> RotY;
        ofParameter<float> RotZ;
        ofParameterGroup Swarm2;
        ofParameter<ofVec3f> Cartesian;
        ofParameter<ofVec3f> Cartesian_1;
        ofParameter<ofVec3f> Cartesian_2;

        struct Dome {
            ofVec3f position;

             ofParameter<ofVec3f> pos;
             ofParameterGroup para_dome;



        };
ofxJoystick joy_;



void drawPointCloud();
ofxKinect kinect;

#ifdef USE_TWO_KINECTS
    ofxKinect kinect2;
#endif

    ofxCvColorImage colorImg;

    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image

    ofxCvContourFinder contourFinder;

    bool bThreshWithOpenCV;
    bool bDrawPointCloud;

    int nearThreshold;
    int farThreshold;

    int angle;

    // used for viewing the point cloud
ofEasyCam easyCam;



    //***************************************************//
    //     This is where we setup our OSCQuery Server:   //
    ofxOscQueryServer server; //We will set it up in ofApp.cpp
    //***************************************************//

        ofTrueTypeFont verdana;

        Camera cam;
        ofEasyCam cam2;
        ofxGameCamera cam3;

    bool bShowHelp;

        std::vector<Cube*> cubes;
        std::vector<Material*> materials;

        swarm nodeSwarm;
        swarm nodeSwarm_1;
        swarm nodeSwarm_2;

        ofxAssimpModelLoader Model;

        bool init;

        std::vector<ofVec3f> Domes;
       // std::vector<ofVec3f> bb;
        ofParameterGroup D;
        ofParameter<ofVec3f> _Domes;





};
