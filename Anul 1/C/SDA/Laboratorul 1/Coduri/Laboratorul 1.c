/* Se da un array 1D de numere intregi, sa se citeasca de la tastatura random numerele tabloului,
    sa se sorteze elementele tabloului prin metoda Selection Sort, sa se determine numarul de 
    elemente pare, sa se afiseze tabloul (pana la sortare si dupa sortare).*/
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genRand(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        v[i] = rand() % 201 - 100;
}

void afisare(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[minIndex])
                minIndex = j;

        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

    void analiza(int v[], int n) {
    int pare = 0;

    for (int i = 0; i < n; i++) {

        if (v[i] % 2 == 0) pare++;
}

int main() {
    int n;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    int v[n];
    printf ("Vectorul cu elementele generate random:\n");    
    genRand(v, n);
    afisare(v, n);

    printf("\nVector sortat (Selection Sort):\n");
    selectionSort(v, n);
    afisare(v, n);

    return 0;
}


