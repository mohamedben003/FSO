#include<stdio.h>
#include<stdlib.h>

typedef struct monome{
    int coefficient ;
    int puissance ;
    struct monome *suivant;
    
}monome;

typedef struct ListePolynome{
    monome *debut;
    monome *fin;
    int taille;
}ListePolynome;

void initaliser_list(ListePolynome *L){
    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

void insert_element(ListePolynome *L , monome *nv , int k){
    if (L->debut == NULL ){
        nv->suivant = NULL;
        L->debut = nv;
        L->fin = nv;
        L->taille++;
        return;
    }
    if (k == 1){
        nv->suivant = L->debut;
        L->debut = nv;
        L->taille++;
    }else {
        monome *courant = L->debut;
        int i;
        for(i=1 ; i<k ; i++){
            courant = courant->suivant;
        }
        nv->suivant = courant->suivant; 
        courant->suivant = nv;
        L->taille++;
    }
}

void ajoutermonome(ListePolynome *L ,monome *nv){
    monome *courant = L->debut;
    int i;
    while(courant !=NULL ){
        if(courant->puissance == nv->puissance){
            courant->coefficient += nv->coefficient;
            return;
        }
        courant = courant->suivant ;
    }
    courant = L->debut;
    int count = 1;
    while (courant !=NULL){
        if(nv->coefficient > courant->coefficient){
            insert_element(L , nv , 1);
            break;
        }
        else if((nv->coefficient < courant->coefficient)&&(nv->coefficient > courant->suivant->coefficient)){
            insert_element(L , nv , count );
            break;
        }else{
            insert_element(L , nv , L->taille);
            break;
        }
        courant = courant->suivant;
        count++;
    }
}
void afficher_List(ListePolynome *L){
    monome *courant ;
    courant=L->debut;
    while (courant!=NULL){
        if(courant->suivant == NULL){
            printf("%dx^%d",courant->coefficient,courant->puissance);
            return;
        }
        printf("%dx^%d +",courant->coefficient,courant->puissance);
        courant = courant->suivant;
        
    }
}

int main(){
    ListePolynome *L = (ListePolynome *)malloc (sizeof(ListePolynome));
    initaliser_list(L);
    monome *nv = (monome *)malloc(sizeof(monome));
    nv->coefficient = 3;
    nv->puissance = 4 ;
    insert_element(L ,nv,1);
    afficher_List(L);
}




