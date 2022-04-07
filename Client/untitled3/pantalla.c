//
// Created by maxta on 1/4/2022.
//

#include "pantalla.h"

void comenzar(){
    //The window we'll be rendering to
    srand(time(NULL));
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }    else
    {
        //Create window
        window = SDL_CreateWindow( "PolePosition", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        screenSurface = SDL_GetWindowSurface(window);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        usuario3 = crearUsuario(renderer,"images/carroVerde.bmp",0);
        principal = crearUsuario(renderer,"images/carroRojo.bmp",1);
        usuario2 = crearUsuario(renderer,"images/carroAzul.bmp",2);
        usuario4 = crearUsuario(renderer,"images/carroAmarillo.bmp",3);


        objeto1 = crearOBjeto(renderer,"images/hueco.bmp",-3000);
        objeto2 = crearOBjeto(renderer,"images/vida.bmp",-1000);
        objeto3 = crearOBjeto(renderer,"images/power.bmp",100);

        image3 = SDL_LoadBMP("images/fondo.bmp");
        fondo = SDL_CreateTextureFromSurface(renderer,image3);
        SDL_FreeSurface(image3);

        SDL_Rect backround;
        backround.x=0;
        backround.y=0;
        backround.w=600;
        backround.h=600;

        int veloc = 0;
        int aceleracion = 0;
        time(&start);
        int presion = 0;
        int pantallas =0;


        while (!juegoTerminado) {
            time(&stop);
            seconds = difftime(stop, start);
            //printf("time %.5f\n",seconds);
            if (seconds == 3 && power){
                principal.aceleracion = 6;
                aceleracion = 6;
                power = 0;
                printf("Se quita el power \n");
            }
            backround.y = frame ;
            if (veloc>(10-aceleracion)){
                frame--;
                veloc = 0;
                //printf("Rojo y Azul están a %i: \n" , principal.posicion.y-usuario2.posicion.y);
                actualizarPosicion(&usuario2, 0, principal.aceleracion-usuario2.aceleracion);
                actualizarObjeto(&objeto1,1);
                actualizarObjeto(&objeto2, 1);
                actualizarObjeto(&objeto3,1);
            }
            if (aceleracion != 0){
                veloc++;
            }
            if (SDL_PollEvent((&event))) {
                tipoEvento = event.type;
                if (tipoEvento == SDL_QUIT) {
                    juegoTerminado = 1;
                }
                else if (tipoEvento == SDL_KEYDOWN){
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            actualizarPosicion(&principal,10,0);
                            break;
                        case SDLK_LEFT:
                            actualizarPosicion(&principal,-10,0);
                            break;
                        case SDLK_a:
                            if (usuario2.aceleracion < 6){
                                usuario2.aceleracion +=1;
                            }
                            break;
                        case SDLK_UP:
                            if (aceleracion == 0){
                                principal.aceleracion = 1;
                                aceleracion = 1;
                            }
                            presion = presion + 1;
                            if(aceleracion<7) {
                                if (presion > 40) {
                                    printf("Sube aceleracion a: %i \n", aceleracion);
                                    principal.aceleracion ++;
                                    aceleracion++;
                                    presion = 0;
                                }
                            }
                            break;
                        case SDLK_DOWN:
                            presion = presion + 1;
                            if(aceleracion>0) {
                                if (presion > 10) {
                                    printf("Baja aceleracion a: %i \n", aceleracion);
                                    aceleracion--;
                                    principal.aceleracion --;
                                    presion = 0;
                                }
                            }
                            break;
                        case SDLK_SPACE:
                            time(&start);
                            aceleracion=9;
                            principal.aceleracion = 9;
                            printf("Súper power up: %i \n", aceleracion);
                            power = 1;
                            break;
                    }
                } else if (tipoEvento == SDL_KEYUP){
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            actualizarPosicion(&principal,0,0);
                            break;
                        case SDLK_LEFT:
                            actualizarPosicion(&principal,0,0);
                            break;
                    }
                }

            }
            if (frame>6000) {
                frame = 1;
            }
            if (frame<1) {
                frame = 6000;
                pantallas++;
                printf("pantalla: %i",pantallas);
            }

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer,fondo,&backround,NULL);

            renderizarObjeto(renderer,&objeto1);
            renderizarObjeto(renderer,&objeto2);
            renderizarObjeto(renderer,&objeto3);
            renderizarUsuario(renderer,&principal);
            renderizarUsuario(renderer,&usuario2);
            renderizarUsuario(renderer,&usuario3);
            renderizarUsuario(renderer,&usuario4);


            //SDL_UpdateWindowSurface(window);
            SDL_RenderPresent(renderer);
        }
    }

    //Destroy Renderer
    SDL_DestroyRenderer(renderer);
    //Destroy window
    SDL_DestroyWindow( window );
    image1 = image2 = image3 = NULL;
    window = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}

