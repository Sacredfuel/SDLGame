#include "Game.h"
#include "Texture.h"
#include "GameEngine.h"
#include "Tilemap.h"
#include "GameStack.h"
#include <stdio.h>

#define DEBUG 0                                                                 //change debug to 0 to enter release mode

GameEngine* player = nullptr;

Game::Game() {}                                                                 //constructor
Game::~Game() {}                                                                //destructor

SDL_Renderer* Game::render1 = nullptr;
SDL_Rect* sourceRect, destinationRect;
Tilemap* map;

void Game::init(const char* windowname, int xpos, int ypos, int width, int height, bool maximize)
{
	int flag = 0;
	if (maximize) {                                                             
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {                                   
		printf("System Initializition has begun...\n");
		window1 = SDL_CreateWindow(windowname, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (window1) { 
			printf("System window initialized!\n");                     
		}
		render1 = SDL_CreateRenderer(window1, -1, 0);
		if (render1) {                                                        
			SDL_SetRenderDrawColor(render1, 255, 255, 255, 255);
			printf("System renderer initialized!\n");
		}
		isRunning = true;
		
		player = new GameEngine("Assets/CharacterForward.png", 0, 400);         

		map = new Tilemap();                                                    
		map->DrawEnemies();
		map->LoadTilemap("Maps/SampleMapMain.txt");                            
	}
	else {
		isRunning = false;                                                      
	}
}

void Game::eventHandler()
{
	SDL_Event event1;                                                           //event that we will check
	SDL_PollEvent(&event1);                                                     //dereference event because it requires
	switch (event1.type) {
	case SDL_QUIT:
		isRunning = false;                                                      //stops the app when gets quit request
		break;
	case SDL_KEYDOWN:
		player->EventHandler(event1);                                           //updates Villian sprite with UI in event1 (to remove)
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();
	//map->LoadTilemap();
}

void Game::tickPrint()
{
	currentTick++;
}

void Game::moveChar()
{
	if (c == 'a') {
		//if my character is in the A map(Left)
		if (player->getY() < 245 && player->getY() > 155 && player->getX() > 700 && warpA) {
			player->move(40, 215);
			c = 'b';
			map->LoadTilemap("Maps/SampleMapMain.txt");
			printf("moving to b, can go to C now");
			warpC = false;
		}
	}
	if (c == 'c') {
		//if my character is in the C map(Right)
		if (player->getY() < 245 && player->getY() > 155 && player->getX() < 40 && warpC) {
			player->move(670, 215);
			c = 'b';
			map->LoadTilemap("Maps/SampleMapMain.txt");
			printf("moving to b, can go to A now");
			warpA = false;
		}
	}
	if (c == 'b') {
		warpA = true;
		warpC = true;
		//if my character is in the B map(main)
		if (player->getY() < 245 && player->getY() > 155 && player->getX() > 700) {
			player->move(40, 215);
			c = 'c';
			map->LoadTilemap("Maps/SampleMapRight.txt");
			printf("moving to c, can no longer go to A");
			warpA = false;
		}
	}
	if(c == 'b'){
		warpA = true;
		warpC = true;
		if (player->getY() < 245 && player->getY() > 155 && player->getX() < 40) {
			player->move(700, 215);
			c = 'a';
			map->LoadTilemap("Maps/SampleMapLeft.txt");
			printf("moving to a, can no longer go to C");
			warpC = false;
		}
	}
}

void Game::render()
{
	SDL_RenderClear(render1);
	map->DrawTileMap();                                                         //draws the tilemap
	player->render();														    //draws the villian
	SDL_RenderPresent(render1);                                                 //renders everything on screen
}
																				// all the code for render and update are inside GameEngine.cpp
void Game::memManage()
{
	SDL_DestroyWindow(window1);
	SDL_DestroyRenderer(render1);
	SDL_Quit();
	printf("System buffer cleared.\n");                                         //destroys the SDL
}
