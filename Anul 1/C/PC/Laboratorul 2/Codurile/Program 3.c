#include <stdio.h>

int main() {
    int N;

    printf("Introduceti un numar natural mai mare ca 10 si mai mic sau egal cu 20: ");
    scanf("%d", &N);

    switch (N) {
        case 11: printf ("Na - Sodiu\n"); break;
        case 12: printf ("Mg - Magneziu\n"); break;
        case 13: printf ("Al - Aluminiu\n"); break;
        case 14: printf ("Si - Siliciu\n"); break;
        case 15: printf ("P - Fosfor\n"); break;
        case 16: printf ("S - Sulf\n"); break;
        case 17: printf ("Cl - Clor\n"); break;
        case 18: printf ("Ar - Argon\n"); break;
        case 19: printf ("K - Potasiu\n"); break;
        case 20: printf ("Ca - Calciu\n"); break;
        default: printf ("Trebuie un numar intre 11 si 20!"); break;
    }

    return 0;
}
