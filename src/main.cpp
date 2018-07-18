#include "ofMain.h"
#include "ofApp.h"
//#include "SDL/SDL.h"
//#include "ofxopenni.h"
#undef main
//========================================================================
int main( ){

//  int init;
//  init=SDL_Init(SDL_INIT_JOYSTICK);

//  SDL_Joystick *joy;
//  // Check for joystick
//  if(SDL_NumJoysticks()>0){
//    // Open joystick
//    joy=SDL_JoystickOpen(0);

//    if(joy)
//    {
//      printf("Opened Joystick 0\n");
//      printf("Name: %s\n", SDL_JoystickName(0));
//      printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
//      printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
//      printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
//    }
//    else
//      printf("Couldn't open Joystick 0\n");

//    // Close if opened
//    if(SDL_JoystickOpened(0))
//      SDL_JoystickClose(joy);
//  }
//    int I;
//I=SDL_Init(SDL_INIT_JOYSTICK);

//SDL_Joystick *joy;
//// Check for joystick
//if(SDL_NumJoysticks()>0){
//    //std::cout<<I<<std::endl;
//  // Open joystick
//  joy=SDL_JoystickOpen(0);
//  SDL_JoystickEventState(SDL_ENABLE);

//  if(joy)
//  {
//    printf("Opened Joystick 0\n");
//    printf("Name: %s\n", SDL_JoystickName(0));
//    printf(" Axes: %d\n", SDL_JoystickNumAxes(joy));
//    printf("Buttons: %d\n", SDL_JoystickNumButtons(joy));
//    printf("Balls: %d\n", SDL_JoystickNumBalls(joy));
//    printf("Hats: %d\n", SDL_JoystickNumHats(joy));
//  }
//  else
//     {printf("Couldn't open Joystick 0\n");
//  }


//////          SDL_JoystickUpdate();

//////          //printf("Axes: %d\n", SDL_JoystickGetAxis(joy,2));
//////          //printf("Buttons: %d\n", SDL_JoystickGetButton(joy,1));

//////         printf("Hats: %d\n", SDL_JoystickGetHat(joy,0));
//////         }

//////SDL_JoystickUpdate();
//SDL_Event test_event; //empty event structure
////GstEvent event;
//int i=0;
//while(i<1000){
//    i=i+1;



//    while(SDL_WaitEvent(&test_event)) {
//    printf(" nouveau while \n ");

//    switch(test_event.type) {
//    //    case SDL_JOYHATMOTION:
//    //        printf ("HAT %d\n " , SDL_JoystickGetHat(joy,0));
//    //        break;
//    case SDL_JOYAXISMOTION :

//        if(test_event.jaxis.axis==0){

//           if(test_event.jaxis.value>0){
//               printf("Axes: %d\n", SDL_JoystickGetAxis(joy,0));

//           }
//           if(test_event.jaxis.value==0){
//               printf("Axes: %d\n", SDL_JoystickGetAxis(joy,0));
//              // printf(test_event.type);
//           }
//        }
//        break;
//    case SDL_MOUSEMOTION:
//        printf ("mouse \n ");
//        break;


//    ////    case SDL_JOYHATMOTION:

//    ////    case SDL_JOYBUTTONDOWN:

//    ////    case SDL_JOYBUTTONUP :


//    }
//    }
//    }

//    //  // Close if opened
//    //  if(SDL_JoystickOpened(0))
//    //    {SDL_JoystickClose(joy);
//    //}
//    // }


////return 0;
  ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

  // this kicks off the running of my app
  // can be OF_WINDOW or OF_FULLSCREEN
  // pass in width and height too:
  ofRunApp( new ofApp());

//}

}

