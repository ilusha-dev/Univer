// Din 2D linie in !D, linia se alege prin index K


#include <stdio.h>
#define MAX 50

void citireMatrice(int a[][MAX], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", *(a + i) + j);
        }
}

void afisareMatrice(int a[][MAX], int n, int m)
{
    printf("\nMatricea este:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%4d", *(*(a + i) + j));
        printf("\n");
    }
}

void afisareVector(int v[], int m)
{
    printf("\nVectorul 1D este:\n");
    for (int j = 0; j < m; j++)
        printf("%4d", *(v + j));
    printf("\n");
}

void copiazaRand(int a[][MAX], int n, int m, int k, int v[])
{
    for (int j = 0; j < m; j++)
        *(v + j) = *(*(a + k) + j);
}

int main()
{
    int a[MAX][MAX], v[MAX];
    int n, m, k;

    printf("Numar linii: "); scanf("%d", &n);
    printf("Numar coloane: "); scanf("%d", &m);

    citireMatrice(a, n, m);
    afisareMatrice(a, n, m);

    printf("\nIntroduceti indexul K al randului de copiat: ");
    scanf("%d", &k);

    copiazaRand(a, n, m, k, v);
    afisareVector(v, m);

    return 0;
}
