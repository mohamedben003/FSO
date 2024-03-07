#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    typedef struct {
        short jour;
        short mois;
        int annee;
    }Date;
    typedef  struct {
        char nom[20];
        char prenom[20];
        int CNE;
        Date naissance;
        float Notes[6];
    }etudiant;

     //part A :
     etudiant et1 ={"shoul","Karim",2048765,{05,03,2001},{10.25,10,10,10,10,10}};
     printf("nom : %s \nprenom : %s \nCNE : %d \nDate : %d/%d/%d \n", et1.nom , et1.prenom , et1.CNE , et1.naissance.jour , et1.naissance.mois , et1.naissance.annee );
     printf("Notes : \n");
     for (int i=0 ; i<6 ; i++){
         printf("module %d : ",i+1);
         printf("%.2f\n",et1.Notes[i]);
     }
    // part B :
    etudiant et2 ;
    printf("le nom : ");
    scanf("%s",et2.nom);
    printf("le prenom : ");
    scanf("%s",et2.prenom);
    printf("CNE : ");
    scanf("%d",&et2.CNE);
    printf("Date de naissance : \n");
    printf("jour : ");
    scanf("%d",&et2.naissance.jour);
    printf("mois : ");
    scanf("%d",&et2.naissance.mois);
    printf("année : ");
    scanf(" %d",&et2.naissance.annee);
    printf("Les Notes : \n");
    for (int i=0 ; i<6 ; i++){
        printf("module %d : ",i+1);
        scanf("%fl",&et2.Notes[i]);
    }
    printf("nom : %s \nprenom : %s \nCNE : %d \nDate : %d/%d/%d \n", et2.nom , et2.prenom , et2.CNE , et2.naissance.jour , et2.naissance.mois , et2.naissance.annee );
    for (int i=0 ; i<6 ; i++){
         printf("module %d : ",i+1);
         printf("%.2f\n",et2.Notes[i]);
    }
    //Part C :
    etudiant et3;
    strcpy(et3.nom ,et1.nom);
    strcpy(et3.prenom ,et1.prenom);
    et3.CNE = et1.CNE;
    et3.naissance.jour = et1.naissance.jour;
    et3.naissance.mois = et1.naissance.mois;
    et3.naissance.annee = et1.naissance.annee;
    for (int i=0 ; i<6 ; i++){
         et3.Notes[i] = et1.Notes[i];
    }
    printf("nom : %s \nprenom : %s \nCNE : %d \nDate : %d/%d/%d \n", et3.nom , et3.prenom , et3.CNE , et3.naissance.jour , et3.naissance.mois , et3.naissance.annee );
    for (int i=0 ; i<6 ; i++){
         printf("module %d : ",i+1);
         printf("%.2f\n",et3.Notes[i]);
    }
}
