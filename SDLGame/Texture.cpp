#include "Texture.h"
#include "GameEngine.h"

SDL_Texture* Texture::generateTexture(const char* title, SDL_Renderer* renderer) {
	SDL_Surface* atomicSurface = IMG_Load(title);
	SDL_Texture* sprite = SDL_CreateTextureFromSurface(renderer, atomicSurface);
	SDL_FreeSurface(atomicSurface);

	return sprite;
}