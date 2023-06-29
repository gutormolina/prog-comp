#include <stdio.h>

typedef struct
{
    int x;
    int y;
} coord;

int main()
{
    int tam;
    printf("Informe a quantidade de pontos a ser inserida: ");
    scanf("%d", &tam);
    printf("\n");
    coord pontos[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("Informe as coordenadas x e y do ponto %d: ", i);
        scanf("%d %d", &pontos[i].x, &pontos[i].y);
    }
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Coordenadas do ponto %d: %d %d\n", i, pontos[i].x, pontos[i].y);
    }
    printf("\n");
}