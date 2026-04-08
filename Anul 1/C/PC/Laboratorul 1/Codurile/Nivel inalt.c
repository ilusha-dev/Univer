#include <stdio.h>
#include <math.h>

int main() {
    double a, b, x, z, f;
    printf ("Introdu valoarea pentru a: ");
    scanf ("%lf", &a);
    printf ("Introdu valoarea pentru b: ");
    scanf ("%lf", &b);
    printf ("Introdu valoarea pentru x: ");
    scanf ("%lf", &x);
    printf ("Introdu valoarea pentru z: ");
    scanf ("%lf", &z);1
    f = (pow(cos(b * pow(x, 3)), 7) - (sin(pow(a, 2)) + cos(pow(x, 3) + pow(z, 3) - pow(a, 2)))) /
        (asin(pow(a, 2)) + acos(pow(x, 7) - pow(a, 2)));
    printf("Rezultatul este: %lf", f);

    return 0;
}
