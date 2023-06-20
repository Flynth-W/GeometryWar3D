#include "cube.hpp"
#include <iostream>

void DrawCube::Render(){
    this->shader->use();
    this->model = glm::mat4(1.0);
    this->model = glm::translate(this->model,*this->translate );
    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    this->shader->setVec3("color", glm::vec3(0.4,0.4,0.3));
    
    this->shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    this->shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos(0.1f, 0.1f, 0.1f);
    this->shader->setVec3("lightPos", lightPos);
    this->shader->setVec3("viewPos", this->camera->cameraPos);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}


void DrawCube::setVetices(float *vertex, unsigned int vertexSize){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);

    // position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    // color attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    // normal attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));

    this->shader= new Shader("./shader/cube.vs" ,"./shader/cube.fs");
}
void DrawCube::move(glm::vec3 translate){
    *this->translate= *this->translate + translate;
}

void DrawCube::setPosition(glm::vec3 *position){
    this->translate = position;
}
void DrawCube::setCamera(Camera *camera){
    this->camera = camera ;
}
