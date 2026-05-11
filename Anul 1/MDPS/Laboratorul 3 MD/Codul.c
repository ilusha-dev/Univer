#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000

typedef struct Arc { int dest, pond; struct Arc *next; } Arc;
typedef struct Nod { int id; Arc *arce; struct Nod *next; } Nod;
typedef struct     { Nod *cap; int n; } Graf;

/* ================================================================== */
/*  OPERATII PE GRAF                                                    */
/* ================================================================== */

Graf *creeazaGraf(void)
{
    Graf *g = (Graf *)malloc(sizeof(Graf));
    if (!g) { perror("malloc Graf"); exit(1); }
    g->cap = NULL; g->n = 0;
    return g;
}

Nod *cautaNod(Graf *g, int id)
{
    Nod *p = g->cap;
    while (p && p->id != id) p = p->next;
    return p;
}

Nod *adaugaNod(Graf *g, int id)
{
    Nod *p = cautaNod(g, id);
    if (p) return p;

    p = (Nod *)malloc(sizeof(Nod));
    if (!p) { perror("malloc Nod"); exit(1); }
    p->id = id; p->arce = NULL; p->next = NULL;

    if (!g->cap || g->cap->id > id) { p->next = g->cap; g->cap = p; }
    else {
        Nod *cur = g->cap;
        while (cur->next && cur->next->id < id) cur = cur->next;
        p->next = cur->next; cur->next = p;
    }
    g->n++;
    return p;
}

void adaugaArc(Graf *g, int s, int d, int pond)
{
    Nod *ns = adaugaNod(g, s); adaugaNod(g, d);
    for (Arc *a = ns->arce; a; a = a->next)
        if (a->dest == d) { a->pond = pond; return; }

    Arc *nou = (Arc *)malloc(sizeof(Arc));
    if (!nou) { perror("malloc Arc"); exit(1); }
    nou->dest = d; nou->pond = pond;
    nou->next = ns->arce; ns->arce = nou;
}

int stergeArc(Graf *g, int s, int d)
{
    Nod *ns = cautaNod(g, s); if (!ns) return 0;
    for (Arc **pp = &ns->arce; *pp; pp = &(*pp)->next)
        if ((*pp)->dest == d) { Arc *t = *pp; *pp = t->next; free(t); return 1; }
    return 0;
}

void distrugeGraf(Graf **pg)
{
    if (!pg || !*pg) return;
    Nod *nod = (*pg)->cap;
    while (nod) {
        Arc *a = nod->arce;
        while (a) { Arc *t = a->next; free(a); a = t; }
        Nod *t = nod->next; free(nod); nod = t;
    }
    free(*pg); *pg = NULL;
}

/* ================================================================== */
/*  AFISARE LISTA DE ADIACENTA                                          */
/* ================================================================== */

void afiseazaGraf(Graf *g)
{
    printf("\n  Lista de adiacenta (%d noduri):\n", g->n);
    for (Nod *p = g->cap; p; p = p->next) {
        printf("  Nod %2d ->", p->id);
        if (!p->arce) { printf(" (fara arce)\n"); continue; }
        for (Arc *a = p->arce; a; a = a->next)
            printf(" [->%d, pond=%d]", a->dest, a->pond);
        printf("\n");
    }
}

/* ================================================================== */
/*  AFISARE MATRICE PONDERATA DE ADIACENTA                              */
/* ================================================================== */

void afiseazaMatrice(Graf *g)
{
    int n = g->n;
    int M[101][101];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            M[i][j] = (i == j) ? 0 : INF;

    for (Nod *p = g->cap; p; p = p->next)
        for (Arc *a = p->arce; a; a = a->next)
            M[p->id][a->dest] = a->pond;

    printf("\n  Matricea ponderata de adiacenta:\n");
    printf("      ");
    for (int j = 1; j <= n; j++) printf("%6d", j);
    printf("\n      ");
    for (int j = 1; j <= n; j++) printf("------");
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("  %2d |", i);
        for (int j = 1; j <= n; j++)
            printf(M[i][j] == INF ? "   INF" : "%6d", M[i][j]);
        printf("\n");
    }
}

/* ================================================================== */
/*  INTRODUCERE GRAF                                                    */
/* ================================================================== */

