//
// Created by maxta on 1/4/2022.
//

#ifndef UNTITLED3_PANTALLA_H
#define UNTITLED3_PANTALLA_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>

void comenzar();
int sumar();

static const int SCREEN_WIDTH = 600;
static const int SCREEN_HEIGHT = 600;
static int frame = 0;

static int juegoTerminado;
static int tipoEvento;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer;
static SDL_Event event;
static SDL_Rect user;
static SDL_Texture *rojo;
static SDL_Texture *azul;
static SDL_Texture *fondo;

//The surface contained by the window
static SDL_Surface* screenSurface = NULL;
static SDL_Surface *image1 = NULL;
static SDL_Surface *image2 = NULL;
static SDL_Surface *image3 = NULL;
static SDL_Surface *current = NULL;
#endif //UNTITLED3_PANTALLA_H
