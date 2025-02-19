#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//
// Created by Ahmed Soleiman on 19/02/2025.
//


// 1.Créez une liste pouvant contenir des Fighter avec les propriétés suivantes:
// * Un nom;
// * Un nombre de points de vie (nombre entier tel que 0<PV<MAX_PV).
// * Une position (coordonnées telles que 0<=x<MAX_X et 0<=y<MAX_Y, avec MAX_X et
// MAX_Y des constantes que vous définissez).
// * Une vitesse (entier tel que 0<vitesse<MAX_VITESSE)

struct Position {
    int x;
    int y;
};

struct Fighter {
    char *nom;
    int *points;
    int *speed;
} typedef Fighter;


struct Node {
    struct Node *next;
    Fighter *fighter;
} typedef Node;


struct Queue {
    Node *head;
    Node *tail;
    int size;
} typedef Queue;


Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    // Return the pointer to the Queue struct
    return queue;
}

bool is_empty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, Fighter *fighter)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->fighter = fighter;
    newNode->next = NULL;


    if (is_empty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
    }

    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}


Fighter *createFighter(char *nom, int *points, int speed) {
    Fighter *fighter = malloc(sizeof(Fighter));
}