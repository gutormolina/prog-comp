#include <stdio.h>
#include <math.h>

#define MAXESCOLAS 5
#define MAXESTUDANTES 10

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
} escola;

typedef struct
{
    coord local;
} estudante;

escola listaescolas[MAXESCOLAS];
estudante listaestudantes[MAXESTUDANTES];

void questao01(int *qesc, int *qest);
escola questao02(int qesc);
void questao03(escola x);
void questao04(int qesc, int qest);

int main()
{
    int qtde_esc, qtde_est;
    questao01(&qtde_esc, &qtde_est);
    questao03(questao02(qtde_esc));
    questao04(qtde_esc, qtde_est);
    return 0;
}

void questao01(int *qesc, int *qest)
{
    scanf("%d", qesc);
    for (int i = 0; i < *qesc; i++)
    {
        scanf("%d %d %f %d", &listaescolas[i].local.x,
                             &listaescolas[i].local.y,
                             &listaescolas[i].raio,
                             &listaescolas[i].capac);
    }
    scanf("%d", qest);
    for (int i = 0; i < *qest; i++)
    {
        scanf("%d %d", &listaestudantes[i].local.x,
                       &listaestudantes[i].local.y);
    }
}

escola questao02(int qesc)
{
    int aux = 0;
    for (int i = 0; i < qesc; i++)
    {
        if (listaescolas[i].raio > listaescolas[aux].raio)
        {
            aux = i;
        }
    }
    return listaescolas[aux];
}

void questao03(escola x)
{
    printf("%d %d %f %d\n", x.local.x,
                          x.local.y,
                          x.raio,
                          x.capac);
}

void questao04(int qesc, int qest)
{
    for (int i = 0; i < qest; i++)
    {
        int aux = 0;
        printf("%d: ", i);
        for (int j = 0; j < qesc; j++)
        {
            int catetoA = listaestudantes[i].local.x - listaescolas[j].local.x;
            int catetoB = listaestudantes[i].local.y - listaescolas[j].local.y;
            if (listaescolas[j].raio > sqrt(pow(catetoA, 2) + pow(catetoB, 2)))
            {
                printf("%d ", j);
                aux++;
            }
        }
        if (aux == 0)
            {
                printf("-1");
            }
        printf("\n");
    }
}