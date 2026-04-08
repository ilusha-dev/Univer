#include <stdio.h>
#include <math.h> 

int main() {
    double x, y;
    printf ("x = "); scanf ("%lf", &x);
    if (x < 10) {
        y = pow ((x + 3), 3) / 5 * x;
    } else if (x >= 10 && x < 20) {
        y = cbrt(pow(x, 2) + x - 15);  
    } else {
        y = (exp(x + 1) + 3 * x);
    }

    printf ("y = %lf", y); 
    return 0;
}