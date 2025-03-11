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

    Queue_t result = new_queue();

    Node_t current = q->head;
    Node_t next = q->head->next;
    int nb_seq_val = 1;

    while(next != NULL) {
        if (current->value == next->value) {
            nb_seq_val++;
            next = next->next;
        }else {
            enqueue(result, current->value);
            enqueue(result, nb_seq_val);
            nb_seq_val = 1;
            current =  next;
            next = next->next;
        }
    }

    enqueue(result, current->value);
    enqueue(result, nb_seq_val);


    Node_t curr = result->head;
    while(curr!=NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    return 0;
}




int main()
{
    int val=0;
    int nbv_value = 0;
    Queue_t q = new_queue();
    printf("Enter number of elements: ");
    scanf("%d", &nbv_value);

    while(nbv_value!=0) {
      scanf("%d",&val);
      enqueue(q,val);
      nbv_value--;
    }
    printf("Decompression queue:\n");
    decompress(q);

    //int len = q->size;
    // for(int i=0;i<len;i++) {
    //   printf("%d ",dequeue(q));
    // }
    return 0;
}