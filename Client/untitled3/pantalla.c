//
// Created by maxta on 1/4/2022.
//

#include "pantalla.h"

void comenzar(){
    //The window we'll be rendering to

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }    else
    {
        //Create window
        window = SDL_CreateWindow( "Ventana Movible", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        screenSurface = SDL_GetWindowSurface(window);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

        image1 = SDL_LoadBMP("images/carroRojo.bmp");
        rojo = SDL_CreateTextureFromSurface(renderer,image1);
        SDL_FreeSurface(image1);
        image2 = SDL_LoadBMP("images/carroAzul.bmp");
        azul = SDL_CreateTextureFromSurface(renderer,image2);
        SDL_FreeSurface(image2);
        image3 = SDL_LoadBMP("images/fondo1.bmp");
        fondo = SDL_CreateTextureFromSurface(renderer,image3);
        SDL_FreeSurface(image3);
        current = image3;

        SDL_Rect userRect;
        userRect.x=150;
        userRect.y=520;
        userRect.w=35;
        userRect.h=70;

        SDL_Rect userRect2;
        userRect2.x=290;
        userRect2.y=520;
        userRect2.w=35;
        userRect2.h=70;

        SDL_Rect backround;
        backround.x=0;
        backround.y=0;
        backround.w=600;
        backround.h=600;

        while (!juegoTerminado) {
            if (frame>360) {
                frame = 0;
            }
            if (frame<0) {
                frame = 359;
            }

            if (SDL_PollEvent((&event))) {
                tipoEvento = event.type;
                if (tipoEvento == SDL_QUIT) {
                    juegoTerminado = 1;
                }
                else if (tipoEvento == SDL_KEYDOWN){
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            frame--;
                            backround.y = 15*frame;
                            userRect.x += 10;
                            break;
                        case SDLK_LEFT:
                            frame--;
                            backround.y = 15*frame;
                            userRect.x -= 10;
                            break;
                        case SDLK_UP:
                            //userRect.y -= 10;
                            frame--;
                            backround.y = 15*frame;
                            printf("%d\n",frame);
                            break;
                        case SDLK_DOWN:
                            //userRect.y += 10;
                            frame++;
                            backround.y = 15*frame;
                            printf("%d\n",frame);
                            break;
                        case SDLK_d:
                            userRect2.x += 10;
                            break;
                        case SDLK_a:
                            userRect2.x -= 10;
                            break;
                        case SDLK_w:
                            //userRect2.y -= 10;
                            frame--;
                            backround.y = 15*frame;
                            break;
                        case SDLK_s:
                            //userRect2.y += 10;
                            frame++;
                            backround.y = 15*frame;
                            break;
                    }
                }
            }

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer,fondo,&backround,NULL);
            //SDL_BlitSurface(current,NULL, screenSurface,&userRect);
            SDL_RenderCopy(renderer,rojo,NULL,&userRect);
            SDL_RenderCopy(renderer,azul,NULL,&userRect2);
            //SDL_UpdateWindowSurface(window);
            SDL_RenderPresent(renderer);



        }
    }

    //Destroy Renderer
    SDL_DestroyRenderer(renderer);
    //Destroy window
    SDL_DestroyWindow( window );
    current = image1 = image2 = image3 = NULL;
    window = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}
