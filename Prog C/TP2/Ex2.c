#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i,j;
void afficher_matrice(int **A){
    for(i=0 ; i<5 ; i++){
        for(j=0 ; j<5 ; j++){
            printf("%d\t",*(*(A+i)+j));
        }
        printf("\n");
    }
}
int main(){
    //declaration :
    int **A = (int **)malloc(5*sizeof(int *));
    if (A==NULL){
        printf("pas de memoire !!");
    }
    for(i=0 ; i<5 ; i++){
        *(A+i) = (int *)malloc(5*sizeof(int));
    }
    //initalisation :
    for(i=0 ; i<5 ; i++){
        for(j=0 ; j<5 ; j++){
            printf("etrer A[%d][%d] = ",i,j);
            scanf("%d",*(A+i)+j);
        }
    }
    //affichage : 
    afficher_matrice(A);

}