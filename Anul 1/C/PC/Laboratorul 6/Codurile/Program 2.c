#include <stdio.h>
#include <math.h>

double calcul_pi_div_4() {
    return M_PI / 4;
}

double calcul_serie(int n) {
    double rezultat = 1.0;
    double termen = 1.0;

    for (int i = n; i >= 1; i--) {
        int numar_impar = 2 * i - 1;
        rezultat = 1.0 / (1.0 + (pow(numar_impar, 2) / (2 + rezultat)));
    }

    return rezultat;
}

int main() {
    int n;
    printf("Introduceti valoarea lui n: ");
    scanf("%d", &n);

    double pi_div_4 = calcul_pi_div_4();
    double serie = calcul_serie(n);

    printf("Valoarea expresiei pi/4 este: %lf\n", pi_div_4);
    printf("Valoarea expresiei din seria ceruta este: %lf\n", serie);

    if (fabs(pi_div_4 - serie) < 0.001) {
        printf("Valorile sunt aproximativ egale.\n");
    } else {
        printf("Valorile sunt diferite.\n");
    }

    return 0;
}
