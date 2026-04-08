#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 20

void citire_iter(double *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%lf", (v + i));
    }
}

void generare_iter(double *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        *(v + i) = (rand() % 100) - 50;
}

void afis_iter(double *v, int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", *(v + i));
    printf("\n");
}

double produs_iter(double *v, int n) {
    double p = 1;
    for (int i = 0; i < n; i++)
        p *= *(v + i);
    return p;
}

double sumaPoz_iter(double *v, int n) {
    double s = 0;
    for (int i = 0; i < n; i++)
        if (*(v + i) > 0) s += *(v + i);
    return s;
}

double produsNeg_iter(double *v, int n) {
    double p = 1;
    for (int i = 0; i < n; i++)
        if (*(v + i) < 0) p *= *(v + i);
    return p;
}

int nrNeg_iter(double *v, int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (*(v + i) < 0) c++;
    return c;
}

double medie_iter(double *v, int n) {
    double s = 0;
    for (int i = 0; i < n; i++)
        s += *(v + i);
    return s / n;
}

void citire_rec(double *v, int n, int i) {
    if (i == n) return;
    printf("v[%d] = ", i);
    scanf("%lf", (v + i));
    citire_rec(v, n, i + 1);
}

void generare_rec(double *v, int n, int i) {
    if (i == n) return;
    *(v + i) = (rand() % 100) - 50;
    generare_rec(v, n, i + 1);
}

void afis_rec(double *v, int n, int i) {
    if (i == n) {
        printf("\n");
        return;
    }
    printf("%.2f ", *(v + i));
    afis_rec(v, n, i + 1);
}

double produs_rec(double *v, int n) {
    if (n == 1) return *v;
    return *(v + n - 1) * produs_rec(v, n - 1);
}

double sumaPoz_rec(double *v, int n) {
    if (n == 0) return 0;
    return (*(v + n - 1) > 0 ? *(v + n - 1) : 0) + sumaPoz_rec(v, n - 1);
}

double produsNeg_rec(double *v, int n) {
    if (n == 0) return 1;
    double cur = (*(v + n - 1) < 0 ? *(v + n - 1) : 1);
    return cur * produsNeg_rec(v, n - 1);
}

int nrNeg_rec(double *v, int n) {
    if (n == 0) return 0;
    return ((*(v + n - 1) < 0) ? 1 : 0) + nrNeg_rec(v, n - 1);
}

double medie_rec(double *v, int n) {
    if (n == 1) return *v;
    return (*(v + n - 1) + (n - 1) * medie_rec(v, n - 1)) / n;
}

int main() {
    int n;
    double v[NMAX];

    printf("n = ");
    scanf("%d", &n);

    printf("\n--- Functii iterative ---\n");
    generare_iter(v, n);
    afis_iter(v, n);
    printf("Produs = %.2f\n", produs_iter(v, n));
    printf("Suma pozitive = %.2f\n", sumaPoz_iter(v, n));
    printf("Produs negative = %.2f\n", produsNeg_iter(v, n));
    printf("Nr negative = %d\n", nrNeg_iter(v, n));
    printf("Media = %.2f\n", medie_iter(v, n));

    printf("\n--- Functii recursive ---\n");
    generare_rec(v, n, 0);
    afis_rec(v, n, 0);
    printf("Produs = %.2f\n", produs_rec(v, n));
    printf("Suma pozitive = %.2f\n", sumaPoz_rec(v, n));
    printf("Produs negative = %.2f\n", produsNeg_rec(v, n));
    printf("Nr negative = %d\n", nrNeg_rec(v, n));
    printf("Media = %.2f\n", medie_rec(v, n));

    return 0;
}
