#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void introducere_valori(int arr[], int n) {
    printf("Introduceti valorile pentru tablou (de la 1 la %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valoarea elementului %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void completare_random(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printf("Tabloul a fost completat cu valori aleatoare.\n");
}

void afisare_tablou(int arr[], int n) {
    printf("Elementele tabloului sunt: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void valori_diferite(int arr1[], int n1, int arr2[], int n2) {
    printf("Valorile din primul tablou care nu se afla in al doilea tablou sunt: ");
    int gasit;
    for (int i = 0; i < n1; i++) {
        gasit = 0;
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                gasit = 1;
                break;
            }
        }
        if (!gasit) {
            printf("%d ", arr1[i]);
        }
    }
    printf("\n");
}

void meniu(int arr1[], int n1, int arr2[], int n2) {
    int optiune;

    printf("\nMeniu:\n");
    printf("1. Introducerea valorilor tabloului 1\n");
    printf("2. Completarea tabloului 1 cu valori random\n");
    printf("3. Afisarea elementelor tabloului 1\n");
    printf("4. Determinarea valorilor din primul tablou care nu se afla in al doilea\n");
    printf("5. Iesire\n");

    printf("Alegeti o optiune: ");
    scanf("%d", &optiune);

    switch(optiune) {
        case 1:
            introducere_valori(arr1, n1);
            break;
        case 2:
            completare_random(arr1, n1);
            break;
        case 3:
            afisare_tablou(arr1, n1);
            break;
        case 4:
            valori_diferite(arr1, n1, arr2, n2);
            break;
        case 5:
            printf("Iesire... La revedere!\n");
            return;
        default:
            printf("Optiune invalida. Incearca din nou.\n");
    }

    meniu(arr1, n1, arr2, n2);
}

int main() {
    int n1, n2;

    printf("Introduceti dimensiunea primului tablou: ");
    scanf("%d", &n1);
    printf("Introduceti dimensiunea celui de-al doilea tablou: ");
    scanf("%d", &n2);

    int arr1[n1], arr2[n2];

    meniu(arr1, n1, arr2, n2);

    return 0;
}
