#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char denumire[50];
    int nrAngajati;
} Companie;

int citire(Companie *v) {
    FILE *f = fopen("dateIN.txt", "r");
    if (f == NULL) {
        printf("Eroare! Fisierul dateIN.txt nu exista!\n");
        exit (1);
    }

    int i = 0;
    while (fscanf(f, "%49s %d", (v + i) -> denumire, &(v + i) -> nrAngajati) == 2) {
        i++;
    }
    fclose(f);
    return i;
}

void scriereBinar(Companie *v, int n) {
    FILE *f = fopen ("dateOUT.bin", "wb");
    if (f == NULL) {
        printf("Eroare! Fisierul dateOUT.bin nu poate fi creat! \n");
        exit (1);
    }

    fwrite (v, sizeof(Companie), n, f);
    
    fclose(f);
    printf("Datele au fost scrise in dateOUT.bin cu succes! \n");
}

void afisareBinar(int n) {
    FILE *f = fopen("dateOUT.bin", "rb");
    if (f == NULL) {
        printf("Eroare! Nu s-a putut deshide fisierul dateOUT.bin! \n");
        exit (1);
    }

    Companie temp;
    printf("\n %-5s %-30s %-15s\n", "Nr.", "Denumire", "Nr. Angajati");
    printf("%-5s %-30s %-15s\n", "---", "------------------------------", "---------------");

    for (int i = 0; i < n; i++) {
        fread(&temp, sizeof(Companie), 1, f);
        printf("%-5d %-30s %-15d\n", i + 1, temp.denumire, temp.nrAngajati);
    }

    fclose(f);
}

void bubbleSort (Companie *v, int n) {
    Companie temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp((v + j) -> denumire, (v + j + 1) -> denumire) > 0) {
                temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }
        }
    }

    printf("BubbleSort dupa denumire finalizat. \n");
}

void selectionSort (Companie *v, int n) {
    Companie temp;
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;
        for (int j = i + 1; j < n; j++) {
            if ((v + j) -> nrAngajati < (v + idx_min) -> nrAngajati) {
                idx_min = j;
            }
        } 

        if (idx_min != 1) {
            temp = *(v + i);
            *(v + i) = *(v + idx_min);
            *(v + idx_min) = temp;
        }
    }

    printf ("SelectionSort dupa nrAngajati finalizat! \n");
}

void afisareConsola(Companie *v, int n) {
    printf ("\n %-5s %-30s %-15s \n", "Nr.", "Denumire", "Nr, Angajati");
    printf ("%-5s %-30s %-15s \n", "---", "------------------------------", "------------");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-30s %-15d \n", i + 1, (v + i) -> denumire, (v + i) -> nrAngajati);
    }
}

int main() {
    int n;
    printf("Introduceti numarul de companii: ");
    scanf("%d", &n);

    Companie *v = (Companie *) malloc(n * sizeof(Companie));
    if (v == NULL) {
        printf("Eroare! Nu s-a putut aloca memorie pentru companii! \n");
        return 1;
    }

    int citite = citire(v);
    printf("Au fost citite %d companii din fisierul dateIN.txt! \n\n", citite);

    printf("=====Date initiale=====");
    afisareConsola(v, citite);

    printf("\n Scrierea datelor in dateOUT.bin (datele initiale) \n");
    scriereBinar(v, citite);

    printf("\n BubbleSort dupa denumire) \n");
    bubbleSort(v, citite);
    afisareConsola(v, citite);
    scriereBinar(v, citite);

    printf("\n SelectionSort dupa nrAngajati \n");
    selectionSort(v, citite);
    afisareConsola(v, citite);

    printf("\n Scrierea finala in dateOUT.bin \n");
    scriereBinar(v, citite);

    printf("\n Afisarea datelor din dateOUT.bin \n");
    afisareBinar(citite);

    free(v);
    printf("\n Program terminat cu succes! \n");
    return 0;
}