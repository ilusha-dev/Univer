#include <stdio.h>

int suma(int n, int m, int arr[][50]) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            s += arr[i][j];
        }
    }
    return 0;
}

int main() {
    int tab[50][50], n = 10, m = 7;
    int sum = suma(n, m, tab);
    citire(m, n, tab);
}

// 

#include <stdio.h>

void citire(int n, int m, int arr[][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

int main() {
    
}