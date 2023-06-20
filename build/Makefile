OBJS = ../src/main.o \
	   ../src/app/app.o \
	   ../src/scenes/orchestrator.o \
	   ../src/scenes/beginGame/beginGame.o \
	   ../src/factory/app/app.o \
	   ../src/event/events.o  \
	   ../src/utils/classes/nave/nave.o \
	   ../src/utils/classes/square/cube.o \
	   ../src/utils/classes/collision.o \
	   ../src/utils/classes/sysSquares/sysSquares.o \
	   ../src/utils/classes/bullet/bullet.o \
	   ../src/utils/classes/Draw/bullet/bullet.o \
	   ../src/utils/classes/sysBullets/sysBullet.o \
	   ../src/utils/classes/song/song.o \
	   ./irrKlang/bin/linux-gcc-64/libIrrKlang.so \
	   ../src/utils/classes/Draw/cube/cube.o \
	   ../src/utils/classes/camera/camera.o  \
	   ../src/utils/classes/Draw/nave/nave.o \
	   ../src/utils/classes/Draw/skybox/skybox.o 

FILE_BIN = Asteroid.bin
LIBS = -lGL -lglfw -lGLEW 
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm $(FILE_BIN) ../src/*.o ../src/*/*.o ../src/*/*/*.o ../src/*/*/*/*.o ../src/*/*/*/*/*.o
th: 
	@ ./mk $(OBJS) $(LIBS) 
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
