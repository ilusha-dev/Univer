#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void meniu();
void introducere_valori(int *arr, int n);
void random_valori(int *arr, int n);
void afisare(int *arr, int n);

int estePrim(int x);
int existaZero(int *arr, int n);
int existaPrim(int *arr, int n);
long long produsImpare(int *arr, int n);

/* SORTARI */
void bubbleSort(int *arr, int n);
void countingSort(int *arr, int n, int crescator);
void heapSort(int *arr, int n, int descrescator);
void radixSort(int *arr, int n);
void combSort(int *arr, int n, int descrescator);
void mergeSort(int *arr, int st, int dr);
void merge(int *arr, int st, int mid, int dr);

int *arr = NULL;
int n;

/* ======================= MAIN ======================= */
int main()
{
    printf("Introduceti n (numar PAR): ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Eroare! n trebuie sa fie par!\n");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
        printf("Eroare alocare memorie!\n");
        return 0;
    }

    meniu();
    return 0;
}

/* ======================= MENIU RECURSIV ======================= */
void meniu()
{
    int opt;
    printf("\n===== MENIU =====\n");
    printf("1. Introducere valori\n");
    printf("2. Completare random\n");
    printf("3. Afisare\n");
    printf("4. Manipulare si sortare\n");
    printf("5. Iesire\n");
    printf("Optiunea: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        introducere_valori(arr, n);
        afisare(arr, n);
        meniu();
        break;

    case 2:
        random_valori(arr, n);
        afisare(arr, n);
        meniu();
        break;

    case 3:
        afisare(arr, n);
        meniu();
        break;

    case 4:
    {
        printf("\nArray original:\n");
        afisare(arr, n);

        /* A */
        if (existaZero(arr, n))
        {
            printf("\nExista cel putin un element 0 -> HeapSort descrescator\n");
            heapSort(arr, n, 1);
        }
        else
        {
            printf("\nNu exista element 0 -> CountingSort crescator\n");
            countingSort(arr, n, 1);
        }

        afisare(arr, n);

        /* B */
        if (produsImpare(arr, n) > 0)
        {
            printf("\nProdus impare pozitiv -> RadixSort crescator\n");
            radixSort(arr, n);
        }
        else
        {
            printf("\nProdus impare negativ/zero -> CombSort descrescator\n");
            combSort(arr, n, 1);
        }

        afisare(arr, n);

        /* C */
        if (existaPrim(arr, n))
        {
            printf("\nExista numar prim -> MergeSort descrescator\n");
            mergeSort(arr, 0, n - 1);
            // inversare pentru descrescator
            for(int i=0;i<n/2;i++){
                int temp=arr[i];
                arr[i]=arr[n-1-i];
                arr[n-1-i]=temp;
            }
        }
        else
        {
            printf("\nNu exista numere prime -> BubbleSort crescator\n");
            bubbleSort(arr, n);
        }

        afisare(arr, n);

        meniu();
        break;
    }

    case 5:
        free(arr);
        printf("Memorie eliberata. Program terminat.\n");
        exit(0);

    default:
        printf("Optiune invalida!\n");
        meniu();
    }
}

/* ======================= FUNCTII ======================= */

void introducere_valori(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
}

void random_valori(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 21 - 10;
}

void afisare(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int existaZero(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            return 1;
    return 0;
}

int estePrim(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int existaPrim(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (estePrim(arr[i]))
            return 1;
    return 0;
}

long long produsImpare(int *arr, int n)
{
    long long p = 1;
    int exista = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 != 0)
        {
            p *= arr[i];
            exista = 1;
        }
    if (!exista)
        return 0;
    return p;
}

/* ================= SORTARI ================= */

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void countingSort(int *arr, int n, int crescator)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    int k = 0;

    if (crescator)
        for (int i = 0; i < range; i++)
            while (count[i]--)
                arr[k++] = i + min;
    else
        for (int i = range - 1; i >= 0; i--)
            while (count[i]--)
                arr[k++] = i + min;

    free(count);
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n, int desc)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }

    if (desc)
        for(int i=0;i<n/2;i++){
            int t=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=t;
        }
}

void combSort(int *arr, int n, int desc)
{
    int gap = n;
    int swapped = 1;

    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = 0;

        for (int i = 0; i + gap < n; i++)
        {
            if ((desc && arr[i] < arr[i + gap]) ||
                (!desc && arr[i] > arr[i + gap]))
            {
                int t = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = t;
                swapped = 1;
            }
        }
    }
}

void merge(int *arr, int st, int mid, int dr)
{
    int i = st, j = mid + 1, k = 0;
    int temp[1000];

    while (i <= mid && j <= dr)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= dr)
        temp[k++] = arr[j++];

    for (i = st, k = 0; i <= dr; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int *arr, int st, int dr)
{
    if (st < dr)
    {
        int mid = (st + dr) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, dr);
        merge(arr, st, mid, dr);
    }
}

void radixSort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int output[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}