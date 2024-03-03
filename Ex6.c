#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *v ,*v1,*v2 ;
    v2 = (char *) malloc (30*sizeof(char));
    v = (char *) malloc (24*sizeof(char));
    
    if (v==NULL || v1==NULL || v2==NULL){
        puts("pas de memoire !!");
    }
    puts("entrez le verbe :");
    gets(v);
    v1 = (char *) malloc((strlen(v)-3)*sizeof(char));
        if (v1==NULL){
        puts("pas de memoire !!");
    }
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
            for(int i=0 ;i<strlen(v)-2;i++){
                v1[i] = v[i];
            }
        }
    }
    v2[0]='\0';
    strcat(v2,"je ");
    strcat(v2,v1);
    strcat(v2,"e");
    puts(v2);
    
}