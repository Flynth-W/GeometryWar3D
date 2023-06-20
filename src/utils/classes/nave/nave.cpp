#include "nave.hpp"

void Nave::Init(){
    float vertex[] = {
                                               
         0.0f,  0.3f,  0.2f,    0.0f, 0.5f, 0.3f,  0.0f,  0.3f,  0.2f, 
        -0.5f,  0.0f,  0.5f,    0.0f, 0.1f, 0.3f, -0.5f,  0.0f,  0.5f, 
         0.5f,  0.0f,  0.5f,    0.0f, 0.1f, 0.3f,  0.5f,  0.0f,  0.5f,

         0.0f,  0.3f,  0.2f,    0.0f, 0.5f, 0.3f,  0.0f,  0.3f,  0.2f, 
        -0.5f,  0.0f,  0.5f,    0.0f, 0.1f, 0.3f, -0.5f,  0.0f,  0.5f, 
         0.0f,  0.0f, -1.5f,    1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.5f,

         0.0f,  0.3f,  0.2f,    0.0f, 0.5f, 0.3f,  0.0f,  0.3f,  0.2f, 
         0.5f,  0.0f,  0.5f,    0.0f, 0.1f, 0.3f,  0.5f,  0.0f,  0.5f, 
         0.0f,  0.0f, -1.5f,    1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.5f,

        -0.5f,  0.0f,  0.5f,    0.0f, 0.0f, 0.0f, -0.5f,  0.0f,  0.5f,
         0.0f,  0.0f, -1.5f,    0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.5f,
         0.5f,  0.0f,  0.5f,    0.0f, 0.0f, 0.0f,  0.5f,  0.0f,  0.5f,
    };
    this->song= new Song("./songs/bullet.wav",false);
    this->movement= Movement::none;
    this->type=TypeObjet::Nave;
    this->run=true;
    this->radio=1.3;
    this->position=new  glm::vec3(0.5,-0.5,-2.0);
    
    this->nave.setVetices(vertex, sizeof(vertex));
    this->nave.setPosition(this->position);
    this->nave.setCamera(this->camera);
    
    Event::setKey(keys, GLFW_KEY_J);
    Event::setKey(keys, GLFW_KEY_L);
    Event::setKey(keys, GLFW_KEY_I);
   
    bullets.setDeltaTime(this->deltaTime);
    bullets.setCollisionHandler(this->handleCollision);
    bullets.setCamera(this->camera);
    bullets.Init();
    
}
void Nave::events(){
    this->movement= Movement::none;
    float translationSpeed = 1.5;
    float rotationSpeed = 2.0;
    
    if( Event::getIfStateKey(keys, GLFW_KEY_W,ButtonState::Pressed ,ButtonState::Repeat) ){
        glm::vec3 translate=glm::vec3( 0.0f ,0.0f ,float( -translationSpeed * *deltaTime )  );
        nave.move( translate);
        if(this->viewReverse){
            if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(1.0f * *deltaTime);
            }
            if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(-1.0f * *deltaTime);
            }
        }else{
            if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(-1.0f * *deltaTime);
            }
            if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(1.0f * *deltaTime);
            }
        }

        if(Event::getIfStateKey(keys,GLFW_KEY_I, ButtonState::Pressed , ButtonState::Repeat )){
                this->movement= Movement::top;
                this->nave.rotateVertical(1.0f * *deltaTime);
        }
        if(Event::getIfStateKey(keys,GLFW_KEY_K, ButtonState::Pressed , ButtonState::Repeat )){
                this->movement= Movement::buttom;
                this->nave.rotateVertical(-1.0f * *deltaTime);
        }
    }
    if( Event::getIfStateKey(keys, GLFW_KEY_S,ButtonState::Pressed ,ButtonState::Repeat) ){
        glm::vec3 translate=glm::vec3( 0.0f ,0.0f ,float( translationSpeed * *deltaTime )  );
        nave.move( translate);
        
        if(this->viewReverse){
            if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(-1.0f * *deltaTime);
            }
            if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(1.0f * *deltaTime);
            }
        }else{
            if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(1.0f * *deltaTime);
            }
            if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
                this->nave.rotateHorizontal(-1.0f * *deltaTime);
            }
        }

        if(Event::getIfStateKey(keys,GLFW_KEY_I, ButtonState::Pressed , ButtonState::Repeat )){
                this->movement= Movement::buttom;
                this->nave.rotateVertical(-1.0f * *deltaTime);
        }
        if(Event::getIfStateKey(keys,GLFW_KEY_K, ButtonState::Pressed , ButtonState::Repeat )){
                this->movement= Movement::top;
                this->nave.rotateVertical(1.0f * *deltaTime);
        }
    }
    if(Event::getIfStateKey(keys,GLFW_KEY_J, ButtonState::Released)){
        this->bullets.AddBullet(*this->position, this->nave.angleHorizontal, this->nave.angleVertical);
        this->song->anotherPlay("./songs/bullet.wav");
    }

}
void Nave::Update(){
    this->events();
    nave.Update();
    bullets.Update();
}
void Nave::checkOrinetation( double Ycurrent ){

    if(this->movement == Movement::top){
        if(viewReverse){
            if(  !( Ycurrent > Yprevious  )){
                viewReverse=false;
            } 
        }else{
            if(  !( Yprevious > Ycurrent )){
                viewReverse=true;
            } 
        }
    }
    if(this->movement == Movement::buttom){
        if(viewReverse==true){
            if(   !( Yprevious > Ycurrent )){
                viewReverse=false;
            } 
        }else{
            if(  !( Ycurrent > Yprevious )){
                viewReverse=true;
            } 
        }
    }
}
void Nave::view(){
    glm::mat4 model = this->nave.model;
    
    glm::mat4 front = glm::mat4(model);
              front = glm::translate(front, glm::vec3(0.0,2.0,-1.0));
    glm::vec3 cameraFront = glm::vec3(front[3][0],front[3][1],front[3][2]);
    
    glm::mat4 position  = glm::mat4(model);
              position  = glm::translate(position, glm::vec3( 0.0 , 3.0 , 8.0));
    glm::vec3 cameraPos = glm::vec3(position[3][0] , position[3][1] , position[3][2]);
    

    double Ycurrent = cameraPos.y - cameraFront.y; 
    this->checkOrinetation(Ycurrent);
    Yprevious=Ycurrent;

    glm::vec3 cameraUp = glm::vec3(0.0);
    if(viewReverse == true){
        cameraUp.y=-1;
    }else{
        cameraUp.y=1;
    }
    *camera->view = glm::lookAt(cameraPos,  cameraFront, cameraUp);
    this->camera->cameraPos=cameraPos;
}
void Nave::Render(){
    this->view();
    this->nave.Render();
    this->bullets.Render();
}
void Nave::setDeltaTime(double *deltaTime){
    this->deltaTime = deltaTime;
}
void Nave::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
bool Nave::getRun(){
    return this->run;
}

glm::vec3 Nave::getPosition(){
    return *this->position;
}
double Nave::getRadio(){
    return this->radio;
}
void Nave::colision(Iobjet_colicion *a){
    if(a->type == TypeObjet::Square){
        std::cout << "nave -> cube" << std::endl;
    }
}

void Nave::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
void Nave::setCamera(Camera *camera){
    this->camera=camera;
}
void Nave::setMouse(Mouse *mouse){
    this->mouse = mouse;
}
void Nave::setMouseKeys(std::unordered_map<int, ButtonKey> *mousekeys){
    this->mouseKeys = mousekeys;
}
