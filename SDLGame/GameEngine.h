#pragma once
#include "Game.h"
class GameEngine {
public:

	GameEngine(SDL_Texture* tex, SDL_Renderer* renderRec, int x, int y);
	~GameEngine();

	void update();
	void render();

private:

	int xpos;
	int ypos;
	SDL_Texture* texture;
	SDL_Rect sourceRect, destinationRect;
	SDL_Renderer* renderer;
};