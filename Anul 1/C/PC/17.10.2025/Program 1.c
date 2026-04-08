#include <stdio.h>

int main() {
    int a, b, counter = 0;
    printf ("a ="); scanf ("%d", &a);
    printf ("b ="); scanf ("%d", &b);
    
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            counter++;
        }
    }
    printf ("Numerele pare din intervalul [a, b]: %d", counter);
return 0;
}