 #include "Swarm.h"

// This 'swarm' object demonstrates a simple particle system
//  with 'simple harmonic motion'

swarm::swarm(){
        light.setAmbientColor(ofColor(0, 0, 0));
}

void swarm::init(int nParticles, float positionDispersion, float velocityDispersion,string name,ofVec3f dome,ofVec3f dome1,ofVec3f dome2){
   //poscam=pos;
   _dome=dome;
   _dome_1=dome1;
   _dome_2=dome2;
    if (nParticles!=0)
     {param.setName(name);}

	// Check if we've already initialised
	if(particles.size() != 0){
		// clear out old data
		ofLogWarning("swarm") <<  "Swarm: Already initialised";

		particles.clear();
	}

	ofSeedRandom();
	//
	ofVec3f position, velocity;
	ofColor color;
	for(int i = 0; i < nParticles; i++){
                position.x = (ofRandom(2.0f) - 1.0f)  * positionDispersion;
                position.y = (ofRandom(2.0f) - 1.0f)  * positionDispersion;
                position.z = (ofRandom(2.0f) - 1.0f)  * positionDispersion;

                velocity.x = (ofRandom(0.5f) - 0.25f)  * velocityDispersion;
                velocity.y = (ofRandom(0.5f) - 0.25f)  * velocityDispersion;
                velocity.z = (ofRandom(0.5f) - 0.25f)  * velocityDispersion;

		color.r = ofRandom(255.0f);
		color.g = ofRandom(255.0f);
		color.b = 150.0f;
		color.a = 255.0f;

		particle newParticle;
		newParticle.position = position;
		newParticle.velocity = velocity;
		newParticle.color = color;
        stringstream ss;
        ss << i;
        string str = ss.str();
        std::cout<<position<<std::endl;

        newParticle.parameters.setName(str);
        ofVec3f posi;
        posi[0]=position.x;
        posi[1]= -1*position.z;
        posi[2]=position.y;
        newParticle.parameters.add( newParticle.pos.set("Cartesian",posi));


         //parameters.add(position.set("position",ofVec2f(ofGetWidth()*.5,ofGetHeight()*.5),ofVec2f(0,0),ofVec2f(ofGetWidth(),ofGetHeight())));


        param.add(newParticle.parameters);


		// add our new particle to the vector
		particles.push_back(newParticle);
	}

}

void swarm::customDraw(){
	// We run the update ourselves manually. ofNode does
	//  not do this for us.
    update();


	//--
	// Draw particles

	// We use the position of the first
	//  particle as the position of the
	//  light.
	ofPushStyle();
	light.enable();
 light.setPosition(poscam);
  //std::cout<<light.getPosition()<<std::endl;


	for(unsigned int i = 0; i < particles.size(); i++){
		//ofPushStyle();
		//ofSetColor(particles[i].color);
                material.setDiffuseColor(particles[i].color);

		material.begin();
        ofDrawSphere(particles[i].position, 0.5);

		//ofPopStyle();
	}
	material.end();

	light.disable();
	ofDisableLighting();

	//
	//--



	// Render light as white sphere

	ofPopStyle();
}

