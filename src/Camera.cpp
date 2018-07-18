#include "Camera.h"
#include "ofMain.h"

#include "math.h"




Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::init(int windowWidth, int windowHeight)
{
    width = windowWidth;
    height = windowHeight;
    aim_distz =0;// plan lointain
    aim_distx = 0;//centré
    rotX = 0;
    rotY = 0;
    lastX1 = width/2;
    lastY1 = height/2;
    teta =0;
    betax=0;
    betaz=0;
    distx=0;
    distz=0;

    campos[2]=aim_distz;
    campos[0]=distx;
    campos[1]=0;
    corectx=0;
    corectz=0;
    rot==false;
    std::cout<<"création caméra"<<std::endl;
     //par.add(Origine.set("Origine",campos));


}


 void Camera::applyMatrix()
 {
    ofLoadIdentityMatrix();
    ofTranslate(aim_distx, 0, -aim_distz);
    ofRotateX(rotX);
    ofRotateY(rotY);

    ofRotateY(teta);
    ofRotateX(betax);
    ofRotateZ(betaz);






 }

void Camera::update(int x, int y)
{


    float rateX = 180.0/float(height);
    float rateY = 180.0/float(width);
    float diffX = x - lastX1;
    float diffY = lastY1 - y;
    lastX1 = x;
    lastY1 = y;
    rotX += diffY * rateY;
    rotY += diffX * rateX;


}

void Camera::mousePressed(int x, int y)
{
    lastX1 = x;
    lastY1 = y;
}


