//Un tablou 2D, prin functie sa se zerografieze diagonala principala


#include <stdio.h>

void zero_main_diagonal(int rows, int cols, int mat[rows][cols]) {
    int limit = (rows < cols) ? rows : cols;
    for (int i = 0; i < limit; ++i) {
        mat[i][i] = 0;
    }
}

int main(void) {
    int rows, cols;
    printf("Introduceți numărul de rânduri și coloane: ");
    if (scanf("%d %d", &rows, &cols) != 2) return 1;

    int mat[rows][cols];

    printf("Introduceți elementele matricei (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            scanf("%d", &mat[i][j]);

    zero_main_diagonal(rows, cols, mat);

    printf("Matricea după zero pe diagonala principală:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
