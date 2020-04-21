#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* windowname, int xpos, int ypos, int width, int height, bool maximize); //creates a game class
	void eventHandler(); //handles user input
	void update(); //updates events in the game
	void render(); //renders textures according to update
	void memManage(); //deletes junk
	void tickPrint();//outputs the current Tick every 100 ticks
	void moveChar();//moves to next tilemap

	static SDL_Renderer* render1;

	bool active() { return isRunning; };//tells if the game is active

private:
	bool isRunning;
	int currentTick = 0;
	char c = 'b';
	bool warpA = true;
	bool warpC = true;
	SDL_Window *window1;
};