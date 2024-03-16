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
            break;
        }else{
            courant = courant->suivant;
            i++;
        }
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
int main(){
    Liste *L = (Liste *)malloc(sizeof(Liste));
    Livre *nv =(Livre *)malloc(sizeof(Livre));
    if (L==NULL || nv==NULL){
        puts("pas de memoire !!");
    }
    intialiser_Liste(L);
    strcpy(nv->nom_aut,"benjeloun ahmed");
    strcpy(nv->titre,"GOT");
    nv->annee = 1999;
    first_elem(L , nv);

    Livre *nv1 =(Livre *)malloc(sizeof(Livre));
    strcpy(nv1->nom_aut,"david bendivos");
    strcpy(nv1->titre,"brezking bad");
    nv1->annee = 1877;
    debut_Liste(L , nv1);

    Livre *nv2 =(Livre *)malloc(sizeof(Livre));
    strcpy(nv2->nom_aut,"kim son doo");
    strcpy(nv2->titre,"solo level");
    nv2->annee = 1766;
    fin_Liste(L , nv2);

    Livre *nv3 =(Livre *)malloc(sizeof(Livre));
    strcpy(nv3->nom_aut,"dadivos sivecsff");
    strcpy(nv3->titre,"brezd");
    nv3->annee = 1666;
    k_em_pos(L , nv3 , 2);
    afficher_Liste(L);
    delete_first(L);
    delete_k_em(L , 1);
    delete_with_year(L , 1766);
    puts("-----------------");
    afficher_Liste(L);
    destroy_Liste(L);
    puts("------------------");
    afficher_Liste(L);
    puts("fin ...");

}