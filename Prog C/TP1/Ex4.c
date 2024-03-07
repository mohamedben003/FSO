#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char phrase[200];
    char **T = (char **) malloc(200 * sizeof(char *));
    if(T == NULL){
        printf("pas de mémoire !!");
        exit(1);
    }
    for (int i=0 ; i<200 ; i++){
        *(T+i) = (char *) malloc(200 * sizeof(char));
    }
    gets(phrase);
    int j =0 ;
    int k =0 ;
    for (int i=0 ; i<=strlen(phrase) ; i++){
        if (phrase[i] == ' ' || phrase[i] == '\t' || phrase[i] == '\n' || phrase[i] == '\0' ){
            T[j][k] = '\0' ;
            j++;
            k=0;
        } else {
            T[j][k] = phrase[i];
            k++;
        }
    }
    for(int i = 0 ; i<j ; i++){
        printf("%s \n",*(T+i));
    }
}