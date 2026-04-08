#include <stdio.h>
#include <math.h>

double calcul_pi_div_4() {
    return M_PI / 4;
}

double calcul_serie_leibniz(int n) {
    double suma = 0.0;
    for (int i = 0; i <= n; i++) {
        suma += (pow(-1, i)) / (2 * i + 1);
    }
    return suma;
}

int main() {
    int n;
    printf("Introduceti valoarea lui n: ");
    scanf("%d", &n);

    double pi_div_4 = calcul_pi_div_4();
    double serie_leibniz = calcul_serie_leibniz(n);

    printf("Valoarea expresiei pi/4 este: %lf\n", pi_div_4);
    printf("Valoarea expresiei din seria Leibniz este: %lf\n", serie_leibniz);

    if (fabs(pi_div_4 - serie_leibniz) < 0.001) {
        printf("Valorile sunt aproximativ egale.\n");
    } else {
        printf("Valorile sunt diferite.\n");
    }

    return 0;
}
