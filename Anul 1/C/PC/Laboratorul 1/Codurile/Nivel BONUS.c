#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, x, y, ZZ;  
    printf ("a = "); scanf ("%lf", &a);
    printf ("b = "); scanf ("%lf", &b);
    printf ("c = "); scanf ("%lf", &c);
    printf ("x = "); scanf ("%lf", &x);
    printf ("y = "); scanf ("%lf", &y);

    ZZ = ((exp(M_PI + pow(x, 2 + a) + pow(y, 3) + pow(c, 2)) + sqrt(pow(x, 2+a) + pow(y, 2 + b - (pow(a, 2)-b) / pow(c, 2 + cos(pow(a, 2)))))) / sqrt((pow(x, -2 * a + cos(pow(x, 2))) + pow(b, 2 - pow(x, 2 + b))) / (pow(x, 2) + 2 * pow(y, 2)))) / (((x - y + pow(c, 2)) / sqrt((x + pow(y, a + cos(x - pow(y, 2)) + 2) + tan(x)) / (2 - pow(x, 2 + pow(cos(x), 2)) * pow(y, 3)))) + (a + b) / (-pow(x, 2) + pow(b, y)));
    printf ("%lf", ZZ);
    return 0;
}
