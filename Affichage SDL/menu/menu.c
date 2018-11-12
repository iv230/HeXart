#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "menu.h"

void displayLoadingScreen(SDL_Surface ** screen)
{
    SDL_Surface * overlay = SDL_DisplayFormatAlpha(*screen), * logo = IMG_Load("data/img/icon.png");
    Uint16 alpha = 0;

    SDL_Rect overlayPos = {0}, logoPos = {0};
    overlayPos.x = 0;
    overlayPos.y = 0;
    logoPos.x = (Uint16)(((*screen)->w)/2 - (logo->w) / 2);
    logoPos.y = (Uint16)(((*screen)->h)/2 - (logo->h) / 2);

    int currTime = SDL_GetTicks(), enterTime = currTime, prevTime = currTime;

    while(currTime - enterTime < 5000)
    {
        currTime = SDL_GetTicks();
    }
}

void displayMenu(SDL_Surface ** screen)
{
    SDL_Event event;

    bool follow = true;

    while(follow)
    {
        SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                follow = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        follow = 0;
                        break;
                }
                break;
        }

        SDL_Flip(*screen);
    }
}
