#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livre{
    char nom_aut[30];
    char titre[100];
    int annee;
    struct Livre *suivant;
}Livre;
typedef struct{
    Livre *debut;
    Livre *fin;
    int taille;
}Liste;
int i;
void intialiser_Liste(Liste *L){
    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

void first_elem(Liste *L , Livre *nv){
    L->debut = nv;
    L->fin = nv;
    L->debut->suivant = NULL;
    L->taille++;
}

void debut_Liste(Liste *L , Livre *nv){
    nv->suivant = L->debut;
    L->debut = nv;
    L->taille++;
}

void fin_Liste(Liste *L , Livre *nv){
    nv->suivant=NULL;
    L->fin->suivant = nv;
    L->fin = nv;
    L->taille++;
}

void k_em_pos(Liste *L , Livre *nv ,int k){
    Livre *courant = L->debut;
    if (L->taille > k && k>0){
        for(i=1 ; i<k ; i++){
           courant = courant->suivant; 
        }
        nv ->suivant = courant->suivant;
        courant->suivant = nv ;
        L->taille++;
    }else{
        puts("error");
    }
}

void delete_first(Liste *L){
    if(L->taille == 0){
        printf("La liste est vide !");
    }else{
        L->debut = L->debut->suivant;
        L->taille--;
    }
    
}

void delete_k_em(Liste *L , int k){
    if(L->taille == 0){
        printf("La liste est vide !");
    }else{
        if(k==1){
            delete_first(L);
        }else{
            Livre *courant = L->debut;
            for(i=1 ; i<k-1 ; ++i){
                courant = courant->suivant;
            }
            Livre *temp = courant->suivant;
            courant->suivant = temp->suivant;
            temp=NULL;
            free(temp);
            L->taille--;
        }
    }
}

void delete_with_year(Liste *L ,int year){
    Livre *courant = L->debut;
    i=1;
    while(courant!=NULL){
        if(courant->annee == year){
            delete_k_em(L , i);
        }
        courant = courant->suivant;
        i++;
    }
}

void afficher_Liste(Liste *L){
    Livre *courant = L->debut;
    while (courant != NULL)
    {
        printf("%s \t%s \t %d \n",courant->nom_aut , courant->titre , courant->annee);
        courant = courant->suivant;
    }
    
}

void destroy_Liste(Liste *L){
    Livre *courant = L->debut;
    while(courant != NULL){
        Livre *temp = courant;
        delete_first(L);
        temp = NULL;
        free(temp);
        courant = courant->suivant;
    }
}

void triabulle(Liste* L) {
    Livre *courant;
    Livre *temp = (Livre*)malloc(sizeof(Livre));
    for (i=0 ; i<L->taille ; i++ ) {
        courant = L->debut;
        while (courant->suivant !=NULL) {
            if (courant->annee > courant->suivant->annee) {
                strcpy(temp->nom_aut, courant->nom_aut);
                strcpy(courant->nom_aut, courant->suivant->nom_aut);
                strcpy(courant->suivant->nom_aut, temp->nom_aut);

                strcpy(temp->titre, courant->titre);
                strcpy(courant->titre, courant->suivant->titre);
                strcpy(courant->suivant->titre, temp->titre);

                temp->annee = courant->annee;
                courant->annee = courant->suivant->annee;
                courant->suivant->annee = temp->annee;
            }
            courant = courant->suivant;
        }
    }
}
int main(){
    Liste *L = (Liste*)malloc(sizeof(Liste));
    if (L == NULL){
        printf("pas de memo !");
    }
    Livre nv1 = {"aaa","aaa",2000};
    Livre nv2 = {"bbb","bbb",2001};
    Livre nv3 = {"ccc","ccc",2002};
    Livre nv4 = {"ddd","ddd",2003};
    Livre nv5 = {"eee","eee",2004};
    Livre nv6 = {"fff","fff",2005};

    first_elem (L , &nv1);
    debut_Liste(L , &nv2);
    debut_Liste(L , &nv3);
    debut_Liste(L , &nv4);
    debut_Liste(L , &nv5);
    debut_Liste(L , &nv6);

    triabulle(L);

    afficher_Liste(L);
}