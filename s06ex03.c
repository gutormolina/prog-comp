#include <stdio.h>

int primo(int num);

int main()
{
    int num;
    printf("Insira o número a ser verificado se é primo: ");
    scanf("%d", &num);
    primo(num);
}

int primo(int num)
{
    int div = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0) {
            div++;
        }
    }
    if (div <= 2) {
        printf("\nO número é primo.\n");
    }
    else {
        printf("\nO número não é primo.\n");
    }
}