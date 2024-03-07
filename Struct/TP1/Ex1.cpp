#include <stdio.h>

int main(){
    int a = -2;
    int b = a++;
    int c = --b;
    int *p1 = &a;
    int *p2 = &b;
    printf("a = %d \nb = %d \nc = %d \np1 = %d \np2 = %d \n",a,b,c,*p1,*p2);
    *p1 = (*p2)+++1;
    printf("a = %d \nb = %d \nc = %d \np1 = %d \np2 = %d \n",a,b,c,*p1,*p2);
    p1 = p2;
    printf("a = %d \nb = %d \nc = %d \np1 = %d \np2 = %d \n",a,b,c,*p1,*p2);
    c*=-*p2;
    printf("a = %d \nb = %d \nc = %d \np1 = %d \np2 = %d \n",a,b,c,*p1,*p2);
}

