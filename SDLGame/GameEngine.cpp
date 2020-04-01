#include "GameEngine.h"
#include "Texture.h"
#include <stdio.h>

GameEngine::GameEngine(const char* texloc, int x, int y)
{
	xpos = x;
	ypos = y;
	texture = Texture::generateTexture(texloc);
	//puts the character at the initial position, and generates the sprite and stores it as a texture
}

GameEngine::~GameEngine()
{}

void GameEngine::update()
{
	//Character is 63x45 pixels

	sourceRect.h = 63;
	sourceRect.w = 45;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = xpos;
	destinationRect.y = ypos;
	destinationRect.h = sourceRect.h * 2;
	destinationRect.w = sourceRect.w * 2;


	/*
	destinationRect.x = xpos;
	destinationRect.y = ypos;
	*/
}

void GameEngine::EventHandler(SDL_Event c) {
	//handles WASD input
	SDL_KeyCode lastMotion;
	switch (c.key.keysym.sym) {
	case SDLK_d:
		if (lastMotion != SDLK_d) {
			//turn
		}
		xpos+=5;
		break;
	case SDLK_a:
		if (lastMotion != SDLK_a) {
			//turn
		}
		xpos-=5;
		break;
	case SDLK_w:
		if (lastMotion != SDLK_w) {
			//turn
		}
		ypos -= 5;
		break;
	case SDLK_s:
		if (lastMotion != SDLK_s) {
			//turn
		}
		ypos += 5;
		break;
	default:
		break;
	}
	lastMotion = c.key.keysym.sym;
}

void GameEngine::render()
{
	//puts the charcter to the window1 via renderer
	SDL_RenderCopy(Game::render1, texture, &sourceRect, &destinationRect); //copies to screen
}
