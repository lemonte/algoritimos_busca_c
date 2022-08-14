#include <stdio.h>
#include <stdlib.h>

#define TAM 100000000

struct Aluno
{
	char nome[100];
	int telefone;
	char email[100];
};
typedef struct Aluno Aluno;

struct Matricula
{
	int num_matricula;
	char nome_curso[100];
	float coeficiente;
	struct Aluno dados_aluno;
};
typedef struct Matricula Matricula;



int separa (long int vetor[], int ini, int fim) {
   int pivo = vetor[fim]; // pivô
   int aux,f, i = ini;
   for (f = ini; f < fim; ++f)
      if (vetor[f] <= pivo) {
         aux = vetor[i]; 
				 vetor[i] = vetor[f]; 
				 vetor[f] = aux;
         ++i; 
      } 
   aux = vetor[i]; 
	 vetor[i] = vetor[fim]; 
	 vetor[fim] = aux;
   return i; 
}
int separaMatricula (Matricula vetor[], int ini, int fim) {
   Matricula aux, pivo = vetor[fim]; // pivô
   int f, i = ini;
   for (f = ini; f < fim; ++f)
      if (vetor[f].num_matricula <= pivo.num_matricula) {
         aux = vetor[i]; 
				 vetor[i] = vetor[f]; 
				 vetor[f] = aux;
         ++i; 
      } 
   aux = vetor[i]; 
	 vetor[i] = vetor[fim]; 
	 vetor[fim] = aux;
   return i; 
}
void quickSort( Matricula vetor[], long int ini, long int fim)
{

	long int posPivo;
	if (ini < fim)
	{
		posPivo = separaMatricula(vetor, ini, fim);
		quickSort(vetor, ini, posPivo - 1);
		quickSort(vetor, posPivo + 1, fim);
	}
}
void bubbleSort(Matricula vetor[], long int tam) {
	long int i, trocas, soma=0;
	Matricula aux;
	do {
		trocas = 0;
		tam--;
		for(i=0; i < tam; i++) {
			if ( vetor[i].num_matricula > vetor[i+1].num_matricula ) {
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				trocas++;
			}
		}
		soma = soma + trocas;
	} while (trocas > 0 );
}

void imprimir(long int *vetor, long int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("  %ld", vetor[i]);
	}
}
void imprimirMatricula(Matricula vetor[], long int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("  %d", vetor[i].num_matricula );
	}
}
int main()
{
	// SEMENTE DOS NUMEROS ALEAT�RIOS. Usa a hora local
	// srand((unsigned)time(NULL));

	//	int vetor[TAM] = {54, 2, 17, 65, 9, 1, 38, 13};
	//	int vetor[TAM] = {9, 80, 67, 1, 13, 9, 55, 5, 2, 13, 51, 1, 23};
	//	int n = 13;
	//	int n = 12;
	//	long int vetor[TAM] = {55, 10, 44, 21, 8, 19, 33, 41, 5, 16, 27, 30};
	Matricula matricula1;
	matricula1.num_matricula = 2;
	Matricula matricula2;
	matricula2.num_matricula = 9;
	Matricula matricula3;
	matricula3.num_matricula = 7;
	Matricula matricula4;
	matricula4.num_matricula = 5;

	Matricula vetorMatricula[4] = {matricula1, matricula2, matricula3, matricula4};

	long int vetor[12] = {60, 55, 51, 48, 42, 39, 35, 27, 22, 19, 15, 5};

	//	long int vetor[TAM];
	// long int *vetor = (long int *)malloc(TAM * sizeof(long int));
	long int n = 12;

	// gerarAleatorio(vetor, n);
	printf("Completoooo ---- \n\n");
	// imprimir(vetor, n);
	imprimirMatricula(vetorMatricula, 4);
	bubbleSort(vetorMatricula, 4);
	// quickSort(vetorMatricula, 0, 3 - 1);
	printf("\n\n DEPOIS: ");
	imprimirMatricula(vetorMatricula, 4);
	// imprimir(vetor, n);
	return 0;
}
