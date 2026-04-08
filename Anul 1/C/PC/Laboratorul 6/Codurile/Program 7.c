#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int are_cifre_distincte(int num) {
    int cifre[10] = {0}; 

    while (num > 0) {
        int cifra = num % 10;
        if (cifre[cifra] != 0) {
            return 0;
        }
        cifre[cifra] = 1;
        num /= 10;
    }

    return 1;
}

int numara_elemente_cu_cifre_distincte(int vector[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (are_cifre_distincte(vector[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Introduceti numarul de elemente din tablou: ");
    scanf("%d", &n);

    int vector[n];
    srand(time(0));
    printf("Elementele vectorului: ");
    
    for (int i = 0; i < n; i++) {
        vector[i] = rand() % 900 + 100;
        printf("%d ", vector[i]);
    }

    int count_distincte = numara_elemente_cu_cifre_distincte(vector, n);

    printf("\nNumărul elementelor cu cifre distincte este: %d\n", count_distincte);

    printf("Elementele cu cifre distincte: ");
    for (int i = 0; i < n; i++) {
        if (are_cifre_distincte(vector[i])) {
            printf("%d ", vector[i]);
        }
    }
    printf("\n");

    return 0;
}
