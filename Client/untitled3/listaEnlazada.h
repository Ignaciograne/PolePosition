//
// Created by maxta on 8/4/2022.
//

#ifndef UNTITLED3_LISTAENLAZADA_H
#define UNTITLED3_LISTAENLAZADA_H

#include<stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

#endif //UNTITLED3_LISTAENLAZADA_H
