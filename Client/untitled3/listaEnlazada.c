//
// Created by maxta on 8/4/2022.
//

#include "listaEnlazada.h"

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" (%d, %d)", node->data.posicion.x, node->data.posicion.y);
        node = node->next;
    }
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, Objeto new_data){

    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        last = last->next;}

    /* 6. Change the next of last node */
    last->next = new_node;
}

void deleteNode(struct Node** head_ref, Objeto * obj)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && &temp->data == obj) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && &temp->data != obj) {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL){
        return;}

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void printListU(struct NodeU *node)
{
    while (node != NULL)
    {
        printf(" (%d, %d)", node->data.posicion.x, node->data.posicion.y);
        node = node->next;
    }
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void appendU(struct NodeU** head_ref, User new_data){

    /* 1. allocate node */
    struct NodeU* new_node = (struct NodeU*) malloc(sizeof(struct NodeU));

    struct NodeU *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        last = last->next;}

    /* 6. Change the next of last node */
    last->next = new_node;
}

void deleteNodeU(struct NodeU** head_ref, User * usi)
{
    printf("\nLlega a delete noce\n");
    // Store head node
    struct NodeU *temp = head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && &temp->data == usi) {
        printf("Primero este (%d,%d) comprado con este(%d,%d)\n", temp->data.posicion.x,temp->data.posicion.y,usi->posicion.x,usi->posicion.y);
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && &temp->data != usi) {
        printf("Segundo este (%d,%d) comprado con este(%d,%d)\n", temp->data.posicion.x,temp->data.posicion.y,usi->posicion.x,usi->posicion.y);
        prev = temp;
        temp = temp->next;
        //printf("Segundo este (%d,%d) comprado con este(%d,%d)\n", temp->data.posicion.x,temp->data.posicion.y,usi->posicion.x,usi->posicion.y);
    }
    // If key was not present in linked list
    if (temp == NULL){
        printf("temp es nulo");
        return;}

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}



void colisionObjetos(User * usuario, struct Node *objetos){
    node = objetos;
    while (node != NULL){
        if(SDL_HasIntersection(&usuario->posicion,&node->data.posicion)){
            usuario->aceleracion = usuario->aceleracion + node->data.aceleracion;
            if (usuario->aceleracion > 9){
                usuario->aceleracion = 9;
            }
            if (usuario->aceleracion<1){
                usuario->aceleracion = 1;
            }
            if(node->data.vida!=0){
                usuario->vidas = usuario->vidas + node->data.vida;
            }
            if (node->data.puntos!=0){
                usuario->puntaje = usuario->puntaje + node->data.puntos;
                printf("Puntaje subido a: %d por objeto. \n", usuario->puntaje);
            }
            deleteNode(&objetos,&node->data);
        }
        node = node->next;
    }
}

void colisionUsuarios(User * usuario, struct NodeU *usuarios){
    nodeU = usuarios;
    while (nodeU != NULL){
        if(SDL_HasIntersection(&usuario->posicion,&nodeU->data.posicion)){
            /**usuario->aceleracion = usuario->aceleracion + node->data.aceleracion;
            if (usuario->aceleracion > 9){
                usuario->aceleracion = 9;
            }
            if (usuario->aceleracion<1){
                usuario->aceleracion = 1;
            }
            if(node->data.vida!=0){
                usuario->vidas = usuario->vidas + node->data.vida;
            }
            if (node->data.puntos!=0){
                usuario->puntaje = usuario->puntaje + node->data.puntos;
                printf("Puntaje subido a: %d por objeto. \n", usuario->puntaje);
            }
            deleteNode(&objetos,&node->data);**/
        }
        nodeU = nodeU->next;
    }
}