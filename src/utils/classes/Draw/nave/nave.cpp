#include "nave.hpp"
#include <iostream>

DrawNave::DrawNave(){
    this->angleHorizontal=0;
    this->angleVertical=0;
    this->direction=glm::vec3(0.0);
    this->translate=glm::vec3(0.0);
    this->model = glm::mat4(1.0);
}
void DrawNave::Update(){

    glm::mat4 modelTmp = glm::mat4(1.0);
    modelTmp = glm::translate(modelTmp,*this->position );
    modelTmp = glm::rotate(modelTmp, this->angleHorizontal, glm::vec3(0.0f, 1.0f, 0.0f));
    modelTmp = glm::rotate(modelTmp, this->angleVertical, glm::vec3(1.0f, 0.0f, 0.0f));
    modelTmp = glm::translate(modelTmp,this->translate );
    this->model=modelTmp;

    this->position->x=this->model[3][0];
    this->position->y=this->model[3][1];
    this->position->z=this->model[3][2];
   
    this->translate=glm::vec3(0.0);
    
}

void DrawNave::Render(){
    this->shader->use();
    

    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    
    this->shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    this->shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos(0.1f, 0.1f, 0.1f);
    this->shader->setVec3("lightPos", lightPos);
    this->shader->setVec3("viewPos", this->camera->cameraPos);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glBindVertexArray(0);
}


void DrawNave::setVetices(float *vertex, unsigned int vertexSize){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // normal attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));

    this->shader= new Shader("./shader/nave/nave.vs" ,"./shader/nave/nave.fs");
}
void DrawNave::move(glm::vec3 translate){
    this->translate += translate;
}

void DrawNave::setPosition(glm::vec3 *position){
    this->position = position;
}
void DrawNave::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawNave::rotateHorizontal(float angle){
    this->angleHorizontal += angle;
}
void DrawNave::rotateVertical(float angle){
    this->angleVertical += angle;
}
