#include <stdio.h>
#include <math.h>

int main() {
    float a, x, y, TZ;
    printf ("a = "); scanf ("%f", &a);
    printf ("x = "); scanf ("%f", &x);
    printf ("y = "); scanf ("%f", &y);

    if (-1 <= x * y && x * y <= 6) {
        TZ = exp(2) * log (a + x + pow(y, 2));
        printf ("S-a efectuat prima conditie: TZ = %f", TZ);
    } else if (x * y < -1) {
        TZ = cbrt(x + y);
        printf ("S-a efectuat a doua conditie: TZ = %f", TZ);
    } else if (x * y > 6) {
        TZ = (pow(cos(x), 2) + pow(a, 2));
        printf ("S-a efectuat a treia conditie: TZ = %f", TZ);
    }

    return 0;
}