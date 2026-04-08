#include <stdio.h>

int main() {
    int n, i;
    float e[100], suma, medie;
    int cicluri = 0;
    int continua = 1;

    printf("Numar roboti: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Energia robotului %d: ", i);
        scanf("%f", &e[i]);
    }

    while(continua) {
        cicluri++;
        suma = 0;

        for(i = 0; i < n; i++)
            suma += e[i];

        medie = suma / n;

        for(i = 0; i < n; i++)
            e[i] -= 0.1 * medie;

        continua = 0;
        for(i = 0; i < n; i++) {
            if(e[i] >= 5)
                continua = 1;
        }
    }

    printf("Numar cicluri pana la oprire: %d\n", cicluri);
    return 0;
}