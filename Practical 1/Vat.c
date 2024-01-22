#include<stdio.h>

int main(){
    int amount;
    float withVat;
    int vatRate=13; //vat in percentage

    printf("Enter an amount: ");
    scanf("%d",&amount);

    withVat= amount+((amount*vatRate)/100);

    printf("With VAT added amount is: %.2f",withVat);

    return 0;

}