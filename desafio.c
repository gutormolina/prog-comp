#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prod
{
    char nome[100];
    double preco;
    int id;
    struct prod *prox;
};

typedef struct prod produto;
void addProduto(produto *start);
void remProduto(produto *start);
void imprime(produto *start);
void carregaLista(produto *start);
void salvaLista(produto *start);
void sair(produto *start);

int main()
{
    produto *head = (produto *)malloc(sizeof(produto));
    int menu;
    for (;;)
    {
        do
        {
            printf("\n");
            printf("1- Adicionar produto\n");
            printf("2- Remover produto\n");
            printf("3- Imprimir lista\n");
            printf("4- Carregar lista do arquivo \"produtos.bin\"\n");
            printf("5- Salvar lista atual no arquivo \"produtos.bin\"\n");
            printf("6- Sair\n\n");
            scanf("%d", &menu);
        } while (menu < 1 || menu > 6);
        switch (menu)
        {
        case 1:
            addProduto(head);
            break;
        case 2:
            remProduto(head);
            break;
        case 3:
            imprime(head);
            break;
        case 4:
            carregaLista(head);
            break;
        case 5:
            salvaLista(head);
            break;
        case 6:
            sair(head);
            break;
        }
    }
    return 0;
}

void addProduto(produto *start)
{
    produto *prod = (produto *)malloc(sizeof(produto));
    
    printf("Insira o nome do produto: ");
    getchar();
    fgets(prod->nome, 100, stdin);
    printf("Insira o preço do produto: ");
    scanf("%lf", &prod->preco);
    printf("Insira o ID do produto: ");
    scanf("%d", &prod->id);

    produto *aux = start;
    while (aux->prox)
    {
        if (aux->prox->preco > prod->preco)
        {
            break;
        }
        aux = aux->prox;
    }
    prod->prox = aux->prox;
    aux->prox = prod;
}


void remProduto(produto *start)
{
    produto *p, *q;
    int rem;
    
    printf("Insira o ID do produto que deseja remover: ");
    scanf("%d", &rem);
    p = start;
    q = start->prox;
    while ((q != NULL) && (q->id != rem))
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)
    {
        p->prox = q->prox;
        free(q);
    }
}

void imprime(produto *start)
{
    produto *p;
    
    for (p = start->prox; p != NULL; p = p->prox)
    {
        printf("NOME: %s", p->nome);
        printf("PRECO: %.02lf\n", p->preco);
        printf("ID: %d\n\n", p->id);
    }
}

void carregaLista(produto *start)
{
    FILE *arquivo = fopen("produtos.bin", "rb");
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    produto *atual = start;
    while (1)
    {
        produto *prod = (produto *)malloc(sizeof(produto));
        int ler = fread(prod, sizeof(produto), 1, arquivo);
        if (ler < 1)
        {
            free(prod);
            break;
        }
        atual->prox = prod;
        atual = prod;
    }
}

void salvaLista(produto *start)
{
    produto *p;
    FILE *arquivo = fopen("produtos.bin", "wb");
    
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    p = start->prox;
    while (p != NULL)
    {
        fwrite(p, sizeof(produto), 1, arquivo);
        p = p->prox;
    }
    fclose(arquivo);
}

void sair(produto *start)
{
    produto *atual = start, *prox = atual->prox;
    
    for (start; start != NULL; start = start->prox)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    exit(0);
}