#include <stdio.h>
#include <math.h>

int main() {
    double k, y, U;
    printf ("Introdu valoarea lui k: ");
    scanf ("%lf", &k);
    printf ("Introdu valoarea lui y: ");
    scanf ("%lf", &y);
    U = log(2 * k + 4.3) / (exp(k + y) + sqrt(y));
    printf ("Rezultatul este: U = %.6lf\n", U);

    return 0;
}
