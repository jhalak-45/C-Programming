#include<stdio.h>

int main(){
    int r;
    float volume;
    float pi=3.14;
    printf("Enter a Radius of Sphere: ");
    scanf("%d",&r);

    volume=(4.0*pi*r*r*r)/3.0;

    printf("The Volume of sphere is: %.2f",volume);

    return 0;

}