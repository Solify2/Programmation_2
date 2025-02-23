#include <stdio.h>
#include "fighters.c"
#define NB_FIGHTERS 20

char *fighters[NB_FIGHTERS] = {"Fighter_1","Fighter_2","Fighter_3","Fighter_4","Fighter_5"};

int main(void) {
    int nb_fighters;
    int i = 0;
    printf("NB Fighters ? \n");
    scanf("%d", &nb_fighters);

    while(i < nb_fighters) {

        // Create fighters
        printf("%d\n", nb_fighters);
        i++;
    }

    return 0;
}
