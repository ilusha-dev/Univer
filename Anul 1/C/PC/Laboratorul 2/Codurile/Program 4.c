#include <stdio.h>
#include <math.h>
int main () {
    int a, b, x, K;
    printf ("a = "); scanf ("%d", &a);
    printf ("b = "); scanf ("%d", &b);
    printf ("x = "); scanf ("%d", &x);
    if (1 <= x && x <= 3) {
        K= (M_PI* (fabs(a+x)));
    printf ("Rezultatul este: K = %d", K); }
    else if (x>3) {
        K= ((pow(x,2)*a)/4);
    printf ("Rezultatul este: K = %d", K); }
    else if (x<1) {
        K= (b*(pow(x,2))-a)/((exp(a*x))-1); 
    printf ("Rezultatul este: K = %d", K); }
    return 0;
}