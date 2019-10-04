// Enunciado
// Considere S uma sequência não ordenada de valores que representam as medições de temperatura realizadas em uma sala.
// As medições foram realizadas em uma ordem temporal, crescente durante um certo período do dia: manhã, tarde ou noite.
// Cada elemento de S é dado por uma tupla (st, si), onde st é o tempo em que o evento ocorreu, e si é o valor da temperatura.
// Escreva um programa que encontre para um certo tempo t qual foi a temperatura si registrada.
// No caso de um tempo t não identificado, o programa deve gerar a seguinte mensagem: sem registro de temperatura
// O seu programa deve considerar que várias entradas de tempo serão informadas, ou seja,
// seu programa vai receber várias consultas e depois deve informar a saída apropriada.
// Dicas
// O primeiro valor a ser lido é a quantidade de medidas realizadas;
// Seguido dos valores que formam a sequência S;
// O valores que serão consultados serão informados após a sequência S;
// Um valor negativo para o tempo a ser consultado significa que a sequência de consultas chegou ao fim;
// Use um algoritmo de busca (sequencial ou binária);
// Use vetores para armazenar os valores si e st.
// Exemplos de Entrada e Saída
// Entrada
// 3
// 0 26.7
// 10 26.8
// 30 28.0
// 15
// 10
// 20
// -1
// Saída
// 15 sem registro de temperatura
// 10 26.8
// 20 sem registro de temperatura

#include <stdio.h>

int bsearch(int vetor[], int N, int chave){

	int i = 0, j = N - 1;

	while(i <= j){

		int meio = (i + j)/2;

		if(vetor[meio] < chave) i = meio + 1;
		else if(vetor[meio] > chave) j = meio - 1;
		else return meio;

	}

	return -1;

}

int main(void){

	int quantMedidas, cont;

	scanf("%d", &quantMedidas);

	int tempos[quantMedidas]; double temperaturas[quantMedidas];

	for(cont = 0; cont < quantMedidas; cont++) scanf("%d %lf", &tempos[cont], &temperaturas[cont]);

	int tempo; scanf("%d", &tempo);

	while(tempo >= 0){

		int indice = bsearch(tempos, quantMedidas, tempo);

		if(indice != -1) printf("%d %.1lf\n", tempo, temperaturas[indice]);
		else printf("%d sem registro de temperatura\n", tempo);

		scanf("%d", &tempo);

	}

	return 0;

}