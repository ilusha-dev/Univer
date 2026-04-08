// Se inverseaza liniile in tabloul 2D


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

void afisareMatrice(int a[][MAX], int n, int m, const char* mesaj)
{
    printf("\n%s\n", mesaj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%4d", *(*(a + i) + j));
        printf("\n");
    }
}

void inversareRanduri(int a[][MAX], int n, int m)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        int st = 0, dr = m - 1;
        while (st < dr)
        {
            aux = *(*(a + i) + st);
            *(*(a + i) + st) = *(*(a + i) + dr);
            *(*(a + i) + dr) = aux;
            st++;
            dr--;
        }
    }
}

int main()
{
    int a[MAX][MAX];
    int n, m;

    printf("Numar linii: "); scanf("%d", &n);
    printf("Numar coloane: "); scanf("%d", &m);

    citireMatrice(a, n, m);
    afisareMatrice(a, n, m, "Matricea initiala:");

    inversareRanduri(a, n, m);

    afisareMatrice(a, n, m, "Matricea dupa inversarea randurilor:");

    return 0;
}
