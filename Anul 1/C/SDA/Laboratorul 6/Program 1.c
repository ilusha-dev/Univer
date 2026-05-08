#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tableta {
    char tip[50];
    char producator[50];
    float dimensiuneEcran;
    char sistemOperare[50];
    int numarNuclee;
    float pret;

    struct Tableta* next;
} Tableta;

// ===== STACK =====
typedef struct {
    Tableta* top;
} Stack;

// ===== QUEUE =====
typedef struct {
    Tableta* front;
    Tableta* rear;
} Queue;

// ===== INITIALIZARE =====
void initStack(Stack* s) {
    s->top = NULL;
}

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// ===== CREARE NOD =====
Tableta* creareTableta() {
    Tableta* nou = (Tableta*)malloc(sizeof(Tableta));

    printf("Tip (tableta/carte electronica/tableta grafica): ");
    getchar();
    fgets(nou->tip, 50, stdin);
    nou->tip[strcspn(nou->tip, "\n")] = '\0';

    printf("Producator: ");
    fgets(nou->producator, 50, stdin);
    nou->producator[strcspn(nou->producator, "\n")] = '\0';

    printf("Dimensiune ecran: ");
    scanf("%f", &nou->dimensiuneEcran);

    printf("Sistem de operare: ");
    getchar();
    fgets(nou->sistemOperare, 50, stdin);
    nou->sistemOperare[strcspn(nou->sistemOperare, "\n")] = '\0';

    printf("Numar de nuclee: ");
    scanf("%d", &nou->numarNuclee);

    printf("Pret: ");
    scanf("%f", &nou->pret);

    nou->next = NULL;

    return nou;
}

// ===== PUSH STACK =====
void push(Stack* s, Tableta* nou) {
    nou->next = s->top;
    s->top = nou;
}

// ===== AFISARE STACK IN FISIER =====
void scrieStackFisier(Stack* s) {
    FILE* f = fopen("stiva.txt", "a");

    if (f == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        return;
    }

    Tableta* temp = s->top;

    while (temp != NULL) {
        fprintf(f,
                "Tip: %s\nProducator: %s\nDimensiune: %.2f\nSO: %s\nNuclee: %d\nPret: %.2f\n\n",
                temp->tip,
                temp->producator,
                temp->dimensiuneEcran,
                temp->sistemOperare,
                temp->numarNuclee,
                temp->pret);

        temp = temp->next;
    }

    fclose(f);

    printf("Datele au fost salvate in stiva.txt\n");
}

// ===== MAXIM =====
void elementMaxim(Stack* s) {
    if (s->top == NULL) {
        printf("Stiva este goala!\n");
        return;
    }

    Tableta* max = s->top;
    Tableta* temp = s->top;

    while (temp != NULL) {
        if (temp->pret > max->pret) {
            max = temp;
        }

        temp = temp->next;
    }

    printf("\n=== TABLETA CU PRET MAXIM ===\n");
    printf("Tip: %s\n", max->tip);
    printf("Producator: %s\n", max->producator);
    printf("Pret: %.2f\n", max->pret);
}

// ===== ADAUGARE IN QUEUE =====
void enqueue(Queue* q, Tableta* data) {
    Tableta* nou = (Tableta*)malloc(sizeof(Tableta));

    *nou = *data;
    nou->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = nou;
    } else {
        q->rear->next = nou;
        q->rear = nou;
    }
}

// ===== COPIERE STACK -> QUEUE =====
void copiazaInQueue(Stack* s, Queue* q) {
    Tableta* temp = s->top;

    while (temp != NULL) {
        enqueue(q, temp);
        temp = temp->next;
    }

    printf("Date copiate in Queue!\n");
}

