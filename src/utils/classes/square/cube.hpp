#pragma once
#include "../Draw/cube/cube.hpp"
#include "../collision.hpp"
#include "../camera/camera.hpp"

class Cube:public Iobjet_colicion{
    private:
        double * deltaTime;
        DrawCube cube;
        double radius;
        bool run=false;
        glm::vec3 direction;
        Camera *camera;
    public:
        void Init(glm::vec3 position);
        void Update();
        void Render();
        
        void setDeltaTime(double *deltaTime);
        void setRadius(unsigned int radius);
        void setCamera(Camera *camera);
        
        bool getRun() override;
        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
};
