//
// Created by maxta on 4/4/2022.
//

#ifndef UNTITLED3_USUARIO_H
#define UNTITLED3_USUARIO_H

#include "SDL.h"
#include <stdio.h>

static SDL_Surface *imagen1 = NULL;
typedef struct {
    int h;
} imagen;

typedef struct {
    SDL_Texture *textura;
    SDL_Rect imagenActual;
    SDL_Rect posicion;
    int cantImagenes;
    int anchoImagen;
    int aceleracion;
} user;

user inializar(SDL_Renderer *renderer, char *path, int cantidadImagenes, int imagenInicial, int posicionUsuario);
void cambiarImagen(user * usuario, int imagen);
void actualizarPosicion(user * usuario, int x, int y);
void renderizar(SDL_Renderer * renderer, user * usuario);
void setPosicion(user * objeto, int posicion, int metros);
#endif //UNTITLED3_USUARIO_H
