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
        printf("Anadido el principio (%d,%d): \n", (*head_ref)->data.posicion.x,(*head_ref)->data.posicion.y );
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        printf("posicion x en (%d,%d): \n", last->data.posicion.x,last->data.posicion.y );
        last = last->next;}

    /* 6. Change the next of last node */
    last->next = new_node;
    printf("Anadido el (%d,%d): \n", last->next->data.posicion.x,last->next->data.posicion.y );
}


