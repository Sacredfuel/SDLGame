#pragma once
#include "Game.h"

class GameEngine {
public:

	GameEngine(const char* texloc , int x, int y);//constructor
	~GameEngine();//destructor

	void update();//sets the character to appear at a certain x and y coord
	void EventHandler(SDL_Event c);//handles all WASD input
	void render();//puts character on the screen based on coords from update()

private:

	int xpos;
	int ypos;
	SDL_Texture* texture; 
	//Texture object that holds the image of the respective character
	SDL_Rect sourceRect, destinationRect;
	//used to make size proportions for characters

};

enum Type {
	PLAYER = 0,
	ENEMY = 1,
	BOSS = 2,
	UNDEF = 9
};