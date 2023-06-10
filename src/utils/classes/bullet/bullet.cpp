#include "bullet.hpp"

Bullet::Bullet(){
    float vertexBullet[] = {
        -0.05f, -0.05f, -0.05f,  
         0.05f, -0.05f, -0.05f,  
         0.05f,  0.05f, -0.05f,  
         0.05f,  0.05f, -0.05f,  
        -0.05f,  0.05f, -0.05f,  
        -0.05f, -0.05f, -0.05f, 

        -0.05f, -0.05f,  0.05f,  
         0.05f, -0.05f,  0.05f,  
         0.05f,  0.05f,  0.05f,  
         0.05f,  0.05f,  0.05f,  
        -0.05f,  0.05f,  0.05f,  
        -0.05f, -0.05f,  0.05f, 

        -0.05f,  0.05f,  0.05f,  
        -0.05f,  0.05f, -0.05f,  
        -0.05f, -0.05f, -0.05f,  
        -0.05f, -0.05f, -0.05f,  
        -0.05f, -0.05f,  0.05f,  
        -0.05f,  0.05f,  0.05f, 

         0.05f,  0.05f,  0.05f,  
         0.05f,  0.05f, -0.05f,  
         0.05f, -0.05f, -0.05f,  
         0.05f, -0.05f, -0.05f,  
         0.05f, -0.05f,  0.05f,  
         0.05f,  0.05f,  0.05f, 

        -0.05f, -0.05f, -0.05f,  
         0.05f, -0.05f, -0.05f,  
         0.05f, -0.05f,  0.05f,  
         0.05f, -0.05f,  0.05f,  
        -0.05f, -0.05f,  0.05f,  
        -0.05f, -0.05f, -0.05f, 

        -0.05f,  0.05f, -0.05f,  
         0.05f,  0.05f, -0.05f,  
         0.05f,  0.05f,  0.05f,  
         0.05f,  0.05f,  0.05f,  
        -0.05f,  0.05f,  0.05f,  
        -0.05f,  0.05f, -0.05f,  
    };
    square.setVetices(vertexBullet, sizeof(vertexBullet));
    this->radius=0.05;
    this->type=TypeObjet::Bullet;
}
void Bullet::Init(glm::vec3 position, float angleHorizonatal ,float angleVertical){
    square.setCamera(this->camera);
    square.setPosition(position);
    square.Init();
    square.rotateHorizontal(angleHorizonatal);
    square.rotateVertical(angleVertical);
    square.move(0.0,1.5);
    this->position=square.position;
    this->run=true;
    this->type=TypeObjet::Bullet;
}
void Bullet::Update(){
    if( run ){
        float limit=50.0;
        double speed = *deltaTime * 5.0;
        square.move(0.0,speed);
        
        if( !( -limit < this->position->x && this->position->x < limit ) ){
            this->run=false;
        }
        if( !( -limit < this->position->y && this->position->y < limit ) ){
            this->run=false;
        }
        if( !( -limit < this->position->z && this->position->z < limit ) ){
            this->run=false;
        }
    }
}
void Bullet::Render(){
    if (run){
        square.Render();
    }
}
void Bullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Bullet::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Bullet::getPosition(){
    return this->square.getPosition();
}
double Bullet::getRadio(){
    return this->radius;
}
bool Bullet::getRun(){
    return this->run;
}
void Bullet::colision(Iobjet_colicion *a){
    if(a->type == TypeObjet::Square){
        this->run=false;
    }
}
void Bullet::setCamera(Camera *camera){
    this->camera=camera;
}
