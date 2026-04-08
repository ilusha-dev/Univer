#include <stdio.h>

int main() {
    int i=1, n, divizor = 0;
    printf ("n = "); scanf("%d", &n);
    while (i<=n) {
        if(n % i == 0)
            divizor++; 
        i++;
    }
    printf ("Divizorii: %d", divizor);
return 0;
}