#pragma once
#include "GameEngine.h"
#include <vector>

class GameStack {
public:
	GameStack();
	~GameStack();
	std::vector<GameEngine*> stack;
	void updateType();
	void eventHandle(SDL_Event s);
	void renderAll();
	void spawnEnemy(int x = 400, int y = 320);
	void addEntity(const char* text, int x1, int y1);
	void destroyEnemy(int j);
};