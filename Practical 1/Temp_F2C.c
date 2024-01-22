#include<stdio.h>

int main()
{
    float C,F;

    printf("Enter Temperature in Farenheit:");
    scanf("%f",&F);

    C=(F-32)/1.8;

    printf("The Temperatur in Celcius:%.2f Degree",C);

    return 0;

} 