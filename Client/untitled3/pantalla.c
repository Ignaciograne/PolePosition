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
        principal = crearUsuario(renderer,"images/carroRojo.bmp",1);

        static struct Node * objetos;
        objetos = parsear(&objetos,renderer);

        static struct NodeU * usuarios;
        parsearUsuarios(&usuarios,renderer);

        nodeU = &usuarios;
        /**int prin = 2;
        int i = 0;
        while (nodeU !=NULL){
            if(i == prin+1){
                principal = nodeU->data;
                deleteNodeU(&usuarios,&nodeU->data);
            }
            i++;
            nodeU = nodeU->next;
        }**/

        image3 = SDL_LoadBMP("images/fondo.bmp");
        fondo = SDL_CreateTextureFromSurface(renderer,image3);
        SDL_FreeSurface(image3);

        SDL_Rect backround;
        backround.x=0;
        backround.y=0;
        backround.w=600;
        backround.h=600;

        int veloc = 0;
        time(&startPower);

        int presion = 0;
        int pantallas =0;

        while (!juegoTerminado) {

            time(&stop);
            seconds = difftime(stop, startPower);
            //printf("time %.5f\n",seconds);

            time(&stopPower);
            secondsPower = difftime(stopPower, startPower);
            //printf("time %.5f\n",secondsPower);

            //printf("time %.5f\n",seconds);
            if (secondsPower == 3 && power){
                principal.aceleracion = 6;
                power = 0;
                printf("Se quita el power \n");
            }
            if (seconds == 10){
                principal.puntaje = principal.puntaje + 10;
                printf("Puntaje Subido a: %d por tiempo.\n", principal.puntaje);
                time(&startPower);
            }
            backround.y = frame ;
            if (veloc>(10-principal.aceleracion)){
                frame--;
                veloc = 0;
                //printf("Rojo y Azul están a %i: \n" , principal.posicion.y-usuario2.posicion.y);
                colisionObjetos(&principal,&objetos);
                if (principal.aceleracion==9 && !power){
                    time(&startPower);
                    principal.aceleracion=9;
                    printf("Súper power up: %i \n", principal.aceleracion);
                    power = 1;
                }
                while (nodeU !=NULL && node->data.aceleracion!=0){
                    actualizarPosicion(&nodeU->data, 0, principal.aceleracion-nodeU->data.aceleracion);
                    printf("aceleracion %d\n",principal.aceleracion-nodeU->data.aceleracion);
                    nodeU = nodeU->next;
                }
                //printf("--- \n\n");
                node = &objetos;
                while (node != NULL)
                {
                    actualizarObjeto(&(node->data),1);
                    node = node->next;
                }
            }
            if (principal.aceleracion != 0){
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
                            nodeU = &usuarios;
                            while (nodeU !=NULL){
                                if(nodeU->data.aceleracion < 6){
                                    nodeU->data.aceleracion++;
                                }

                                printf("aceleracion: %d\n\n",nodeU->data.aceleracion);
                                nodeU = nodeU->next;
                            }
                            break;
                        case SDLK_UP:
                            if (principal.aceleracion == 0){
                                principal.aceleracion = 1;
                            }
                            presion = presion + 1;
                            if(principal.aceleracion<7) {
                                if (presion > 40) {
                                    printf("Sube aceleracion a: %i \n", principal.aceleracion);
                                    principal.aceleracion ++;
                                    presion = 0;
                                }
                            }
                            break;
                        case SDLK_DOWN:
                            presion = presion + 1;
                            if(principal.aceleracion>1) {
                                if (presion > 10) {
                                    printf("Baja aceleracion a: %i \n", principal.aceleracion);
                                    principal.aceleracion--;
                                    presion = 0;
                                }
                            }
                            break;
                        case SDLK_SPACE:
                            time(&startPower);
                            principal.aceleracion=9;
                            printf("Súper power up: %i \n", principal.aceleracion);
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


            node =  &objetos;
            while (node != NULL)
            {
                renderizarObjeto(renderer,&node->data);
                node = node->next;
            }
            renderizarUsuario(renderer,&principal);

            nodeU = &usuarios;
            while (nodeU !=NULL){
                renderizarUsuario(renderer,&nodeU->data);
                actualizarPosicion(&nodeU->data, 0, principal.aceleracion-nodeU->data.aceleracion);
                nodeU = nodeU->next;
            }


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

