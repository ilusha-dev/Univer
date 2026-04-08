#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* PROTOTIPURI */
void meniu(int **v1, int **v2, int **v3, int n, int *creat);
void alocare(int **v, int n);
void citire(int *v, int n);
void random_arr(int *v, int n);
void combinare(int *v1, int *v2, int *v3, int n);
void afisare(int *v, int n);
void freemem(int **v);

/* SORTARI */
void bubble(int *v, int n, int ordine);
void selection(int *v, int n, int ordine);
void insertion(int *v, int n, int ordine);
void mergeSort(int *v, int st, int dr, int ordine);
void quickSort(int *v, int st, int dr, int ordine);

/* AUXILIARE */
void merge(int *v, int st, int mid, int dr, int ordine);
int partition(int *v, int st, int dr, int ordine);

/* ================= MAIN ================= */

int main()
{
    int n;
    int *v1=NULL, *v2=NULL, *v3=NULL;
    int creat = 0;

    printf("Introduceti dimensiunea vectorilor: ");
    scanf("%d",&n);

    if(n<=0){
        printf("Dimensiune invalida!\n");
        return 0;
    }

    meniu(&v1,&v2,&v3,n,&creat);
    return 0;
}

/* ================= MENIU RECURSIV ================= */

void meniu(int **v1, int **v2, int **v3, int n, int *creat)
{
    int opt;

    printf("\n===== MENIU =====\n");
    printf("1. Alocare memorie\n");
    printf("2. Citire vectori\n");
    printf("3. Completare random\n");
    printf("4. Combinare vectori\n");
    printf("5. Sortare vector rezultat\n");
    printf("6. Afisare vectori\n");
    printf("0. Iesire\n");
    scanf("%d",&opt);

    switch(opt)
    {
        case 1:
            alocare(v1,n);
            alocare(v2,n);
            alocare(v3,2*n);
            *creat = 0;
            printf("Memorie alocata.\n");
            break;

        case 2:
            if(*v1==NULL || *v2==NULL){
                printf("Vectorii nu sunt alocati!\n");
                break;
            }
            printf("Vector 1:\n");
            citire(*v1,n);
            printf("Vector 2:\n");
            citire(*v2,n);
            printf("Vectorii dupa citire:\n");
            afisare(*v1,n);
            afisare(*v2,n);
            break;

        case 3:
            if(*v1==NULL || *v2==NULL){
                printf("Vectorii nu sunt alocati!\n");
                break;
            }
            srand(time(NULL));
            random_arr(*v1,n);
            random_arr(*v2,n);
            printf("Vectorii completati random:\n");
            afisare(*v1,n);
            afisare(*v2,n);
            break;

        case 4:
            if(*v1==NULL || *v2==NULL || *v3==NULL){
                printf("Vectorii nu sunt alocati!\n");
                break;
            }
            combinare(*v1,*v2,*v3,n);
            *creat = 1;
            printf("Vector rezultat (combinat):\n");
            afisare(*v3,2*n);
            break;

        case 5:
        {
            if(*v3==NULL || *creat==0){
                printf("Vectorul 3 nu este combinat!\n");
                break;
            }

            int tip, ordine;

            printf("1.Bubble\n2.Selection\n3.Insertion\n4.Merge\n5.Quick\n");
            scanf("%d",&tip);

            printf("1.Crescator  2.Descrescator\n");
            scanf("%d",&ordine);

            switch(tip){
                case 1: bubble(*v3,2*n,ordine); break;
                case 2: selection(*v3,2*n,ordine); break;
                case 3: insertion(*v3,2*n,ordine); break;
                case 4: mergeSort(*v3,0,2*n-1,ordine); break;
                case 5: quickSort(*v3,0,2*n-1,ordine); break;
                default: printf("Optiune invalida!\n");
            }

            printf("Vector sortat:\n");
            afisare(*v3,2*n);
            break;
        }

        case 6:
            if(*v1!=NULL){
                printf("Vector 1:\n");
                afisare(*v1,n);
            } else printf("Vector 1 nealocat!\n");

            if(*v2!=NULL){
                printf("Vector 2:\n");
                afisare(*v2,n);
            } else printf("Vector 2 nealocat!\n");

            if(*v3!=NULL && *creat==1){
                printf("Vector 3:\n");
                afisare(*v3,2*n);
            }
            else if(*v3!=NULL && *creat==0){
                printf("Vector 3 este alocat dar nu este combinat!\n");
            }
            else{
                printf("Vector 3 nealocat!\n");
            }

            break;

        case 0:
            freemem(v1);
            freemem(v2);
            freemem(v3);
            printf("Memorie eliberata. Program inchis.\n");
            exit(0);

        default:
            printf("Optiune invalida!\n");
    }

    meniu(v1,v2,v3,n,creat);
}

