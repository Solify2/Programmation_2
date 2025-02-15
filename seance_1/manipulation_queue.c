/*
Auteur: Cédric Libert
Description:
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#define MAX_SIZE 100
typedef struct Queue {
  int elements[MAX_SIZE];
  int start;
  int end;
};

Queue_t new_queue() {
  Queue_t init_queue = (Queue_t)malloc(sizeof( struct Queue));
  init_queue->start = -1;
  init_queue->end = -1;
  return init_queue;
}

int size(Queue_t queue) {
  if (queue->start == -1) {
    return 0;
  }
  return (queue->end - queue->start+1);
}


void enqueue(Queue_t q, int i) {
  if (q->end == MAX_SIZE - 1) {
    printf("Queue is full!\n");
    return;
  }

  if (q->start == -1) {
      q->start = 0;
  }


  q->end++;
  q->elements[q->end] = i;
}

int dequeue(Queue_t q) {
  if (q->start == -1 || q->start > q->end) {
     return  0;
   }

  int first_element = q->elements[q->start];
  for (int i = q->start; i < q->end ; i++) {
    q->elements[i] = q->elements[i + 1];
  }
  q->end--;
  return first_element;


}


int main(int argc, char **argv){
  Queue_t q = new_queue();

  printf("Taille:%i\n",size(q));
  enqueue(q,3);
  printf("Taille:%i\n",size(q));
  enqueue(q,5);
  printf("Taille:%i\n",size(q));
  enqueue(q,2);
  printf("Taille:%i\n",size(q));


  int a = dequeue(q);
  printf("Element enleve:%i\n",a);
  int b = dequeue(q);
  printf("Element enleve:%i\n",b);
  //printf("Taille:%i\n",size(q));
  int c = dequeue(q);
  printf("Element enleve:%i\n",c);
  enqueue(q,1);
  printf("Taille:%i\n",size(q));
  int d = dequeue(q);
  printf("Element enleve:%i\n",d);

  free(q);

  //printf("Taille:%i\n",size(queue));
  return EXIT_SUCCESS;
}
