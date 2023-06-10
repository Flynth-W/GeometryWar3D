#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"

class DrawNave{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        Camera *camera;
        glm::vec3 direction;
        glm::vec3 translate=glm::vec3(0.0);
    public:
        float angleHorizontal;
        float angleVertical;
        glm::mat4 model;
        glm::vec3 *position;
    public:
        DrawNave();
        void Update();
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setPosition(glm::vec3 * position);
        void setCamera(Camera *camera);
        void move(glm::vec3 translate);
        void rotateHorizontal(float angle);
        void rotateVertical(float angle);
};
