#include <stdio.h>

typedef struct
{
    int x;
    int y;
} coord;

typedef struct
{
    coord centro;
    float raio;
} circulo;

int main()
{
    int tam;
    printf("Informe a quantidade de circulos a serem digitados: ");
    scanf("%d", &tam);
    printf("\n");
    circulo dados[tam];
    for (int i = 0; i < tam; i++)
    {
        printf("Informe as coordenadas x e y do ponto %d e seu raio: ", i);
        scanf("%d %d %f", &dados[i].centro.x, &dados[i].centro.y, &dados[i].raio);
    }
    printf("\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Ponto central e raio do ponto %d: %d %d %f\n", 
            i, dados[i].centro.x, dados[i].centro.y, dados[i].raio
        );
    }
    printf("\n");
}