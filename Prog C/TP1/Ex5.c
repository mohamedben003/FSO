#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 200 , M, P , i , j ;
    printf("M = ");
    scanf("%d",&M);
    printf("P = ");
    scanf("%d",&P);
    getchar();
    char **A = (char **) malloc(M * sizeof(char*));
    char **B = (char **) malloc(P * sizeof(char*));
    char **FUS = (char **) malloc((M+P) * sizeof(char*));
    if(A == NULL || B== NULL || FUS == NULL){
        printf("pas de mémoire !!");
        exit(1);
    }
    for (i=0 ; i<M ; i++){
        *(A+i) = (char *) malloc(N * sizeof(char));
    }
    for (i=0 ; i<P ; i++){
        *(B+i) = (char *) malloc(N * sizeof(char));
    }
    for (i=0 ; i<M+P ; i++){
        *(FUS+i) = (char *) malloc((N+N) * sizeof(char));
    }
    printf("les donnee de A : \n");
    for(i=0; i<M ;i++){
        gets(*(A+i));
    }
            for(i=0 ; i<(M) ; i++){
        printf("%s \t",*(A+i));
    }
    printf("\n");
    printf("les donnee de B : \n");
    for(i=0 ; i<P ; i++){
        gets(*(B+i));
    }
            for(i=0 ; i<(P) ; i++){
        printf("%s \t",*(B+i));
    }
    printf("\n");
    for(i=0 ; i<(M) ; i++){
        *(FUS+i) = *(A+i);
    }
    for(i=0 ; i<(P) ; i++){
        *(FUS+i+M) = *(B+i);
    }
    printf("le resultat : \n");    
    for(i=0 ; i<(M+P) ; i++){
        printf("%s \t",*(FUS+i));
    }
}
