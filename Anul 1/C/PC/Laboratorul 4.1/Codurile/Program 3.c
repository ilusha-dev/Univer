#include <stdio.h>  

int main() {
    int n, i, y, A[30], pozitie = -1;

    printf("Introduce-ti numarul de elemente n (n <= 30): ");
    scanf("%d", &n);

    printf("Introduce-ti elementele vectorului:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Introduce-ti valoarea lui y: ");
    scanf("%d", &y);

    for(i = 0; i < n; i++) {
        if(A[i] == y) {
            pozitie = i;
        }
    }

    if(pozitie == -1)
        printf("Nu exista niciun element egal cu %d in vector.\n", y);
    else
        printf("Ultimul element egal cu %d se afla pe pozitia %d.\n", y, pozitie + 1); 

    return 0;
}
