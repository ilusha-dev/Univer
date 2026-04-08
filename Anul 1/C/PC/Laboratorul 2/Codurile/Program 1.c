#include <stdio.h>

int main() {
    int a, b, c, Produs, Minim;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    printf ("c = "); scanf ("%d", &c);
    
    if (a!= 0 && b != 0 && c != 0) {
        Produs = a * b * c;
        printf ("Produsul numerelor este: %d", Produs);
    } else {
        Minim = a;
        if (b < Minim) Minim = b;
        if (c < Minim) Minim = c;
        printf ("Cel mai mic numar este: %d", Minim);
    }

    return 0;
}