// ===== SCRIERE QUEUE IN FISIER =====
void scrieQueueFisier(Queue* q) {
    FILE* f = fopen("queue.txt", "w");

    if (f == NULL) {
        printf("Eroare la fisier!\n");
        return;
    }

    Tableta* temp = q->front;

    while (temp != NULL) {
        fprintf(f,
                "Tip: %s\nProducator: %s\nDimensiune: %.2f\nSO: %s\nNuclee: %d\nPret: %.2f\n\n",
                temp->tip,
                temp->producator,
                temp->dimensiuneEcran,
                temp->sistemOperare,
                temp->numarNuclee,
                temp->pret);

        temp = temp->next;
    }

    fclose(f);

    printf("Datele au fost salvate in queue.txt\n");
}

// ===== LUNGIME STACK =====
int lungimeStack(Stack* s) {
    int count = 0;

    Tableta* temp = s->top;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// ===== MODIFICARE =====
void modificaElement(Stack* s) {
    if (s->top == NULL) {
        printf("Stiva goala!\n");
        return;
    }

    char producator[50];

    printf("Introdu producatorul tabletei de modificat: ");
    getchar();
    fgets(producator, 50, stdin);
    producator[strcspn(producator, "\n")] = '\0';

    Tableta* temp = s->top;

    while (temp != NULL) {
        if (strcmp(temp->producator, producator) == 0) {

            printf("Noul pret: ");
            scanf("%f", &temp->pret);

            printf("Noul numar de nuclee: ");
            scanf("%d", &temp->numarNuclee);

            FILE* f = fopen("stiva.txt", "a");

            fprintf(f,
                    "MODIFICAT -> Tip: %s | Producator: %s | Pret: %.2f\n",
                    temp->tip,
                    temp->producator,
                    temp->pret);

            fclose(f);

            printf("Element modificat!\n");
            return;
        }

        temp = temp->next;
    }

    printf("Elementul nu a fost gasit!\n");
}

// ===== ELIBERARE STACK =====
void freeStack(Stack* s) {
    Tableta* temp;

    while (s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }

    printf("Memoria stivei a fost eliberata!\n");
}

// ===== ELIBERARE QUEUE =====
void freeQueue(Queue* q) {
    Tableta* temp;

    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    q->rear = NULL;

    printf("Memoria queue a fost eliberata!\n");
}

// ===== MENIU =====
int main() {

    Stack stiva;
    Queue queue;

    initStack(&stiva);
    initQueue(&queue);

    int optiune;
    int n;

    do {

        printf("\n===== MENIU =====\n");
        printf("1. Crearea unei stive dinamice\n");
        printf("2. Citirea datelor pentru stiva\n");
        printf("3. Salvarea stivei in fisier\n");
        printf("4. Elementul maximal din stiva\n");
        printf("5. Copiere stack -> queue\n");
        printf("6. Salvarea queue in fisier\n");
        printf("7. Lungimea stivei\n");
        printf("8. Modificarea unui element\n");
        printf("9. Adaugarea elementului modificat in fisier\n");
        printf("10. Eliberare memorie stiva\n");
        printf("11. Eliberare memorie queue\n");
        printf("0. Iesire\n");

        printf("Alege optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {

            case 1:
                initStack(&stiva);
                printf("Stiva creata!\n");
                break;

            case 2:
                printf("Numarul de elemente: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("\nElementul %d\n", i + 1);

                    Tableta* nou = creareTableta();
                    push(&stiva, nou);
                }

                break;

            case 3:
                scrieStackFisier(&stiva);
                break;

            case 4:
                elementMaxim(&stiva);
                break;

            case 5:
                copiazaInQueue(&stiva, &queue);
                break;

            case 6:
                scrieQueueFisier(&queue);
                break;

            case 7:
                printf("Lungimea stivei: %d\n", lungimeStack(&stiva));
                break;

            case 8:
                modificaElement(&stiva);
                break;

            case 9:
                printf("Elementul modificat a fost deja adaugat in fisier.\n");
                break;

            case 10:
                freeStack(&stiva);
                break;

            case 11:
                freeQueue(&queue);
                break;

            case 0:
                printf("Iesire din program...\n");
                break;

            default:
                printf("Optiune invalida!\n");
        }

    } while (optiune != 0);

    freeStack(&stiva);
    freeQueue(&queue);

    return 0;
}