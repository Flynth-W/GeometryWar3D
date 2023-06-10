#pragma once

#include <iostream>
#include "../../../../build/irrKlang/include/irrKlang.h"
using namespace irrklang;

class Song{
    private:
        ISoundEngine *engine;
    public:
        Song(const char *file, bool loop);
        void play();
        void anotherPlay(const char *file);
};
