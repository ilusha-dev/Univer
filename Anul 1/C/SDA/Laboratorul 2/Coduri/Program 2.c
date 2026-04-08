#include <stdio.h>
#include <stdlib.h>

#define K 50 

void citire(int **a, int n);
void afisare(int **a, int n);

long long produsSubDiag(int **a, int n);
void quickSort(int v[], int st, int dr);
void shellSort(int v[], int n, int desc);

void selectionSort(int v[], int n);
void insertionSort(int v[], int n, int desc);

int main()
{
    int n;
    printf("Introduceti n (n >= 0): ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Dimensiune invalida!\n");
        return 0;
    }

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    citire(a, n);

    printf("\nMatricea initiala:\n");
    afisare(a, n);

    long long prod = produsSubDiag(a, n);
    printf("\nProdus sub diagonala principala = %lld\n", prod);

    if (prod > K)
    {
        printf("Produs > K -> QuickSort crescator pe diagonala principala\n");

        int diag[n];
        for (int i = 0; i < n; i++)
            diag[i] = a[i][i];

        quickSort(diag, 0, n - 1);

        for (int i = 0; i < n; i++)
            a[i][i] = diag[i];
    }
    else
    {
        printf("Produs <= K -> ShellSort descrescator pe diagonala secundara\n");

        int diag[n];
        for (int i = 0; i < n; i++)
            diag[i] = a[i][n - i - 1];

        shellSort(diag, n, 1);

        for (int i = 0; i < n; i++)
            a[i][n - i - 1] = diag[i];
    }

    printf("\nMatricea dupa punctul A:\n");
    afisare(a, n);

    int min = a[0][0];
    int count = 0;
    int lin = 0, col = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] < min)
                min = a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == min)
            {
                count++;
                lin = i;
                col = j;
            }

    printf("\nElement minim = %d, apare de %d ori\n", min, count);

    if (count == 1)
    {
        printf("Minimul apare o singura data -> SelectionSort crescator pe linia %d\n", lin);

        selectionSort(a[lin], n);
    }
    else
    {
        printf("Minimul apare de mai multe ori -> InsertionSort descrescator pe coloanele cu minim\n");

        for (int j = 0; j < n; j++)
        {
            int exista = 0;
            for (int i = 0; i < n; i++)
                if (a[i][j] == min)
                    exista = 1;

            if (exista)
            {
                int colv[n];
                for (int i = 0; i < n; i++)
                    colv[i] = a[i][j];

                insertionSort(colv, n, 1);

                for (int i = 0; i < n; i++)
                    a[i][j] = colv[i];
            }
        }
    }

    printf("\nMatricea dupa punctul B:\n");
    afisare(a, n);

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}


void citire(int **a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
}

void afisare(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d ", a[i][j]);
        printf("\n");
    }
}

long long produsSubDiag(int **a, int n)
{
    long long p = 1;
    int exista = 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            p *= a[i][j];
            exista = 1;
        }

    if (!exista)
        return 0;

    return p;
}

int partition(int v[], int st, int dr)
{
    int pivot = v[dr];
    int i = st - 1;

    for (int j = st; j < dr; j++)
        if (v[j] <= pivot)
        {
            i++;
            int t = v[i]; v[i] = v[j]; v[j] = t;
        }

    int t = v[i + 1]; v[i + 1] = v[dr]; v[dr] = t;
    return i + 1;
}

void quickSort(int v[], int st, int dr)
{
    if (st < dr)
    {
        int pi = partition(v, st, dr);
        quickSort(v, st, pi - 1);
        quickSort(v, pi + 1, dr);
    }
}

void shellSort(int v[], int n, int desc)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
        {
            int temp = v[i];
            int j;
            for (j = i; j >= gap &&
                 (desc ? v[j - gap] < temp : v[j - gap] > temp);
                 j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
}

void selectionSort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;

        int t = v[i]; v[i] = v[min]; v[min] = t;
    }
}

/* ========== INSERTION SORT ========== */
void insertionSort(int v[], int n, int desc)
{
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 &&
               (desc ? v[j] < key : v[j] > key))
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}