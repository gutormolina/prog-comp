#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} coord;

typedef struct antena
{
    coord local;
    float raio;
    struct antena *prox;
} antena;

typedef struct usuario
{
    coord local;
    struct usuario *prox;
} usuario;

void lerArquivo(FILE *entrada);
void insereDados(usuario *headUser, antena *headAntena);
void imprimeQualidade();

int main()
{
    usuario *headUser;
    antena *headAntena;
    headUser = (usuario *)malloc(sizeof(usuario));
    headAntena = (antena *)malloc(sizeof(antena));
    FILE *entrada, *saida;
    headUser->prox = NULL;
    headAntena->prox = NULL;
    entrada = fopen("entrada.txt", "r");
    saida = fopen("saida.txt", "w");
    int numAnt = 0;
    fscanf(entrada,"%d", &numAnt);
    for (int i = 0; i < numAnt; i++)
    {
        antena antenaAtual;
        fscanf(entrada,"%d %d %f", &antenaAtual.local.x, &antenaAtual.local.y, &antenaAtual.raio);
        antena *current = headAntena;

        while(current->prox != NULL) {
            current = current->prox;
        }

        current->prox = (antena *)malloc(sizeof(antena));
        current->prox->local.x = antenaAtual.local.x;
        current->prox->local.y = antenaAtual.local.y;
        current->prox->raio = antenaAtual.raio;
        current->prox->prox = NULL;
    }
}