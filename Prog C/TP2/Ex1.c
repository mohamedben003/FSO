#include <stdio.h>
#include <math.h>

double distance(double xa , double ya , double xb , double yb){
    double AB;
    AB = ((yb - ya)*(yb - ya)) + ((xb-xa)*(xb-xa));
    return sqrt(AB);
}

double main(){
    printf("%f",distance(1,1,7,7));
}