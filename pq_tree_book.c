#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    char title[100];
    int year;
    int pages;
} Book, *Book_t;

typedef struct {
    Book_t *data;
    int size;
    int capacity;
    int (*leq)(Book_t, Book_t);
} PQ, *PQ_t;


void swap(Book_t *arr, int indexOne, int indexTwo){
    Book_t temp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = temp;
}

int getLeftChildIndex(int parent){
    return (2 * parent) + 1;
}

int getRightChildIndex(int parent){
    return (2 * parent) + 2;
}

int getParentIndex(int childIndex){
    return (childIndex -1) / 2;
}

bool hasLefChild(int index,int size){
    return getLeftChildIndex(index) < size;
}

bool hasRightChild(int index,int size){
    return getRightChildIndex(index) < size;
}

bool hasParent(int index){
    return getParentIndex(index) >=0;
}

Book_t leftChild(Book_t *data, int index){
    return data[getLeftChildIndex(index)];
}

Book_t rightChild(Book_t *data, int index){
    return data[getRightChildIndex(index)];
}

Book_t parent(Book_t *data,int index){
    return data[getParentIndex(index)];
}


PQ_t create(int (*leq)(Book_t, Book_t)) {
    PQ_t pq = malloc(sizeof(PQ));
    if (!pq) return NULL;

    pq->data = malloc(INITIAL_CAPACITY * sizeof(Book));
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
    while(hasLefChild(index, pq->size)){
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


Book_t peek(PQ_t pq){
    return pq->data[0];
}


Book_t serve(PQ_t pq){
    Book_t item = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq);
    return item;
}

void enqueue(PQ_t pq, Book_t item){
    pq->data[pq->size] = item;
    pq->size++;
    heapifyUp(pq);
}


void addBook(PQ_t pq) {
    if (!pq) return;

    Book_t newBook = malloc(sizeof(Book));
    printf("Book title: ");
    scanf(" %s", newBook->title);
    printf("Book Year: ");
    scanf("%d", &(newBook->year));
    printf("NB pages: ");
    scanf("%d", &(newBook->pages));
    enqueue(pq, newBook);
    printf("Enqueu OK\n");
}


void suggestBook(PQ_t pq) {
    if (pq->size == 0) {
        printf("no books available, the PQ is emtpy.\n");
        return;
    }

    Book_t bestBook = serve(pq);

    printf("Title: %s\n", bestBook->title);
    printf("Year: %d\n", bestBook->year);
    printf("Pages: %d\n\n", bestBook->pages);
    free(bestBook);
}

int book_priority(Book_t a, Book_t b) {
    if (a->year != b->year) {
        return a->year >= b->year;
    }
    return a->pages <= b->pages;
}


void displayBooks(PQ_t pq) {
    if (!pq || pq->size == 0) {
        printf("There is no books in the PQ.\n");
        return;
    }

    printf("Books in PQ:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Title: %s , Year: %d , Pages: %d\n", pq->data[i]->title, pq->data[i]->year, pq->data[i]->pages);
    }
    printf("\n");
}


int main() {
    PQ_t pq = create(book_priority);

    int choice;
    do {
        printf("Type (1) to Add a new Book\n");
        printf("Type (2) to Get a Book Suggestion\n");
        printf("Type (3) to display all books\n");
        printf("Type (4) to close the program\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(pq);
                break;
            case 2:
                suggestBook(pq);
                break;
            case 3:
                displayBooks(pq);
                break;
            case 4:
                printf("Close\n");
                break;
            default:
                printf("Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}