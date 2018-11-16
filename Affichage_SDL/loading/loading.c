#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "loading.h"

void displayLoadingScreen(SDL_Surface ** screen)
{
    SDL_Surface * logo = IMG_Load("data/img/icon.png"), * heart = IMG_Load("data/img/heart/heart_5.png");
    Uint8 alpha = 255;

    SDL_Rect logoPos = {0}, heartPos = {0}, overlayPos = {0};
    overlayPos.x = 0;
    overlayPos.y = 0;
    logoPos.x = (Uint16)(((*screen)->w)/2 - (logo->w) / 2);
    logoPos.y = (Uint16)(((*screen)->h)/2 - (logo->h) / 2);
    heartPos.x = (Uint16)(((*screen)->w)/2 - 40 / 2);
    heartPos.y = (Uint16)(((*screen)->h)/2 - 40 / 2);

    int heartCount = 1;
    int * heartStates = calloc(1, sizeof(int));
    heartStates[0] = 5;

    int currTime = SDL_GetTicks(), enterTime = currTime, prevTime = currTime, prevAddHeartTime = currTime, prevAnimationTime = currTime;

    double t = 0;
    SDL_Rect pos;

    while(currTime < 7000)
    {
        currTime = SDL_GetTicks();

        SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 255, 255, 255));

        SDL_Surface * overlay = SDL_DisplayFormatAlpha(*screen);
        SDL_FillRect(overlay, NULL, SDL_MapRGBA(overlay->format, 255, 255, 255, alpha));
        SDL_BlitSurface(logo, NULL, *screen, &logoPos);

        if(currTime < 5000)
            SDL_BlitSurface(overlay, NULL, *screen, &overlayPos);

        for(int i = 0; i < heartCount; i++)
        {
            if(heartStates[i] > 1)
            {
                double r = t - i * M_PI / 12;

                if(t <= 10 * M_PI)
                {
                    pos.x = heartPos.x + (Uint16)(10 * r * cos(r));
                    pos.y = heartPos.y + (Uint16)(10 * r * sin(r));
                }
                else
                {
                    pos.x = heartPos.x + (Uint16)(100 * M_PI * cos(r));
                    pos.y = heartPos.y + (Uint16)(100 * M_PI * sin(r));
                }

                SDL_BlitSurface(heart, NULL, *screen, &pos);
            }
        }

        if(currTime > 5000)
            SDL_BlitSurface(overlay, NULL, *screen, &overlayPos);

        if(currTime - prevTime > 33)
        {
            prevTime = currTime;
            t += M_PI / 12;

            if(currTime > 5000)
            {
                if(alpha <= 252)
                    alpha += 3;
                else
                    alpha = 255;
            }
            else if(currTime > 1000)
            {
                if(alpha >= 1)
                    alpha--;
                else
                    alpha = 0;
            }

        }

        if(currTime - prevAddHeartTime > 165 * heartCount && currTime < 5000)
        {
            heartCount++;
            heartStates = realloc(heartStates, heartCount * sizeof(int));
            heartStates[heartCount - 1] = 5;

            prevAddHeartTime = currTime;
        }

        SDL_Flip(*screen);

        SDL_FreeSurface(overlay);
    }

    SDL_FreeSurface(heart);
    SDL_FreeSurface(logo);
}