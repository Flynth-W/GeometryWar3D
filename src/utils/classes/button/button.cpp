#include "button.hpp"

void DrawButton::initBuffer(){
    this->shader= new Shader("./shader/button/button.vs" ,"./shader/button/button.fs");
}
void DrawButton::initShader(){
    
    float vertex[] = {
        -0.003f, -0.003f, -0.1f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.003f, -0.003f, -0.1f,  1.0f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.003f,  0.003f, -0.1f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
         0.003f,  0.003f, -0.1f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f, 
        -0.003f,  0.003f, -0.1f,  0.0f, 0.5f, 0.3f,  0.0f,  0.0f, -1.0f, 
        -0.003f, -0.003f, -0.1f,  0.3f, 0.1f, 0.0f,  0.0f,  0.0f, -1.0f,
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    // position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    // color attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    // normal attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));

}

DrawButton::DrawButton(){
   this->state=DrawButtonState::none; 
   this->initShader();
   this->initBuffer();
}
void DrawButton::Update(){
    //change light
}
void DrawButton::Render(){
    
    this->shader->use();
    this->model = glm::mat4(1.0);
    //this->model = glm::translate(this->model,*this->translate );
    this->shader->setMat4("model", this->model);
    //this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
void DrawButton::setPosition(glm::vec3 position){
    this->position=position;
}
void DrawButton::setCamera(Camera *camera){
    this->camera= camera;
}
void DrawButton::setState(DrawButtonState state){
    this->state=state;
}
bool touch(){
    return false; 
};
DrawButtonState DrawButton::getState(){
    return this->state;
}

