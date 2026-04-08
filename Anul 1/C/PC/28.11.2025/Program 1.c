#include <stdio.h> 

int suma(int a, int b) {
    int s = a + b;
    return s;
}

int main() {
    int x = 7, y = 2;
    int sum = suma(x, y);
}

// 

#include <stdio.h>

void suma(int a, int b) {
    int s = a + b;
    printf("Suma: %d ", s);
    return; // optional, jelatelino sa nu il scrim, nu va fi nimic considerabil !
}

int main() {
    int x = 5, y = 7;
    summa(x, y);
}


