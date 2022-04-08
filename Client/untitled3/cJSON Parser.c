//
// Created by maxta on 7/4/2022.
//

#include "cJSON Parser.h"

void parsear(){
    cJSON *parsed = NULL;
    parsed = cJSON_Parse(crearJSON());
    cJSON * turbos = NULL;
    cJSON * vidas = NULL;
    cJSON * huecos = NULL;

    turbos = cJSON_GetObjectItem(parsed, "turbo");
    huecos = cJSON_GetObjectItem(parsed, "hole");
    vidas = cJSON_GetObjectItem(parsed, "life");
    printf("Turbos ");
    getObjetos(turbos);
    printf("Huecos ");
    getObjetos(huecos);
    printf("Vidas");
    getObjetos(vidas);

/**
    cJSON *jugadorR = NULL;
    cJSON  *corX = NULL;
    cJSON *corY = NULL;
    jugadorR = cJSON_GetObjectItem(parsed,"Jug");
    corY = cJSON_GetObjectItem(jugadorR,"corY");
    corX = cJSON_GetObjectItem(jugadorR,"corX");

    int cX = corX->valueint;
    int cY = corY->valueint;

    printf("Cordenada en X = %d\n", cX);
    printf("Cordenada en Y = %d\n", cY);**/
}

void getObjetos(cJSON * lista){
    cJSON * item =NULL;
    int turbosSize = cJSON_GetArraySize(lista);
    printf("--- %i: \n", turbosSize);

    for (int i =0; i<turbosSize ; i++){
        item = cJSON_GetArrayItem(lista,i);
        printf("posicion: %i \n", cJSON_GetObjectItem(item,"position")->valueint);
        printf("health: %i \n", cJSON_GetObjectItem(item,"health")->valueint);
        printf("puntos: %i \n\n", cJSON_GetObjectItem(item,"points")->valueint);
    }
}

cJSON * crearObjeto (int posicion, int vida, int puntos){
    cJSON * objeto;
    objeto = cJSON_CreateObject();

    cJSON_AddNumberToObject(objeto, "position", posicion);
    cJSON_AddNumberToObject(objeto, "health", vida);
    cJSON_AddNumberToObject(objeto, "points", puntos);

    return objeto;
}

char * crearJSON(){
    cJSON *informe = NULL;
    cJSON *turbos = NULL;
    cJSON *huecos = NULL;
    cJSON *vidas = NULL;

    char *str = NULL;

    informe = cJSON_CreateObject();

    turbos = cJSON_CreateArray();
    huecos = cJSON_CreateArray();
    vidas = cJSON_CreateArray();
    cJSON_AddItemToArray(turbos, crearObjeto(1,0,2));
    cJSON_AddItemToArray(turbos, crearObjeto(16,0,2));


    cJSON_AddItemToArray(huecos, crearObjeto(1,0,2));

    cJSON_AddItemToArray(vidas, crearObjeto(1,0,2));
    cJSON_AddItemToArray(vidas, crearObjeto(16,0,2));


    cJSON_AddItemToObject(informe, "turbo", turbos);
    cJSON_AddItemToObject(informe, "hole", huecos);
    cJSON_AddItemToObject(informe, "life", vidas);

    str = cJSON_Print(informe);
    printf("%s\n", str);
    return str;
}
