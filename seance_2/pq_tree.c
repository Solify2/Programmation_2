#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* data;              
    int size;           
    int capacity;   
    int (*leq)(int, int);
} PQ, *PQ_t;


int getLeftChildIndex(int parent){
    return (2 * parent) + 1;
}

int getRightChildIndex(int parent){
    return (2 * parent) + 2;
}

int getParentIndex(int childIndex){
    return (childIndex -1) / 2;
}

bool hasLeftChild(int index,int size){
    return getLeftChildIndex(index) < size;
}

bool hasRightChild(int index,int size){
    return getRightChildIndex(index) < size;
}

bool hasParent(int index){
    return getParentIndex(index) >=0;
}

int leftChild(int *data, int index){
    return data[getLeftChildIndex(index)];
}

int rightChild(int *data, int index){
    return data[getRightChildIndex(index)];
}

int parent(int *data,int index){
    return data[getParentIndex(index)];
}


void swap(int *arr, int indexOne, int indexTwo){
    int temp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = temp;
}



PQ_t create(int (*leq)(int, int)) {
    PQ_t pq = (PQ_t)malloc(sizeof(PQ_t));
    if (!pq) return NULL;

    pq->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!pq->data) {
        free(pq);
        return NULL;
    }

    pq->size = 0;
    pq->capacity = INITIAL_CAPACITY;
    pq->leq = leq;

    return pq;
}

void heapifyUp(PQ_t pq){
    int index = pq->size - 1;
    while(hasParent(index) &&  !(pq->leq(parent(pq->data,index),pq->data[index]))){
        swap(pq->data,getParentIndex(index), index);
        index = getParentIndex(index);
    }
}


void heapifyDown(PQ_t pq){
    int index = 0;
    while(hasLeftChild(index, pq->size)){
        int smallerChildrenIndex = getLeftChildIndex(index);
        if(hasRightChild(index, pq->size) && pq->leq(rightChild(pq->data,index), leftChild(pq->data,index))){
            smallerChildrenIndex = getRightChildIndex(index);
        }

        if(pq->leq(pq->data[index],pq->data[smallerChildrenIndex])){
            break;
        }else{
            swap(pq->data,index, smallerChildrenIndex);
        }
        index = smallerChildrenIndex;
    }

}


int peek(PQ_t pq){
    if(pq->size == 0){
        return -1;
    }
    return pq->data[0];
}


int serve(PQ_t pq){
    if(pq->size == 0){
        return -1;
    }

    int item = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq);
    return item;
}

void enqueue(PQ_t pq, int item){
    pq->data[pq->size] = item;
    pq->size++;
    heapifyUp(pq);
}


void printPQ(PQ_t pq) {

    if (pq == NULL || pq->size == 0) {
        printf("Priority Queue is NULL or Empty.\n");
        return;
    }

    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}


int min_priority(int a, int b) {
    return a <= b;
}


int max_priority(int a, int b) {
    return a >= b;
}

int main()
{
    printf("Hello World");
    PQ_t pq = create(max_priority);

    enqueue(pq, 5);
    enqueue(pq, 2);
    enqueue(pq, 8);
    enqueue(pq, 1);
    printPQ(pq);
    printf("Served: %d\n", serve(pq));
    printf("Served: %d\n", serve(pq));
    printf("Served: %d\n", serve(pq));
    printf("Served: %d\n", serve(pq));
    printf("Served: %d\n", serve(pq));

    return 0;
}