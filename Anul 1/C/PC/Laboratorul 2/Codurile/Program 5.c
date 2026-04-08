#include <stdio.h>

int main() {
    int a, b, c;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    c = (a * b) / a;
    printf ("c = %d", c);
    return 0;
}