/* ================= FUNCTII ================= */

void alocare(int **v, int n){
    if(*v!=NULL) free(*v);
    *v = (int*)malloc(n*sizeof(int));
}

void citire(int *v, int n){
    for(int i=0;i<n;i++){
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }
}

void random_arr(int *v, int n){
    for(int i=0;i<n;i++)
        v[i]=rand()%100;
}

void combinare(int *v1, int *v2, int *v3, int n){
    for(int i=0;i<n;i++)
        v3[i]=v1[i];
    for(int i=0;i<n;i++)
        v3[n+i]=v2[i];
}

void afisare(int *v, int n){
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

void freemem(int **v){
    if(*v!=NULL){
        free(*v);
        *v=NULL;
    }
}

/* ================= SORTARI ================= */

void bubble(int *v, int n, int ordine){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if((ordine==1 && v[j]>v[j+1]) ||
               (ordine==2 && v[j]<v[j+1])){
                int t=v[j]; v[j]=v[j+1]; v[j+1]=t;
            }
}

void selection(int *v, int n, int ordine){
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++)
            if((ordine==1 && v[j]<v[idx]) ||
               (ordine==2 && v[j]>v[idx]))
                idx=j;
        int t=v[i]; v[i]=v[idx]; v[idx]=t;
    }
}

void insertion(int *v, int n, int ordine){
    for(int i=1;i<n;i++){
        int key=v[i], j=i-1;
        while(j>=0 && ((ordine==1 && v[j]>key) ||
                       (ordine==2 && v[j]<key))){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}

/* MERGE */

void merge(int *v, int st, int mid, int dr, int ordine){
    int n1=mid-st+1, n2=dr-mid;
    int *L=malloc(n1*sizeof(int));
    int *R=malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++) L[i]=v[st+i];
    for(int i=0;i<n2;i++) R[i]=v[mid+1+i];

    int i=0,j=0,k=st;

    while(i<n1 && j<n2){
        if((ordine==1 && L[i]<=R[j]) ||
           (ordine==2 && L[i]>=R[j]))
            v[k++]=L[i++];
        else
            v[k++]=R[j++];
    }

    while(i<n1) v[k++]=L[i++];
    while(j<n2) v[k++]=R[j++];

    free(L);
    free(R);
}

void mergeSort(int *v, int st, int dr, int ordine){
    if(st<dr){
        int mid=(st+dr)/2;
        mergeSort(v,st,mid,ordine);
        mergeSort(v,mid+1,dr,ordine);
        merge(v,st,mid,dr,ordine);
    }
}

/* QUICK */

int partition(int *v, int st, int dr, int ordine){
    int pivot=v[dr], i=st-1;

    for(int j=st;j<dr;j++)
        if((ordine==1 && v[j]<pivot) ||
           (ordine==2 && v[j]>pivot)){
            i++;
            int t=v[i]; v[i]=v[j]; v[j]=t;
        }

    int t=v[i+1]; v[i+1]=v[dr]; v[dr]=t;
    return i+1;
}

void quickSort(int *v, int st, int dr, int ordine){
    if(st<dr){
        int p=partition(v,st,dr,ordine);
        quickSort(v,st,p-1,ordine);
        quickSort(v,p+1,dr,ordine);
    }
}
