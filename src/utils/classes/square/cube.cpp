#include "cube.hpp"

void Cube::Init(glm::vec3 position){
    float vertex[] = {
        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.5f, -0.5f, -0.5f,  1.0f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.5f,  0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.5f,  0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
        -0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.3f,  0.0f,  0.0f, -1.0f, 
        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f,  1.0f, 
         0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.3f,  0.0f,  0.0f,  1.0f, 
         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f,  1.0f, 
         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f,  1.0f, 
        -0.5f,  0.5f,  0.5f,  1.0f, 0.1f, 0.0f,  0.0f,  0.0f,  1.0f, 
        -0.5f, -0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f,  1.0f, 

        -0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  -1.0f,  0.0f, 00.0f, 
        -0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.3f,  -1.0f,  0.0f, 00.0f, 
        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  -1.0f,  0.0f, 00.0f, 
        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  -1.0f,  0.0f, 00.0f, 
        -0.5f, -0.5f,  0.5f,  1.0f, 0.1f, 0.0f,  -1.0f,  0.0f, 00.0f, 
        -0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  -1.0f,  0.0f, 00.0f,

         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  1.0f,  0.0f, 00.0f, 
         0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.3f,  1.0f,  0.0f, 00.0f, 
         0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  1.0f,  0.0f, 00.0f, 
         0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  1.0f,  0.0f, 00.0f, 
         0.5f, -0.5f,  0.5f,  1.0f, 0.1f, 0.0f,  1.0f,  0.0f, 00.0f, 
         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  1.0f,  0.0f, 00.0f,

        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  -1.0f, 00.0f, 
         0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.3f,  0.0f,  -1.0f, 00.0f, 
         0.5f, -0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  -1.0f, 00.0f, 
         0.5f, -0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  -1.0f, 00.0f, 
        -0.5f, -0.5f,  0.5f,  1.0f, 0.1f, 0.0f,  0.0f,  -1.0f, 00.0f, 
        -0.5f, -0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  -1.0f, 00.0f,

        -0.5f,  0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  1.0f, 00.0f, 
         0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.3f,  0.0f,  1.0f, 00.0f, 
         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  1.0f, 00.0f, 
         0.5f,  0.5f,  0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  1.0f, 00.0f, 
        -0.5f,  0.5f,  0.5f,  1.0f, 0.1f, 0.0f,  0.0f,  1.0f, 00.0f, 
        -0.5f,  0.5f, -0.5f,  0.3f, 0.1f, 0.0f,  0.0f,  1.0f, 00.0f, 
    };
    this->position= new glm::vec3(position);
    this->radius=0.6;
    this->run=true;
    cube.setVetices(vertex,sizeof(vertex));
    cube.setPosition(this->position);
    cube.setCamera(this->camera);
    
    float limit=10.0;
    if(this->position->x > limit){
        this->direction.x=-1;
    }else{
        this->direction.x=1;
    }
    if(this->position->y > limit){
        this->direction.y=-1;
    }else{
        this->direction.y=1;
    }
    if(this->position->z > limit){
        this->direction.z=-1;
    }else{
        this->direction.z=1;
    }
}
void Cube::Update(){
    glm::vec3  speed = glm::vec3(*deltaTime * 1.0);
    speed *= direction; 

    cube.move(speed);

    float limit=10.0;


    if( this->position->x  > limit  && this->direction.x == 1){
        this->direction.x = -1;
    };
    if(  this->position->x  < -limit  && this->direction.x == -1){
        this->direction.x = 1;
    };
    if( this->position->y  > limit  && this->direction.y == 1){
        this->direction.y = -1;
    };
    if(  this->position->y  < -limit  && this->direction.y == -1){
        this->direction.y = 1;
    };
    if( this->position->z  > limit  && this->direction.z == 1){
        this->direction.z = -1;
    };
    if(  this->position->z  < -limit  && this->direction.z == -1){
        this->direction.z = 1;
    };

}
void Cube::Render(){
    cube.Render();
}
void Cube::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Cube::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Cube::getPosition(){
    return *this->position;
}
double Cube::getRadio(){
    return this->radius;
}
bool Cube::getRun(){
    return this->run;
}
void Cube::colision(Iobjet_colicion *a){
    if( a->type == TypeObjet::Bullet){
        this->run=false;
    }
}
void Cube::setCamera(Camera *camera){
    this->camera= camera;
}
