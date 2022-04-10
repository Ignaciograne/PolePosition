//
// Created by maxta on 8/4/2022.
//

#ifndef UNTITLED3_LISTAENLAZADA_H
#define UNTITLED3_LISTAENLAZADA_H

#include<stdlib.h>
#include <stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include "usuario.h"

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();


struct Node
{
    Objeto data;
    struct Node *next;
};

//Lista crearLista();
//display the list
static struct Node * node;
void printList(struct Node *node);

//void insertFirst (Lista *l, int dato);
void append(struct Node** head_ref, Objeto new_data);
void colisionObjetos(User * usuario, struct Node *objetos);

#endif //UNTITLED3_LISTAENLAZADA_H
