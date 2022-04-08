//
// Created by maxta on 7/4/2022.
//

#ifndef UNTITLED3_CJSON_PARSER_H
#define UNTITLED3_CJSON_PARSER_H

#include "json/cJSON.h"
#include <stdio.h>


void parsear(), getObjetos(cJSON * lista);
char * crearJSON();
cJSON * crearObjeto (int posicion, int vida, int puntos);

#endif //UNTITLED3_CJSON_PARSER_H
