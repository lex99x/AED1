// Enunciado
// Candidatos com Maior Nota.
// Em uma série S estão registradas tuplas contendo matrícula e nota de cada candidato
// que fez uma certa prova. Faça um programa que encontre e imprima:
// O texto "nota:" e ao lado a maior nota na prova.
// Na linha seguinte, o texto “matricula(s): “ e depois a(s) matrícula(s) do(s) candidato(s)
// que obtiveram a maior nota. Um registro por linha.
// A(s) matricula(s) deve(m) ser impressas na ordem em que aparecem em S.
// As matriculas são valores inteiros e as notas são valores reais, com duas casas;
// Considere que a sequência S está desordenada e tem tamanho indefinido,
// mas sabe-se que ela termina quando a matrícula for um valor menor que zero.
// Veja os formatos de entrada e saída esperada na entrada exemplo
// Exemplo de Entrada
// 2176462 26.44
// 2176635 674.95
// 2173590 546.12
// 2171008 128.57
// 2173671 603.95
// 2174818 419.29
// 2175033 144.10
// 2175501 216.81
// 2174500 598.99
// 2173739 674.95
// -1
// Exemplo de Saída
// nota: 674.95
// matricula(s):
// 2176635
// 2173739

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Implementação de vetor dinâmico pelo professor

typedef struct VD {
  int ocupacao, tamanho;
  void* *agregador;
} TVDinamico;

void inserir(TVDinamico *vd, void *novo, int pos){
  if (pos >= vd->tamanho){
	int anterior = vd->tamanho;

	int k = ceil(log2(pos));

	vd->tamanho = pow(2, k) + 1;
	vd->agregador = realloc(vd->agregador,vd->tamanho*sizeof(void*));
	memset(vd->agregador+anterior,'\0',(vd->tamanho-anterior)*sizeof(void*));
  }
  vd->agregador[pos] = novo;
  vd->ocupacao++;
}

void* acessar(TVDinamico vd, int indice){
	if (indice < vd.tamanho){
	  return vd.agregador[indice];
	}else
	  return NULL;
}

TVDinamico criarVD(int tamanho){
  TVDinamico vd ;
  vd.tamanho = tamanho;
  vd.ocupacao = 0;
  vd.agregador = malloc(vd.tamanho*sizeof(void*));

  memset(vd.agregador,'\0',vd.tamanho*sizeof(void*));

  return vd;
}

// Uso do vetor dinâmico

typedef struct{

	int matricula;
	double nota;

} Candidato;

TVDinamico lerCandidatos(void){

	TVDinamico candidatos = criarVD(5);

	Candidato* candidato = (Candidato*) malloc(sizeof(Candidato));

	int cont;

	scanf("%d", &candidato -> matricula);

	for(cont = 0; candidato -> matricula >= 0; cont++){

		scanf("%lf", &candidato -> nota);

		inserir(&candidatos, candidato, cont);

		candidato = (Candidato*) malloc(sizeof(Candidato));

		scanf("%d", &candidato -> matricula);

	}

	free(candidato);

	return candidatos;

}

int main(void){

	TVDinamico candidatos = lerCandidatos();

	double mnota = 0.0;

	int cont;

	for(cont = 0; cont < candidatos.ocupacao; cont++){

		Candidato* candidato = acessar(candidatos, cont);

		if(candidato -> nota > mnota) mnota = candidato -> nota;

	}

	printf("nota: %.2lf\n", mnota);

	printf("matricula(s):\n");

	for(cont = 0; cont < candidatos.ocupacao; cont++){

		Candidato* candidato = acessar(candidatos, cont);

		if(candidato -> nota == mnota) printf("%d\n", candidato -> matricula);

	}

	return 0;

}