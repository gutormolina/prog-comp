#include <stdio.h>

int main(){

	int n=0;
	
	printf("Quantos números serão armazenados? ");
	scanf("%d", &n);
	
	int vetor[n];
	
	for(int i=0; i<n; i++) {
		printf("Digite o valor para a posição %d: ", i);
		scanf("%d", &vetor[i]);
	}
	int posicaoMenorValor = 0;
	
	
	for(int i=0; i<n; i++) {
		if (vetor[i] < vetor[posicaoMenorValor])
			posicaoMenorValor = i;
	}
	printf("Posição do menor valor: %d", posicaoMenorValor);
}
