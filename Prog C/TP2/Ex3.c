#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficher_heure(int iHeures ,int iMinutes ,int iSecondes ){
    printf("Il est ");
    if(iHeures == 01 || iHeures == 00){
        printf("%d heure",iHeures);
    }else{
        printf("%d heures",iHeures);
    }
    if(iMinutes == 01 || iMinutes == 00){
        printf(" %d minutes",iMinutes);
    }else{
        printf(" %d minutes",iMinutes);
    }
    if(iSecondes == 01 || iSecondes == 00){
        printf(" %d secondes",iSecondes);
    }else{
        printf(" %d secondes",iSecondes);
    }
    printf("\n");
}

void saisie_heure(int *iH ,int *iM , int *iS){
    scanf("%d",iH);
    scanf("%d",iM);
    scanf("%d",iS);
}

void tick(int *iH, int *iM, int *iS) {
    (*iS)++;
    if (*iS == 60) {
        (*iM)++;
        *iS = 0;
        if (*iM == 60) {
            (*iH)++;
            *iM = 0;
            if (*iH == 24) {
                *iH = 0;
            }
        }
    }
}

int main(){
    int h,m,s;
    saisie_heure(&h,&m,&s);
    afficher_heure(h,m,s);
    tick(&h,&m,&s);
    system("cls");
    system("color a");
    afficher_heure(h,m,s);
}