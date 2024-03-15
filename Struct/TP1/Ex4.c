#include <stdio.h>
#include <stdlib.h>

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
}Etudiant;
//------------- 1:
void creerEtudiant(Etudiant *E){
    printf("le nom : ");
    scanf("%s",E->nom);
    printf("le prenom : ");
    scanf("%s",E->prenom);
    printf("CNE : ");
    scanf("%d",&E->CNE);
    printf("Date de naissance : \n");
    printf("jour : ");
    scanf("%d",&E->naissance.jour);
    printf("mois : ");
    scanf("%d",&E->naissance.mois);
    printf("annee : ");
    scanf(" %d",&E->naissance.annee);
    printf("Les Notes : \n");
    for (int i=0 ; i<6 ; i++){
        printf("module %d : ",i+1);
        scanf("%fl",&E->Notes[i]);
    }
}
//-------------- 2:
void creerTableauEtudiant(Etudiant *t, int n) {
    for (int i = 0; i < n; i++) {
        printf("Etudiant %d : ", i + 1);
        creerEtudiant(&t[i]);
    }
}
//-------------- 3:
float CalculerMoyS3(Etudiant *E){
    float moy ;
    float sum = 0 ;
    for(int i=0 ; i<6 ; i++){
        sum += E->Notes[i];
    }
    moy = sum / 6;
    return moy;
}
//--------------- 4:
void afficherEtudiant(Etudiant *E){
    printf("nom : %s \nprenom : %s \nCNE : %d \nDate : %d/%d/%d \n", E->nom , E->prenom , E->CNE , E->naissance.jour , E->naissance.mois , E->naissance.annee );
    printf("Notes : \n");
    for(int i=0 ; i<6 ; i++){
        printf("le module %d : ", i+1);
        printf("%.2f\n",E->Notes[i]);
    }
    printf("La Moyenne est : %.2f" ,CalculerMoyS3(E));
    printf("\n");
}
// -------------- 5:
void afficheTableauEtudiants(Etudiant *t , int n){
    printf("affichage du donnees : \n");
    for(int i=0 ; i<n ; i++){
        afficherEtudiant(&t[i]);
        if (i != n-1){
            printf("\n");
        }
    }
}

void modifieEtudiant(Etudiant *E){
    char confirm ,c = 'O';
    getchar();
    printf("tu veux modifie quelque chose : (oui) = O / (non) = N ");
    scanf("%c",&confirm);
    if(confirm == 'O'){
        while(c =='O'){
        puts("quoi tu veux modifie : \n1 = (nom)\n2 = (prenom)\n3 = (CNE)\n4 = (Date de naissance)\n5 = (Notes)\n");
        int a ;
        scanf("%d",&a);
        switch(a){
            case 1 :
                puts("entrer le nom : ");
                scanf("%s",E->nom);
                break;
            case 2 :
                puts("entrer le prenom : ");
                scanf("%s",E->prenom);
                break;
            case 3 :
                puts("entrer le CNE : ");
                scanf("%d",&E->CNE);
                break;
            case 4 :
                puts("enter la date : ");
                scanf("%d",&E->naissance.jour);
                scanf("%d",&E->naissance.mois);
                scanf("%d",&E->naissance.annee);
                break;
            case 5 :
                printf("quel note : \n");
                scanf("%d",&a);
                switch(a){
                printf("la note modifie : ");
                case 1 :
                    scanf("%f",&E->Notes[0]);
                    break;
                case 2 :
                    scanf("%f",&E->Notes[1]);
                    break;
                case 3 :
                    scanf("%f",&E->Notes[2]);
                    break;
                case 4 :
                    scanf("%f",&E->Notes[3]);
                    break;
                case 5 :
                    scanf("%f",&E->Notes[4]);
                    break;
                case 6 :
                    scanf("%f",&E->Notes[5]);
                    break;
                default:
                    puts("n'exist pas !!");
                    break;
                }
                break;
            default:
            puts("valeur erronee !!");
            break;
        }
        getchar();
        printf("Tu veux changer autre chose ? (oui) = O / (non) = N ");
        scanf("%c",&c);
    }
    }else if (confirm == 'N'){
        puts("d'accord mercii pour la confirmation : ");
    }else{
        puts("tu na pas repponder corectement (¬_¬\")");
    }
}

//-------------- 6:
int main(){
    int n;
    Etudiant *E;

    puts("enter le nbr des etudiants :");
    scanf("%d",&n);
    creerTableauEtudiant(E,n);
    afficheTableauEtudiants(E,n);
    // modifieEtudiant(&E);
    // afficheTableauEtudiants(&E,n);
}
