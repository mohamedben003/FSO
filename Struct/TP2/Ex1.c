#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employe{
    char nom[20];
    char prenom[20];
    int code;
}Employe;

typedef struct ListEmploye{
    Employe A[100];
    int taille;
}ListEmploye;

int i = 0;

void initialiser_list(ListEmploye *L){
    L->taille = 0;
}

void insert_fin(ListEmploye *L , Employe *nv){
    if(L->taille < 100){
        L->A[L->taille] = *nv;
        L->taille++;
    }else{
        puts("la Liste est saturee !!");
    }
}
void insert_mid(ListEmploye *L , Employe *nv , int k){
    if(L->taille < 100){
        for (i=L->taille ; i>k ; i--){
            L->A[i] = L->A[i-1];
        }
        L->A[k] = *nv;
        L->taille++;
    }else{
        puts("la Liste est saturee !!");
    }
}

void delete_last(ListEmploye *L){
    L->taille--;
}

void delete_mid(ListEmploye *L , int k){
    for(i=k ; i<L->taille ; i++ ){
        L->A[i] = L->A[i+1];
    }
    L->taille--;
}

void afficher_list(ListEmploye *L){
    for(i=0 ; i<L->taille ; i++){
        printf("%s \t %s \t %d \n",L->A[i].nom , L->A[i].prenom , L->A[i].code );
    }
}

int main(){
    ListEmploye *L;
    L = (ListEmploye *)malloc(sizeof(ListEmploye));
    Employe *e;
    e = (Employe *)malloc(sizeof(Employe));
    if (L==NULL || e==NULL){
        puts("pas de memoire !!");
    }
    initialiser_list(L);
    for(i=0 ; i<4 ; i++){
        printf("le nom = ");
        scanf("%s",e->nom);
        printf("le prenom = ");
        scanf("%s",e->prenom);
        printf("le code = ");
        scanf("%d",&e->code);
        insert_fin(L ,e);
    }
    strcpy(e->nom,"med");
    strcpy(e->prenom,"ben");
    e->code = 121212;
    insert_mid(L , e , 2);
    afficher_list(L);
    delete_last(L);
    delete_mid(L,1);
    puts("on suprime les elements :");
    afficher_list(L);
    while (L->taille!=0)
    {
        delete_last(L);
    }
    afficher_list(L); 
    puts("fin du programme");
}