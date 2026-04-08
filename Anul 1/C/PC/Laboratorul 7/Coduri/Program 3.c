#include <stdio.h>
#include <math.h>

double suma_iterativ(int n) {
    double suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += sqrt(i);
    }
    return suma;
}

double suma_recursiv(int n) {
    if (n == 1)
        return 1;
    else
        return sqrt(n) + suma_recursiv(n - 1);
}

int main() {
    int n;

    printf("Introduceti n: ");
    scanf("%d", &n);

    printf("Suma calculata iterativ: %.4lf\n", suma_iterativ(n));
    printf("Suma calculata recursiv: %.4lf\n", suma_recursiv(n));

    return 0;
}
