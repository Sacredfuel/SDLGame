#include "Game.h"
#include "Texture.h"
#include "GameEngine.h"
#include "Tilemap.h"
#include "GameStack.h"
#include <stdio.h>

#define DEBUG 1                                                                 //change debug to 0 to enter release mode

GameEngine* player = nullptr;
GameEngine* player2 = nullptr;

Game::Game() {}                                                                 //constructor
Game::~Game() {}                                                                //destructor

SDL_Renderer* Game::render1 = nullptr;
SDL_Rect* sourceRect, destinationRect;
Tilemap* map;

void Game::init(const char* windowname, int xpos, int ypos, int width, int height, bool maximize)
{
	int flag = 0;
	if (maximize) {                                                             //checks the user for fullscreen
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {                                   //initializes SDL
		printf("System Initializition has begun...\n");
		window1 = SDL_CreateWindow(windowname, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (window1) { 
			printf("System window initialized!\n");                             //if the window not = 0(false), then it is created
		}
		render1 = SDL_CreateRenderer(window1, -1, 0);
		if (render1) {                                                          //if the renderer not = 0(false), then it is created
			SDL_SetRenderDrawColor(render1, 255, 255, 255, 255);
			printf("System renderer initialized!\n");
		}
		isRunning = true;
		
		player = new GameEngine("Assets/VillianMain.png", 0, 0);                //creates new sprite with name player
		player2 = new GameEngine("Assets/CharacterForward.png", 0, 400);        //creates new prite at 0,400 with name player1

		map = new Tilemap();                                                    //creates a tilemap
		map->LoadTilemap("Maps/SampleMap.txt");                                 //loads SampleMap
	}
	else {
		isRunning = false;                                                      //if SDL fails to initialize, stop the game
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
		player->EventHandler(event1, map->flag);                                           //updates Villian sprite with UI in event1 (to remove)
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();
	player2->update();
	//map->LoadTilemap();
}

void Game::tickPrint()
{
#if DEBUG																	    //remove in release version
	currentTick++;
	if (currentTick % 100 == 0) {
		printf("%d\n", currentTick);                                            //prints every 100 ticks, for debug use only
	}
	if (currentTick == 1000) {
		map->LoadTilemap("Maps/SampleMapGrassy.txt");
	}
#endif
}

void Game::render()
{
	SDL_RenderClear(render1);
	map->DrawTileMap();                                                         //draws the tilemap
	player->render();														    //draws the villian
	player2->render();
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
