#include <stdio.h>

int main()
{

    int num, temp=0,i;

    printf("Enter Number to Check Prime or not: \t");
    scanf("%d", &num);

    for (i = 2; i < num/2; i++){
        if (num % i == 0){
            temp++;
            break;
        }
    }

    if (temp == 0){
        printf("%d is a Prime number", num);

    }
    else{
        printf("%d is not a Prime number", num);
    }

    return 0;
}