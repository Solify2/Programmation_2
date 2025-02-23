//
// Created by Ahmed Soleiman on 23/02/2025.
//

#ifndef LIST_H
#define LIST_H

struct List; //déclaration du nom de ma structure
struct Node;
typedef struct List* List_t; //déclaration d'un alias qui désigne le type "pointeur vers struct Queue"
typedef struct Node* Node_t;

//PRE: /
//POST: initialise une Queue vide et renvoie un pointeur vers celle-ci

List_t new_list();
Node_t create_node(int value);

void insert_value_at_start(List_t list, int value);
void insert_value_at_end(List_t list, int value);
void insert_after(List_t list, Node_t node, int value);
void delete_node(Node_t node, int value);
void destory_list(List_t list);
void display_list(List_t list);

Node_t find_node(List_t list, int value);




//PRE: q est initialisé
//POST: renvoie le nombre d'éléments présents dans q. q n'est pas modifiée.
//int size(List_t q);

//PRE: q est initialisé
//POST: size(q') = size(q)+1 et le dernier élément de q est i. Le reste n'a pas été modifié
//void enqueue(List_t q, int i);


#endif
