#pragma once
#include "Game.h"

class Texture {
public:
	static SDL_Texture* generateTexture(const char* title, SDL_Renderer* render);
};