void swarm::update(){


	// Calculate time past per frame
	float dt = ofGetLastFrameTime();

	// Update positions, velocities
    for(unsigned int i = 0; i < particles.size(); i++){

		// -----------
		//
		//	MOTION MATHS
		//
		//		'Simple Harmonic Motion' + a little extra
		// ----
		//

		// [1] apply velocity to postion
                //  (i.e. integrate velocity)
		//
		//  v = dx / dt (*)
		//  x = x + dx [every frame]
		//
		// therefore
		//  x = x + v * dt (*)
		//

		// (velcotity is taken from previous frame)
		particles[i].position += particles[i].velocity * dt;
        particles[i].pos=particles[i].position ;



		// [2] apply spring force to velocity
		//  (i.e. integrate acceleration)
		//
		//  a = -k * x (this is the shm restoring force, aka spring force)
		//  a = dv / dt
		//
		// therefore from (*)s above
		//  (v = v + dv)
		//
		//  v = v + (dt * a)
		//  v = v + (dt * -k * x)
		//
                particles[i].velocity += -SPRING_CONSTANT * particles[i].position * dt;


		// [3] to get a super simple kind of 'flocking' behaviour
		//  we add a second spring force to velocity relative
		//  to the position of the light
		// NOTICE: THIS ISN'T REAL FLOCKING!
                float dist=_dome.distance(particles[i].position);
                float dist1=_dome_1.distance(particles[i].position);
                float dist2=_dome_2.distance(particles[i].position);
                //float m =min(dist,dist1);
                float mini=min(min(dist,dist1),dist2);
                if (mini==dist){particles[i].velocity += -SPRING_CONSTANT * (particles[i].position - _dome) * dt;

                }

                else if(mini==dist1){particles[i].velocity += -SPRING_CONSTANT * (particles[i].position - _dome_1) * dt;

                }
                else if (mini==dist2){particles[i].velocity += -SPRING_CONSTANT * (particles[i].position - _dome_2) * dt;

                }




		// [4] Force a maximum velocity
		if(particles[i].velocity.length() > MAX_VELOCITY){
			particles[i].velocity /= particles[i].velocity.length() * MAX_VELOCITY;
		}






                // [5]Representation of the collision between 2 or more particles TEST
//                                vector<int> Doublons;
//                                bool doublon=true;
//                                int n=0;
//                              while(doublon==true){
//                                      ofDrawBitmapString(i, particles[i].position);
//                                    for(unsigned int j=1;j<particles.size();j++){
//                                        ofDrawBitmapString(j, particles[j].position);//list of all the particles at the same position as particle i
//                                        if((particles[i].position.x==particles[j].position.x)&(particles[i].position.y==particles[j].position.y)&(particles[i].position.z==particles[j].position.z) & (i!=j)){
//                                            ofDrawBitmapString(" Doublon", particles[j].position);

//                                            Doublons.push_back(j);

//                                            n=n+1;
//                                        }
//                                   }

//                                    //                                   if (n==1){ // change the trajectory of both particles for the moment just the case of a collision between two particles
//                                    //                                            std::cout<<"doublon"<<std::endl;
//                                    //                                            int j=Doublons[0];

//                                    //                                           //-calculation of new of  position and velocity of the particles
//                                    //                                           ofVec3f v1=particles[i].velocity;
//                                    //                                           ofVec3f v2=particles[j].velocity;
//                                    //                                           ofVec3f v=v1-v2;
//                                    //                                           ofVec3f mid = v1.getMiddle(v2);

//                                    //                                           ofVec3f u1=1/2*v ;// if the particles have the same weight
//                                    //                                           ofVec3f u2=-u1;






//                                    //                                           //-modification of  position and velocity of the particles
//                                    //                                           ofVec3f positioni, velocityi;
//                                    //                                           ofColor colori;

//                                    //                                           ofVec3f positionj, velocityj;
//                                    //                                           ofColor colorj;
//                                    //                //                           positioni.x =
//                                    //                //                           positioni.y =
//                                    //                //                           positioni.z =

//                                    //                                           velocityi.x += u1.x ;
//                                    //                                          velocityi.y += u1.y ;
//                                    //                                           velocityi.z += u1.z ;

//                                    //                                           colori.r = ofRandom(255.0f);
//                                    //                                          colori.g = ofRandom(255.0f);
//                                    //                                           colori.b = 150.0f;
//                                    //                                          colori.a = 255.0f;

//                                    //                //                           positionj.x =
//                                    //                //                           positionj.y =
//                                    //               //                           positionj.z =

//                                    //                                           velocityj.x += u2.x ;
//                                    //                                          velocityj.y += u2.y ;
//                                    //                                           velocityj.z += u2.z ;

//                                    //                                           colorj.r = ofRandom(255.0f);
//                                    //                                           colorj.g = ofRandom(255.0f);
//                                    //                                           colorj.b = 150.0f;
//                                    //                                           colorj.a = 255.0f;


//                                    //                                           positioni=particles[i].position;
//                                    //                                           positionj=particles[j].position;
//                                    //                                          particle newParticlei;
//                                    //                                           particle newParticlej;
//                                    //                                           newParticlei.position = particles[i].position;
//                                    //                                           newParticlei.velocity  = velocityi;
//                                    //                                           newParticlei.color = colori;

//                                    //                                           particles[i]=newParticlei;
//                                    //                                           particles[j]=newParticlej;

//                                    //                                           //-


//                                    //                                   }

//                                                                       if(n!=1){doublon=false;
//                                                                       ofDrawBitmapString(i, particles[i].position);}

//                                                                      Doublons.clear();

//                                                                    }
/////
/// 	// [4] Force a maximum velocity
//                                if(particles[i].velocity.length() > MAX_VELOCITY){
//                                        particles[i].velocity /= particles[i].velocity.length() * MAX_VELOCITY;
//                                }




                //
                // -----------
//        stringstream ss;
//        ss << i;
//        string str = ss.str();
//        param.str.pos.set("Cartesian",particle[i].position/100);

        //particle[i].position=particle[i].position/100;
        }



}


void swarm::updatepos(ofVec3f pos){
    poscam=pos;
 light.setPosition(poscam);
    ofSetColor(255, 255, 255);
    //ofDrawSphere(light.getPosition(), 2.0);
   //std::cout<<light.getPosition()<<std::endl;
    //ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);
   // ofDrawBitmapString(" light", light.getPosition());

}
