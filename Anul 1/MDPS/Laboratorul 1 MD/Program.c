#include <stdio.h>
#include <stdlib.h>

#define MAX 50


typedef struct Nod {
    int varf;
    struct Nod* next;
} Nod;

Nod* lista[MAX];

//  INITIALIZARE LISTA 
void initializareLista(int n) {
    for (int i = 0; i < n; i++)
        lista[i] = NULL;
}

// ADAUGARE ARC 
void adaugaArc(int i, int j) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->varf = j;
    nou->next = lista[i];
    lista[i] = nou;
}

//  CITIRE MATRICE ADIACENTA 
void citireMatriceAd(int matr[MAX][MAX], int n) {
    printf("Introduceti matricea de adiacenta:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matr[i][j]);
}

// CITIRE MATRICE INCIDENTA
void citireMatriceInc(int inc[MAX][MAX], int m, int n) {
    printf("Introduceti matricea de incidenta:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &inc[i][j]);
}

//  CITIRE LISTA ADIACENTA
void citireLista(int n) {
    initializareLista(n);
    printf("Introduceti lista (terminati fiecare linie cu 0):\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        int x;
        scanf("%d", &x);
        while (x != 0) {
            adaugaArc(i, x - 1);
            scanf("%d", &x);
        }
    }
}

// AFISARE MATRICE ADIACENTA
void afisareMatriceAd(int matr[MAX][MAX], int n) {
    printf("\nMatricea de adiacenta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}

//  AFISARE LISTA
void afisareLista(int n) {
    printf("\nLista de adiacenta:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        Nod* temp = lista[i];
        while (temp) {
            printf("%d ", temp->varf + 1);
            temp = temp->next;
        }
        printf("0\n");
    }
}

//  AFISARE MATRICE INCIDENTA
void afisareMatriceInc(int inc[MAX][MAX], int m, int n) {
    printf("\nMatricea de incidenta:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", inc[i][j]);
        printf("\n");
    }
}

//  MATRICE ADIACENTA -> LISTA
void matrAd_to_lista(int ad[MAX][MAX], int n) {
    initializareLista(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ad[i][j] == 1)
                adaugaArc(i, j);
}

//  MATRICE INCIDENTA -> LISTA
void matrInc_to_lista(int inc[MAX][MAX], int n, int m) {
    initializareLista(n);

    for (int i = 0; i < m; i++) {
        int start = -1, end = -1;

        for (int j = 0; j < n; j++) {
            if (inc[i][j] == -1) start = j;
            if (inc[i][j] == 1) end = j;
            if (inc[i][j] == 2) adaugaArc(j, j); // bucla
        }

        if (start != -1 && end != -1)
            adaugaArc(start, end);
    }
}

//  LISTA -> MATRICE ADIACENTA 
void lista_to_matrAd(int ad[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ad[i][j] = 0;

    for (int i = 0; i < n; i++) {
        Nod* temp = lista[i];
        while (temp) {
            ad[i][temp->varf] = 1;
            temp = temp->next;
        }
    }
}

// LISTA -> MATRICE INCIDENTA 
int lista_to_matrInc(int inc[MAX][MAX], int n) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        Nod* temp = lista[i];
        while (temp) {
            for (int j = 0; j < n; j++)
                inc[k][j] = 0;

            if (i == temp->varf) {
                inc[k][i] = 2;
            } else {
                inc[k][i] = -1;
                inc[k][temp->varf] = 1;
            }

            k++;
            temp = temp->next;
        }
    }
    return k;
}

int main() {
    int n, m;
    int matrAd[MAX][MAX];
    int matrInc[MAX][MAX];

    printf("Numar varfuri: ");
    scanf("%d", &n);

    printf("\nForma de introducere:\n");
    printf("1 - Matrice adiacenta\n");
    printf("2 - Matrice incidenta\n");
    printf("3 - Lista adiacenta\n");
    printf("Optiune: ");

    int opt;
    scanf("%d", &opt);

    if (opt == 1) {
        citireMatriceAd(matrAd, n);
        matrAd_to_lista(matrAd, n);
    }
    else if (opt == 2) {
        printf("Numar arce: ");
        scanf("%d", &m);
        citireMatriceInc(matrInc, m, n);
        matrInc_to_lista(matrInc, n, m);
    }
    else if (opt == 3) {
        citireLista(n);
    }
    else {
        printf("Optiune invalida!\n");
        return 0;
    }


    lista_to_matrAd(matrAd, n);
    m = lista_to_matrInc(matrInc, n);

    afisareMatriceAd(matrAd, n);
    afisareLista(n);
    afisareMatriceInc(matrInc, m, n);

    return 0;
}