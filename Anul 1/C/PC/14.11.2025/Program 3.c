#include <stdio.h>

int main() {
    int A, B, count = 1;
    printf("Introduceti valoarea lui A: ");
    scanf("%d", &A);
    printf("Introduceti valoarea lui B: ");
    scanf("%d", &B);

    for (int i = A; i <= B; i++) {
        for (int j = 1; j <= count; j++) {
            printf("%d ", i);
        }
        count++;
        printf("\n");
    }

    return 0;
}