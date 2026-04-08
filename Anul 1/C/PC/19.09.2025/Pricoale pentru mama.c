#include <stdio.h>

int main() {
    int ore;
    printf ("Noroc Viorica, uite urmatorl grafic al orelor copilului tau iubit ! \n");
    scanf ("%d", &ore);
    switch (ore) {
        case 1: printf ("Perechea 1: Programarea calculatoarelor");
            break;
        case 2: printf ("Perechea 2: Ora libera");
            break;
        case 3: printf ("Perechea 3: Tehnologiile de programare aplicata");
            break;
        case 4: printf ("Perechea 4: Educatia fizica");
            break;
        default: printf ("Ilusha nu are perechea data !");
            break;
    }
    
    return 0;
}