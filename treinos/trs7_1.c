// Enunciado
// Consumo do restaurante - maior
// Em uma  sequência S registrou-se a quantidade de gasto de produtos em um restaurante.
// Em uma outra sequência R registrou-se o preco de cada produto. Escreva um programa que
// leia S e R, armazene as suas informações em vetores e indique qual o produto gerou o
// maior gasto para o restaurante. As posições dos produtos nas sequências S e R,
// são os seus identificadores.
// Lembre-se que O número 0 como índice do vetor deve indicar o produto 1,
// assim como, o índice 3 indica o produto 4.
// Mostre ao final da execução do programa o número correspondente ao produto que gerou o
// maior gasto (gasto * preco) no restaurante, por exemplo, se a MAIOR preco total foi
// do produto 0 o resultado deve ser 1, se foi 20 deverá ser 21.
// Dicas
// Lembre-se que o número usado para representar o produto é o índice do vetor
// acrescido de UMA unidade.
// É possível que haja mais de um produto na condição de MAIOR gerador de gasto,
// e portanto todos eles devem ser impressos como saida do programa;
// Exemplos (não exaustivos):
// Consumo por produto S: 10 20 30 40 50 60 70 80 90 100 110 120 -1
// Valor por produto R: 5.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 13.0 14.0 15.0 16.0
// O Valor de resposta deverá ser 12
// Exemplo de Entrada
// 60 20 30 40 50 60 70 80 90 100 110 120 -1
// 32.0 6.0 7.0 8.0 9.0 10.0 11.0 12.0 13.0 14.0 15.0 16.0
// Exemplo de Saída
// 1
// 12

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int consumo;
	int preco;
	int valor;

} Gasto;

typedef struct{

	int capacidade;
	int ocupacao;
	Gasto* armazenador;

} Vetor;

Vetor criarVetor(int capacidade){

	if(capacidade < 1) exit(0);

	Vetor vetor;

	vetor.capacidade = capacidade;
	vetor.ocupacao = 0;
	vetor.armazenador = malloc(capacidade * sizeof(Gasto));

	return vetor;

}

void inserirVetor(Vetor vetor, Gasto gasto){

	if(vetor.capacidade == vetor.ocupacao){

		vetor.capacidade *= 2;
		vetor.armazenador = realloc(vetor.armazenador, vetor.capacidade * sizeof(Gasto));

	}

	vetor.armazenador[vetor.ocupacao] = gasto;
	vetor.ocupacao++;

}

Gasto acessarVetor(Vetor vetor, int indice){

	if(indice < 0 || indice > vetor.ocupacao) exit(0);

	return vetor.armazenador[indice];

}

int main(void){

	Vetor gastos = criarVetor(1);

	Gasto gasto; scanf("%d", &gasto.consumo);

	while(gasto.consumo >= 0){

		scanf("%lf", &gasto.preco);

		inserirVetor(gastos, gasto);

		scanf("%d", &gasto.consumo);

	}

	int cont; double mvalor = 0.0;

	for(cont = 0; cont < gastos.ocupacao; cont++){

		Gasto gasto = acessarVetor(gastos, cont);

		scanf("%lf", &gasto.preco);

		gasto.valor = gasto.consumo * gasto.preco;

		if(gasto.valor > mvalor) mvalor = gasto.valor;

	}

	for(cont = 0; cont < gastos.ocupacao; cont++){

		Gasto gasto = acessarVetor(gastos, cont);

		if(gasto.valor == mvalor) printf("%d\n", cont + 1);

	}

	return 0;

}