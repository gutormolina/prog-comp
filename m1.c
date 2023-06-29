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
    printf("Insira a quantidade de escolas: ");
    scanf("%d", &*qesc);
    for (int i = 0; i < *qesc; i++)
    {
        printf("Insira as informações (coordenadas, raio e capacidade) para escola %d: ", i);
        scanf("%d %d %f %d", &listaescolas[i].local.x,
            &listaescolas[i].local.y,
            &listaescolas[i].raio,
            &listaescolas[i].capac
        );
    }
    printf("Insira a quantidade de estudantes: ");
    scanf("%d", &*qest);
    for (int i = 0; i < *qest; i++)
    {
        printf("Insira as informações (coordenadas) para estudante %d: ", i);
        scanf("%d %d", &listaestudantes[i].local.x, &listaestudantes[i].local.y);
    }
}

escola questao02(int qesc)
{
    float aux = 0;
    int ind;
    for (int i = 0; i < qesc; i++)
    {
        if (listaescolas[i].raio > aux)
        {
            aux = listaescolas[i].raio;
            ind = i;
        }
    }
    return listaescolas[ind];
}

void questao03(escola x)
{
    printf("Informações da escola com maior raio (%d): ", x);
    printf("%d %d %f %d", x.local.x, x.local.y, x.raio, x.capac);
    printf("\n");
}

void questao04(int qesc, int qest)
{
    for (int i = 0; i < qest; i++)
    {
        int disp = 0;
        printf("%d: ", i);
        for (int j = 0; j < qesc; j++)
        {
            float dist = 
                sqrt(pow(listaescolas[j].local.x - listaestudantes[i].local.x, 2) + 
                pow(listaescolas[j].local.y - listaestudantes[i].local.y, 2));
            if (dist < listaescolas[j].raio)
            {
                printf("%d ", j);
                disp++;
            }
        }
        if (disp == 0)
        {
            printf("%d", -1);
        }    
        printf("\n");
    }
}