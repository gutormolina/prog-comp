#include <stdio.h>
#include <math.h>

#define MAXDELEGACIAS 5
#define MAXVITIMAS 10

typedef struct
{  
    int x;
    int y;
} coord;

typedef struct
{
    coord local;
    float raio;
    int capac;
} delegacia; 

typedef struct
{
    coord local;
} vitima;

delegacia listadelegacias[MAXDELEGACIAS];
vitima listavitimas[MAXVITIMAS];

void questao01(int *qdel, int *qvit);
vitima questao02(int del, int vit);
void questao03(vitima x);
void questao04(int qdel, int qvit);
float dist(int x1, int y1, int x2, int y2);

int main()
{
    int qtde_del, qtde_vit;
    questao01(&qtde_del, &qtde_vit);
    questao03(questao02(qtde_del, qtde_vit));
    questao04(qtde_del, qtde_vit);
    return 0;
}

void questao01(int *qdel, int *qvit)
{
    printf("Insira o número de delegacias: ");
    scanf("%d", &*qdel);
    for (int i = 0; i < *qdel; i++)
    {
        printf("Insira os dados para delegacia %d: ", i);
        scanf("%d %d %f %d", &listadelegacias[i].local.x, &listadelegacias[i].local.y,
              &listadelegacias[i].raio, &listadelegacias[i].capac);
    }
    printf("Insira o número de vítimas: ");
    scanf("%d", &*qvit);
    for (int i = 0; i < *qvit; i++)
    {
        printf("Insira os dados para vítima %d: ", i);
        scanf("%d %d", &listavitimas[i].local.x, &listavitimas[i].local.y);
    }
}

vitima questao02(int del, int vit)
{
    float menorDistancia = 10000;
    int menorIndice;
    for (int i = 0; i < vit; i++)
    {
        for (int j = 0; j < del; j++)
        {
            float distancia = dist(listadelegacias[j].local.x, listadelegacias[j].local.y,
                                   listavitimas[i].local.x, listavitimas[i].local.y);
            if (distancia < menorDistancia)
            {
                menorDistancia = distancia;
                menorIndice = i;
            }
        }
    }
    return listavitimas[menorIndice];
}

void questao03(vitima x)
{
    printf("%d %d\n", x.local.x, x.local.y);
}

float dist(int x1, int y1, int x2, int y2)
{
    float catetoX = pow(x1 - x2, 2);
    float catetoY = pow(y1 - y2, 2);
    float hipotenusa = sqrt(catetoX + catetoY);
    return hipotenusa;
}

void questao04(int qdel, int qvit)
{
    
}