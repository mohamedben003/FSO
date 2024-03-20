#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
typedef struct {
    int num;
    int den;
}ratio;

ratio saisie(){
    ratio a; 
    printf("enter le num :");
    scanf("%d",&a.num);
    printf("enter le den :");
    scanf("%d",&a.den);
    return a;
}

int pgcd(int a , int b){
    int x;
    int min;
    if(a<b){
        min = a;
    }else{
        min = b;
    }
    for(i=min ; i>0 ; i--){
        if(a%i == 0 && b%i == 0){
           x=i;
           break;
        }
    }
    return x;
}

void affichage(ratio y){
    i = pgcd(y.num,y.den);
    if(y.den/i == 1 ){
        printf("%d\n",y.num/i);
        return;
    }
    printf("%d\n--\n%d\n",y.num/i , y.den/i);
}

ratio somme(ratio a, ratio b){
    ratio y;
    if (a.den == b.den){
        y.num = a.num + b.num;
        y.den = a.den;
    }else{
        y.den = a.den * b.den;
        y.num = a.num * b.den + b.num * a.den;
    }
    return y;
}

ratio sous(ratio a , ratio b){
    ratio y;
    if (a.den == b.den){
        y.num = a.num - b.num;
        y.den = a.den;
    }else{
        y.den = a.den * b.den;
        y.num = (a.num * b.den) - (b.num * a.den);
    }
    return y;
}

ratio mul(ratio a , ratio b){
    ratio y;
    y.num = a.num * b.num;
    y.den = a.den * b.den;
    return y;
}

ratio divi(ratio a , ratio b){
    ratio y;
    y.num = a.num * b.den;
    y.den = a.den * b.num;
    return y;
}

int main(){
    ratio x = saisie();
    ratio y = saisie();
    ratio z ;
    z = somme(x,y);
    affichage(z);
    puts("////////////");
    z = sous(x,y);
    affichage(z);
    puts("////////////");
    z = mul(x,y);
    affichage(z);
    puts("////////////");
    z = divi(x,y);
    affichage(z);
}