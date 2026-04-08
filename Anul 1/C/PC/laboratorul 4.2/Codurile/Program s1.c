#include <stdio.h>
#include <math.h>

int main() {
    int n, i, valid;
    float zgomot[100];
    float media = 0, medie_anterioara, suma;

    printf("Numar masuratori: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Zgomot[%d] = ", i);
        scanf("%f", &zgomot[i]);
    }

    do {
        medie_anterioara = media;
        suma = 0;
        valid = 0;

        for(i = 0; i < n; i++) {
            if(zgomot[i] >= 20 && zgomot[i] <= 120) {
                suma += zgomot[i];
                valid++;
            }
        }

        if(valid > 0)
            media = suma / valid;
        else
            media = 0;

    } while(fabs(media - medie_anterioara) > 0.01);

    printf("Media stabilizata a zgomotului: %.2f\n", media);
    return 0;
}