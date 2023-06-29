#include <stdio.h>

int main(){

	int n=0, m=0;
	
	printf("Quantas linhas terá a matriz? ");
	scanf("%d", &n);
	printf("Quantas colunas terá a matriz? ");
	scanf("%d", &m);
	
	float valores[n][m];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("Insira o valor para a célula (%d,%d): ", i, j);
			scanf("%f", &valores[i][j]);
		}
	}
	
	float soma, media;
	
	for(int i=0; i<n; i++){
		soma = 0, media = 0;
		for(int j=0; j<m; j++){
			soma += valores[i][j];
		}
		
		media = soma / m;
		printf("Média da linha %d: %.2f\n", i, media);
		
		int c = 0;
		
		for(int j=0; j<m; j++){
			if (valores[i][j] > media)
				c++;
		}
		printf("Acima da média na linha %d: %d\n", i, c);
	}
}
