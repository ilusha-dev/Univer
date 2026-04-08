// Se inverseaza coloanele in tabloul 2D


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

void inversareColoane(int a[][MAX], int n, int m)
{
    int aux;
    for (int j = 0; j < m; j++)
    {
        int sus = 0, jos = n - 1;
        while (sus < jos)
        {
            aux = *(*(a + sus) + j);
            *(*(a + sus) + j) = *(*(a + jos) + j);
            *(*(a + jos) + j) = aux;
            sus++;
            jos--;
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

    inversareColoane(a, n, m);

    afisareMatrice(a, n, m, "Matricea dupa inversarea coloanelor:");

    return 0;
}
