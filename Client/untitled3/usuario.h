//
// Created by maxta on 4/4/2022.
//

#ifndef UNTITLED3_USUARIO_H
#define UNTITLED3_USUARIO_H

#include "SDL.h"
#include <stdio.h>
#include "Constantes.h"
#include <time.h>

static SDL_Surface *imagen1 = NULL;

typedef struct {
    SDL_Texture *textura;
    SDL_Rect imagenActual;
    int cantImagenes;
    int anchoImagen;
} Imagen;


typedef struct {
    SDL_Rect posicion;
    Imagen imagenUsuario;
    int aceleracion;
    int vidas;
    int puntaje;
} User; //hacer estructura de user y obejeto que tengan una imagen
//hacer colisiones

typedef struct {
    SDL_Rect posicion;
    Imagen imagenObjeto;
    int puntos;
    int vida;
    int aceleracion;
} Objeto;

static int num;
User crearUsuario(SDL_Renderer *renderer, char *path, int posicion);
Objeto crearOBjeto(SDL_Renderer *renderer, char *path, int metros, int ace, int vida, int puntos);

Imagen crearImagen(SDL_Renderer *renderer, char *path, int cantidadImagenes, int imagenInicial);
void cambiarImagen(Imagen * img, int imagen);
void actualizarPosicion(User * usuario, int x, int y);
void actualizarObjeto(Objeto * obj, int y);
void renderizarUsuario(SDL_Renderer * renderer, User * usuario);
void renderizarObjeto(SDL_Renderer * renderer, Objeto * obj);
void colocarObjeto(Objeto * obj, int metros);
#endif //UNTITLED3_USUARIO_H


