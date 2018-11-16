#include <stdbool.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../utils/utils.h"
#include "../generator/generator.h"
#include "../loading/loading.h"
#include "menu.h"

void slide(int direction, int * target, SDL_Surface ** buttons, SDL_Surface ** shadows, SDL_Surface ** screen);

void displayMenu(SDL_Surface ** screen)
{
    char * types[7] = { "blink", "2per2", "3per3", "chain", "lonely", "twosides", "random"};

    int max[7] = {2, 2, 3, 10, 2, 6, 8};

    SDL_Surface * blink[2];
    SDL_Surface * twoPerTwo[2];
    SDL_Surface * threePerThree[3];
    SDL_Surface * chain[10];
    SDL_Surface * lonely[2];
    SDL_Surface * twosides[6];
    SDL_Surface * random[8];

    SDL_Surface ** ledSprites[7];

    ledSprites[0] = blink;
    ledSprites[1] = twoPerTwo;
    ledSprites[2] = threePerThree;
    ledSprites[3] = chain;
    ledSprites[4] = lonely;
    ledSprites[5] = twosides;
    ledSprites[6] = random;

    for(int i = 0; i < 7; i++)
    {
        int maximum = max[i];
        for(int j = 0; j < maximum; j++)
        {
            char * path = calloc(255, sizeof(char));
            sprintf(path, "data/img/%s/%s_%d.png", types[i], types[i], j);
            ledSprites[i][j] = scaleSurface(IMG_Load(path), (Uint16)((*screen)->w / 3),(Uint16)((*screen)->h / 2));
        }
    }

    SDL_Surface * chooseLedMenu = scaleSurface(IMG_Load("data/img/ledMenu.png"), (Uint16)((*screen)->w),(Uint16)((*screen)->h));
    SDL_Rect menuPos = {0};

    int currSprite[7] = {0, 0, 0, 0, 0, 0, 0};

    SDL_Event event;

    bool follow = true, inLedMenu = false;

    displayLoadingScreen(screen);

    int target = 0;

    SDL_Rect pos = {0};
    SDL_Surface * buttons[7], * shadows[7];
    for(int i = 0; i < 7; i++)
    {
        buttons[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, (*screen)->w / 3,(*screen)->h / 2, 32, 0, 0, 0, 0);
        SDL_FillRect(buttons[i], NULL, SDL_MapRGB(buttons[i]->format, 255, 255, 255));

        shadows[i] = SDL_DisplayFormatAlpha(buttons[i]);
        SDL_FillRect(shadows[i], NULL, SDL_MapRGBA(shadows[i]->format, 0,0,0,25));
    }

    int currTime = SDL_GetTicks(), prevTime = currTime;

    while(follow)
    {
        currTime = SDL_GetTicks();

        SDL_FillRect(*screen, NULL, SDL_MapRGB((*screen)->format, 47, 53, 66));

        for(int i = 0; i < 7; i++)
        {
            pos.x = (Uint16)(((*screen)->w / 2 - buttons[i]->w / 2 + i * (*screen)->w / 2) - target * ((*screen)->w / 2) + 20);
            pos.y = (Uint16)(((*screen)->h / 2 - buttons[i]->h / 2) + 20);

            SDL_BlitSurface(shadows[i], NULL, *screen, &pos);

            pos.x -= 20;
            pos.y -= 20;

            SDL_BlitSurface(buttons[i], NULL, *screen, &pos);
            SDL_BlitSurface(ledSprites[i][currSprite[i]], NULL, *screen, &pos);
        }

        if(currTime - prevTime > 132)
        {
            for(int i = 0; i < 7; i++)
            {
                int maximum = max[i];

                currSprite[i] = currSprite[i] < maximum - 1 ? currSprite[i] + 1 : 0; // Ici, on teste avec le maximum - 1 car on veut tester si le sprite actuel est la dernière valeur ou non.
            }

            prevTime = currTime;
        }

        if(inLedMenu)
            SDL_BlitSurface(chooseLedMenu, NULL, *screen, &menuPos);

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
                        if(target > 0 && !inLedMenu)
                            slide(LEFT, &target, buttons, shadows, screen);
                        break;
                    case SDLK_RIGHT:
                        if(target < 6 && !inLedMenu)
                            slide(RIGHT, &target, buttons, shadows, screen);
                        break;
                    case SDLK_RETURN:
                        if(target == 4)
                        {
                            if(inLedMenu == false)
                            {
                                inLedMenu = true;
                            }
                        }
                        else
                            generateParam(target + 1, 1);
                        break;
                    case SDLK_KP1:
                        generateParam(target + 1, 1);
                        inLedMenu = false;
                        break;
                    case SDLK_KP2:
                        generateParam(target + 1, 2);
                        inLedMenu = false;
                        break;
                    case SDLK_KP3:
                        generateParam(target + 1, 3);
                        inLedMenu = false;
                        break;
                    case SDLK_KP4:
                        generateParam(target + 1, 4);
                        inLedMenu = false;
                        break;
                    case SDLK_KP5:
                        generateParam(target + 1, 5);
                        inLedMenu = false;
                        break;
                    case SDLK_KP6:
                        generateParam(target + 1, 6);
                        inLedMenu = false;
                        break;
                    case SDLK_KP7:
                        generateParam(target + 1, 7);
                        inLedMenu = false;
                        break;
                    case SDLK_KP8:
                        generateParam(target + 1, 8);
                        inLedMenu = false;
                        break;
                }
                break;
        }

        SDL_Flip(*screen);
    }

    for(int i = 0; i < 7; i++)
    {
        int maximum = max[i];
        for(int j = 0; j < maximum; j++)
        {
            SDL_FreeSurface(ledSprites[i][j]);
        }
    }
}

void slide(int direction, int * target, SDL_Surface ** buttons, SDL_Surface ** shadows, SDL_Surface ** screen)
{
    int currTime = SDL_GetTicks(), prevTime = currTime;

    int prevTarget = *target;

    if(direction == LEFT && *target > 0)
        (*target)--;
    if(direction == RIGHT && *target < 6)
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

        for(int i = 0; i < 7; i++)
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
