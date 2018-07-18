#pragma once
#define _KEY_FRONT 'z'
#define _KEY_BACK 's'
#define _KEY_LEFT  'q'
#define _KEY_RIGHT  'd'

#define PI 3.14159265
#include "ofMain.h"

class Camera
{
    public:
        Camera();
        virtual ~Camera();

        void init(int windowWidth, int windowHeight);
        void applyMatrix();
        void update(int x, int y);
        void mousePressed(int x, int y);
        void keyPressed(int key);
        //void keyReleased(int key);
        void drawAim();
         ofVec3f campos;
         ofVec3f  base;
         float corectx;
         float corectz;
         bool rot;
         ofParameterGroup par;
         ofParameter<ofVec3f> Origine;

    private:
        int width;
        int height;

        float rotX;
        float rotY;

        float aim_distz;
        float aim_distx;

        int teta;
        int betax;
        int betaz;
        float distx;
        float distz;


        // Previous mouse position
        int lastX1;
        int lastY1;



};
