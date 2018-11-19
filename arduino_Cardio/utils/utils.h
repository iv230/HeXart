#ifndef AFFICHAGE_SDL_UTILS_H
#define AFFICHAGE_SDL_UTILS_H

SDL_Surface * scaleSurface(SDL_Surface * surface, Uint16 width, Uint16 height);

void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

Uint32 getPixel(SDL_Surface *surface, int x, int y);

#endif //AFFICHAGE_SDL_UTILS_H
