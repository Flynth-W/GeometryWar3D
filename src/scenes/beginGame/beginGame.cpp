#include "beginGame.hpp"

void BeginGame::Init(){
    this->camera= new Camera(1000,1000);
    this->stage=Stages::beginGame;

    this->cubes.setDeltaTime(deltaTime);
    this->cubes.setCamare(this->camera);
    this->cubes.setCollisionHandler(&this->handlerCollision);
    this->cubes.Init();

    nave.setKeys(keys);
    nave.setDeltaTime(deltaTime);
    nave.setCamera(this->camera);
    nave.setCollisionHandler(&this->handlerCollision);
    nave.Init();
    handlerCollision.add(&nave);
};
void BeginGame::Update(){
    this->handlerCollision.resertState();
    this->handlerCollision.loopState();

    this->nave.Update();
    this->cubes.Update();
};
void BeginGame::Render(){

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1f, 0.0f, 0.0f,1.0f);
    this->nave.Render();
    this->cubes.Render();
};

void BeginGame::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void BeginGame::setMouse(Mouse *mouse){
    this->mouse=mouse;
};
void BeginGame::setKeys(std::unordered_map<int,ButtonKey>*Keys){
    this->keys=Keys;
};
void BeginGame::setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys){
    this->mouseKeys=mouseKeys;
};

Stages BeginGame::getStage(){
    return this->stage ;
}
