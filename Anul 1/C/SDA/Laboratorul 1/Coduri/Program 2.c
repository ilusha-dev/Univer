#include <stdio.h>
#include <stdlib.h>

void meniu(int ***mat, int n, int m, int *alocat);
void alocare(int ***mat, int n, int m);
void introducere(int **mat, int n, int m);
void afisare(int **mat, int n, int m);
void sortare_chenar(int **mat, int n, int m, int tip);
void eliberare(int ***mat, int n);

int main() {
    int n, m;
    int **mat = NULL;
    int alocat = 0;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    meniu(&mat, n, m, &alocat);

    return 0;
}

void meniu(int ***mat, int n, int m, int *alocat) {
    int opt;

    printf("\n===== MENIU =====\n");
    printf("1. Alocare matrice\n");
    printf("2. Introducere date\n");
    printf("3. Afisare matrice\n");
    printf("4. Sortare chenar crescator\n");
    printf("5. Sortare chenar descrescator\n");
    printf("0. Iesire\n");
    printf("Optiunea: ");
    scanf("%d", &opt);

    switch(opt) {

        case 1:
            alocare(mat, n, m);
            *alocat = 1;
            printf("Matrice alocata.\n");
            break;

        case 2:
            if(*alocat) {
                introducere(*mat, n, m);
                printf("Date introduse.\n");
                afisare(*mat, n, m);
            } else {
                printf("Matrice nealocata!\n");
            }
            break;

        case 3:
            if(*alocat)
                afisare(*mat, n, m);
            else
                printf("Matrice nealocata!\n");
            break;

        case 4:
            if(*alocat) {
                sortare_chenar(*mat, n, m, 1);
                printf("Chenar sortat crescator:\n");
                afisare(*mat, n, m);
            } else {
                printf("Matrice nealocata!\n");
            }
            break;

        case 5:
            if(*alocat) {
                sortare_chenar(*mat, n, m, 0);
                printf("Chenar sortat descrescator:\n");
                afisare(*mat, n, m);
            } else {
                printf("Matrice nealocata!\n");
            }
            break;

        case 0:
            if(*alocat)
                eliberare(mat, n);
            printf("Program terminat.\n");
            return;

        default:
            printf("Optiune invalida!\n");
    }

    meniu(mat, n, m, alocat); // apel recursiv
}

void alocare(int ***mat, int n, int m) {
    *mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        (*mat)[i] = (int*)malloc(m * sizeof(int));
}

void introducere(int **mat, int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
}

void afisare(int **mat, int n, int m) {
    printf("\nMatrice:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

void sortare_chenar(int **mat, int n, int m, int tip) {

    int max_elem = 2*n + 2*m - 4;
    int *v = (int*)malloc(max_elem * sizeof(int));
    int k = 0;

    // prima linie
    for(int j = 0; j < m; j++)
        v[k++] = mat[0][j];

    // coloana dreapta
    for(int i = 1; i < n-1; i++)
        v[k++] = mat[i][m-1];

    // ultima linie
    for(int j = m-1; j >= 0; j--)
        v[k++] = mat[n-1][j];

    // coloana stanga
    for(int i = n-2; i > 0; i--)
        v[k++] = mat[i][0];

    // sortare bubble
    for(int i = 0; i < k-1; i++)
        for(int j = i+1; j < k; j++)
            if( (tip==1 && v[i] > v[j]) ||
                (tip==0 && v[i] < v[j]) ) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    // repunere in matrice
    k = 0;

    for(int j = 0; j < m; j++)
        mat[0][j] = v[k++];

    for(int i = 1; i < n-1; i++)
        mat[i][m-1] = v[k++];

    for(int j = m-1; j >= 0; j--)
        mat[n-1][j] = v[k++];

    for(int i = n-2; i > 0; i--)
        mat[i][0] = v[k++];

    free(v);
}

void eliberare(int ***mat, int n) {
    for(int i = 0; i < n; i++)
        free((*mat)[i]);
    free(*mat);
    *mat = NULL;
}
