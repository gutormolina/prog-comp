#include <stdio.h>
int main () {
	
	int n, x, y, priQuad = 0, segQuad = 0, terQuad = 0, quaQuad = 0; 
	int eixoX = 0, eixoY = 0, origem = 0;

	printf("Quantos pontos serao escritos? ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("Insira o valor do ponto x: ");
		scanf("%d", &x);
		printf("Insira o valor do ponto y: ");
		scanf("%d", &y);
    printf("\n");
		
		if (x == 0 && y == 0)
    origem++;
    else if (x == 0 && y != 0)
    eixoX++;
    else if (x != 0 && y == 0)
    eixoY++;
    else if (x > 0 && y > 0)
    priQuad++;
    else if (x < 0 && y > 0)
    segQuad++;
    else if (x < 0 && y < 0)
    terQuad++;
    else
    quaQuad++;
    
  }
  
  printf("Total de pontos em cada quadrante\n");
  printf("Origem: %d\n", origem);
  printf("Eixo X: %d\n", eixoX);
  printf("Eixo Y: %d\n", eixoY);
  printf("Primeiro Quadrante: %d\n", priQuad);
  printf("Segundo Quadrante: %d\n", segQuad);
  printf("Terceiro Quadrante: %d\n", terQuad);
  printf("Quarto Quadrante: %d\n", quaQuad);
  
}
