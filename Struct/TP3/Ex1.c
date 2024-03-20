#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

typedef struct Monome{
    int coefficient;
    int puissance;
    struct Monome *suivant;
}Monome;

typedef struct ListPolynome{
    Monome *debut;
    Monome *fin;
    int taille;
}ListPolynome;

void init_List(ListPolynome *L){
    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

void new_element(ListPolynome *L, Monome *nv , int k){
    if(L->debut == NULL){
        nv->suivant = NULL;
        L->debut = nv;
        L->fin = nv;
        L->taille++;
    }else{
        if(k == 1){
            nv->suivant = L->debut;
            L->debut = nv;
            L->taille ++;
        }else if (k == L->taille+1){
            nv->suivant = NULL;
            L->fin->suivant = nv;
            L->fin = nv;
            L->taille++;
        }else{
            Monome *courant = L->debut;
            for(i=1 ; i<k ; i++){
                courant = courant->suivant;
            }
            nv->suivant = courant->suivant;
            courant->suivant = nv;
            L->taille++;
        }
    }
}

void afficher_list(ListPolynome *L){
    Monome *courant = L->debut;
    while(courant != NULL){ 
        if(courant->suivant == NULL){
            printf("%dx^%d",courant->coefficient,courant->puissance);
            break;
        }
        printf("%dx^%d + ",courant->coefficient,courant->puissance);
        courant = courant->suivant;
    }
}

int main(){
    ListPolynome *L = (ListPolynome *)malloc(sizeof(ListPolynome));
    Monome nv1 = {1 , 1};
    Monome nv2 = {2 , 2};
    Monome nv3 = {3 , 3};
    Monome nv4 = {4 , 4};
    Monome nv5 = {5 , 5};
    Monome nv6 = {6 , 6};
    Monome nv7 = {7 , 7};


    init_List(L);
    new_element(L , &nv1 , 1);
    new_element(L , &nv2 , 2);
    new_element(L , &nv3 , 3);
    new_element(L , &nv4 , 4);
    new_element(L , &nv5 , 5);
    new_element(L , &nv6 , 6);
    new_element(L , &nv7 , 4);


    afficher_list(L);
}