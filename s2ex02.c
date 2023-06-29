#include <stdio.h>

int main () {
	
	float v1, v2, mt, media, maiorNota, notaOptativa;
	
	printf("Insira a nota da avaliacao 1: ");
	scanf("%f", &v1);
	printf("Insira a nota da avaliacao 2: ");
	scanf("%f", &v2);
	printf("Insira a media dos trabalhos: ");
	scanf("%f", &mt);
	
	media = (3*v1 + 3*v2 + 4*mt) / 10;
	printf("Media do aluno: %f\n", media);
	
	if (media >= 7) {
		printf("Aprovado por media\n");
	}
	
	else { if (v1 < v2) {
		maiorNota = v2;
	}
	else {
		maiorNota = v1;
	}
	
	notaOptativa = (70 - 3*maiorNota - 4*mt) / 3;
	
	printf("Nota necessaria na optativa: %f", notaOptativa);
	}
}
