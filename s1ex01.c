#include <stdio.h>
#include <math.h>

int main() {
	float r, a;
	
	printf("Insira o raio do círculo: ");
	scanf("%f", &r);
	a = M_PI * (r * r);
	printf("Área do círculo: %f", a);
}