Graf *introduceGraf(void)
{
    char buf[64]; int n, i, j, pond;
    Graf *g = creeazaGraf();

    do {
        printf("Numar de noduri (2..100): ");
        if (!fgets(buf, sizeof(buf), stdin)) continue;
        n = atoi(buf);
    } while (n < 2 || n > 100);

    for (i = 1; i <= n; i++) adaugaNod(g, i);

    printf("\nIntroduceti arcele.  Format: <sursa> <dest> <pondere>\n");
    printf("(0 0 0 pentru a termina)\n\n");

    while (1) {
        printf("Arc: ");
        if (!fgets(buf, sizeof(buf), stdin)) continue;
        if (sscanf(buf, "%d %d %d", &i, &j, &pond) != 3)
            { printf("  [EROARE] Format gresit.\n"); continue; }
        if (i == 0 && j == 0) break;
        if (i < 1 || i > n || j < 1 || j > n)
            { printf("  [EROARE] Noduri invalide (1..%d).\n", n); continue; }
        if (i == j)
            { printf("  [EROARE] Buclele nu sunt permise.\n"); continue; }
        if (pond <= 0 || pond >= INF)
            { printf("  [EROARE] Ponderea trebuie 1..%d.\n", INF-1); continue; }

        Nod *ns = cautaNod(g, i);
        Arc *ex = ns->arce; int gasit = 0;
        while (ex) { if (ex->dest == j) { gasit = 1; break; } ex = ex->next; }
        if (gasit) {
            printf("  Arcul (%d->%d) exista (pond=%d). Suprascrie? (d/n): ", i, j, ex->pond);
            fgets(buf, sizeof(buf), stdin);
            if (buf[0] != 'd' && buf[0] != 'D') continue;
        }

        adaugaArc(g, i, j, pond);
        printf("  Arc %d -> %d (pond=%d) adaugat.\n", i, j, pond);
    }

    afiseazaGraf(g);
    return g;
}

/* ================================================================== */
/*  BELLMAN-CALABA  (drum minim)                                        */
/* ================================================================== */

int bellmanCalaba(Graf *g, int dest, int **pV, int **pPred)
{
    int  n = g->n;
    int *V    = (int *)malloc((n+1) * sizeof(int));
    int *pred = (int *)malloc((n+1) * sizeof(int));
    int *Vold = (int *)malloc((n+1) * sizeof(int));
    if (!V || !pred || !Vold) { perror("malloc"); exit(1); }

    /* initializare V0 */
    for (int i = 1; i <= n; i++) { V[i] = INF; pred[i] = -1; }
    V[dest] = 0; pred[dest] = dest;

    for (Nod *p = g->cap; p; p = p->next)
        if (p->id != dest)
            for (Arc *a = p->arce; a; a = a->next)
                if (a->dest == dest) { V[p->id] = a->pond; pred[p->id] = dest; }

    printf("\n  V0 = [ ");
    for (int i = 1; i <= n; i++)
        if (V[i] == INF) printf("%5s ", "INF"); else printf("%5d ", V[i]);
    printf("]\n");

    int schimbare;
    for (int it = 1; it <= n-1; it++) {
        memcpy(Vold, V, (n+1)*sizeof(int));
        schimbare = 0;

        for (Nod *nod = g->cap; nod; nod = nod->next) {
            int i = nod->id; if (i == dest) continue;
            for (Arc *arc = nod->arce; arc; arc = arc->next) {
                int j = arc->dest;
                if (Vold[j] == INF) continue;
                int val = arc->pond + Vold[j];
                if (val < V[i]) { V[i] = val; pred[i] = j; schimbare = 1; }
            }
        }

        printf("  V%d = [ ", it);
        for (int i = 1; i <= n; i++)
            if (V[i] == INF) printf("%5s ", "INF"); else printf("%5d ", V[i]);
        printf("]\n");

        if (!schimbare) { printf("  Convergenta la iteratia %d. STOP.\n", it); break; }
    }

    /* verificare ciclu negativ */
    if (schimbare) {
        memcpy(Vold, V, (n+1)*sizeof(int));
        for (Nod *nod = g->cap; nod; nod = nod->next)
            for (Arc *arc = nod->arce; arc; arc = arc->next) {
                int j = arc->dest; if (Vold[j] == INF) continue;
                if (arc->pond + Vold[j] < V[nod->id])
                    { free(V); free(pred); free(Vold); return 0; }
            }
    }

    free(Vold); *pV = V; *pPred = pred;
    return 1;
}

/* ================================================================== */
/*  TOATE DRUMURILE MINIME (recursiv DFS)                               */
/* ================================================================== */

void toateDrumurile(Graf *g, int cur, int dest, int *V,
                    int *drum, int len)
{
    drum[len++] = cur;
    if (cur == dest) {
        printf("  Traseu: ");
        for (int k = 0; k < len; k++) printf("%sx%d", k ? " -> " : "", drum[k]);
        printf("\n");
        return;
    }
    for (Arc *a = cautaNod(g, cur)->arce; a; a = a->next) {
        int j = a->dest;
        /* merge pe acest arc doar daca contribuie la drumul minim */
        if (V[j] != INF && V[cur] == a->pond + V[j]) {
            /* verifica sa nu fie ciclu in drumul curent */
            int ciclu = 0;
            for (int k = 0; k < len; k++) if (drum[k] == j) { ciclu = 1; break; }
            if (!ciclu) toateDrumurile(g, j, dest, V, drum, len);
        }
    }
}

/* ================================================================== */
/*  AFISARE REZULTATE                                                   */
/* ================================================================== */

