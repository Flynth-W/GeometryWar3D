#pragma once
#include <android/asset_manager.h>
#include <GLES3/gl3.h>
#include <string>
#include "AndroidOut.h"
void hello();
void readText(AAssetManager *assetManager, const std::string &assetPath);


class Triangle{
    private:
        unsigned int VBO, VAO;
        GLuint shaderProgram;
    public:
        void Init();
        void Render();
};
