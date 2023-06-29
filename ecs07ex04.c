#include <stdio.h>

typedef struct
{
    int x;
    int y;
} coord;

typedef struct
{
    coord ponto1;
    coord ponto2;
    coord ponto3;
} triangulo;

int main()
{
    int tam;
    printf("Informe a quantidade de triangulos a ser inserida: ");
    scanf("%d", &tam);
    triangulo dados[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("\nInforme as coordenadas x e y para ponto 1 do triangulo %d: ", i);
        scanf("%d %d", &dados[i].ponto1.x, &dados[i].ponto1.y);
        printf("Informe as coordenadas x e y para ponto 2 do triangulo %d: ", i);
        scanf("%d %d", &dados[i].ponto2.x, &dados[i].ponto2.y);
        printf("Informe as coordenadas x e y para ponto 3 do triangulo %d: ", i);
        scanf("%d %d", &dados[i].ponto3.x, &dados[i].ponto3.y);
    }
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Informações do triângulo %d", i);
        printf("\n\tPonto 1: %d %d", dados[i].ponto1.x, dados[i].ponto1.y);
        printf("\n\tPonto 2: %d %d", dados[i].ponto2.x, dados[i].ponto2.y);
        printf("\n\tPonto 3: %d %d\n\n", dados[i].ponto3.x, dados[i].ponto3.y);
    }
    printf("\n");
}