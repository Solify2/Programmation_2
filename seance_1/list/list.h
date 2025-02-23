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
//List_t new_list();

//PRE: q est initialisé
//POST: renvoie le nombre d'éléments présents dans q. q n'est pas modifiée.
//int size(List_t q);

//PRE: q est initialisé
//POST: size(q') = size(q)+1 et le dernier élément de q est i. Le reste n'a pas été modifié
//void enqueue(List_t q, int i);


#endif
