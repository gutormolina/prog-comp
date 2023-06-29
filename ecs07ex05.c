#include <stdio.h>

#define maxpontos 10

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

coord pontos[maxpontos];
retangulo envelope;

void ler(int *qtdp);
retangulo envelopar(int qtdp);

int main()
{
    int qtd_p;
    ler(&qtd_p);
    envelopar(qtd_p);
    printf("Coordenadas do envelope que cobre todos os pontos:");
    printf("\n\tPonto IE: %d %d", envelope.infEsq.x, envelope.infEsq.y);
    printf("\n\tPonto SD: %d %d\n", envelope.supDir.x, envelope.supDir.y);
	return 0;
}

void ler(int *qtdp)
{
    printf("Informe a quantidade de pontos a ser lida: ");
    scanf("%d", qtdp);
    for (int i = 0; i < *qtdp; i++)
    {
        printf("\nInsira as coord x e y para o ponto %d: ", i);
        scanf("%d %d", &pontos[i].x, &pontos[i].y);
    }
}

retangulo envelopar(int qtdp) 
{
    int menorX = pontos[0].x, menorY = pontos[0].y,
        maiorX = pontos[0].x, maiorY = pontos[0].y;
    for (int i = 1; i < qtdp; i++)
    {
        if (pontos[i].x < menorX)
        {
            menorX = pontos[i].x;
        }
        if (pontos[i].x > maiorX)
        {
            maiorX = pontos[i].x;
        }
        if (pontos[i].y < menorY)
        {
            menorY = pontos[i].y;
        }
        if (pontos[i].y > maiorY)
        {
            maiorY = pontos[i].y;
        }
    }
    envelope.infEsq.x = menorX; envelope.infEsq.y = menorY;
    envelope.supDir.x = maiorX; envelope.supDir.y = maiorY;
    return envelope;
}