#include "sysBullet.hpp"

void SysBullet::Init(){
    this->numBullets=0;
    this->limitBall=false;
}
void SysBullet::AddBullet(glm::vec3 position, float angleHorizontal, float angleVertical){
    if(this->limitBall){
        bullets[numBullets]->Init(position,angleHorizontal,angleVertical); 
    }else{
        bullets[numBullets]= new Bullet();
        bullets[numBullets]->setDeltaTime(deltaTime); 
        bullets[numBullets]->setCamera(this->camera); 
        bullets[numBullets]->Init(position,angleHorizontal,angleVertical); 
        
        keyBullets[bullets[numBullets]]=numBullets;
        handleCollision->add(bullets[numBullets]);
    }
    numBullets++;
    
    if(numBullets==10){
        numBullets=0;
        this->limitBall=true;
    }
}
void SysBullet::Update(){

  for ( auto item : this->bullets ){
    if( item.second->getRun() ){
      item.second->Update();
    }
  };
}
void SysBullet::Render(){
  for ( auto &item : this->bullets ){
    if( item.second->getRun()){
      item.second->Render();
    }
  };
}


void SysBullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void SysBullet::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
void SysBullet::setCamera(Camera *camera){
    this->camera = camera ;
}
