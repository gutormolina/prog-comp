#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PALAVRAS 18
#define TAM 100

typedef struct
{
  char palavraEscolhida[TAM];
  char palavraImpressa[TAM];
  char descoberto[TAM];
  char dica[TAM];
  int letrasRestantes;
  int chancesRestantes;
} MatchData;

void inicializarDados(int escolha);
int processarDados(char letra);
void separaDica();
int checarLetra(char letra, char tentativas[]);

char const tabelaDePalavras[NUM_PALAVRAS][TAM] = {
    "SOL$Estrela",
    "JATOBA$Fruta",
    "BOLO$Doce",
    "GUITARRA$Instrumento musical",
    "COMPUTADOR$Equipamento tecnologico",
    "VISAO$Um dos sentidos",
    "PISTACHE$Sabor de sorvete",
    "BARCO$Meio de transporte",
    "ANIVERSARIO$Comemoracao",
    "GIRASSOL$Flor",
    "BALAO$Encontrado em festas",
    "CHUVA$Clima",
    "JACARE$Animal com dentes afiados",
    "PINGUIM$Animal com asas",
    "PIZZA$Comida italiana",
    "BICICLETA$Veiculo de duas rodas",
    "MISTERIO$Algo que e desconhecido",
    "ESTACAO$Ponto de partida ou chegada"
    };

MatchData data;

int main(void)
{
  printf("\nJogo de Forca\n\n");
  srand(time(NULL));
  int sorteio = rand() % NUM_PALAVRAS, i = 0, verif;
  inicializarDados(sorteio);
  char palpite, aux[TAM] = {};
  for (data.chancesRestantes = 10; data.chancesRestantes >= 0;)
  {
    if (data.letrasRestantes == 0)
    {
      printf("%s\n", data.descoberto);
      printf("Voce venceu! Parabens!\n");
      exit(0);
    }
    printf("DICA: %s\n\n", data.dica);
    printf("Chances: %d | Letras restantes: %d\n\n", data.chancesRestantes, data.letrasRestantes);
    printf("%s\n\n", data.descoberto);
    printf("Seu palpite: ");
    do
    {
      scanf(" %c", &palpite);
      palpite = toupper(palpite);
      verif = checarLetra(palpite, aux);
      aux[i] = palpite;
      if (palpite == '0')
      {
        printf("Voce saiu.\n");
        exit(0);
      }
      i++;
      if (verif > 0)
      {
        printf("Esse caractere ja foi inserido.\n\n");
      }
    } while (verif > 0);
        printf("\n\n");
    processarDados(palpite);
  }
  if (data.chancesRestantes == 0)
  {
    printf("Voce perdeu!\n");
  }
  return 0;
}

void inicializarDados(int escolha)
{
  strcpy(data.palavraEscolhida, tabelaDePalavras[escolha]);
  separaDica();
  data.letrasRestantes = strlen(data.palavraImpressa);
}

int processarDados(char letra)
{
  int aux = 0;
  for (int i = 0; i < strlen(data.palavraImpressa); i++)
  {
    if (data.palavraImpressa[i] == letra)
    {
      data.descoberto[i] = letra;
      data.letrasRestantes--;
      aux = 1;
    }
  }
  if (aux == 0)
  {
    data.chancesRestantes--;
  }
}

void separaDica()
{
  char *token;
  token = strtok(data.palavraEscolhida, "$");
  strcpy(data.palavraImpressa, token);
  for (int i = 0; i < strlen(data.palavraImpressa); i++)
  {
    data.descoberto[i] = '-';
  }
  token = strtok(NULL, "$");
  strcpy(data.dica, token);
}

int checarLetra(char letra, char tentativas[])
{
  int aux = 0;
  for (int i = 0; i < TAM; i++)
  {
    if (letra == tentativas[i])
    {
      aux++;
    }
  }
  return aux;
}