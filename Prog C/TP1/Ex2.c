#include <stdio.h>
#include <stdlib.h>
int main(){
    int M , N , P , i , j ;
    printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);
    printf("P = ");
    scanf("%d", &P);

    int **A =(int **) malloc(N* sizeof(int*));
    if (A==NULL){
        printf("on a pas de memoire ");
        exit (0);
    }
    for (i=0 ; i<N ; i++){
        *(A+i) = (int *) malloc(M* sizeof(int));
    }

    int **B =(int **) malloc(M* sizeof(int*));
    if (B==NULL){
        printf("on a pas de memoire ");
        exit (0);
    }
    for (i=0 ; i<M ; i++){
        *(B+i) = (int *) malloc(P* sizeof(int));
    }

    int **C =(int **) malloc(N* sizeof(int*));
    if (C==NULL){
        printf("on a pas de memoire ");
        exit (0);
    }
    for (i=0 ; i<P ; i++){
        *(C+i) = (int *) malloc(P* sizeof(int));
    }

    for (i=0 ; i<N ;i++){
        for(j=0 ; j<M ; j++){
            printf("A[%d][%d] = ",i,j);
            scanf("%d", A[i]+j);
        }
    }
    for (i=0 ; i<M ;i++){
        for(j=0 ; j<P ; j++){
            printf("B[%d][%d] = ",i,j);
            scanf("%d",B[i]+j);
        }
    }
    int k=0 , sum=0 ;
    for (i=0 ; i<N ;i++){
        for(j=0 ; j<P ;j++){
            while(k!=M){
                sum += *(A[i]+k) * *(B[k++]+j);
            }
            *(C[i]+j) = sum;
            sum = k = 0;
        }
    }
    for (i=0;i<N;i++){
        for(j=0;j<P;j++){
            printf("C[%d][%d] = ",i,j);
            printf("%d\n",*(C[i]+j));
        }
    }
}