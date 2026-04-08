//Problema 2

#include <stdio.h>

int main() {
    int n, t, vector[n];
    printf("Introduce-ti numarul de elemente (n): ");
    scanf("%d", &n);

    printf("Introduce-ti valorile vectorului: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    printf("Introduce-ti t (1 < t < %d): ", n);
    scanf("%d", &t);

    int suma = 0;
    for (int i = 0; i < t; i++) {
        suma += vector[i];
    }
    printf("Suma primelor %d elemente: %d\n", t, suma);

    int sumaRamase = 0, cntRamase = 0;
    for (int i = t; i < n; i++) {
        sumaRamase += vector[i];
        cntRamase++;
    }

    if (cntRamase > 0)
        printf("Media aritmetica a elementelor ramase: %.2f\n", (float)sumaRamase / cntRamase);
    else
        printf("Nu exista elemente ramase.\n");

    return 0;
}
