#pragma once
#include "../stage.hpp"
#include "../../utils/classes/camera/camera.hpp"
#include "../../utils/classes/nave/nave.hpp"
#include "../../utils/classes/square/cube.hpp"
#include "../../utils/classes/sysSquares/sysSquares.hpp"
#include "../../utils/classes/collision.hpp"
#include "../../utils/classes/Draw/skybox/skybox.hpp"
#include "../../utils/classes/button/button.hpp"

class BeginGame:public Stage{
    private:
        double *deltaTime;
        std::unordered_map<int,ButtonKey>*keys;
        std::unordered_map<int,ButtonKey>*mouseKeys;
        Mouse *mouse;
        Stages stage;
        SysSquare cubes; 
        Camera *camera;
        Nave nave;
        CollisionsHandler handlerCollision;
        DrawSkyBox skyBox;
        DrawButton *button;
    public:
        void Init()   override;
        void Update() override;
        void Render() override;
        void setDeltaTime(double *deltaTime) override;
        void setMouse(Mouse *mouse) override;
        void setKeys(std::unordered_map<int,ButtonKey>*Keys) override;
        void setMouseKeys(std::unordered_map<int,ButtonKey>*mouseKeys) override;
        Stages getStage()override;
};
