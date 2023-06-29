#include <stdio.h>
#include <math.h>

double somar(double num1, double num2);
double subtrair(double num1, double num2);
double dividir(double num1, double num2);
double multiplicar(double num1, double num2);
long fatorial(double num);

int main()
{

    int operacao;
    double num1, num2, num;

    do
    {
        do
        {
            printf("BEM VINDO A CALCULADORA EM C\n\n");
            printf("ESCOLHA UMA OPERACAO:\n\n");
            printf("1. Soma\n");
            printf("2. Subtracao\n");
            printf("3. Divisao\n");
            printf("4. Multiplicacao\n");
            printf("5. Fatorial\n");
            printf("6. Sair\n");
            scanf("%d", &operacao);
            switch (operacao)
            {
            case 1:
                printf("\nInsira o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Insira o segundo numero: ");
                scanf("%lf", &num2);
                printf("Resultado: %.2lf\n\n", somar(num1, num2));
                break;
            case 2:
                printf("\nInsira o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Insira o segundo numero: ");
                scanf("%lf", &num2);
                printf("Resultado: %.2lf\n\n", subtrair(num1, num2));
                break;
            case 3:
                printf("\nInsira o primeiro numero: ");
                scanf("%lf", &num1);
                do
                {
                    printf("Insira o segundo numero: ");
                    scanf("%lf", &num2);
                    if (num2 == 0)
                    {
                        printf("NAO E POSSIVEL FAZER DIVISAO POR ZERO.\n");
                    }
                } while (num2 == 0);
                printf("Resultado: %.2lf\n\n", dividir(num1, num2));
                break;
            case 4:
                printf("\nInsira o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Insira o segundo numero: ");
                scanf("%lf", &num2);
                printf("Resultado: %.2lf\n\n", multiplicar(num1, num2));
                break;
            case 5:
                printf("\nInsira o numero a ser realizado o fatorial: ");
                do
                {
                    scanf("%lf", &num);
                    if (num < 0)
                    {
                        printf("NAO E POSSIVEL REALIZAR FATORIAL DE NUMEROS NEGATIVOS\n");
                    }
                } while (num < 0);
                printf("Resultado: %.2ld\n\n", fatorial(round(num)));
                break;
            case 6:
                break;
            default:
                printf("OPERACAO INVALIDA!\n");
                printf("POR FAVOR DIGITE UM NUMERO DE 1 A 6\n\n");
                break;
            }
        } while (operacao < 0 || operacao > 6);
    } while (operacao != 6);
}

double somar(double num1, double num2)
{
    return num1 + num2;
}

double subtrair(double num1, double num2)
{
    return num1 - num2;
}

double dividir(double num1, double num2)
{
    return num1 / num2;
}

double multiplicar(double num1, double num2)
{
    return num1 * num2;
}

long fatorial(double num)
{
    double resultado = 1;
    for (double i = num; i > 0; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}