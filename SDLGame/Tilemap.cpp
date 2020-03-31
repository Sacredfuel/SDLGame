#include "Tilemap.h"
#include "Texture.h"

//20 rows by 25 columns
int lvl1[20][25]={
	//sample 2d matrix
	//later on we will store them as txt files to make it more readible
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Tilemap::Tilemap()
{
	dirt = Texture::generateTexture("Assets/Dirt.PNG");
	grass = Texture::generateTexture("assets/grass.png");//not yet implemented
	water = Texture::generateTexture("assets/water.png");//not yet implemented

	LoadTilemap(lvl1);//depends on where the character is, we would need a map

	source.x = 0;
	source.y = 0;

	source.w = 32;
	source.h = 32;

	destination.w = 32;
	destination.h = 32;
}

void Tilemap::LoadTilemap(int arr[20][25])
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			TileMap[i][j] = arr[i][j];
		}
	}
}

void Tilemap::DrawTileMap()
{
	int type = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			type = TileMap[i][j];

			destination.x = j * 32;
			destination.y = i * 32;

			switch (type)
			{
			case 0:
				Texture::Draw(dirt, source, destination);
				break;
			case 1:
				Texture::Draw(water, source, destination);
				break;
			case 2:
				Texture::Draw(grass, source, destination);
				break;
			default:
				break;
			}
		}
	}
}

