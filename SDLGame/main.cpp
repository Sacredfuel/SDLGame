#include "SDL.h"
#include "Game.h"
#undef main

Game* g1 = nullptr;
//Game pointer is initialized with the global scope, it is everywhere in the code
//for g1's functions check Game.cpp

int main(int argc, char *argv[]) {
	g1 = new Game();
	//the value of g1 was set

	const int FPS = 60;//refresh rate
	const int delay = 1000 / FPS; //max time between frames

	Uint32 frameStart;
	int frameTime;

	g1->init("DataFrame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	//g1 is initalized to the center of the screen, 800x640 pixel size not fullscreen

	while (g1->active()) {
		//this is the game loop, it runs while the game is active

		frameStart = SDL_GetTicks();
		//gets total amount of time since the game started to when this while loop runs

		g1->eventHandler();
		g1->update();
		g1->render();
		g1->tickPrint();
		//check g1 functions->Game.cpp

		frameTime = SDL_GetTicks() - frameStart;
		//calculated the difference between when the frame started and when it finished running

		if (delay > frameTime) {
			SDL_Delay(delay - frameTime);
		}
		//caps the FPS at 60
	}

	g1->memManage();
	g1->~Game();
	//manages the game's memory

	return 0;
}