#include <stdbool.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>

#include "../generator/generator.h"
#include "../loading/loading.h"
#include "menu.h"

void slide(int direction, int * target, SDL_Surface ** buttons, SDL_Surface ** shadows, SDL_Surface ** screen);

void displayMenu(SDL_Surface ** screen)
{
    char * types[5] = {"chain", "blink", "lonely", "2per2", "3per3"};

    SDL_Surface * blink[2];
    SDL_Surface * twoPerTwo[2];
    SDL_Surface * threePerThree[3];
    SDL_Surface * chain[10];
    SDL_Surface * lonely[2];

    SDL_Surface ** ledSprites[5];

    ledSprites[0] = blink;
    ledSprites[1] = twoPerTwo;
    ledSprites[2] = threePerThree;
    ledSprites[3] = chain;
    ledSprites[4] = lonely;

    for(int i = 0; i < 5; i++)
    {
        int maximum = (i == 3) ? 10 : (i == 2) ? 3 : 2;
        for(int j = 0; j < maximum; j++)
        {
            char * path = calloc(255, sizeof(char));
            sprintf(path, "data/img/%s/%s_%d.png", types[i], types[i], j);
            ledSprites[i][j] = IMG_Load(path);
        }
    }

    int currSprite[5] = {0, 0, 0, 0, 0};

    SDL_Event event;

    bool follow = true;

    displayLoadingScreen(screen);

    int target = 0;

    Uint8 alpha = 255;

    SDL_Rect screenPos = {0};
    screenPos.x = 0;
    screenPos.y = 0;

    SDL_Rect pos = {0};
    SDL_Surface * buttons[5], * shadows[5];
    for(int i = 0; i < 5; i++)
    {
        buttons[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, (*screen)->w / 3,(*screen)->h / 2, 32, 0, 0, 0, 0);
        SDL_FillRect(buttons[i], NULL, SDL_MapRGB(buttons[i]->format, (Uint8)(255 - 15 * i),(Uint8)(255 - 15 * i),(Uint8)(255 - 15 * i)));

        shadows[i] = SDL_DisplayFormatAlpha(buttons[i]);
        SDL_FillRect(shadows[i], NULL, SDL_MapRGBA(shadows[i]->format, 0,0,0,25));
    }

    int currTime = SDL_GetTicks(), prevTime = currTime;

    while(follow)
    {
        currTime = SDL_GetTicks();

        SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 47, 53, 66));

        for(int i = 0; i < 5; i++)
        {
            pos.x = (Uint16)(((*screen)->w / 2 - buttons[i]->w / 2 + i * (*screen)->w / 2) - target * ((*screen)->w / 2) + 20);
            pos.y = (Uint16)(((*screen)->h / 2 - buttons[i]->h / 2) + 20);

            SDL_BlitSurface(shadows[i], NULL, *screen, &pos);

            pos.x -= 20;
            pos.y -= 20;

            SDL_BlitSurface(buttons[i], NULL, *screen, &pos);

            pos.x = (Uint16)(((*screen)->w / 2 - buttons[i]->w / 2 + i * (*screen)->w / 2) - target * ((*screen)->w / 2) + 20);
            pos.y = (Uint16)(((*screen)->h / 2 - buttons[i]->h / 2) + 20);

            SDL_BlitSurface(ledSprites[i][currSprite[i]], NULL, *screen, &pos);
        }

        if(currTime - prevTime > 132)
        {
            for(int i = 0; i < 5; i++)
            {
                int maximum = (i == 3) ? 10 : (i == 2) ? 2 : 3;

                currSprite[i] = currSprite[i] < maximum ? currSprite[i] + 1 : 0;
            }

            prevTime = currTime;
        }

        SDL_EnableKeyRepeat(2000, 2000);

        SDL_PollEvent(&event);
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
                    case SDLK_LEFT:
                        if(target > 0)
                            slide(LEFT, &target, buttons, shadows, screen);
                        break;
                    case SDLK_RIGHT:
                        if(target < 4)
                            slide(RIGHT, &target, buttons, shadows, screen);
                        break;
                    case SDLK_SPACE:
                        printf("test");
                        generateParam(target);
                        break;
                }
                break;
        }

        SDL_Flip(*screen);
    }
}

void slide(int direction, int * target, SDL_Surface ** buttons, SDL_Surface ** shadows, SDL_Surface ** screen)
{
    int currTime = SDL_GetTicks(), prevTime = currTime;

    int prevTarget = *target;

    if(direction == LEFT && *target > 0)
        (*target)--;
    if(direction == RIGHT && *target < 4)
        (*target)++;

    const int animationDuration = 1000;
    int offset = 0, offsetMax = (*screen)->w / 2;

    SDL_Rect pos = {0};

    while(offset < offsetMax)
    {
        currTime = SDL_GetTicks();

        SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 47, 53, 66));

        if(currTime - prevTime > 33)
        {
            offset += offsetMax / (animationDuration / 33);
        }

        for(int i = 0; i < 5; i++)
        {
            if(direction == RIGHT)
                offset *= -1;

            pos.x = (Uint16)(((*screen)->w / 2 - buttons[i]->w / 2 + i * (*screen)->w / 2) - prevTarget * (*screen)->w / 2 + 20 + offset);
            pos.y = (Uint16)(((*screen)->h / 2 - buttons[i]->h / 2) + 20);

            if(direction == RIGHT)
                offset *= -1;

            SDL_BlitSurface(shadows[i], NULL, *screen, &pos);

            pos.x -= 20;
            pos.y -= 20;

            SDL_BlitSurface(buttons[i], NULL, *screen, &pos);
        }

        SDL_Flip(*(screen));

    }
}
