WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = `sdl-config --cflags` -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = `sdl-config --libs`

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -Os -std=c++0x -g
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s -lSDL_gfx -lSDL_image -lSDL_ttf
OBJDIR_RELEASE = obj
DEP_RELEASE = 
OUT_RELEASE = Swrid

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/PointBonusElement.o $(OBJDIR_RELEASE)/src/Player.o $(OBJDIR_RELEASE)/src/MenuScreen.o $(OBJDIR_RELEASE)/src/GridModeNormal.o $(OBJDIR_RELEASE)/src/GridModeHard.o $(OBJDIR_RELEASE)/src/Grid.o $(OBJDIR_RELEASE)/src/GameScreen.o $(OBJDIR_RELEASE)/src/Engine.o $(OBJDIR_RELEASE)/src/ElementUI.o $(OBJDIR_RELEASE)/src/Element.o $(OBJDIR_RELEASE)/src/Button.o $(OBJDIR_RELEASE)/src/BaseElement.o $(OBJDIR_RELEASE)/main.o

all: release

clean: clean_release

before_release: 
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/src/PointBonusElement.o: src/PointBonusElement.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/PointBonusElement.cpp -o $(OBJDIR_RELEASE)/src/PointBonusElement.o

$(OBJDIR_RELEASE)/src/Player.o: src/Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Player.cpp -o $(OBJDIR_RELEASE)/src/Player.o

$(OBJDIR_RELEASE)/src/MenuScreen.o: src/MenuScreen.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/MenuScreen.cpp -o $(OBJDIR_RELEASE)/src/MenuScreen.o

$(OBJDIR_RELEASE)/src/GridModeNormal.o: src/GridModeNormal.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/GridModeNormal.cpp -o $(OBJDIR_RELEASE)/src/GridModeNormal.o

$(OBJDIR_RELEASE)/src/GridModeHard.o: src/GridModeHard.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/GridModeHard.cpp -o $(OBJDIR_RELEASE)/src/GridModeHard.o

$(OBJDIR_RELEASE)/src/Grid.o: src/Grid.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Grid.cpp -o $(OBJDIR_RELEASE)/src/Grid.o

$(OBJDIR_RELEASE)/src/GameScreen.o: src/GameScreen.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/GameScreen.cpp -o $(OBJDIR_RELEASE)/src/GameScreen.o

$(OBJDIR_RELEASE)/src/Engine.o: src/Engine.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Engine.cpp -o $(OBJDIR_RELEASE)/src/Engine.o

$(OBJDIR_RELEASE)/src/ElementUI.o: src/ElementUI.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/ElementUI.cpp -o $(OBJDIR_RELEASE)/src/ElementUI.o

$(OBJDIR_RELEASE)/src/Element.o: src/Element.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Element.cpp -o $(OBJDIR_RELEASE)/src/Element.o

$(OBJDIR_RELEASE)/src/Button.o: src/Button.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Button.cpp -o $(OBJDIR_RELEASE)/src/Button.o

$(OBJDIR_RELEASE)/src/BaseElement.o: src/BaseElement.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/BaseElement.cpp -o $(OBJDIR_RELEASE)/src/BaseElement.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf $(OBJDIR_RELEASE)/src
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_release after_release clean_release

