// Enunciado
// Transparência no Tribunal
// A lei da transparência obriga os órgãos e autarquias federais a tornar públicos os seus gastos.
// Em pró desta lei, pretende-se implementar em um tribunal federal um serviço que permita acesso
// aos gastos com pagamentos de salários.
// Como parte deste serviço, você deverá fazer um programa cuja entrada:
// É uma sequência S, de triplas s que contém:a função, matrícula, e salário de cada funcionário,
// constante na folha salarial do referido Tribunal.
// A função é representada por uma letra A – Administrativo ou N - Não Administrativo;
// para preservação das identidades.
// A matrícula é um valor inteiro. Este campo garante o compromisso de tornar públicos os dados
// e a identificação de indivíduos para qualquer situação de auditoria posterior.
// O salário é um valor real (pode ser fracionário).
// O número de funcionários é desconhecido, portanto, quando for lida uma tripla
// com o campo função = “F” está sendo indicado o fim da sequència S;
// Seu programa deve processar a sequência S e imprimir como saída uma lista contendo
// a matrícula e salário dos funcionários com os 10 maiores salários.
// Note que, como o tribunal pode ter vários funcionários exercendo o mesmo cargo
// (e/ou recebendo diversos “pinduricalhos” que gerem ganhos equivalentes aos de
// funcionários em diferentes cargos), pode haver mais de 10 matriculas que respondam à questão.
// Exemplo de Entrada
// N 20182317 30000.00
// N 20181617 12000.00
// N 20182517 25000.00
// N 20181518 10000.00
// N 20181519 30000.00
// A 20181447 4500.00
// A 20181327 5000.00
// A 20181007 4000.00
// A 20184587 15000.00
// A 20181907 1000.00
// A 20181905 5000.00
// A 20182105 4000.00
// A 20182104 1400.00
// F
// Exemplo de Saída
// 20182317 30000.00
// 20181519 30000.00
// 20182517 25000.00
// 20184587 15000.00
// 20181617 12000.00
// 20181518 10000.00
// 20181327 5000.00
// 20181905 5000.00
// 20181447 4500.00
// 20181007 4000.00
// 20182105 4000.00

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;

typedef struct{

	char funcao;
	int matricula;
	double salario;

} Funcionario;

struct elemento{

	void* info;
	Elemento* prox;

};

typedef struct{

	int quant;
	Elemento* inicio;
	Elemento* final;

} Lista;

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> quant = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

void inserirOrdenadoLista(Lista* lista, void* info){

	Elemento* elemento = lista -> inicio;
	Elemento* ant = NULL;

	while(elemento != NULL && (((Funcionario*) info) -> salario) < (((Funcionario*) elemento -> info) -> salario)){

		ant = elemento;
		elemento = elemento -> prox;

	}

	elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> info = info;
	elemento -> prox = NULL;

	if(ant == NULL){

		elemento -> prox = lista -> inicio;
		lista -> inicio = elemento;

	}else{

		elemento -> prox = ant -> prox;
		ant -> prox = elemento;

	}

	lista -> quant++;

}

typedef void (*Imprimir)(void*);

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant >= 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info);
			elemento = elemento -> prox;

		}

	}

}

Lista* lerFuncionarios(void){

	Lista* listaFuncionarios = criarLista();

	Funcionario* funcionario = (Funcionario*) malloc(sizeof(Funcionario));

	scanf(" %c", &funcionario -> funcao);

	while(funcionario -> funcao != 'F'){

		scanf("%d %lf", &funcionario -> matricula, &funcionario -> salario);

		inserirOrdenadoLista(listaFuncionarios, funcionario);

		funcionario = (Funcionario*) malloc(sizeof(Funcionario));

		scanf(" %c", &funcionario -> funcao);

	}

	free(funcionario);

	return listaFuncionarios;

}

void imprimirFuncionario(void* info){

	Funcionario* funcionario = (Funcionario*) info;

	printf("%d %.2lf\n", funcionario -> matricula, funcionario -> salario);

}

int main(void){

	Lista* listaFuncionarios = lerFuncionarios();

	imprimirLista(listaFuncionarios, imprimirFuncionario);

	return 0;

}