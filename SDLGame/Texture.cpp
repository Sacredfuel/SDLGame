#include "Texture.h"
#include "GameEngine.h"

SDL_Texture* Texture::generateTexture(const char* title) {
	SDL_Surface* atomicSurface = IMG_Load(title);
	SDL_Texture* sprite = SDL_CreateTextureFromSurface(Game::render1, atomicSurface);
	SDL_FreeSurface(atomicSurface);

	return sprite;
}
//uses a surface to create a sprite, the it blows up afterwards

void Texture::Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect destination)
{
	SDL_RenderCopy(Game::render1, tex, &source, &destination);
}
//renders the texture on the screen