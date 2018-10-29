// Enunciado
// Ordene com menos trocas
// Em uma sequência S de inteiros, estão dispostas as notas dos alunos
// que realizaram a prova do ENEM. Escreva um programa que ordene a
// sequência S e a imprima, considerando:
// Que os dois últimos dígitos da nota são as casas decimais;
// Que o primeiro registro da entrada contém o tamanho da sequência S.
// Existem notas repetidas, por isso sua implementação deve ser estável,
// isto é, a ordem dos valores iguais, no vetor ordenado, é definida pela
// ordem com que eles aparecem na sequência original.
// Use o algoritmo de ordenação, visto em sala de aula, que usa a menor
// quantidade de trocas, no pior cenário. Você deve comprovar o uso do
// algoritmo imprimindo na primeira linha o texto "trocas: " e a seguir
// a quantidade de trocas realizadas.
// Veja no exemplo os modelos de entrada e saída.
// Exemplo de Entrada
// 6
// 79125 96916 83490 21806 6504 96916
// Exemplo de Saída
// trocas: 5
// 65.04 218.06 791.25 834.90 969.16 969.16

#include <stdio.h>

int selsort(int vetor[], int n){

	int i, j, imenor, aux, trocas = 0;

	for(i = 0; i < n - 1; i++){

		imenor = i;

		for(j = i + 1; j < n; j++) if(vetor[j] < vetor[imenor]) imenor = j;

		if(imenor != i){

			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
			trocas++;

		}

	}

	return trocas;

}

int main(void){

	int n;

	scanf("%d", &n);

	int notas[n], cont;

	for(cont = 0; cont < n; cont++) scanf("%d", &notas[cont]);

	int trocas = selsort(notas, n);

	printf("trocas: %d\n", trocas);

	for(cont = 0; cont < n; cont++) printf("%.2lf ", notas[cont]/100.0);

	return 0;

}