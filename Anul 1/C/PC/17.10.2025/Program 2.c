#include <stdio.h>

int main() {
    int a, b, i = a, counter = 0;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    while (i <= b) {
        if (i % 2 == 0) {
            counter++;
        }
        i++;
    }
    printf ("Numerele pare din intervalul [a, b]: %d", counter);
return 0;
}