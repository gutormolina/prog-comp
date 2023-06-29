#include <stdio.h>
#include <stdlib.h>

typedef struct _celula
{
    int dado;
    struct _celula *prox;
} Celula;

Celula *criaNo(int dado)
{
    Celula *novoNo = (Celula *)malloc(sizeof(Celula));

    novoNo->dado = dado;
    novoNo->prox = NULL;

    return novoNo;
}

void insereOrdenado(int dado, Celula *lista)
{
    Celula *novaCelula = criaNo(dado);

    Celula *pA = lista;
    Celula *p = lista->prox;

    while (p != NULL && dado > p->dado)
    {
        pA = p;
        p = p->prox;
    }

    pA->prox = novaCelula;
    novaCelula->prox = p;
}

void imprimeLista(Celula *lista)
{
    Celula *p = lista->prox;

    while (p != NULL)
    {
        printf("%d ", p->dado);
        p = p->prox;
    }
}

int main(int argc, char const *argv[])
{
    Celula *listas[10];

    // Cria as cabeças
    for (int i = 0; i < 10; i++)
    {
        listas[i] = criaNo(0);
    }

    FILE *fp = fopen("entrada.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(0);
    }

    int num;
    while (!feof(fp))
    {
        fscanf(fp, "%d ", &num);

        if (num < 10)
            insereOrdenado(num, listas[0]);
        else if (num < 20)
            insereOrdenado(num, listas[1]);
        else if (num < 30)
            insereOrdenado(num, listas[2]);
        else if (num < 40)
            insereOrdenado(num, listas[3]);
        else if (num < 50)
            insereOrdenado(num, listas[4]);
        else if (num < 60)
            insereOrdenado(num, listas[5]);
        else if (num < 70)
            insereOrdenado(num, listas[6]);
        else if (num < 80)
            insereOrdenado(num, listas[7]);
        else if (num < 90)
            insereOrdenado(num, listas[8]);
        else if (num < 100)
            insereOrdenado(num, listas[9]);

        // // Jeito mais rápido (calcula o índice)   
        // int index = num / 10;

        // insereOrdenado(num, listas[index]);
    }

    FILE *fo = fopen("saida.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        for (Celula *p = listas[i]->prox; p != NULL; p = p->prox)
        {
            fprintf(fo, "%d ", p->dado);
        }
    }

    return 0;
}