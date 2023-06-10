#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"

class DrawCube{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 *translate;
        Camera *camera;
    public:
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setPosition(glm::vec3 * position);
        void setCamera(Camera *camera);
        
        void move(glm::vec3 translate);
};
