#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    if (a > b) {
        a = a + b;
        b = pow(b,2);
    } else {
        b = a + b;
        a = pow(a,2);
    }
    printf ("a = %d; b = %d", a, b);
    return 0;
}