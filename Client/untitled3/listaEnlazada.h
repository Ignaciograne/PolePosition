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

struct NodeU
{
    User data;
    struct NodeU *next;
};


//Lista crearLista();
//display the list
static struct Node * node;
void printList(struct Node *node);

//void insertFirst (Lista *l, int dato);
void append(struct Node** head_ref, Objeto new_data);
void deleteNode(struct Node** head_ref, Objeto * obj);
void colisionObjetos(User * usuario, struct Node *objetos);


static struct NodeU * nodeU;
void printListU(struct NodeU *nodeU);

void appendU(struct NodeU** head_ref, User new_data);
void deleteNodeU(struct NodeU** head_ref, User * usi);
//void colisionObjetosU(User * usuario, struct Node *objetos);

#endif //UNTITLED3_LISTAENLAZADA_H
