#include "sysSquares.hpp"

double RandomData(){
    int num =rand() % 1000;
    double increase=11.0;
    double result =(num * 0.001) + increase; 
    if( (num %2 ) == 1   ){
       result *=-1; 
    }
    return result;
}
void SysSquare::AddSquare(){
    double x = RandomData();
    double y = RandomData();
    double z = RandomData();
    squares[numSquares]= new Cube();
    squares[numSquares]->setDeltaTime(deltaTime); 
    squares[numSquares]->setCamera(this->camera); 
    squares[numSquares]->setRadius(2); 
    squares[numSquares]->Init(glm::vec3(x,y,z)); 
    
    keySquares[squares[numSquares]]=numSquares;

    handleCollision->add(squares[numSquares]);
    numSquares++;
}

void SysSquare::Init(){
    srand((unsigned)time(NULL));
    this->AddSquare();
    this->createTime=0;
}
void SysSquare::Update(){
    
    this->createTime+=*deltaTime;
    if(this->createTime > 2){
      this->createTime-=2;
      this->AddSquare();
      this->AddSquare();
    }

    for ( auto item : this->squares ){
        if( item.second->getRun() ){
          item.second->Update();
        }
        else{
          int numObj= keySquares[item.second];
          keySquares.erase(item.second);
          deleteSquares.push(numObj);
        }
    };
    removeSquare();
}
void SysSquare::removeSquare(){
  while(deleteSquares.size()!=0){
    int _num=deleteSquares.front();
    squares.erase(_num);
    deleteSquares.pop();
  }
};
void SysSquare::Render(){
  for ( auto &item : this->squares ){
    if( item.second->getRun()){
      item.second->Render();
    }
  };
}
void SysSquare::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void SysSquare::setCollisionHandler(CollisionsHandler *handleCollision){
    this->handleCollision=handleCollision;
}
void SysSquare::setCamare(Camera *camera){
    this->camera = camera;
}
