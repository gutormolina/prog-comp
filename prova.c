// Augusto Ramos Molina; Turma M10;
#include <stdio.h>
#include <math.h>

typedef struct
{
	float cimento;		//sacos
	float areia;		//latas 18l
	float pedra;		//latas 18l
	float agua;			//latas 18l
	float rendimento;	//metros cubicos
} concreto;

typedef struct
{
	int tipo;			//de concreto
	float largura;		//em m
	float comprimento;	//em m
	float altura;		//em m
} concretagem;

concreto tipos[10];
concretagem obras[30];

void questao01(int *a, int *b);
float questao02(int a, int b);
void questao03(int a, float b, float *c, float *d, float *e, float *f);

int main()
{
	int qtde_tipos, qtde_obras, i;
	float v, vt = 0, cim, are, ped, agu;
	
	questao01(&qtde_tipos, &qtde_obras);
	printf("Quantidade de Tipos: %d\nQuantidade de Obras: %d\n", qtde_tipos, qtde_obras);
	for (i = 0; i < qtde_tipos; i++) {
		v = questao02(i, qtde_obras);
		printf("Para o tipo %d:\n O Volume de concreto e: %.2f (m3)\n", i, v);
		questao03(i, v, &cim, &are, &ped, &agu);
		printf("O traço é:\n %0.f sacos de cimento\n %0.f latas de areia\n %.0f latas de pedra\n %.0f latas de agua\n", cim, are, ped, agu);
		vt += v;
	}
	printf("Volume total a ser concretado: %.2f (m3)", vt);
	return 0;
}

void questao01(int *a, int*b)
{
	scanf("%d", a);
	for(int i = 0; i < *a; i++) 
	{
		scanf("%f %f %f %f %f",
			&tipos[i].cimento,
			&tipos[i].areia,
			&tipos[i].pedra,
			&tipos[i].agua,
			&tipos[i].rendimento
		);
	}
	scanf("%d", b);
	for(int i=0; i < *b; i++)
	{
		scanf("%d %f %f %f",
			&obras[i].tipo,
			&obras[i].largura,
			&obras[i].comprimento,
			&obras[i].altura
		);
	} 
}

float questao02(int a, int b) 
{
	float vol;
	for(int i = 0; i < b; i++) 
	{
        if (obras[i].tipo == a)
        {
            vol += obras[i].altura * obras[i].largura * obras[i].comprimento;
        }
        
	}
	return vol;
}

void questao03(int a, float b, float *c, float *d, float *e, float *f)
{
	*c = ceil(tipos[a].cimento * b / tipos[a].rendimento);
	*d = ceil(tipos[a].areia * b / tipos[a].rendimento);
	*e = ceil(tipos[a].pedra * b / tipos[a].rendimento);
	*f = ceil(tipos[a].agua * b / tipos[a].rendimento);
}
