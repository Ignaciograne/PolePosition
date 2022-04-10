//
// Created by maxta on 4/4/2022.
//

#include "usuario.h"

Imagen crearImagen(SDL_Renderer *renderer, char *path, int cantidadImagenes, int imagenInicial){
    Imagen temp;
    imagen1 = SDL_LoadBMP(path);
    temp.textura = SDL_CreateTextureFromSurface(renderer,imagen1);

    temp.imagenActual.w = (imagen1->w/cantidadImagenes);
    temp.imagenActual.h = imagen1->h;
    temp.imagenActual.x = temp.imagenActual.w * imagenInicial;
    temp.imagenActual.y = 0;
    temp.cantImagenes = cantidadImagenes;

    SDL_FreeSurface(imagen1);

    printf("Usuario Creado de: %d\n", &temp);

    return temp;
}

User crearUsuario(SDL_Renderer *renderer, char *path, int posicion){
    User usuario;
    usuario.imagenUsuario = crearImagen(renderer, path,3,1);
    usuario.posicion.w = usuario.imagenUsuario.imagenActual.w -15;
    usuario.posicion.h = usuario.imagenUsuario.imagenActual.h -15; //arreglar imágenes para que no tenga que restarle 15
    usuario.posicion.y = 500;
    usuario.posicion.x = 95 * posicion + 125;

    usuario.aceleracion = 0;
    usuario.vidas =3;
    usuario.puntaje = 0;

    return usuario;
}
Objeto crearOBjeto(SDL_Renderer *renderer, char *path, int metros, int ace, int vida, int puntos){
    Objeto obj;
    obj.imagenObjeto = crearImagen(renderer,path,1,0);//cambiar a 2
    obj.posicion.w = obj.imagenObjeto.imagenActual.w;
    obj.posicion.h = obj.imagenObjeto.imagenActual.h; //arreglar imágenes para que no tenga que restarle 15

    num = (rand() % (0-3+1))+0;
    obj.posicion.x = 95 * num + 125;
    obj.posicion.y = metros;

    obj.aceleracion = ace;
    obj.vida = vida;
    obj.puntos = puntos;

    return obj;
}

void cambiarImagen(Imagen * img, int imagen){
    if(imagen < img->cantImagenes){
        img->imagenActual.x = img->imagenActual.w*imagen;
    }

}

void colocarObjeto(Objeto * obj, int metros){
    num = (rand() % (0-3+1))+0;
    obj->posicion.x = 95 * num + 125;
    obj->posicion.y = metros;
}
void actualizarObjeto(Objeto * obj, int y) {
    obj->posicion.y += y;
}


void actualizarPosicion(User * usuario, int x, int y){
    if (usuario->posicion.x +x >= 430 || usuario->posicion.x +x <= 110){
        x = 0;
    }
    usuario->posicion.x +=x;
    usuario->posicion.y +=y;
    if (x>0){
        cambiarImagen(&usuario->imagenUsuario, 2);
    } else if (x==0){
        cambiarImagen(&usuario->imagenUsuario, 1); //cambiar a 1
    } else {
        cambiarImagen(&usuario->imagenUsuario,0);
    }
}

void renderizarUsuario(SDL_Renderer * renderer, User * usi){
    if (usi->posicion.y>0-usi->posicion.h && usi->posicion.y<600) {
        SDL_RenderCopy(renderer, usi->imagenUsuario.textura, &usi->imagenUsuario.imagenActual, &usi->posicion);
    }
}

void renderizarObjeto(SDL_Renderer * renderer, Objeto * obj){
    if (obj->posicion.y>0-obj->posicion.h && obj->posicion.y<600) {
        SDL_RenderCopy(renderer, obj->imagenObjeto.textura, &obj->imagenObjeto.imagenActual, &obj->posicion);
    }
}
