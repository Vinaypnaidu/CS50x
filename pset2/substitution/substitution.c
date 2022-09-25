#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int sum = 0;
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
    string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    string key = argv[1];



    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    for (int i = 0; i <= 25; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters.\n");
            exit(1);
        }
    }
    for (int j = 0; j <= 25; j++)
    {
        for (int k = 0; k <= 25; k++)
        {
            if (key[j] == alpha[k])
            {
                check[k] = 1;
            }
            else if (tolower(key[j]) == alpha[k])
            {
                check[k] = 1;
            }
        }
    }
    for (int l = 0; l <= 25; l++)
    {
        sum = sum + check[l];
    }
    if (sum != 26)
    {
        printf("Key must contain 26 distinct characters.\n");

        exit(1);
    }
    string plain;
    plain = get_string("plaintext:");
    printf("ciphertext:");
    int m = 0;
    int n = 0;
    int p = 0;
    for (m = 0; m < strlen(plain); m++)
    {
        if (isalpha(plain[m]))
        {
            if (islower(plain[m]))
            {
                for (n = 0; n <= 25; n++)
                {
                    if (plain[m] == (tolower(alpha[n])))
                    {
                        printf("%c", tolower(key[n]));
                    }
                }
                n = 0;
            }
            else
            {
                for (p = 0; p <= 25; p++)
                {
                    if (plain[m] == (toupper(ALPHA[p])))
                    {
                        printf("%c", toupper(key[p]));
                    }
                }
                p = 0;
            }
        }
        else
        {
            putchar(plain[m]);
        }

    }
    printf("\n");
}