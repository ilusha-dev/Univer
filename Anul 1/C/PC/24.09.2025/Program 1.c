#include <stdio.h>
#include <math.h>

int main() {
    float a, b, m, x, K;
    printf ("a = "); scanf ("%f", &a);
    printf ("b = "); scanf ("%f", &b);
    printf ("m = "); scanf ("%f", &m);
    printf ("x = "); scanf ("%f", &x);
    K = exp(pow((m + x), 3)) - (sqrt(pow(sin(pow (a, 3)), 3))) / (sqrt(cos(pow(b, 3))));
    printf ("K = %f", K); 
    return 0;
}