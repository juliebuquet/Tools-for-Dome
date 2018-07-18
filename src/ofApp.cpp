#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    tex=true;


 ofBackground(0,0,0);

    joy_.setup(GLFW_JOYSTICK_1);
    texture.clear();
   texture.allocate(ofGetWidth(),ofGetHeight(), GL_RGB);
   fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

   fbo.begin();
     ofClear(0,0,0,0);
     fbo.end();
    
    surface.setup(ofGetWidth(),ofGetHeight(), 4, 20);
    surface.addListeners();


    Material* sand = new Material("sand.png");
    materials.push_back(sand);
    Material* stonebrick = new Material("stonebrick.png");
    materials.push_back(stonebrick);
    Material* mossy = new Material("stonebrick_mossy.png");
    materials.push_back(mossy);
    Cube* c;

    Cube* d;
    for (int i=0; i < 2; i++) {
        for (int j=-20; j < 20; j++) {
            for (int k=-20; k < 20; k++) {
//                if (i==1){
                    c = new Cube(sand);
//                }else{
//                    c = new Cube(stonebrick);
//                }
                c->move(j, (i+1),k ); //position of the cube
                cubes.push_back(c);
            }
        }
    }
 nodeSwarm.init(10, 50, 10,"SWARM1");

}

//--------------------------------------------------------------
void ofApp::update(){

    surface.update();
    counter+=1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //------------------------------JOY CONTROL-------------------------------------
    //button control (up down)
    for (int i = 0; i < joy_.getButtonNum(); i++) {
        if (joy_.isPressed(i)) {

            cam3.updateState(i);
        }
        if (joy_.isPushing(i)) {

            cam3.updateState(i);
        }
        if (joy_.isRelease(i)) {

            cam3.updateState(-1);
        }
    }



    //Axes control

    ///////////LEFT (direction)
    int ax_x= joy_.getAxis(1);
    if(ax_x>0){

        cam3.updateAxis_x(1);

    }
    else if (ax_x<0){

        cam3.updateAxis_x(-1);

    }
    else{cam3.updateAxis_x(0);}


    int ax_y= joy_.getAxis(0);
    if(ax_y>0){

        cam3.updateAxis_y(1);

    }
    else if (ax_y<0){

        cam3.updateAxis_y(-1);

    }
    else{cam3.updateAxis_y(0);

    }

    ///////////RIGHT   (Rotation)
    int ax_X= joy_.getAxis(3);
    if(ax_X>0){

        cam3.updateAxis_X(1);

    }
    else if (ax_X<0){

        cam3.updateAxis_X(-1);

    }
    else{cam3.updateAxis_X(0);}


    int ax_Y= joy_.getAxis(4);
    if(ax_Y>0){

        cam3.updateAxis_Y(1);

    }
    else if (ax_Y<0){

        cam3.updateAxis_Y(-1);

    }
    else{cam3.updateAxis_Y(0);

    }
    fbo.begin();
      ofClear(0,0,0,0);
      fbo.end();
 fbo.begin();
 //   ------------------------------------------------------------------------------------------------------------ Draw scene------------------------------------------------

  cam3.begin();

     ofScale(100,100,100);
    for (unsigned int i=0; i<cubes.size(); i++) { //draw cube
        cubes[i]->updatetex(tex);
        cubes[i]->draw();
    }

    mode=false;
    nodeSwarm.updatemode(mode);
    nodeSwarm.draw();

    fbo.end();
      fbo.getTextureReference().bind();
      ofPushMatrix();
          surface.draw();
      fbo.getTextureReference().unbind();
      surface.drawControls();
      ofPopMatrix();

//    ofSetColor(255, 255, 255, 255);
//        glPushMatrix();
//        glScalef(1, -1, 1);
//        fbo.draw( 0, -fbo.getHeight() );
//        glPopMatrix();

//ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 200);

//img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
//texture.loadData(img.getPixels());
////    ofSetHexColor(0xffffff);
////    ofPushMatrix();
////        //ofDrawCircle(150,150,80);

////    ofPopMatrix();
////    ofSetHexColor(0x333333);
////    ofSetColor(255,255,255);
//   // drawAxes();
//    ofScale(100,100,100); // keep i-score units  ( 1 = radius of a dome)

//    for (unsigned int i=0; i<cubes.size(); i++) { //draw cube

//        cubes[i]->draw();
//    }


//texture.loadScreenData(0,0,1024,768);



//    ofPushMatrix();
//        //texture.draw(-width/2,-height/2,width,height);
//    ofPopMatrix();
//    fbo.end();
//texture.bind();

//        surface.draw();
//    texture.unbind();
//    surface.drawControls();
//    //texture.draw(-width/2,-height/2,width,height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 32) // space
        surface.reset();
    else if (key == 115){ // s = save
        xml.clear();
        xml.addChild("points");
        xml.setTo("points");
        vector<ofVec3f> vec = surface.getControlPnts();
        for (int i = 0; i<vec.size(); i++) {
            xml.addChild("point");
            xml.setToChild(i);
            xml.setAttribute("xyz", ofToString(vec[i].x) + "," + ofToString(vec[i].y) + "," + ofToString(vec[i].z));
            xml.setToParent();
        }
        xml.setToParent();
        xml.save("settings.xml");
    }
    else if (key == 108){ // l = load
        string str;
        vector<ofVec3f> vec;
        xml.load("settings.xml");
        for (int i = 0; i<xml.getNumChildren(); i++) {
            
            if (xml.exists("point["+ofToString(i)+"][@xyz]")) {
                str = xml.getAttribute("point["+ofToString(i)+"][@xyz]");
                int x = ofToInt(ofSplitString(str, ",")[0]);
                int y = ofToInt(ofSplitString(str, ",")[1]);
                int z = ofToInt(ofSplitString(str, ",")[2]);
                vec.push_back(ofVec3f(x,y,z));
            }
        }
        surface.setControlPnts(vec);
    }
    else if (key == 45){ // - = decrease points
        surface.setControlPntDim(surface.getControlPntDim()-1);
    }
    else if (key == 61){ // - = increase points
        surface.setControlPntDim(surface.getControlPntDim()+1);
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
