#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void citire(int n, int m, int arr[][30]);
void afisare(int m, int n, int arr[][30]);



int main() {
    int n, m, tab[20][30];
    printf("Introdu valoare lui n: ");
    scanf("%d", &n);
    printf("Introdu valoare lui m: ");
    scanf("%d", &m);
    
    citire(n. m, tab);
    afisare(n, m, tab);










    
}

void citire(int n, int m, int arr[][30]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

}

void afisare(int m, int n, int arr[][30]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("    %d", arr[i][j]);
        }
        printf("\n");
    }
}