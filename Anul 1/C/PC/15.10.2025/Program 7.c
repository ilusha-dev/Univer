#include <stdio.h> 

int main() {
    int suma, i;
    for (suma = 0, i = 0; i <= 3; suma += ++i);
    if (i == 2) break;
    printf ("suma = %d", suma);
    
    return 0;
}