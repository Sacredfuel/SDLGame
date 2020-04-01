#include "GameStack.h"

GameStack::GameStack()
{
}

GameStack::~GameStack()
{
}

void GameStack::updateType()
{
	for (int i = 0; i < stack.size(); i++) {
		stack[i]->update();
	}
}

void GameStack::renderAll()
{
	for (int i = 0; i < stack.size(); i++) {
		stack[i]->render();
	}
}

void GameStack::eventHandle(SDL_Event s) 
{
}

void GameStack::spawnEnemy(int x, int y)
{

}

void GameStack::addEntity(const char* text, int x1, int y1)
{
	GameStack::stack.push_back(new GameEngine(text, x1, y1));
}

void GameStack::destroyEnemy(int j)
{
}
