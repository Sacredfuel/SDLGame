#pragma once
#include "Game.h"

class Texture {
public:
	static SDL_Texture* generateTexture(const char* title);
	static void Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect destination);

};