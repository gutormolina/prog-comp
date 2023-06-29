#include <stdio.h>
#include <math.h>

int fatorial(int n);

int main()
{
    int n;
    do
    {
        printf("Digite o número a ser visualizado o fatorial: ");
        scanf("%d", &n);
        if (n < 0)
            printf("\nNão é possível realizar fatorial de números negativos!\n\n");
        printf("%d\n", fatorial(round(n)));
    } while (n < 0);
}

int fatorial(int n)
{
    int aux = 1;
    if (n <= 1)
    {
        return (1);
    }
    else
    {
        aux = n * fatorial(n - 1);
        return aux;
    }
}