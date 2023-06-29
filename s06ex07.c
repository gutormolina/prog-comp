#include <stdio.h>

int retirar(int numeros[], int n);

int main()
{
    int n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    int numeros[n];
    for (int i = 0; i < n; i++)
    {
        printf("Insira o valor para posição %d do vetor: ", i);
        scanf("%d", &numeros[i]);
    }
    retirar(numeros, n);
    printf("Vetor após retirar números iguais: "); 
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeros[i]);
    }
}

int retirar(int numeros[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (i + 1); j < n;)
        {
            if (numeros[j] == numeros[i])
            {
                for (int k = j; k < n; k++)
                {
                    numeros[k] = numeros[k + 1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
}