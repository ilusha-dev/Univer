#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//Problema Exersare a) 
    int Note[5], count = 0, sum = 0;

    printf("Introduce-ti notele studentilor: \n");
    for (int i = 0; i < 5; ++i) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &Note[i]);

        if (Note[i] < 1 || Note[i] > 10) {
            printf("Nota invalida! Introduce-ti o valoare intre 1 si 10. \n");
            i--;
            continue;
        } 

        if (Note[i] == 9 || Note[i] == 10) {
            count++;
        }

        sum += Note[i];
    }
    printf("Numarul notelor de 9 si 10 este: %d\n", count);
    printf("Suma tuturor notelor este: %d", sum);   

    return 0;
}