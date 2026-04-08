#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char denumirea[100];
    char adresa[150];
    char telefon[20];
    int  nr_exponate;
    float pret_bilet;
} Muzeu;

Muzeu* aloca_memorie(int n) {
    Muzeu *tab = (Muzeu*)malloc(n * sizeof(Muzeu));
    if (tab == NULL) {
        printf("Eroare: Nu s-a putut aloca memoria!\n");
        exit(1);
    }
    printf("Memoria pentru %d muzee a fost alocata cu succes.\n", n);
    return tab;
}

void citire(Muzeu *tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Muzeul %d ---\n", i + 1);

        printf("Denumirea: ");
        fflush(stdin);
        fgets(tab[i].denumirea, sizeof(tab[i].denumirea), stdin);
        tab[i].denumirea[strcspn(tab[i].denumirea, "\n")] = '\0';

        printf("Adresa: ");
        fgets(tab[i].adresa, sizeof(tab[i].adresa), stdin);
        tab[i].adresa[strcspn(tab[i].adresa, "\n")] = '\0';

        printf("Telefonul: ");
        fgets(tab[i].telefon, sizeof(tab[i].telefon), stdin);
        tab[i].telefon[strcspn(tab[i].telefon, "\n")] = '\0';

        printf("Numarul de exponate: ");
        scanf("%d", &tab[i].nr_exponate);

        printf("Pretul biletului (lei): ");
        scanf("%f", &tab[i].pret_bilet);
        getchar();
    }
}

void afisare(Muzeu *tab, int n) {
    if (tab == NULL) {
        printf("Tabloul nu este alocat!\n");
        return;
    }
    printf("\n%-5s %-25s %-30s %-15s %-12s %-10s\n",
           "Nr.", "Denumirea", "Adresa", "Telefon", "Exponate", "Pret(lei)");
    printf("%-5s %-25s %-30s %-15s %-12s %-10s\n",
           "---", "-------------------------", "------------------------------",
           "---------------", "------------", "----------");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-25s %-30s %-15s %-12d %-10.2f\n",
               i + 1,
               tab[i].denumirea,
               tab[i].adresa,
               tab[i].telefon,
               tab[i].nr_exponate,
               tab[i].pret_bilet);
    }
    printf("\n");
}

void swap_muzeu(Muzeu *a, Muzeu *b) {
    Muzeu tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortare_selectie(Muzeu *tab, int n, int camp, int crescator) {

    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            int cmp = 0;
            if (camp == 1)
                cmp = strcmp(tab[j].denumirea, tab[idx].denumirea);
            else if (camp == 2)
                cmp = tab[j].nr_exponate - tab[idx].nr_exponate;
            else if (camp == 3)
                cmp = (tab[j].pret_bilet > tab[idx].pret_bilet) ? 1
                    : (tab[j].pret_bilet < tab[idx].pret_bilet) ? -1 : 0;

            if (crescator ? (cmp < 0) : (cmp > 0))
                idx = j;
        }
        if (idx != i)
            swap_muzeu(&tab[i], &tab[idx]);
    }
    printf("Sortare prin selectie finalizata.\n");
}

void sortare_insertie(Muzeu *tab, int n, int camp, int crescator) {
    for (int i = 1; i < n; i++) {
        Muzeu cheie = tab[i];
        int j = i - 1;
        while (j >= 0) {
            int cmp = 0;
            if (camp == 1)
                cmp = strcmp(tab[j].denumirea, cheie.denumirea);
            else if (camp == 2)
                cmp = tab[j].nr_exponate - cheie.nr_exponate;
            else if (camp == 3)
                cmp = (tab[j].pret_bilet > cheie.pret_bilet) ? 1
                    : (tab[j].pret_bilet < cheie.pret_bilet) ? -1 : 0;

            if (crescator ? (cmp > 0) : (cmp < 0)) {
                tab[j + 1] = tab[j];
                j--;
            } else {
                break;
            }
        }
        tab[j + 1] = cheie;
    }
    printf("Sortare prin insertie finalizata.\n");
}

void meniu_sortare(Muzeu *tab, int n) {
    if (tab == NULL) { printf("Tabloul nu este alocat!\n"); return; }

    int tehnica, camp, ordine;

    printf("\nAlegeti tehnica de sortare:\n");
    printf("  1. Sortare prin Selectie\n");
    printf("  2. Sortare prin Insertie\n");
    printf("Optiunea dvs.: ");
    scanf("%d", &tehnica);
    if (tehnica < 1 || tehnica > 2) { printf("Optiune invalida!\n"); return; }

    printf("\nSortati dupa:\n");
    printf("  1. Denumirea (alfabetic)\n");
    printf("  2. Numarul de exponate\n");
    printf("  3. Pretul biletului\n");
    printf("Campul: ");
    scanf("%d", &camp);
    if (camp < 1 || camp > 3) { printf("Camp invalid!\n"); return; }

    printf("\nOrdinea:\n");
    printf("  1. Crescator\n");
    printf("  2. Descrescator\n");
    printf("Optiunea: ");
    scanf("%d", &ordine);
    if (ordine < 1 || ordine > 2) { printf("Optiune invalida!\n"); return; }

    int crescator = (ordine == 1) ? 1 : 0;

    if (tehnica == 1)
        sortare_selectie(tab, n, camp, crescator);
    else
        sortare_insertie(tab, n, camp, crescator);
}

void elibereaza_memorie(Muzeu **tab) {
    if (*tab != NULL) {
        free(*tab);
        *tab = NULL;
        printf("Memoria a fost eliberata cu succes.\n");
    } else {
        printf("Memoria nu este alocata.\n");
    }
}

void meniu(Muzeu **tab, int *n) {
    int optiune;

    printf("\n========================================\n");
    printf("       GESTIUNEA MUZEELOR - MENIU\n");
    printf("========================================\n");
    printf("  1. Alocarea dinamica a memoriei\n");
    printf("  2. Introducerea elementelor de la tastatura\n");
    printf("  3. Afisarea elementelor la ecran\n");
    printf("  4. Sortarea tabloului (crescator/descrescator)\n");
    printf("  5. Eliberarea memoriei alocate\n");
    printf("  0. Iesire din program\n");
    printf("----------------------------------------\n");
    printf("Optiunea dvs.: ");
    scanf("%d", &optiune);
    getchar();

    switch (optiune) {
        case 1:
            if (*tab != NULL) {
                printf("Memoria este deja alocata! Eliberati-o mai intai (opt. 5).\n");
            } else {
                printf("Introduceti numarul de muzee: ");
                scanf("%d", n);
                getchar();
                if (*n <= 0) { printf("Numar invalid!\n"); break; }
                *tab = aloca_memorie(*n);
            }
            break;

        case 2:
            if (*tab == NULL) {
                printf("Mai intai alocati memoria (opt. 1)!\n");
            } else {
                citire(*tab, *n);
            }
            break;

        case 3:
            afisare(*tab, *n);
            break;

        case 4:
            meniu_sortare(*tab, *n);
            break;

        case 5:
            elibereaza_memorie(tab);
            *n = 0;
            break;

        case 0:
            printf("La revedere!\n");
            if (*tab != NULL) {
                free(*tab);
                printf("(Memoria a fost eliberata automat.)\n");
            }
            return;

        default:
            printf("Optiune invalida! Incercati din nou.\n");
    }

    meniu(tab, n);
}

int main(void) {
    Muzeu *tab = NULL;
    int n = 0;

    meniu(&tab, &n);

    return 0;
}