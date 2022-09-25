#include<stdio.h>
#include<cs50.h>
int main(void)
{
    long n, t, c;
    int count = 0, rem = 0, flag = 0, sum = 0, sum1 = 0, rem1 = 0;
    n = get_long("Number:");
    t = n;
    c = t;
    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    if (!(count == 13 || count == 15 || count == 16))
    {
        printf("INVALID\n");
    }
    else
    {
        while (t > 0)
        {
            rem = t % 10;
            t =  t / 10;
            if (flag == 1)
            {
                if (rem >= 5 && rem <= 9)
                {
                    rem = rem * 2;
                    while (rem > 0)
                    {
                        rem1 = rem % 10;
                        sum1 = sum1 + rem1;
                        rem = rem / 10;
                    }
                    sum = sum + sum1;
                    sum1 = 0;
                    flag = 0;
                }
                else
                {
                    sum = sum + (2 * rem);
                    flag = 0;
                }
            }
            else
            {
                sum = sum + rem;
                flag = 1;
            }
        }
        if (sum % 10 == 0)
        {
            if (count == 15)
            {
                if (c >= 340000000000000 && c <= 349999999999999)
                {
                    printf("AMEX\n");
                }
                else if (c >= 370000000000000 && c <= 379999999999999)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }

            }
            if (count == 16)
            {
                if (c >= 4000000000000000 && c <= 4999999999999999)
                {
                    printf("VISA\n");
                }
                else if (c >= 5100000000000000 && c <= 5599999999999999)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }

            }
            if (count == 13)
            {
                if (c >= 4000000000000 && c <= 4999999999999)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    return 0;

}