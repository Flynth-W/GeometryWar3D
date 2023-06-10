#include "song.hpp"

Song::Song(const char *file, bool loop){
  engine = createIrrKlangDevice();
  engine->play2D(file, loop, true);
}
void Song::play(){
      engine->setAllSoundsPaused(false);
}
void Song::anotherPlay(const char *file){
    engine->play2D(file);
}
