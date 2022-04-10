//
// Created by maxta on 6/4/2022.
//

#include "inicio.h"

void juego() {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }    else
    {

        window1 = SDL_CreateWindow( "PolePosition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        screenSurface1 = SDL_GetWindowSurface(window1);
        renderer1 = SDL_CreateRenderer(window1,-1,SDL_RENDERER_ACCELERATED);

        while (!corriendo){
            if (SDL_PollEvent((&event1))) {
                tipoEvento1 = event1.type;
                if (tipoEvento1 == SDL_QUIT) {
                    corriendo = 1;
                }
                else if (tipoEvento1 == SDL_KEYDOWN){
                    switch (event1.key.keysym.sym) {
                        case SDLK_SPACE:
                            //Destroy Renderer
                            SDL_DestroyRenderer(renderer1);
                            //Destroy window
                            SDL_DestroyWindow( window1 );
                            window1 = NULL;
                            comenzar(1);
                            break;
                    }
                }
            }
        }
    };
    //Destroy Renderer
    SDL_DestroyRenderer(renderer1);
    //Destroy window
    SDL_DestroyWindow( window1 );
    window1 = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}
