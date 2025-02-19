


//
// Created by Ahmed Soleiman on 19/02/2025.
//





// 1.Créez une liste pouvant contenir des Fighter avec les propriétés suivantes:
// * Un nom;
// * Un nombre de points de vie (nombre entier tel que 0<PV<MAX_PV).
// * Une position (coordonnées telles que 0<=x<MAX_X et 0<=y<MAX_Y, avec MAX_X et
// MAX_Y des constantes que vous définissez).
// * Une vitesse (entier tel que 0<vitesse<MAX_VITESSE)


#define NB_FIGHTERS 20



char *langs[NB_FIGHTERS] = {"Fighter_1","Fighter_2","Fighter_3","Fighter_4","Fighter_5"};



struct position {
    int x;
    int y;
};

struct fighters {
    char *nom;
    int *nb_point;
    int *speed;

};

struct Node {
    struct Node *next;
} typedef Node, Node_t*;





void main() {



}
