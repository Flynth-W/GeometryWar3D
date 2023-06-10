#pragma once

#include "../collision.hpp"
#include "../square/cube.hpp"
#include <queue>

using namespace std;

class SysSquare{
    public:
        int numSquares; 
        unordered_map<int,Cube *> squares;
        unordered_map<Cube *, int> keySquares;
        CollisionsHandler *handleCollision;
        double *deltaTime;
        queue<int> deleteSquares;
        float createTime;
        Camera *camera;
    public:
        void Init();
        void Update();
        void Render();

        void AddSquare();
        void removeSquare();
        void setDeltaTime(double *deltaTime);
        void setCollisionHandler(CollisionsHandler *handleCollision);
        void setCamare(Camera *camera);
};
