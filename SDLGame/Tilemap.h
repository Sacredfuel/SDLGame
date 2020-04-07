#pragma once
#include "Game.h"
#include "Enemy.h"
#include <string>

class Tilemap
{
public:

	Tilemap();
	~Tilemap();

	void LoadTilemapFromArr(int arr[20][25]);
	void LoadTilemap(std::string s);
	void DrawEnemies();
	void DrawTileMap();
	bool flag[20][25];

private:

	SDL_Rect source, destination;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* sign;
	SDL_Texture* enemy;

	int TileMap[20][25];

};
