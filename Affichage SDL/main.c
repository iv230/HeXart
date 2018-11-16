#include <stdio.h>
#include <windows.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "menu/menu.h"

int main(int argc, char * argv[])
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Error while initialising the SDL library: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    const SDL_VideoInfo * videoInfo = SDL_GetVideoInfo();

    SDL_Surface * screen = NULL;
    screen = SDL_SetVideoMode(videoInfo->current_w, videoInfo->current_h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);

    SDL_WM_SetCaption("HeXart measurements", NULL);
    SDL_WM_SetIcon(IMG_Load("data/img/icon.png"), NULL);

    SDL_ShowCursor(SDL_DISABLE);

    displayMenu(&screen);

    SDL_Quit();

    return 0;
}