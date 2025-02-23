/*
Auteur: Cédric Libert
Description:
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#define MAX_SIZE 100

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int size;
} List;

List_t new_list() {
  List_t list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}


Node_t create_node(int data) {
  Node_t new_node = malloc(sizeof(Node));
  new_node->value = data;
  new_node->next = NULL;
  return new_node;
}


void insert_value_at_start(List_t list, int value) {
  Node_t new_node = create_node(value);

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  }else {
    new_node->next = list->head;
    list->head = new_node;
  }
  list->size++;
}


void insert_value_at_end(List_t list, int value) {
  Node_t new_node = create_node(value);
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  }else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

void insert_after(List_t list, Node_t prev_node, int value) {
   if (prev_node == NULL) {
     printf("Error in insert_after\n");
     return;
   }

  Node_t new_node = create_node(value);
  new_node->next = prev_node->next;
  prev_node->next = new_node;

  if (prev_node == list->tail) {
    list->tail = new_node;
  }
  list->size++;
}

Node_t find_node(List_t list, int value) {

  Node_t current_value = list->head;

  while (current_value != NULL) {
    if (current_value->value == value) {
      return current_value;
    }
    current_value = current_value->next;
  }
  return NULL;
}

void display_list(List_t list) {
  Node_t current = list->head;
  printf("List size %d \n", list->size);
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
}


void destroy_list(List_t list) {
  Node_t current_node = list->head;
  Node_t next_node = NULL;

  while (current_node != NULL) {
    next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  free(list);
}

int main(int argc, char **argv){

    List_t list = new_list();

    insert_value_at_end(list, 3);
    insert_value_at_end(list, 4);
    insert_value_at_end(list, 6);
    insert_value_at_start(list, 2);
    insert_value_at_start(list, 1);

    display_list(list);

    Node_t temp = find_node(list, 4);

    if (temp != NULL) {
      insert_after(list, temp, 20);
    }

    display_list(list);
    destroy_list(list);

    return EXIT_SUCCESS;
}
