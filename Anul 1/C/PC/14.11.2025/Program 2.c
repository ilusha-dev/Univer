[#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, count;
    printf("Introduce-ti valoarea lui n: ");
    scanf("%d\n", &n);
    printf("Introduce-ti valoarea lui m: ");
    scanf("%d\n", &m);

    int A[n][m], arrDiv5[m], arrPozImp[n*m], media;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            A[i][j] = rand()%101 - 50;
            printf("%i \t", A[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < m; j++) {
        count = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] % 5 == 0)
                count++;
        }
        arrDiv5[j] = count;
    }
    
}