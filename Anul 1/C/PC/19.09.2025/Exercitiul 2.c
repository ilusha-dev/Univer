#include <stdio.h> 

int main() {
    int nr;
    printf(" Introduce-ti nuamrul de perechi: de la 1 la 4 "); 
    scanf ("%d", &nr);
    switch (nr) {
        case 1: printf("Perechea 1: sem. PC"); 
            break;
        case 2: printf("Perechea 2: sem. ICPP");
            break;
        case 3: printf("Perechea 3: sem. ESU");
            break;
        case 4: printf("Perechea 4: sem. TPA");
            break;
        default: printf("Eroare");
            break;
    }
    
   return 0;
}