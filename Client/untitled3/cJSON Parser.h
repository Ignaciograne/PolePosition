//
// Created by maxta on 7/4/2022.
//

#ifndef UNTITLED3_CJSON_PARSER_H
#define UNTITLED3_CJSON_PARSER_H

#include "json/cJSON.h"
#include <stdio.h>
#include "listaEnlazada.h"
#include "Constantes.h"


struct Node * parsear(struct Node *lista, SDL_Renderer *renderer);
struct NodeU * parsearUsuarios(struct NodeU *linked, SDL_Renderer *renderer);
void getObjetos(cJSON * lista, struct Node *linked, char *path, SDL_Renderer *renderer);
char * crearJSON();
char * crearJSonUsuarios();
cJSON * crearObjeto1 (int posicion, int vida, int puntos, int aceleracion);


#endif //UNTITLED3_CJSON_PARSER_H
