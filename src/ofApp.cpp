#include "ofApp.h"
#include <X11/Xlib.h>
#include "ofxjoystick.h"
#include "SDL.h"
#include "ossia/include/ossia_export.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

#undef main
//--------------------------------------------------------------
void ofApp::setup(){


    //------------------------------------------------
//    joy_.setup(GLFW_JOYSTICK_1);
//    ofSetVerticalSync(true);

//    // this uses depth information for occlusion
//    // rather than always drawing things on top of each other
//    ofEnableDepthTest();

//    // this sets the camera's distance from the object
//    //cam2.setDistance(100);

//    ofSetCircleResolution(64);
//    bShowHelp = true;
//   // cam.init(ofGetWidth(),ofGetHeight());
//        init = true;
//        ofBackground(0,0,0);
//        ofEnableDepthTest();
//        ofEnableNormalizedTexCoords();
//        ofEnableAntiAliasing();
//        ofDisableArbTex();

//        ofTrueTypeFont::setGlobalDpi(72);
//        verdana.loadFont("verdana.ttf", 18, true, true, true);
//        verdana.setLineHeight(18.0f);
//        verdana.setLetterSpacing(1.037);

//        // Create cubes and their materials for the floor
//        Material* sand = new Material("sand.png");
//        materials.push_back(sand);
//        Material* stonebrick = new Material("stonebrick.png");
//        materials.push_back(stonebrick);
//        Material* mossy = new Material("stonebrick_mossy.png");
//        materials.push_back(mossy);
//        Cube* c;

//        Cube* d;
//        for (int i=0; i < 2; i++) {
//            for (int j=-20; j < 20; j++) {
//                for (int k=-20; k < 20; k++) {
//                    if (i==1){
//                        c = new Cube(sand);
//                    }else{
//                        c = new Cube(stonebrick);
//                    }
//                    c->move(j, -(i+1), k); //position of the cube
//                    cubes.push_back(c);
//                }
//            }
//        }

//        base[2]=0;// ball 1
//        base[0]=0;
//        base[1]=0;

//        base1[2]=10; //ball 2
//        base1[0]=1;
//        base1[1]=0;

//        base2[2]=-1; //ball3
//        base2[0]=10;
//        base2[1]=0;


//        //---------------------------------------------------------Create cubes and their materials
//    //    Material* tnt = new Material("tnt.png");
//    //    materials.push_back(tnt);
//    //    c = new Cube(tnt);
//    //    c->move(2, 0, -1);
//    //    cubes.push_back(c);



//    //    c= new Cube(tnt);
//    //    c->move(2, 0, -2);
//    //    cubes.push_back(c);



//    //    c = new Cube(mossy);
//    //    c->move(3, 0, -2);
//    //    cubes.push_back(c);

//    //    d = new Cube(mossy);
//    //    d->move(2, -1, -2);
//    //    cubes.push_back(d);

////-----------------------------------draw particles//-------------------------------------------------------------------------------------
//         nodeSwarm.init(50, 50, 10,"SWARM1",base,base1,base2);
//         ofDrawSphere(base, 1);// 1 is the radius, to correspond to i-score  1 unit is 1 radius of dome.

//        nodeSwarm_1.init(50, 50, 10,"SWARM",base,base1,base2);

//         nodeSwarm_2.init(50, 50, 10,"SWARm",base,base1,base2);


////--------------------------------------------------------Import 3D Model from Blender, cinema4D etc....--------------------------------------
//         /* Model.loadModel("HOTEL_PALAU.3ds", 20);
//         Model.setPosition(0, 0, 0);
//          Model.stopAllAnimations()*/;
//    //      Model.getTextureForMesh('stamm2.jpg');


////-------------------------------------------------------------------------------Parameter settings (sent to i-score)//---------------------------------------------------------------------
//  renderer1.setup("renderer");
//  renderer2.setup("renderer");
//  // Note that both Groups are named the same, in order to demonstrate
//  // ossia's behavior in the case of duplicated nodes (adds .1 to the name)


//  parameters.setName("settings");
//  //parameters.add(vSync.set("vSync",true));
//  //parameters.add(VBAP.set("1VBAP_2SCHOA_3HoaLib_4ADTB",0));
//  parameters.add(Origine.set("Origine",base));
//  parameters.add(RotX.set("Pitch",0));
//  parameters.add(RotY.set("Roll",0));
//  parameters.add(RotZ.set("Yaw",0));

//   //parameters.add(cam.par);
//  parameters.add(nodeSwarm.param);
//  Swarm2.setName("SWARM2");
//  int nb=5; // choose teh number of domes
//  for(int i=0;i<nb;i++){

//      Dome newDome;
//      ofVec3f B;
//      B[0]=floor(ofRandom(-20,20));
//      B[1]=0;
//      B[2]=floor(ofRandom(-20,20));

//      ofVec3f Base1;
//      Base1[0]=B[0];
//      Base1[1]= -1*B[2];
//      Base1[2]=B[1];
//      ofDrawSphere(B, 1);
//      stringstream ss;
//      ss << i;
//      string str = ss.str();
//      newDome.position = B;
//     newDome.para_dome.setName(str);
//      Swarm2.add( newDome.pos.set("Cartesian_"+str,Base1));


//      Domes.push_back(B);

//  }


//  parameters.add(Swarm2);


////  ofVec3f Base1;
////  Base1[0]=base1[0];
////  Base1[1]= -1*base1[2];
////  Base1[2]=base1[1];

////  ofVec3f Base;
////  Base[0]=base[0];
////  Base[1]= -1*base[2];
////  Base[2]=base[1];

////  ofVec3f Base2 ;
////  Base2[0]=base2[0];
////  Base2[1]= -1*base2[2];
////  Base2[2]=base2[1];
//// Swarm2.add(Cartesian.set("Cartesian",Base));
//// Swarm2.add(Cartesian_1.set("Cartesian_1",Base1));
//// Swarm2.add(Cartesian_2.set("Cartesian_2",Base2));






////  gui.setup(parameters);

//  // ^ All this above is just the same that we have in of's gui/ParameterGroupExample
//  // i.e. one does not have to change their ofApp structure to use ofxOscQuery,
//  // as long as it uses ofParameters and ofParameterGroups
//  //*********************************************************************************//



//  //*********************************************************************************//
//  //   This is where we setup our OSCQuery Server:
//  // NB this is the only change from of's gui/ParameterGroupExample
//  server.setup(parameters, 1213, 4477, "ofxOscQueryDemo");
//  // i.e. this will create an OSCquery server from 'parameters' ParameterGroup
//  // scan all sub-ParameterGroups and children Parameters recursively
//  // and expose the whole thing to ports 1233 for OSC and 4477 for Websocket
//  // All network communication (sending, receving, listening, queries and replies)
//  // will then be managed by the internal implementation of libossia
//  //*********************************************************************************//



//  //*********************************************************************************//
//  //  Some extra OSCQuery/ossia-specific attributes can be set later on
//  // They requires that we find the node for which we want to set those attributes
//  // This can be achieved with the findNode method, which accepts as argument:
//  // - the object name ofParameter(Group) to which the ossia node is attached
//  // - the OSC path of the node we want to access
//  // Then we have just to use the appropriate set(Attribute) methods
//  //
//  //server.findNode(renderer2.position).setMin(2).setMax(20);
////  server.findNode("/renderer/color/").setDescription("El Color maravilloso!!");       // A description of this node
////  server.findNode("/renderer/position").setUnit("position.cart2D");                   // The cannonnical way to set the unit for a 2D position
////  //
////  // As they return a ofxOssiaNode&, the set(Attribute) methods can be "cascaded" as demonstrateed below:
////  server.findNode(renderer2.position).setUnit("point2d")                              // A shorthand way to do the same
////      .setDescription("A circle renderer position")    // More attributes can be added
////      .setTags({"a little tag", "some other tag", "another tag"}); // In a cascading way
////  //
////  //*********************************************************************************//



//  //*********************************************************************************//
//  // v The rest below is the usual stuff from the example


////  gui.loadFromFile("settings.xml");

////  font.load( OF_TTF_SANS,9,true,true);
////  ofEnableAlphaBlending();


 //TEST KINECT-----------------------------------------------------------------------------------------------------------------------
    ofSetLogLevel(OF_LOG_VERBOSE);

        // enable depth->video image calibration
        kinect.setRegistration(true);

        kinect.init();
        //kinect.init(true); // shows infrared instead of RGB video image
        //kinect.init(false, false); // disable video image (faster fps)

        kinect.open();		// opens first available kinect
        //kinect.open(1);	// open a kinect by id, starting with 0 (sorted by serial # lexicographically))
        //kinect.open("A00362A08602047A");	// open a kinect using it's unique serial #

        // print the intrinsic IR sensor values
        if(kinect.isConnected()) {
            ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
            ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
            ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
            ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
        }

    #ifdef USE_TWO_KINECTS
        kinect2.init();
        kinect2.open();
    #endif

        colorImg.allocate(kinect.width, kinect.height);
        grayImage.allocate(kinect.width, kinect.height);
        grayThreshNear.allocate(kinect.width, kinect.height);
        grayThreshFar.allocate(kinect.width, kinect.height);

        nearThreshold = 230;
        farThreshold = 70;
        bThreshWithOpenCV = true;

        ofSetFrameRate(60);

        // zero the tilt on startup
        angle = 0;
        kinect.setCameraTiltAngle(angle);

        // start from the front
        bDrawPointCloud = false;




}

