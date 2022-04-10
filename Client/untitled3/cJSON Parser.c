//
// Created by maxta on 7/4/2022.
//

#include "cJSON Parser.h"
struct Node * parsear(struct Node *lista, SDL_Renderer *renderer){
    cJSON *parsed = NULL;
    parsed = cJSON_Parse(crearJSON());
    cJSON * turbos = NULL;
    cJSON * vidas = NULL;
    cJSON * huecos = NULL;

    turbos = cJSON_GetObjectItem(parsed, "turbo");
    huecos = cJSON_GetObjectItem(parsed, "hole");
    vidas = cJSON_GetObjectItem(parsed, "life");
    getObjetos(turbos, lista, "images/power.bmp",renderer);
    getObjetos(vidas, lista, "images/vida.bmp",renderer);
    getObjetos(huecos, lista, "images/hueco.bmp",renderer);
    printf("Objetos de JSON\n");
    printList(lista);
    return lista;
    /**
    printf("Huecos ");
    getObjetos(huecos, head_ref);
    printf("Vidas");
    getObjetos(vidas, head_ref);**/

}

void getObjetos(cJSON * lista, struct Node *linked, char *path, SDL_Renderer *renderer){

    cJSON * item =NULL;
    int listSize = cJSON_GetArraySize(lista);
    int * l[listSize*3];
    printf("--- %i: \n", listSize);
    for (int i =0; i<listSize ; i++){
        item = cJSON_GetArrayItem(lista,i);
        printf("posicion: %i \n", cJSON_GetObjectItem(item,"position")->valueint);
        printf("health: %i \n", cJSON_GetObjectItem(item,"health")->valueint);
        printf("puntos: %i \n", cJSON_GetObjectItem(item,"points")->valueint);
        int p = cJSON_GetObjectItem(item,"position")->valueint;
        int v = cJSON_GetObjectItem(item,"health")->valueint;
        int pp = cJSON_GetObjectItem(item,"points")->valueint;
        int ace = cJSON_GetObjectItem(item,"aceleration")->valueint;
        Objeto ob = crearOBjeto(renderer, path, p, ace,v,pp);
        append(&linked, ob);
    }
}

cJSON * crearObjeto1 (int posicion, int vida, int puntos, int aceleracion){
    cJSON * objeto;
    objeto = cJSON_CreateObject();

    cJSON_AddNumberToObject(objeto, "position", posicion);
    cJSON_AddNumberToObject(objeto, "health", vida);
    cJSON_AddNumberToObject(objeto, "points", puntos);
    cJSON_AddNumberToObject(objeto, "aceleration", aceleracion);

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
    cJSON_AddItemToArray(turbos, crearObjeto1(100,0,2,9));
    cJSON_AddItemToArray(turbos, crearObjeto1(-200,0,2,9));
    cJSON_AddItemToArray(turbos, crearObjeto1(-1000,0,2,9));
    cJSON_AddItemToArray(turbos, crearObjeto1(400,0,2,9));


    cJSON_AddItemToArray(huecos, crearObjeto1(300,0,0,-9));

    cJSON_AddItemToArray(vidas, crearObjeto1(450,0,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(-350,0,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(150,0,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(-350,0,2,0));

    cJSON_AddItemToArray(vidas, crearObjeto1(-1450,1,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(-1550,1,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(-1650,1,2,0));
    cJSON_AddItemToArray(vidas, crearObjeto1(-1350,1,2,0));


    cJSON_AddItemToObject(informe, "turbo", turbos);
    cJSON_AddItemToObject(informe, "hole", huecos);
    cJSON_AddItemToObject(informe, "life", vidas);

    str = cJSON_Print(informe);
    printf("%s\n", str);
    return str;
}
