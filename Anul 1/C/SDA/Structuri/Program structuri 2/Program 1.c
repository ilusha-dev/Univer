#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char denumire[50];
    int pret;
} Telefon;

void citire(Telefon *t, int n){
    for(int i = 0; i < n; i++){
        printf("\nTelefonul %d\n", i + 1);

        printf("Denumire: ");
        scanf("%s", t[i].denumire);

        printf("Pret: ");
        scanf("%d", &t[i].pret);
    }
}

void afisare(Telefon *t, int n){
    for(int i = 0; i < n; i++){
        printf("\nTelefonul %d\n", i + 1);
        printf("Denumire: %s\n", t[i].denumire);
        printf("Pret: %d\n", t[i].pret);
    }
}

void bubbleSort(Telefon *t, int n){
    Telefon temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(t[j].pret > t[j+1].pret){
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
}

void selectionSort(Telefon *t, int n){
    Telefon temp;
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < n; j++){
            if(t[j].pret < t[minIndex].pret){
                minIndex = j;
            }
        }

        if(minIndex != i){
            temp = t[i];
            t[i] = t[minIndex];
            t[minIndex] = temp;
        }
    }
}

void insertionSort(Telefon *t, int n){
    for(int i = 1; i < n; i++){
        Telefon key = t[i];
        int j = i - 1;

        while(j >= 0 && t[j].pret > key.pret){
            t[j + 1] = t[j];
            j--;
        }

        t[j + 1] = key;
    }
}

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);

    Telefon *t = (Telefon*) malloc(n * sizeof(Telefon));

    citire(t, n);

    printf("\nTabloul initial:\n");
    afisare(t, n);

    bubbleSort(t, n);
    printf("\nDupa Bubble Sort:\n");
    afisare(t, n);

    selectionSort(t, n);
    printf("\nDupa Selection Sort:\n");
    afisare(t, n);

    insertionSort(t, n);
    printf("\nDupa Insertion Sort:\n");
    afisare(t, n);

    free(t);
    return 0;
}