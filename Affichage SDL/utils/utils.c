#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "utils.h"

SDL_Surface * scaleSurface(SDL_Surface * surface, Uint16 width, Uint16 height)
{
    if(!surface || !width || !height) // On teste si les paramètres sont nulls ou non.
        return 0;

    SDL_Surface * rescaled = SDL_CreateRGBSurface( // On crée une surface identique à celle passée en paramètre mais avec la longueur et la largeur souhaitée.
            surface->flags, width, height, surface->format->BitsPerPixel,
            surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask
            //Rmask, Gmask, Bmask et Amask sont respectivement la localisation des composants rouge, vert, bleu et alpha (transparence) du pixel.
            );

    double factorX = ((double)width  / (double)surface->w), // On récupère le facteur de proportionnalité du recadrage demandé.
           factorY = ((double)height / (double)surface->h); // En d'autres termes, il s'agit du nombre de fois qu'un pixel de l'image d'origine
                                                            // doit être placé sur l'image redimensionnée.

    for(Sint32 y = 0; y < surface->h; y++) // On parcourt l'axe des ordonnées de la surface d'origine.
        for(Sint32 x = 0; x < surface->w; x++) // On parcourt l'axe des abscisses de la surface d'origine.
            for(Sint32 y2 = 0; y2 < factorY; y2++) // On parcourt tous les pixels sur l'axe des y concernés par le pixel sélectionné par les boucles précédentes en fonction du facteur x.
                for(Sint32 x2 = 0; x2 < factorX; x2++) // Idem avec l'axe des x
                    putPixel(rescaled, (Sint32)(factorX * x) + x2, (Sint32)(factorY * y) + y2, getPixel(surface, x, y));

    return rescaled;
}

void putPixel(SDL_Surface * surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel; // The depth of the colors of one pixel.
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp; // The address of the pixel we have to modify

    switch(bpp) { // Put the pixel in function of the depth of the surface we put the pixel in.
        case 1:
            *p = (Uint8) pixel;
            break;

        case 2:
            *(Uint16 *)p = (Uint16) pixel;
            break;

        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) // The order of the pixels depends of the computer which will compile the program.
            {
                p[0] = (Uint8)((pixel >> 16) & 0xff); // & Refers to the & binary operation.
                p[1] = (Uint8)((pixel >> 8) & 0xff);  // >> Refers to a shift: we move all the bits of the pixel toward right, the number of times specified byt the right operand.
                p[2] = (Uint8)(pixel & 0xff); // Actually, 0xff enable us to remove hthe last byte in order to only keep the first ones.
            }
            else
            {
                p[0] = (Uint8)(pixel & 0xff);
                p[1] = (Uint8)((pixel >> 8) & 0xff);
                p[2] = (Uint8)((pixel >> 16) & 0xff);
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}

Uint32 getPixel(SDL_Surface *surface, int x, int y)
{
    // The function as the same particularities as the putPixel one, but get the pixel instead of replacing it.
    // I won't explain it as it might be understandable with the comments of the first function.

    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
        case 1:
            return *p;
        case 2:
            return *(Uint16 *)p;
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
        case 4:
            return *(Uint32 *)p;
        default:
            return 0;
    }
}