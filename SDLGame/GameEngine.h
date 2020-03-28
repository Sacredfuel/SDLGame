#pragma once
#include "Game.h"
class GameEngine {
public:

	GameEngine(const char* texloc , int x, int y);
	~GameEngine();

	void update();
	void render();

private:

	int xpos;
	int ypos;
	SDL_Texture* texture;
	SDL_Rect sourceRect, destinationRect;
};