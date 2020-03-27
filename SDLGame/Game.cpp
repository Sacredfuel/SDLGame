#include "Game.h"
#include "Texture.h"
#include "GameEngine.h"
#include <stdio.h>

GameEngine* player = nullptr;

Game::Game() {} //constructor
Game::~Game() {} //destructor

/*Debugging code*/

SDL_Texture* playerDeb;
SDL_Rect* sourceRect, destinationRect;

/*End Debug*/


void Game::init(const char* windowname, int xpos, int ypos, int width, int height, bool maximize)
{
	int flag = 0;
	if (maximize) { //checks the user for fullscreen
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //initializes SDL
		printf("System Initializition has begun...\n");
		window1 = SDL_CreateWindow(windowname, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (window1) { //if the window not = 0(false), then it is created
			printf("System window initialized!\n");
		}
		render1 = SDL_CreateRenderer(window1, -1, 0);
		if (render1) { //if the renderer not = 0(false), then it is created
			SDL_SetRenderDrawColor(render1, 255, 255, 255, 255);
			printf("System renderer initialized!\n");
		}
		isRunning = true;
		
		/*Begin Debug*/
		playerDeb = Texture::generateTexture("Assets/CharacterForward.png", render1);

		player = new GameEngine(playerDeb, render1, 0, 0);
	}
	else {
		isRunning = false;
	}

}

void Game::eventHandler()
{
	SDL_Event event1; //event that we will check
	SDL_PollEvent(&event1); //dereference event because it requires
	switch (event1.type) {
	case SDL_QUIT:
		isRunning = false; //stops the app
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();

	/*Begin Debugging Code*/
	//destinationRect.h = 63, destinationRect.w = 45;
	/*End Debugging Code*/
}

void Game::tickPrint()
{
	currentTick++;
	if (!currentTick % 100) {
		printf("%d", currentTick);
	}
}

void Game::render()
{
	SDL_RenderClear(render1);
	player->render();
	/*Begin Debugging Code*/
	//SDL_RenderCopy(render1, playerDeb, NULL, &destinationRect);
	/*End Debugging Code*/
	SDL_RenderPresent(render1);
}

void Game::memManage()
{
	SDL_DestroyWindow(window1);
	SDL_DestroyRenderer(render1);
	SDL_Quit();
	printf("System buffer cleared.\n");
}
