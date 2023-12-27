#include <stdio.h>

int main()
{
    int n, i, count;

    printf("Enter the number to check prime or not:\n\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }

    }
    if (count==2)
    {
        printf("Your Entered Number is Prime:");
    }
    else{
        printf("Your Entered Number is not Prime");
    }

    return 0;

}
