#pragma once
#include "../../shader.hpp"
#include "../../camera/camera.hpp"

class DrawSkyBox{
    private:
        Shader *shader;
        unsigned int skyboxVAO, skyboxVBO;
        Camera *camera;
    public:
        void Init();
        void Render();
        void setCamera(Camera *camera);
    private:
        void InitBuffers();
};
