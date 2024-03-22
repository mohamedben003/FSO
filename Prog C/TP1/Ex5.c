#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i , j;
    char **A = (char **) malloc(5*sizeof(char*));
    char **B = (char **) malloc(5*sizeof(char*));
    char **FUS = (char **) malloc(10*sizeof(char*));
    if(A == NULL || B== NULL || FUS == NULL){
        printf("pas de mémoire !!");
        exit(1);
    }
    for(i=0 ; i<5 ; i++){
        *(A+i) = (char *)malloc(20*sizeof(char));
    }
    for(i=0 ; i<5 ; i++){
        *(B+i) = (char *)malloc(20*sizeof(char));
    }
    printf("enter les donnee de A : \n");
    for(i=0 ; i<5 ; i++){
        scanf("%s",*(A+i));
    }
    printf("enter les donnee de B : \n");
    for(i=0 ; i<5 ; i++){
        scanf("%s",*(B+i));
    }
    printf("le tableau FUS : \n");
    for(i=0 ; i<5 ; i++){
        *(FUS+i) = *(A+i);
        *(FUS+i+5) = *(B+i);
    }
    //tri : 
    char *temp;
    for(i=0 ; i<9 ; i++){
        for(j=i+1 ; j<10 ; j++){
            if(strcmp(*(FUS+i),*(FUS+j)) > 0  ){
                strcpy(temp , *(FUS+i));
                strcpy(*(FUS+i), *(FUS+j));
                strcpy(*(FUS+j), temp);
            }
        }
    }
    for(i=0 ; i<10 ; i++){
        printf("%s\t",*(FUS+i));
    }
}
