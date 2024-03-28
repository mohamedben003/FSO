#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i , j ;
    char *verb = (char *)malloc(30*sizeof(char));
    char *cong = (char *)malloc(40*sizeof(char));
    char *v =(char *)malloc(30*sizeof(char));
    if(verb == NULL||cong == NULL||v == NULL){
        puts("pas de memo !!");
    }
    gets(verb);
    if(strlen(verb)<4){
        puts("pas un verb !");
        exit(1);
    }
    cong[0] ='\0';
    v[0]='\0';
    if(verb[strlen(verb)-2] == 'e' && verb[strlen(verb)-1] == 'r'){
        for(i=0 ; i<strlen(verb)-1 ; i++){
            v[i] = verb[i];
        }
        v[i]='\0';
    }else{
        puts("pas un verb du 1er groupe !!");
        exit(1);
    }
    strcat(cong , "je ");
    strcat(cong ,v);
    puts(cong);
    cong[0] ='\0';
    strcat(cong , "tu ");
    strcat(cong ,v);
    strcat(cong ,"s");
    puts(cong);
    cong[0] ='\0';
    strcat(cong , "il ");
    strcat(cong ,v);
    puts(cong);
    cong[0] ='\0';
    strcat(cong , "nous ");
    strcat(cong ,v);
    strcat(cong ,"ons");
    puts(cong);
    cong[0] ='\0';
    strcat(cong , "vous ");
    strcat(cong ,v);
    strcat(cong ,"z");
    puts(cong);
    cong[0] ='\0';
    strcat(cong , "ils ");
    strcat(cong ,v);
    strcat(cong ,"nt");
    puts(cong);
}