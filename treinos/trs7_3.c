// Enunciado
// Objetivo: Controle de estoque e vendas de uma Uma fábrica.
// Uma Fábrica possui um catálogo de produtos que ela deseja controlar o nível
// de estoque e o faturamento realizado diariamente. Você deve projetar e implementar
// um programa que lê o catalogo de produtos e as vendas realizadas, indicando ao final
// o resultado desse processamento.
// O seu programa deve ler e armazenar as seguintes informações sobre os produtos:
// O codigo do produto;
// A quantidade disponível em estoque e;
// O preco de venda.
// O termino do cadastramento deve ocorrer quando se digitar 0 (zero) para o codigo do produto.
// Nao se sabe com quantos produtos diferentes a fabrica trabalha.
// Na segunda fase, devem ser lidos o codigo do produto e a quantidade a ser vendida.
// Se o codigo do produto estiver cadastrado, a venda podera ser realizada.
// Caso contrário, a mensagem "Produto nao cadastrado" deve ser exibida.
// Caso o produto esteja cadastrado, a venda só poderá ser realizada se a quantidade
// disponível em estoque for suficiente para atender ao pedido.
// Nesse caso, deve ser abatida do estoque a quantidade vendida.
// Se o estoque for insuficiente, a mensagem "Estoque insuficiente" deve ser exibida.
// O final das vendas deve ocorrer quando se digitar 0 (zero) para o codigo do produto.
// Ao final, o programa deve ser apresentar uma listagem com o total vendido no dia
// e a relação de todos os produtos do estoque, com suas respectivas quantidades.
// Exemplo de Entrada
// 2 1 10.0
// 4 2 25.0
// 6 1 100.0
// 0
// 2 1
// 4 1
// 6 1
// 6 2
// 0
// Exemplo de Saída
// Estoque insuficiente
// 2 0 10.0
// 4 1 25.0
// 6 0 100.0
// Total das Vendas: R$ 135.0

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int tam;
	int ocup;
	void** agreg;

} Array;

Array* criarArray(int tam){

	Array* array = (Array*) malloc(sizeof(Array));

	if(tam != '\0') array -> tam = tam; else array -> tam = 1;

	array -> ocup = 0;
	array -> agreg = malloc(tam * sizeof(void*));

	return array;

}

void inserirArray(Array* array, void* elem){

	if(array -> tam == array -> ocup){

		array -> tam *= 2;
		array -> agreg = realloc(array -> agreg, array -> tam * sizeof(void*));

	}

	array -> agreg[array -> ocup] = elem;
	array -> ocup++;

}

void* acessarArray(Array* array, int pos){

	if(pos < 0 || pos > array -> ocup) exit(0);

	return array -> agreg[pos];

}

typedef struct{

	int codigo;
	int quant;
	double preco;

} Produto;

Array* lerEstoque(void){

	Array* estoque = criarArray('\0');

	Produto* produto = (Produto*) malloc(sizeof(Produto));

	scanf("%d", &produto -> codigo);

	while(produto -> codigo != 0){

		scanf("%d %lf", &produto -> quant, &produto -> preco);

		inserirArray(estoque, produto);

		produto = (Produto*) malloc(sizeof(Produto));

		scanf("%d", &produto -> codigo);

	}

	free(produto);

	return estoque;

}

Produto* buscaProduto(Array* estoque, int codigo){

	int cont;

	for(cont = 0; cont < estoque -> ocup; cont++){

		Produto* produto = acessarArray(estoque, cont);

		if(produto -> codigo == codigo) return produto;

	}

	return NULL;

}

int main(void){

	Array* estoque = lerEstoque();

	int codigo, quant;
	double total = 0.0;

	scanf("%d", &codigo);

	while(codigo != 0){

		scanf("%d", &quant);

		Produto* produto = buscaProduto(estoque, codigo);

		if(produto != NULL){

			if(quant <= produto -> quant){

				produto -> quant -= quant;
				total += quant * produto -> preco;

			}else printf("Estoque insuficiente\n");

		}else printf("Produto nao cadastrado\n");

		scanf("%d", &codigo);

	}

	int cont;

	for(cont = 0; cont < estoque -> ocup; cont++){

		Produto* produto = acessarArray(estoque, cont);

		printf("%d %d %.1lf\n", produto -> codigo, produto -> quant, produto -> preco);

	}

	printf("Total das Vendas: R$ %.1lf\n", total);

	return 0;

}