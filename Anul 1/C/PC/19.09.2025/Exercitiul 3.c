 #include <stdio.h>
 #include <math.h>

int main()
{
    int n;
    
    printf("0<=n<=50: ");
    scanf("%d", &n);
    
    switch(n){
        case 0 ... 9:
            printf("%f\n", pow(n, 2));
            break;
        case 10 ... 20:
            printf("%d\n", n + 100);
            break;
        case 21 ... 30:
            printf("%f\n", sqrt(n));
            break;
        case 31 ... 40:
            printf("%f\n", cbrt(n));
            break;
        case 41 ... 50:
            printf("%f\n", n / 3.0);
            break;
        default:
            printf("Valoarea gresita\n");
            break;
    }

    return 0; 
}