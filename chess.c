#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// #include "global.h"
// #include "starter.h"
// #include "credit.h"
#include "copyofMain.h"
int WINDOW_WIDTH = 640;
int WINDOW_HEIGHT = 640;

SDL_Window *xwindow = NULL;
SDL_Renderer *xrenderer = NULL;
SDL_Texture *xtexturer = NULL;
char *x_font = "Monaco.ttf";
void start(SDL_Renderer *xrenderer)
{
    /* Clear the screen with selected color */
    SDL_SetRenderDrawColor(xrenderer, 200, 55, 250, 255);
    SDL_RenderClear(xrenderer);
    char *workingButton = "Oops,Still Working,press 1 to go main menu";
    TTF_Font *monaco = TTF_OpenFont(x_font, 24);
    if (monaco == NULL)
    {
        printf("Error opening font: %s\n", SDL_GetError());
        return;
    }
    SDL_Color blue = {0, 100, 255};
    SDL_Surface *workingSurface = TTF_RenderText_Blended(monaco, workingButton, blue);
    SDL_Texture *workingTexture = SDL_CreateTextureFromSurface(xrenderer, workingSurface);
    if (!workingTexture)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_FreeSurface(workingSurface);
        TTF_CloseFont(monaco);
        return;
    }
    SDL_Rect working_rect;
    working_rect.x = (WINDOW_WIDTH - workingSurface->w) / 2;
    working_rect.y = (WINDOW_HEIGHT - workingSurface->h) / 2 + 5;
    working_rect.w = workingSurface->w;
    working_rect.h = workingSurface->h;

    SDL_RenderCopy(xrenderer, workingTexture, NULL, &working_rect);

    SDL_FreeSurface(workingSurface);
    SDL_DestroyTexture(workingTexture);
    TTF_CloseFont(monaco);
}

void initSDLs()
{
    SDL_Init(SDL_INIT_VIDEO);
    xwindow = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    xrenderer = SDL_CreateRenderer(xwindow, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
}

int working()
{
    initSDLs();

    int quit = 0;
    SDL_Event e;
    start(xrenderer);
    SDL_RenderPresent(xrenderer);
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            if (e.key.keysym.sym == SDLK_1)
            {
                // SDL_DestroyRenderer(xrenderer);
                // SDL_DestroyWindow(xwindow);
                SDL_Quit();
                callFunction();
            }
            start(xrenderer);
            SDL_RenderPresent(xrenderer);
        }
        start(xrenderer);
        SDL_RenderPresent(xrenderer);
    }

    SDL_DestroyRenderer(xrenderer);
    SDL_DestroyWindow(xwindow);
    SDL_Quit();
    TTF_Quit();

    return 0;
}