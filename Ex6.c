#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *v ,*v1,*v2 ;
    v2 = (char *) malloc (30*sizeof(char));
    v = (char *) malloc (24*sizeof(char));
    v1 = (char *) malloc(22*sizeof(char));
    if (v==NULL || v1==NULL || v2==NULL){
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
            for(int i=0 ;i<=strlen(v)-2;i++){
                v1[i] = v[i];
            }
            v1[strlen(v)-2]='\0';
        }
    }
    v2[0]='\0';
    strcat(v2,"je ");
    strcat(v2,v1);
    strcat(v2,"e");
    puts(v2);

    v2[0]='\0';
    strcat(v2,"tu ");
    strcat(v2,v1);
    strcat(v2,"es");
    puts(v2);
    
    v2[0]='\0';
    strcat(v2,"il ");
    strcat(v2,v1);
    strcat(v2,"e");
    puts(v2);

    v2[0]='\0';
    strcat(v2,"nous ");
    strcat(v2,v1);
    strcat(v2,"ons");
    puts(v2);

    v2[0]='\0';
    strcat(v2,"vous ");
    strcat(v2,v1);
    strcat(v2,"ez");
    puts(v2);

    v2[0]='\0';
    strcat(v2,"elles ");
    strcat(v2,v1);
    strcat(v2,"ent");
    puts(v2);
}