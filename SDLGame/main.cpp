#include "SDL.h"
#include "Game.h"
#undef main

Game* g1 = nullptr;

int main(int argc, char *argv[]) {
	g1 = new Game();

	const int FPS = 60;//refresh rate
	const int delay = 1000 / FPS; //max time between frames

	Uint32 frameStart;
	int frameTime;

	g1->init("DataFrame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (g1->active()) {

		frameStart = SDL_GetTicks();

		g1->eventHandler();
		g1->update();
		g1->render();
		g1->tickPrint();

		frameTime = SDL_GetTicks() - frameStart;

		if (delay > frameTime) {
			SDL_Delay(delay - frameTime);
		}
	}

	g1->memManage();
	g1->~Game();

	return 0;
}