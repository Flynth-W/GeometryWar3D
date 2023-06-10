#pragma once

#include "../sysBullets/sysBullet.hpp"
#include "../../../event/events.hpp"
#include "../collision.hpp"
#include "../song/song.hpp"
#include "../Draw/nave/nave.hpp"

enum class Movement{
    none,
    up,
    down,
    right,
    left,
    top,
    buttom,
};

class Nave:public Iobjet_colicion{
    private:
        Movement movement;
        double Yprevious=4.0;
        bool viewReverse=false;
        DrawNave nave;
        double radio;
        double * deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
        bool run=false;
        SysBullet bullets;
        CollisionsHandler *handleCollision;
        Song *song;
        Camera *camera;
    public:
        void Init();
        void Update();
        void Render();
        void setCollisionHandler(CollisionsHandler *handleCollision);
        void setDeltaTime(double *deltaTime);
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) ;
        void setMouseKeys(std::unordered_map<int,ButtonKey>*mousekeys) ;
        void setMouse(Mouse *mouse);
        bool getRun() override;

        glm::vec3 getPosition() override;
        double getRadio() override;
        void colision(Iobjet_colicion *a) override;
        void setCamera(Camera *camera);

    private:
        void events();
        void view();
        void checkOrinetation(double Ycurrent);
};