void ofApp::vSyncChanged(bool & vSync){
  ofSetVerticalSync(vSync);
}


//--------------------------------------------------------------
void ofApp::update(){
//  // frameNum is a readonly parameter so this will fail to compile
//  // unless we are inside the CirclesRenderer class
//  // renderer.frameNum = 5;
//    // Constrain mouse cursor inside window



//       if(init){
//           moveMouse(ofGetWidth()/2, ofGetHeight()/2);
//           init = false;
//       }
//       else{
//           int x = ofGetMouseX();
//           int y = ofGetMouseY();
//           if(x >= ofGetWindowWidth()-1)
//               moveMouse(1,y);
//           if(x <= 0)
//               moveMouse(ofGetWindowWidth()-2,y);
//           if(y <= 0)
//               moveMouse(x,ofGetHeight()-2);
//           if(y >= ofGetHeight()-1)
//               moveMouse(x,1);
//       }
    // TEST KINECT-----------------------------------------------------------------------------------------------------------------------
    ofBackground(100, 100, 100);

        kinect.update();

        // there is a new frame and we are connected
        if(kinect.isFrameNew()) {

            // load grayscale depth image from the kinect source
            grayImage.setFromPixels(kinect.getDepthPixels());

            // we do two thresholds - one for the far plane and one for the near plane
            // we then do a cvAnd to get the pixels which are a union of the two thresholds
            if(bThreshWithOpenCV) {
                grayThreshNear = grayImage;
                grayThreshFar = grayImage;
                grayThreshNear.threshold(nearThreshold, true);
                grayThreshFar.threshold(farThreshold);
                cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL); // les 3 caméras qu'on veut afficher
            } else {

                // or we do it ourselves - show people how they can work with the pixels
                ofPixels & pix = grayImage.getPixels();
                int numPixels = pix.size();
                for(int i = 0; i < numPixels; i++) {
                    if(pix[i] < nearThreshold && pix[i] > farThreshold) {
                        pix[i] = 255;
                    } else {
                        pix[i] = 0;
                    }
                }
            }

            // update the cv images
            grayImage.flagImageChanged();

            // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
            // also, find holes is set to true so we will get interior contours as well....
            contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
        }

    #ifdef USE_TWO_KINECTS
        kinect2.update();
    #endif


}

