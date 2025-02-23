//
// Created by Ahmed Soleiman on 23/02/2025.
//

#include <stdlib.h>
#include <stdio.h>

#include "../list/list.h"
#include "queue.h"
#define MAX_SIZE 100

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue_t new_queue() {
    Queue_t queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return  queue;
}

int size(Queue_t queue) {
    return queue->size;
}

void enqueue(Queue_t q, int i) {
    Node_t new_node = malloc(sizeof(Node));
    new_node->value = i;

    if(q->size==0) {
        q->head = new_node;
        q->tail = new_node;
    }else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

int dequeue(Queue_t q) {
    if(q->size==0) {
        return -1;
    }

    int value = q->head->value;
    Node_t oldHead = q->head;

    if (q->size==1) {
        q->head = NULL;
        q->tail = NULL;
    }else {
        q->head = q->head->next;
    }
    free(oldHead);
    q->size--;
    return value;
}


int main(int argc, char **argv){
    Queue_t q = new_queue();
    printf("Taille:%i\n",size(q));
    enqueue(q,3);
    printf("Enqueue 3 \n");
    printf("3 -> NULL\n");
    printf("Taille:%i\n",size(q));
    printf("-------------\n");

    enqueue(q,5);
    printf("Enqueue 5 \n");
    printf("3 -> 5 -> NULL\n");
    printf("Taille:%i\n",size(q));
    printf("-------------\n");

    enqueue(q,1);
    printf("Enqueue 1 \n");
    printf("3 -> 5 -> 1 -> NULL\n");
    printf("Taille:%i\n",size(q));
    printf("-------------\n");

    int a = dequeue(q);
    printf("Dequeue \n");
    printf("Élement enlevé:%i\n",a);
    printf("5 -> 1 -> NULL\n");
    printf("-------------\n");

    int b = dequeue(q);
    printf("Dequeue \n");
    printf("Élement enlevé:%i\n",b);
    printf("1 -> NULL\n");
    printf("-------------\n");

    printf("Taille:%i\n",size(q));
    printf("Enqueue 6 \n");
    enqueue(q,6);
    printf("1 -> 6 -> NULL\n");

    printf("-------------\n");

    int c = dequeue(q);
    printf("Dequeue \n");
    printf("Élement enlevé:%i\n",c);
    printf("6 -> NULL\n");

    return EXIT_SUCCESS;
}
