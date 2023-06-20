#include "skybox.hpp"

void DrawSkyBox::InitBuffers(){
    float skyboxVertices[] = {
        // positions          
        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, -1.0f, 
        -1.0f, -1.0f, -1.0f,  0.5f, 0.2f, 0.0f,  0.0f,  0.0f, -1.0f,  
         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, -1.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, -1.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 0.5f, 0.3f,  0.0f,  0.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  -1.0f,  0.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,  0.5f, 0.2f, 0.0f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f,  1.0f,  0.0f, 0.5f, 0.3f,  -1.0f,  0.0f,  0.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  -1.0f,  0.0f,  0.0f,

         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  1.0f,  0.0f,  0.0f,
         1.0f, -1.0f,  1.0f,  0.5f, 0.2f, 0.0f,  1.0f,  0.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  1.0f,  0.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  1.0f,  0.0f,  0.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 0.5f, 0.3f,  1.0f,  0.0f,  0.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  1.0f,  0.0f,  0.0f,

        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,  0.0f, 0.5f, 0.3f,  0.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f,  0.5f, 0.2f, 0.0f,  0.0f,  0.0f, 1.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  0.0f, 1.0f,

        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  1.0f, 00.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 0.5f, 0.3f,  0.0f,  1.0f, 00.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  1.0f, 00.0f,
         1.0f,  1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  1.0f, 00.0f,
        -1.0f,  1.0f,  1.0f,  0.0f, 0.5f, 0.3f,  0.0f,  1.0f, 00.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  1.0f, 00.0f,

        -1.0f, -1.0f, -1.0f,  0.5f, 0.2f, 0.0f,  0.0f,  -1.0f, 00.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  -1.0f, 00.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  -1.0f, 00.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  -1.0f, 00.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.1f, 0.1f,  0.0f,  -1.0f, 00.0f,
         1.0f, -1.0f,  1.0f,  0.5f, 0.2f, 0.0f,  0.0f,  -1.0f, 00.0f, 
    };
    // skybox VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
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
void DrawSkyBox::Init(){
    this->shader = new Shader("./shader/skybox/skybox.vs","./shader/skybox/skybox.fs");
    this->InitBuffers();
}
void DrawSkyBox::Render(){
        // draw skybox as last
        glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        this->shader->use();
        glm::mat4 view = glm::mat4(glm::mat3(*this->camera->view)); // remove translation from the view matrix
        glm::mat4 model = glm::mat4(1.0);
        this->shader->setMat4("view", view);
        this->shader->setMat4("model", model);
        this->shader->setMat4("projection", *this->camera->projection);
        
        this->shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        this->shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
        glm::vec3 lightPos(0.1f, 0.1f, 0.1f);
        this->shader->setVec3("lightPos", lightPos);
        this->shader->setVec3("viewPos", this->camera->cameraPos);
        // skybox cube
        glBindVertexArray(skyboxVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default

}
void DrawSkyBox::setCamera(Camera *camera){
    this->camera=camera;
}
