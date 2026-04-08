#include <stdio.h>
#include <math.h>

int main() {
    double y, F;
    printf ("Introdu valoarea lui y: ");
    scanf ("%lf", &y);
    F = 2 * sin(0.214 * pow(y, 5) + 1);
    printf ("Rezultatul este: F = %.6lf\n", F);
    return 0;
}
