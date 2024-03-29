//
// Created by maxta on 1/4/2022.
//

#ifndef UNTITLED3_PANTALLA_H
#define UNTITLED3_PANTALLA_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdio.h>
#include "usuario.h"
#include "time.h"
#include "Constantes.h"
#include "cJSON Parser.h"


void comenzar(int prin);

static int frame = 0;
static double seconds;
static double secondsPower;
static clock_t startPower;
static clock_t stopPower;

//static clock_t start;
static clock_t stop;

static int juegoTerminado;
static int power;
static int tipoEvento;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer;
static SDL_Event event;
static SDL_Texture *rojo;
static SDL_Texture *azul;
static SDL_Texture *fondo;
static User principal;
static struct Node * node;
static struct NodeU * nodeU;

//The surface contained by the window
static SDL_Surface* screenSurface = NULL;
static SDL_Surface *image1 = NULL;
static SDL_Surface *image2 = NULL;
static SDL_Surface *image3 = NULL;
#endif //UNTITLED3_PANTALLA_H
