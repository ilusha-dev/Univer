#include <stdio.h>

int main() {
    int var = 5, *ptr;
    printf("var: %i \n", var);
    ptr = &var;
    printf("Valoarea pointerului ptr: %i", *ptr);
    return 0;
}