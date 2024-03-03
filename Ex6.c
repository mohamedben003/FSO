#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *v ,*v1 ;
    v = (char *) malloc (24*sizeof(char));
    if (v==NULL){
        puts("pas de memoire !!");
    }
    puts("entrez le verbe :");
    gets(v);
    int a = 0;
    if(strlen(v)<4){
        puts("pas un verbe !!");
        exit(1);
    }
    if (v[strlen(v)-2] != 'e' ){
        puts("le verbe ne termine pas avec 'er' !!");
        exit(1);
    }else{
        if(v[strlen(v)-1] != 'r'){
            puts("le verbe ne termine pas avec 'er' !!");
            exit(1);
        }else{
            for(int i=0 ;i<strlen(v)-1;i++){
                v1[i] = v[i];
            }
        }
    }
    
    puts(v1);
    
}