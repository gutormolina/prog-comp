#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
    char conteudo;
    struct cel *prox;
} celula;

celula *cria(void);
void le_arquivo(celula *c);
void insere_fim(char x, celula *c);
int lista_vazia(celula *c);
char remove_inicio(celula *c);
char remove_fim(celula *c);

int main()
{
    celula *listaA, *listaB, *listaC;
    char removido;
    
    listaA = cria();
    listaB = cria();
    listaC = cria();
    
    le_arquivo(listaA);
    while (!lista_vazia(listaA))
    {
        removido = remove_inicio(listaA);
        printf("%c ", removido);
        insere_fim(removido, listaB);
    }
    printf("\n");
    while (!lista_vazia(listaB))
    {
        removido = remove_fim(listaB);
        printf("%c ", removido);
        insere_fim(removido, listaC);
    }
    printf("\n");
    while (!lista_vazia(listaC))
    {
        removido = remove_fim(listaC);
        printf("%c ", removido);
    }
    printf("\n");
    return 0;
}

celula *cria(void)
{
    celula *head = (celula *)malloc(sizeof(celula));
    
    head->prox = NULL;
    return head;
}

void le_arquivo(celula *c)
{
    FILE *fp;
    fp = fopen("exame.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }
    
    char letra;
    while (!feof(fp))
    {
        fscanf(fp, "%c ", &letra);
        insere_fim(letra, c);
    }
    fclose(fp);
}

void insere_fim(char x, celula *c)
{
    celula *novaCelula = (celula*)malloc(sizeof(celula));

    novaCelula->conteudo = x;
    novaCelula->prox = NULL;

    celula *p = c;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novaCelula;
}

int lista_vazia(celula *c)
{
    if (c->prox == NULL)
        return 1;
    else 
        return 0;     
}

char remove_inicio(celula *c)
{
    celula *rem = (celula *)malloc(sizeof(celula));

    rem = c->prox;
    char removido = rem->conteudo;
    
    c->prox = rem->prox;
    free(rem);
    return removido;
}

char remove_fim(celula *c)
{
    celula *rem = c,
           *ant = NULL;
    
    while (rem->prox != NULL)
    {
        ant = rem;
        rem = rem->prox;
    }
    char removido = rem->conteudo;
    
    ant->prox = NULL;
    free(rem);
    return removido;
}