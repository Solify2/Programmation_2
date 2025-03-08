//
// Created by Ahmed Soleiman on 08/03/2025.
//
//
// Created by Ahmed Soleiman on 06/03/2025.
//
#include <stdio.h>

#include "../list/list.h"
#include "../queue/queue.h"
#include <stdio.h>

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

int decompress(Queue_t q) {

    Node_t current = q->head;
    Node_t value = q->head;
    int counter = 0;

    int len = q->size;
    while(len != 0) {
        if (current->value == current->next->value) {
            counter++;
            current = current->next;
            dequeue(q);
        }else {

        }

    }


}




int main()
{
    int val=0;
    int nbv_value = 0;
    Queue_t q = new_queue();
    printf("Enter number of elements: \n");
    scanf("%d", &nbv_value);

    while(nbv_value!=0) {
      scanf("%d",&val);
      enqueue(q,val);
      nbv_value--;
    }


    Node_t current = q->head;
    while(current!=NULL) {
        printf("%d\n", current->value);
        current = current->next;

    }
    //int len = q->size;
    // for(int i=0;i<len;i++) {
    //   printf("%d ",dequeue(q));
    // }
    return 0;
}