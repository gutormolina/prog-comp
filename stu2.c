#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    int dado;
    struct cel *prox;
} Celula;

Celula *criaNo(int x);
void insereOrdem(int x, Celula *lista);

int main()
{
    Celula *head[10];
    for (int i = 0; i < 10; i++)
    {
        head[i] = criaNo(0);
    }
    
    FILE *fi = fopen("entrada.txt", "r");
    int num = 0, index = 0;
    while (!feof(fi))
    {
        fscanf(fi, "%d", &num);
        index = num / 10;
        insereOrdem(num, head[index]);
    }
    fclose(fi);
    FILE *fo = fopen("saida.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        for (Celula *p = head[i]->prox; p != NULL; p = p->prox)
        {
            fprintf(fo, "%d ", p->dado);
        }
    }
    fclose(fo);
}

Celula *criaNo(int x)
{
    Celula *novoNo = (Celula *)malloc(sizeof(Celula));

    novoNo->dado = x;
    novoNo->prox = NULL;

    return novoNo;
}

void insereOrdem(int x, Celula *lista)
{
    Celula *novaCelula = criaNo(x);
    Celula *p = lista->prox, 
           *pA = lista;
    while (p != NULL && x > p->dado)
    {
        pA = p;
        p = p->prox;
    }
    
    pA->prox = novaCelula;
    novaCelula->prox = p;
}