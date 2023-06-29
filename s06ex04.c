#include <stdio.h>

void amigos(int a, int b);

int main()
{
    int a, b;
    printf("Insira A: ");
    scanf("%d", &a);
    printf("Insira B: ");
    scanf("%d", &b);
    amigos(a, b);
}

void amigos(int a, int b)
{
    int adiv = 0, bdiv = 0;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            adiv += i;
        }
    }
    for (int i = 1; i < b; i++)
    {
        if (b % i == 0)
        {
            bdiv += i;
        }
    }
    if (a == bdiv && b == adiv)
    {
        printf("\nOs números são amigos.\n");
    }
    else
    {
        printf("\nOs números não são amigos.\n");
    }
}