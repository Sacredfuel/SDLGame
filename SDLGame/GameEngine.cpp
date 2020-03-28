#include "GameEngine.h"
#include "Texture.h"
#include <stdio.h>

GameEngine::GameEngine(const char* texloc, int x, int y)
{
	xpos = x;
	ypos = y;
	texture = Texture::generateTexture(texloc);
}

GameEngine::~GameEngine()
{

}

void GameEngine::update()
{
	//temp
	xpos++;

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

void GameEngine::render()
{
	SDL_RenderCopy(Game::render1, texture, &sourceRect, &destinationRect); //copies to screen
}
