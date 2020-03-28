#pragma once
#include "Game.h"

class Tilemap
{
public:

	Tilemap();
	~Tilemap();

	void LoadTilemap(int arr[20][25]);
	void DrawTileMap();

private:

	SDL_Rect source, destination;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int TileMap[20][25];

};