void Camera::keyPressed(int key){



// quand on sort de la rotation on applique la correction à distx


    if(key == 'z') //------------------mode "avancer" on différencie les cas suivant la valeur et le signe de l'angle teta (angle entre la caméra et l'axe z)
       {//distx=corectx;
        //aim_distz=corectz;




            if (abs(teta)>359)
            {teta=abs(teta)%360;
                teta=-teta;}

            if (abs(teta)==0)
                    {
                        distx+=2*3*sin(teta* PI / 180.0 );
                        aim_distz-=2*3*cos(teta* PI / 180.0 );
                         distz-=2*3*cos(teta* PI / 180.0 );
                    }
            if (abs(teta)==180)
            {
                distx-=2*3*sin(teta* PI / 180.0 );
                aim_distz+=2*3*cos(teta* PI / 180.0 );
                distz+=2*3*cos(teta* PI / 180.0 );
            }
            if ((abs(teta)<90)  &(abs(teta)>0))
            {
                aim_distz-=2*3*cos(teta* PI / 180.0 );
                distx+=2*3*sin(teta* PI / 180.0 );
                distz-=2*3*cos(teta* PI / 180.0 );


            }

            else if ((89<abs(teta)) &(abs(teta)<180))
            {




                distx+=2*3*sin(teta* PI / 180.0 );
                if (abs(teta)==90)
                {
                     aim_distz-=2*3;


                }
                else{aim_distz+=2*3*cos(teta* PI / 180.0 );
                    distz+=2*3*cos(teta* PI / 180.0 );}
            }
            else if ((180<abs(teta)) & (abs(teta)<270))
            {
                aim_distz+=2*3*cos(teta* PI / 180.0 );
                distz+=2*3*cos(teta* PI / 180.0 );
                 distx+=2*3*sin(teta* PI / 180.0 );

//                if (abs(teta)==180)
//                {
//                    aim_distx+=2*3*sin(teta* PI / 180.0 );
//                    aim_distz-=2*3*cos(teta* PI / 180.0 );
//                }
            }
            else if ((269<abs(teta)) & (abs(teta)<360))
            {

                distx+=2*3*sin(teta* PI / 180.0 );
                if (abs(teta)==270)
                {
                     aim_distz-=2*3;

                }
                else
                {
                     aim_distz-=2*3*cos(teta* PI / 180.0 );
                     distz-=2*3*cos(teta* PI / 180.0 );

                }
            }


//            corectx=distx;
//           corectz=aim_distz;



  }
    if (key == 's')//--------------------mode "reculer" fonctionne de la même manière
        {//distx=corectx;
        //aim_distz=corectz;





            if (abs(teta)>359)
            {teta=abs(teta)%360;
                teta=-teta;}

            if (abs(teta)==0)
                    {
                        aim_distx-=2*3*sin(teta* PI / 180.0 );
                        aim_distz+=2*3*cos(teta* PI / 180.0 );
                        distz+=2*3*cos(teta* PI / 180.0 );
                    }

            if (abs(teta)==180)
                    {
                        aim_distx+=2*3*sin(teta* PI / 180.0 );
                        aim_distz-=2*3*cos(teta* PI / 180.0 );
                        distz-=2*3*cos(teta* PI / 180.0 );
                    }

            if ((abs(teta)<90)  &(abs(teta)>0))
            {
                aim_distz+=2*3*cos(teta* PI / 180.0 );
                distz+=2*3*cos(teta* PI / 180.0 );
                distx-=2*3*sin(teta* PI / 180.0 );


            }

            else if ((89<abs(teta)) &(abs(teta)<180))
            {


                distx-=2*3*sin(teta* PI / 180.0 );

                if (abs(teta)==90)
                {
                     aim_distz+=2*3*cos(teta* PI / 180.0 );// on annule l'effet de la ligne du dessus
                }
                else
                    {aim_distz-=2*3*cos(teta* PI / 180.0 );
                    distz-=2*3*cos(teta* PI / 180.0 );

                }
            }
            else if ((180<abs(teta)) & (abs(teta)<270))
            {
                aim_distz-=2*3*cos(teta* PI / 180.0 );
                distz-=2*3*cos(teta* PI / 180.0 );
                distx-=2*3*sin(teta* PI / 180.0 );

            }
            else if ((269<abs(teta)) & (abs(teta)<360))
            {

                distx-=2*3*sin(teta* PI / 180.0 );

                if (abs(teta)==270)
                {
                     aim_distz+=2*3*cos(teta* PI / 180.0 );
                }
                else
                    {aim_distz+=2*3*cos(teta* PI / 180.0 );
                   distz+=2*3*cos(teta* PI / 180.0 );

                }

            }

           // corectx=distx;
             //corectz=aim_distz;

    }


    else if (key == 'q') // rotation DE LA CAMERA
        {


        teta+=10;
//        corectx=distx;
//        corectx= -2*3*sin(teta* PI / 180.0 )*distx;

//        corectz=aim_distz;
//        teta=teta%360;
//        if((0<abs(teta)) & (abs(teta)<90))
//            {corectz=2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((90<abs(teta)) & (abs(teta)<180))
//            {corectz=-2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((180<abs(teta)) & (abs(teta)<270))
//            {corectz=2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((270<abs(teta)) & (abs(teta)<360))
//            {corectz=-2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        std::cout<<"sortie dans le test Q mode X puis Z" <<std::endl;

//        std::cout<<distx <<std::endl;
//        std::cout<<corectx <<std::endl;
//        std::cout<<aim_distz <<std::endl;
//        std::cout<<corectz <<std::endl;

    }
    else if (key == 'd')
        { teta-=10;

//        corectx=distx;

//        corectx= -2*3*sin(teta* PI / 180.0 )*distx;
//        corectz=aim_distz;
//        teta=teta%360;
//        if((0<abs(teta)) & (abs(teta)<90))
//            {corectz=2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((90<abs(teta)) & (abs(teta)<180))
//            {corectz=-2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((180<abs(teta)) & (abs(teta)<270))
//            {corectz=2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }
//        else if((270<abs(teta)) & (abs(teta)<360))
//            {corectz=-2*3*cos(teta* PI / 180.0 )*aim_distz;


//        }

        }

    else if (key == 'p')// mode up and down
        {
            betaz+=10*sin(teta* PI / 180.0 );
            betax+=10*cos(teta* PI / 180.0 );

        }
    else if (key == 'm')
        {
            betaz-=10*sin(teta* PI / 180.0 );
            betax-=10*cos(teta* PI / 180.0 );
        }


    if (teta > 179)
            {
    campos[2]=-distz/100;}
    else{
        campos[2]=distz/100;}

    campos[0]=distx/100;
    campos[1]=0;
//  std::cout<<teta<<std::endl;
//std::cout<<aim_distz<<std::endl;
//std::cout<<distz<<std::endl;



}


//-------------------------------------------------------------------------------
//void Camera::keyReleased(int key)
//{
//    if (key=='q')
//    { rot==true;

////        if (abs(teta)>359)
////        {teta=abs(teta)%360;
////            teta=-teta;}



////        corectx= -2*3*sin(teta* PI / 180.0 )*distx;


//        }

//    else
//         {
//        rot=false;
//    }




//}




void Camera::drawAim()
{
    ofDisableDepthTest();

    ofPushMatrix();
    ofTranslate(width/2, height/2);
    ofSetLineWidth(4);
    ofSetColor(100, 100, 100);
    ofLine(-10, 0, 10, 0);
    ofLine(0, -10, 0, 10);
    ofPopMatrix();

    ofEnableDepthTest();
}
