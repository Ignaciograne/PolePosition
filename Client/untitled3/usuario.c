//
// Created by maxta on 4/4/2022.
//

#include "usuario.h"

user inializar(SDL_Renderer *renderer, char *path, int cantidadImagenes, int imagenInicial, int posicionUsuario){
    user temp;
    imagen1 = SDL_LoadBMP(path);
    temp.textura = SDL_CreateTextureFromSurface(renderer,imagen1);

    temp.imagenActual.w = (imagen1->w/cantidadImagenes);
    temp.imagenActual.h = imagen1->h;
    temp.imagenActual.x = temp.imagenActual.w * imagenInicial;
    temp.imagenActual.y = 0;
    temp.cantImagenes = cantidadImagenes;

    temp.posicion.w = temp.imagenActual.w -15;
    temp.posicion.h = temp.imagenActual.h -15;
    temp.posicion.y = 500;
    temp.posicion.x = 95 * posicionUsuario + 125;

    temp.aceleracion = 0;

    SDL_FreeSurface(imagen1);

    printf("Usuario Creado de: %d", &temp);

    return temp;
}

void cambiarImagen(user * usuario, int imagen){
    if(imagen <= usuario->cantImagenes){
        usuario->imagenActual.x = usuario->imagenActual.w*imagen;
    } else {
        printf("Imagen no existe");
    }

}

void setPosicion(user * objeto, int posicion, int metros){
    objeto->posicion.x = 95 * posicion + 125;
    objeto->posicion.y = metros;
}

void actualizarPosicion(user * usuario, int x, int y){
    if (usuario->posicion.x +x >= 430 || usuario->posicion.x +x <= 110){
        x = 0;
    }
    usuario->posicion.x +=x;
    usuario->posicion.y +=y;
    if (x>0){
        cambiarImagen(usuario, 2);
    } else if (x==0){
        cambiarImagen(usuario, 0);
    } else {
        cambiarImagen(usuario,0);
    }
}

void renderizar(SDL_Renderer * renderer, user * usi){
    if (usi->posicion.y>0-usi->posicion.h && usi->posicion.y<600) {
        SDL_RenderCopy(renderer, usi->textura, &usi->imagenActual, &usi->posicion);
    }
}