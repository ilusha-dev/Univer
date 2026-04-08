#include <stdio.h>
#include <math.h>

int main() {
    int a;
    printf ("a = "); scanf("%d", &a);
    if (a % 2 == 0) {
        printf ("Numarul este par!");
    } else {
        printf ("Numarul este impar!");
    }
    return 0;
}