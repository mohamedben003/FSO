#include <stdio.h>
#include <string.h>

int main(){
    char chaine[] = "hello NIGGA !!!";
    for (int i=0 ; i<strlen(chaine) ; i++){
        if (chaine[i]>='a' && chaine[i] <= 'z'){
            chaine[i] -= 32;
        } else if (chaine[i]>='A' && chaine[i] <= 'Z') {
            chaine[i] += 32;
        }
    }
    printf("%s",chaine);
}