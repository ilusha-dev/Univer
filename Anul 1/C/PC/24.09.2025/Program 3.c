#include <stdio.h>

int main () {
    int a, b, c;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    printf ("c = "); scanf ("%d", &c);

    if (a > b && a > c) {
        printf ("Cel mai mare numar este: %d", a);
    } else if (b > a && b > c) {
        printf ("Cel mai mare nuamr este: %d", b);
    } else {
        printf ("Cel mai mare numar este: %d", c);
    }
    return 0;
}