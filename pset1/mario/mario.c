#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int n = 0, i = 0, j = 0, k = 0;
    do
    {
        n = get_int("Height:\n");
    }
    while (!(n >= 1 && n <= 8));
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - 1; j++)
        {
            printf(" ");
        }
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
