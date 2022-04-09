//
// Created by maxta on 7/4/2022.
//

#include "cJSON Parser.h"
void parsear(struct Node *lista, SDL_Renderer *renderer){
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
        int h = cJSON_GetObjectItem(item,"health")->valueint;
        int pp = cJSON_GetObjectItem(item,"points")->valueint;
        Objeto ob = crearOBjeto(renderer, path, p);
        append(&linked, ob);
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
    cJSON_AddItemToArray(turbos, crearObjeto(100,0,2));
    cJSON_AddItemToArray(turbos, crearObjeto(-200,0,2));
    cJSON_AddItemToArray(turbos, crearObjeto(-1000,0,2));
    cJSON_AddItemToArray(turbos, crearObjeto(400,0,2));


    cJSON_AddItemToArray(huecos, crearObjeto(300,0,2));

    cJSON_AddItemToArray(vidas, crearObjeto(400,0,2));
    cJSON_AddItemToArray(vidas, crearObjeto(-300,0,2));


    cJSON_AddItemToObject(informe, "turbo", turbos);
    cJSON_AddItemToObject(informe, "hole", huecos);
    cJSON_AddItemToObject(informe, "life", vidas);

    str = cJSON_Print(informe);
    printf("%s\n", str);
    return str;
}
