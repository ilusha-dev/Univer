#include <stdio.h>
#include <math.h>

int main() {
    float a, x, y, L;
    printf ("a = "); scanf ("%f", &a);
    printf ("x = "); scanf ("%f", &x);
    printf ("y = "); scanf ("%f", &y);

    if (x < 1.5) {
        L = fabs(pow(x, y/x) - cbrt(y / x));
        printf ("X corespunde dupa prima conditie: L = %f", L);
    } else if (x == 1.5) {
        L = (pow(cos(pow(x, 3)), 2) - pow(M_E, x/a));
        printf ("X corespunde dupa a doua conditie: L = %f", L);
    } else if (x > 1.5) {
        L = M_PI * exp(-a*x) * sqrt(pow(a, 2) + 1.5);
        printf ("X corespunde dupa a treia conditie: L = %f", L);
    }
    return 0;
}