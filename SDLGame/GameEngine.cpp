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
	SDL_Keycode lastMotion{};
	currentXtile = (int)destinationRect.x;
	currentYtile = (int)destinationRect.y;
	switch (c.key.keysym.sym) {
	case SDLK_d:
		printf("%d , %d\n", currentXtile, currentYtile);
		texture = Texture::generateTexture("Assets/CharacterForward.png");
		xpos += 15;
		break;
	case SDLK_a:
		printf("%d , %d\n", currentXtile, currentYtile);
		texture = Texture::generateTexture("Assets/CharacterLeft.png");
		xpos -= 15;
		break;
	case SDLK_w:
		printf("%d , %d\n", currentXtile, currentYtile);
		ypos -= 15;
		break;
	case SDLK_s:
		printf("%d , %d\n", currentXtile, currentYtile);
		ypos += 15;
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

void GameEngine::redefTexture(const char* s)
{
	texture = Texture::generateTexture(s);
}

void GameEngine::move(int x, int y)
{
	xpos = x;
	ypos = y;
}
int GameEngine::getX()
{
	return destinationRect.x;
}
int GameEngine::getY()
{
	return destinationRect.y;
} 