//--------------------------------------------------------------
void ofApp::draw(){

// //------------------------------JOY CONTROL-------------------------------------
//    //button control (up down)
//    for (int i = 0; i < joy_.getButtonNum(); i++) {
//        if (joy_.isPressed(i)) {

//          cam3.updateState(i);
//        }
//        if (joy_.isPushing(i)) {

//          cam3.updateState(i);
//        }
//        if (joy_.isRelease(i)) {

//          cam3.updateState(-1);
//        }
//      }



//        //Axes control

//     ///////////LEFT (direction)
//   int ax_x= joy_.getAxis(1);
//   if(ax_x>0){

//       cam3.updateAxis_x(1);

//   }
//   else if (ax_x<0){

//       cam3.updateAxis_x(-1);

//   }
//   else{cam3.updateAxis_x(0);}


//   int ax_y= joy_.getAxis(0);
//       if(ax_y>0){

//           cam3.updateAxis_y(1);

//       }
//       else if (ax_y<0){

//           cam3.updateAxis_y(-1);

//       }
//       else{cam3.updateAxis_y(0);

//       }

// ///////////RIGHT   (Rotation)
//       int ax_X= joy_.getAxis(3);
//       if(ax_X>0){

//           cam3.updateAxis_X(1);

//       }
//       else if (ax_X<0){

//           cam3.updateAxis_X(-1);

//       }
//       else{cam3.updateAxis_X(0);}


//       int ax_Y= joy_.getAxis(4);
//           if(ax_Y>0){

//               cam3.updateAxis_Y(1);

//           }
//           else if (ax_Y<0){

//               cam3.updateAxis_Y(-1);

//           }
//           else{cam3.updateAxis_Y(0);

//           }

////------------------------------------------------------------------------------------------------------------
//    cam3.begin();

//     drawAxes();
//    ofScale(100,100,100);

//    for (unsigned int i=0; i<cubes.size(); i++) {
//         cubes[i]->draw();
//     }

//      //nodeSwarm.updatepos( cam3.getPosition()/100);
//    ofVec3f posi;
//    posi[0]=cam3.getPosition().x/100;
//    posi[1]= -1*cam3.getPosition().z/100;
//    posi[2]=cam3.getPosition().y/100;
//      Origine.set("Origine",posi);
//      RotX.set("Pitch",cam3.rotationX*(-1));
//      RotY.set("Roll",cam3.rotationY*(-1));
//      RotZ.set("Yaw",cam3.rotationZ*(-1));
//      ofSetColor(255,255,255,75);
//      //ofDrawSphere(base, 1);
//     // ofScale(100,100,100);
//    //ofDrawSphere(base1, 1);
//    //ofDrawSphere(base2, 1);
////-------------------------------------------------------------------------------Draw Domes---------------------------------------------------------------------
//      for(int i=0;i<Domes.size();i++){

//          stringstream ss;
//          ss << i;
//          string str = ss.str();
//          ofParameter<ofVec3f> ps;
//          ps=Swarm2.getVec3f(i);

//          ofVec3f P;
//          ofVec3f p;
//          p=ps;
//          P[0]=p[0];
//          P[1]=p[2];
//          P[2]=-p[1];



//          ofDrawSphere(P, 1);
//          }
//      //--------------------------------------------------------------------------------------------------------------------------------------------------
//ofPushMatrix();
////ofScale(0.01,0.01,0.01); // activated : the particles remain in the dome
////nodeSwarm.draw(); // particles system drawn (gravitation around closest dome doesn't work with random domes yet.

//ofPopMatrix();
////ofPushMatrix();
////ofScale(0.01,0.01,0.01);
////nodeSwarm_1.draw();
////ofPopMatrix();
////        ofScale(100,100,100);

// //   nodeSwarm_2.draw();




////      ofPopMatrix();


//     //cam.drawAim();




    // TEST KINECT-----------------------------------------------------------------------------------------------------------------------
    ofSetColor(255, 255, 255);

        if(bDrawPointCloud) {
            easyCam.begin();
            drawPointCloud();
            easyCam.end();
        } else {
            // draw from the live kinect
            kinect.drawDepth(10, 10, 400, 300);
            kinect.draw(420, 10, 400, 300);

            grayImage.draw(10, 320, 400, 300);
            contourFinder.draw(10, 320, 400, 300);

    #ifdef USE_TWO_KINECTS
            kinect2.draw(420, 320, 400, 300);
    #endif
        }

        // draw instructions
        ofSetColor(255, 255, 255);
        stringstream reportStream;

        if(kinect.hasAccelControl()) {
            reportStream << "accel is: " << ofToString(kinect.getMksAccel().x, 2) << " / "
            << ofToString(kinect.getMksAccel().y, 2) << " / "
            << ofToString(kinect.getMksAccel().z, 2) << endl;
        } else {
            reportStream << "Note: this is a newer Xbox Kinect or Kinect For Windows device," << endl
            << "motor / led / accel controls are not currently supported" << endl << endl;
        }

        reportStream << "press p to switch between images and point cloud, rotate the point cloud with the mouse" << endl
        << "using opencv threshold = " << bThreshWithOpenCV <<" (press spacebar)" << endl
        << "set near threshold " << nearThreshold << " (press: + -)" << endl
        << "set far threshold " << farThreshold << " (press: < >) num blobs found " << contourFinder.nBlobs
        << ", fps: " << ofGetFrameRate() << endl
        << "press c to close the connection and o to open it again, connection is: " << kinect.isConnected() << endl;

        if(kinect.hasCamTiltControl()) {
            reportStream << "press UP and DOWN to change the tilt angle: " << angle << " degrees" << endl
            << "press 1-5 & 0 to change the led mode" << endl;
        }

        ofDrawBitmapString(reportStream.str(), 20, 652);


}
//----------------------------------------------------------------
void ofApp::drawAxes()
{
    ofPushMatrix();
    ofSetLineWidth(2);
    ofSetColor(255, 0, 0);
    ofLine(0, 0, 0, 20, 0, 0);
    verdana.drawStringAsShapes("x", 25, 0);
    ofSetColor(0, 255, 0);
    ofLine(0, 0, 0, 0, 20, 0);
    verdana.drawStringAsShapes("y", 5, 25);
    ofSetColor(0, 0, 255);
    ofLine(0, 0, 0, 0, 0, 20);
    ofTranslate(0,0,22);
    verdana.drawStringAsShapes("z", -5, -5);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::moveMouse(int x, int y)
{
#if defined(__APPLE__)
    CGWarpMouseCursorPosition(CGPointMake(ofGetWindowPositionX()+x,ofGetWindowPositionY()+y));
#elif defined(_WIN32)
    SetCursorPos(x,y); // not tested
#else // xlib
    Display *display = XOpenDisplay(0);
    Window window;


    int state;
    XGetInputFocus(display,&window,&state);
   //XWarpPointer(display, None, window, 0, 0, 0, 0, x, y);
    XCloseDisplay(display);
#endif
    cam.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


//  if(key=='g'){
//    settings.serialize(parameters);
//    settings.save("settings.xml");
//  }
//  if(key=='l'){
//    settings.load("settings.xml");
//    settings.deserialize(parameters);
//  }
//  if(key=='o'){
//    cout << renderer1.parameters;
//    cout << renderer2.parameters;
//  }
//  if(key=='r'){
//    renderer1.color = ofColor(127);
//    renderer2.color = ofColor(127);
//  }
//  cam.keyPressed(key);
//  if(key == 'f')
//      {ofToggleFullscreen();}
//  switch(key) {
//      case 'C':
//      case 'c':
//          if(cam2.getMouseInputEnabled()) cam2.disableMouseInput();
//          else cam2.enableMouseInput();
//          break;

//      case 'F':
//      case 'f':
//          ofToggleFullscreen();
//          break;
//      case 'H':
//      case 'h':
//          bShowHelp ^=true;
//          break;
//  }
//-----------------------------------KINECT--------------------------------------------
    switch (key) {
            case ' ':
                bThreshWithOpenCV = !bThreshWithOpenCV;
                break;

            case'p':
                bDrawPointCloud = !bDrawPointCloud;
                break;

            case '>':
            case '.':
                farThreshold ++;
                if (farThreshold > 255) farThreshold = 255;
                break;

            case '<':
            case ',':
                farThreshold --;
                if (farThreshold < 0) farThreshold = 0;
                break;

            case '+':
            case '=':
                nearThreshold ++;
                if (nearThreshold > 255) nearThreshold = 255;
                break;

            case '-':
                nearThreshold --;
                if (nearThreshold < 0) nearThreshold = 0;
                break;

            case 'w':
                kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
                break;

            case 'o':
                kinect.setCameraTiltAngle(angle); // go back to prev tilt
                kinect.open();
                break;

            case 'c':
                kinect.setCameraTiltAngle(0); // zero the tilt
                kinect.close();
                break;

            case '1':
                kinect.setLed(ofxKinect::LED_GREEN);
                break;

            case '2':
                kinect.setLed(ofxKinect::LED_YELLOW);
                break;

            case '3':
                kinect.setLed(ofxKinect::LED_RED);
                break;

            case '4':
                kinect.setLed(ofxKinect::LED_BLINK_GREEN);
                break;

            case '5':
                kinect.setLed(ofxKinect::LED_BLINK_YELLOW_RED);
                break;

            case '0':
                kinect.setLed(ofxKinect::LED_OFF);
                break;

            case OF_KEY_UP:
                angle++;
                if(angle>30) angle=30;
                kinect.setCameraTiltAngle(angle);
                break;

            case OF_KEY_DOWN:
                angle--;
                if(angle<-30) angle=-30;
                kinect.setCameraTiltAngle(angle);
                break;

}
    }
//------------------------------------------------------------------
void ofApp::exit()
{
    for (unsigned int i=0; i<cubes.size(); i++) {
        delete cubes[i];
    }
    for (unsigned int i=0; i<materials.size(); i++) {
        delete materials[i];
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){




}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(button==0)
        cam.update(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(button==0 && x>0 && y>0)
        cam.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    //cam.init(ofGetWidth(),ofGetHeight());
}


void ofApp::drawPointCloud() { // FOR KINECT APPLICATION
    int w = 640;
    int h = 480;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    int step = 2;
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x,y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    glPointSize(3);
    ofPushMatrix();
    // the projected points are 'upside down' and 'backwards'
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000); // center the points a bit
    ofEnableDepthTest();
    mesh.drawVertices();
    ofDisableDepthTest();
    ofPopMatrix();
}


//void ofApp::update_Dome(){

//    for(int i=0;i<Domes.size();i++){

//        Domes[i]=
//    }
//}