void afiseazaRezultate(Graf *g, int dest, int *V, int *pred)
{
    int n = g->n;

    printf("\n  %-8s %-12s  Drum\n", "Sursa", "Cost minim");
    printf("  %-8s %-12s  %s\n", "-------", "----------", "--------------------------");

    for (Nod *p = g->cap; p; p = p->next) {
        int s = p->id; if (s == dest) continue;
        printf("  %-8d ", s);
        if (V[s] == INF) { printf("%-12s  (fara drum)\n", "---"); continue; }
        printf("%-12d  ", V[s]);
        int drum[101], len = 0, cur = s;
        while (cur != dest && len < n) { drum[len++] = cur; cur = pred[cur]; }
        drum[len++] = dest;
        for (int k = 0; k < len; k++) printf("%s%d", k ? "->" : "", drum[k]);
        printf("\n");
    }

    /* sumar final: toate drumurile minime de la nodul 1 la destinatie */
    if (dest != 1 && V[1] != INF) {
        int drum_buf[101];
        printf("\n  Distanta minima d(x1, x%d) = %d\n", dest, V[1]);
        printf("  Toate traseele optime:\n");
        toateDrumurile(g, 1, dest, V, drum_buf, 0);
    }
}

/* ================================================================== */
/*  MODIFICARE GRAF                                                     */
/* ================================================================== */

void modificaGraf(Graf *g)
{
    char buf[64]; int i, j, pond;
    printf("\n  Format: <sursa> <dest> <pondere>  (pondere 0 = sterge arc)\n");
    printf("  Arc: ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    if (sscanf(buf, "%d %d %d", &i, &j, &pond) != 3)
        { printf("  [EROARE] Format gresit.\n"); return; }
    if (!cautaNod(g,i) || !cautaNod(g,j))
        { printf("  [EROARE] Nod inexistent.\n"); return; }
    if (i == j) { printf("  [EROARE] Buclele nu sunt permise.\n"); return; }
    if (pond < 0) { printf("  [EROARE] Ponderea negativa.\n"); return; }

    if (pond == 0)
        printf(stergeArc(g,i,j) ? "  Arcul (%d->%d) sters.\n"
                                 : "  Arcul (%d->%d) nu exista.\n", i, j);
    else {
        adaugaArc(g, i, j, pond);
        printf("  Arcul (%d->%d) setat la %d.\n", i, j, pond);
    }
    afiseazaGraf(g);
}

/* ================================================================== */
/*  MENIU PRINCIPAL                                                     */
/* ================================================================== */

int main(void)
{
    Graf *g = NULL; int *V = NULL, *pred = NULL;
    char buf[64]; int opt, dest;


    g = introduceGraf();

    do {
        printf("\nIntroduceti varful final (1..%d): ", g->n);
        if (!fgets(buf, sizeof(buf), stdin)) continue;
        dest = atoi(buf);
    } while (dest < 1 || dest > g->n || !cautaNod(g, dest));

    while (1) {
        if (V)    { free(V);    V    = NULL; }
        if (pred) { free(pred); pred = NULL; }

        printf("\n========== MENIU ==========\n");
        printf("  Varf final curent: %d\n", dest);
        printf("1. Afiseaza lista de adiacenta\n");
        printf("2. Afiseaza matricea ponderata de adiacenta\n");
        printf("3. Drum MINIM\n");
        printf("4. Schimba varful final\n");
        printf("5. Modifica graful\n");
        printf("6. Reintroduce graful\n");
        printf("0. Iesire\n");
        printf("Optiune: ");

        if (!fgets(buf, sizeof(buf), stdin)) continue;
        opt = atoi(buf);

        switch (opt) {

        case 1:
            afiseazaGraf(g);
            break;

        case 2:
            afiseazaMatrice(g);
            break;

        case 3:
            printf("\n  Bellman-Calaba MINIM, varf final = %d\n", dest);
            if (!bellmanCalaba(g, dest, &V, &pred))
                printf("  [EROARE] Ciclu negativ detectat!\n");
            else
                afiseazaRezultate(g, dest, V, pred);
            break;

        case 4:
            do {
                printf("Noul varf final (1..%d): ", g->n);
                if (!fgets(buf, sizeof(buf), stdin)) continue;
                dest = atoi(buf);
            } while (dest < 1 || dest > g->n || !cautaNod(g, dest));
            printf("  Varf final schimbat la %d.\n", dest);
            break;

        case 5:
            modificaGraf(g);
            break;

        case 6:
            distrugeGraf(&g);
            g = introduceGraf();
            do {
                printf("\nIntroduceti varful final (1..%d): ", g->n);
                if (!fgets(buf, sizeof(buf), stdin)) continue;
                dest = atoi(buf);
            } while (dest < 1 || dest > g->n || !cautaNod(g, dest));
            break;

        case 0:
            if (V)    free(V);
            if (pred) free(pred);
            distrugeGraf(&g);
            printf("La revedere!\n");
            return 0;

        default:
            printf("  Optiune invalida.\n");
        }
    }
}