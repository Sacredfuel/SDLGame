#pragma once
#include "Game.h"
#include <string>

class Tilemap
{
public:

	Tilemap();
	~Tilemap();

	void LoadTilemapFromArr(int arr[20][25]);
	void LoadTilemap(std::string s);
	void DrawTileMap();

private:

	SDL_Rect source, destination;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int TileMap[20][25];

};
