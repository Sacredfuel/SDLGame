#include "Tilemap.h"
#include "Texture.h"
#include <istream>
#include <fstream>

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
	grass = Texture::generateTexture("Assets/Grass.png");
	water = Texture::generateTexture("Assets/Water.png");
	sign = Texture::generateTexture("Assets/GrassSign.png");

	/*LoadTilemapFromArr(lvl1); */  //depends on where the character is, we would need a map

	source.x = 0;
	source.y = 0;

	source.w = 32;
	source.h = 32;

	destination.w = 32;
	destination.h = 32;
}

void Tilemap::LoadTilemapFromArr(int arr[20][25])
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 25; j++) {
			TileMap[i][j] = arr[i][j];
		}
	}
}

void Tilemap::LoadTilemap(std::string s)
{
	std::ifstream indata;
	indata.open(s);
	int myArray[3][5];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 25; j++)
			indata >> TileMap[i][j];
	//indata.close;
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
				flag[i][j] = true;
				break;
			case 1:
				Texture::Draw(grass, source, destination);
				flag[i][j] = true;
				break;
			case 2:
				Texture::Draw(water, source, destination);
				flag[i][j] = false;
				break;
			case 3:
				Texture::Draw(sign, source, destination);
				flag[i][j] = false;
				break;
			default:
				break;
			}
		}
	}
}

