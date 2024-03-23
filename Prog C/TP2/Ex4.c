#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void crypt(char *A){
    int i;
    for(i=0 ; i<strlen(A) ; i++){
        if((*(A+i) >= 'a' && *(A+i) <= 'u') ||(*(A+i) >= 'A' && *(A+i) <= 'U')){
            *(A+i) += 5;
        }else if((*(A+i) >= 'v' && *(A+i) <= 'z') ||(*(A+i) >= 'V' && *(A+i) <= 'Z')){
            *(A+i) -= 21; 
        }
    }
}
void decrypt(char *A){
    int i;
    for(i=0 ; i<strlen(A) ; i++){
        if((*(A+i) >= 'f' && *(A+i) <= 'z') ||(*(A+i) >= 'F' && *(A+i) <= 'Z')){
            *(A+i) -= 5;
        }else if((*(A+i) >= 'a' && *(A+i) <= 'e') ||(*(A+i) >= 'A' && *(A+i) <= 'e')){
            *(A+i) += 21; 
        }
    }
}


int main(){
    char *Message = (char *)malloc(100*sizeof(char));
    if(Message==NULL){
        puts("pas de memoire !!");
    }
    gets(Message);
    crypt(Message);
    puts(Message);
    decrypt(Message);
    puts(Message);

}