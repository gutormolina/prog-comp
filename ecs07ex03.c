#include <stdio.h>

typedef struct
{
    int x;
    int y;
} coord;

typedef struct
{
    coord infEsq;
    coord supDir;
} retangulo;

int main()
{
    int tam;
    printf("Informe a quantidade de retangulos a ser inserida: ");
    scanf("%d", &tam);
    retangulo dados[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("\nInforme as coordenadas x e y referentes ao canto inferior esquerdo do ponto %d: ", i);
        scanf("%d %d", &dados[i].infEsq.x, &dados[i].infEsq.y);
        printf("Informe as coordenadas x e y referentes ao canto superior direito do ponto %d: ", i);
        scanf("%d %d", &dados[i].supDir.x, &dados[i].supDir.y);
    }
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Coordenadas do retangulo %d:", i);
        printf("\n\tIE: %d %d", dados[i].infEsq.x, dados[i].infEsq.y);
        printf("\n\tID: %d %d", dados[i].supDir.x, dados[i].infEsq.y);
        printf("\n\tSE: %d %d", dados[i].infEsq.x, dados[i].supDir.y);
        printf("\n\tSD: %d %d\n\n", dados[i].supDir.x, dados[i].supDir.y);
    }
    printf("\n");
}