#include "GameEngine.h"
#include "Texture.h"
#include <stdio.h>

GameEngine::GameEngine(SDL_Texture* tex, SDL_Renderer* renderRec, int x, int y)
{
	xpos = x;
	ypos = y;
	renderer = renderRec;
	texture = tex;
}

GameEngine::~GameEngine()
{

}

void GameEngine::update()
{
	//temp
	xpos++;
	ypos++;

	sourceRect.h = 0;
	sourceRect.w = 0;
	destinationRect.h = 63;
	destinationRect.w = 45;

	/*
	sourceRect.h = 63;
	sourceRect.w = 45;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = xpos;
	destinationRect.y = ypos;
	destinationRect.w = sourceRect.w * 2;
	destinationRect.h = sourceRect.h * 2;
	*/
}

void GameEngine::render()
{
	SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect); //copies to screen
}
