#include <stdio.h>

int suma(int n, int arr[]) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += arr[i];
    }
return s;
}

int main() {
    int tab[50], n = 10;
    int sum = suma(n, tab); // "tab" - se transmite adesa catre primul elemenet(arr[0])
}

//

#include <stdio.h>

void citire(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    
}