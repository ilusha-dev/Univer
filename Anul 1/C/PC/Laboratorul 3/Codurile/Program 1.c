#include <stdio.h>

int main() {
    int a, b;
    int suma = 0;
    printf("a = "); scanf ("%d", &a);
    printf("b = "); scanf ("%d", &b);
    printf("Numerele pare din intervalul [%d, %d] sunt:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma numerelor pare este: %d\n", suma);
    return 0;
}
