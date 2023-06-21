#pragma once

#include "../shader.hpp"
#include "../camera/camera.hpp"

enum class DrawButtonState{
    none,
    down,
    up,
};


class DrawButton{
    private:
        glm::vec3 position;
        Camera *camera;
        DrawButtonState state;
        Shader *shader;
        glm::mat4 model;
        unsigned int VBO, VAO;
    public:
        DrawButton();
        void Update();
        void Render();
        void setPosition(glm::vec3 position);
        void setCamera(Camera *camera);
        void setState(DrawButtonState state);
        bool touch();
        DrawButtonState getState(); 
    private:
        void initBuffer();
        void initShader();


};


