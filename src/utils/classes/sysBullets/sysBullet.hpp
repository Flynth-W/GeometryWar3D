#pragma once

#include "../bullet/bullet.hpp"

class SysBullet{
    public:
        unordered_map<int,Bullet *>  bullets;
        unordered_map<Bullet *, int> keyBullets;
        CollisionsHandler *handleCollision;
        Camera  *camera;
        
        int numBullets; 
        bool limitBall;
        double *deltaTime;
    public:
        void Init();
        void Update();
        void Render();

        void AddBullet(glm::vec3 position, float angleHorizontal , float angleVertical);
        void setDeltaTime(double *deltaTime);
        void setCollisionHandler(CollisionsHandler *handleCollision);
        void setCamera(Camera *camera);
};
