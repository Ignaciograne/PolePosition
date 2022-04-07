//
// Created by maxta on 6/4/2022.
//

#ifndef UNTITLED3_INICIO_H
#define UNTITLED3_INICIO_H


#include "Constantes.h"

#include <stdio.h>
#include "usuario.h"
#include "time.h"
#include "Constantes.h"

#include "pantalla.h"

void juego();

static SDL_Window *window1 = NULL;
static SDL_Renderer *renderer1;

static SDL_Event event1;
static int corriendo = 0;
static int tipoEvento1;

static SDL_Surface* screenSurface1 = NULL;

#endif //UNTITLED3_INICIO_H
