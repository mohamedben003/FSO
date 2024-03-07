#include<stdio.h>
#include<string.h>

int main(){
    char TABCH[5][50];
    for(int i=0 ; i<5 ;i++){
        printf("mot %d : ",i+1);
        scanf("%s",TABCH[i]);
    }
    for (int i=0 ; i<5 ; i++){
        for(int j=0 ; j<strlen(TABCH[i])/2 ; j++){
            char temp = TABCH[i][j];
            TABCH[i][j] = TABCH[i][strlen(TABCH[i])-j-1];
            TABCH[i][strlen(TABCH[i])-j-1] = temp;
        }
    }
    for(int i=0; i<5;i++){
        printf("%s\n",TABCH[i]);
    }
}
