#include <stdio.h>
#include <stdlib.h>

void meniu(int ***a, int ***b, int n, int *alocat);
void alocare(int ***mat, int n);
void introducere(int **mat, int n);
void afisare(int **mat, int n);
void construire(int **a, int **b, int n);
void eliberare(int ***mat, int n);

int main() {
    int n;
    int **a = NULL, **b = NULL;
    int alocat = 0;

    printf("Introduceti n: ");
    scanf("%d", &n);

    meniu(&a, &b, n, &alocat);

    return 0;
}

void meniu(int ***a, int ***b, int n, int *alocat) {
    int opt;

    printf("\n===== MENIU =====\n");
    printf("1. Alocare matrici\n");
    printf("2. Introducere matrice initiala\n");
    printf("3. Afisare matrice initiala\n");
    printf("4. Construire matrice noua (schema snake)\n");
    printf("5. Afisare matrice noua\n");
    printf("0. Iesire\n");
    printf("Optiunea: ");
    scanf("%d", &opt);

    switch(opt) {

        case 1:
            alocare(a, n);
            alocare(b, n);
            *alocat = 1;
            printf("Matrici alocate.\n");
            break;

        case 2:
            if(*alocat) {
                introducere(*a, n);
                printf("Matrice initiala:\n");
                afisare(*a, n);
            } else {
                printf("Matrici nealocate!\n");
            }
            break;

        case 3:
            if(*alocat)
                afisare(*a, n);
            else
                printf("Matrice nealocata!\n");
            break;

        case 4:
            if(*alocat) {
                construire(*a, *b, n);
                printf("Matrice noua construita:\n");
                afisare(*b, n);
            } else {
                printf("Matrici nealocate!\n");
            }
            break;

        case 5:
            if(*alocat)
                afisare(*b, n);
            else
                printf("Matrice nealocata!\n");
            break;

        case 0:
            if(*alocat) {
                eliberare(a, n);
                eliberare(b, n);
            }
            printf("Program terminat.\n");
            return;

        default:
            printf("Optiune invalida!\n");
    }

    meniu(a, b, n, alocat); // apel recursiv
}

void alocare(int ***mat, int n) {
    *mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        (*mat)[i] = (int*)malloc(n * sizeof(int));
}

void introducere(int **mat, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void afisare(int **mat, int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

void construire(int **a, int **b, int n) {

    int total = n * n;
    int *v = (int*)malloc(total * sizeof(int));
    int k = 0;

    // copiere elemente in vector
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            v[k++] = a[i][j];

    // sortare crescatoare (bubble)
    for(int i = 0; i < total - 1; i++)
        for(int j = i + 1; j < total; j++)
            if(v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    // completare snake
    k = 0;
    for(int i = 0; i < n; i++) {

        if(i % 2 == 0) {  // stanga -> dreapta
            for(int j = 0; j < n; j++)
                b[i][j] = v[k++];
        }
        else {            // dreapta -> stanga
            for(int j = n - 1; j >= 0; j--)
                b[i][j] = v[k++];
        }
    }

    free(v);
}

void eliberare(int ***mat, int n) {
    for(int i = 0; i < n; i++)
        free((*mat)[i]);
    free(*mat);
    *mat = NULL;
}
