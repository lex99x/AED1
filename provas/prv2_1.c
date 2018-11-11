// Enunciado
// Dois sensores foram instalados em uma sala para monitorar o mesmo fenômeno: o nível de ruído.
// Como os sensores monitoram o mesmo espaço medidas iguais representam que a percepção do ruído
// no espaço foi a mesma, portanto, como medida de redução de custo de armazenamento, esses dados
// precisam ser fundidos gerando registros únicos do fenômeno. Sua tarefa é processar as medições
// geradas pelos sensores, a partir de listas encadeadas, produzindo ao final uma sequência fruto
// da fusão desses dados.
// Dicas
// Considere:
// As sequências têm tamanhos iguais e possui o registro do Ruído (db) e O instante em que ele ocorreu
// Os sensores são ativados ao mesmo instante em que o ruído ocorre;
// Os registros estão em uma sequência de tamanho desconhecido mas finalizados por um valor negativo;
// Os registros, das duas sequências, precisam ser apresentados ao final, a primeira seguida da segunda.
// Os registros da fusão também devem ser impressos após a impressão das demais entradas;
// No caso da fusão produzir uma lista vazia você deve imprimir a mensagem: sala absolutamente silenciosa
// A impressão da lista deve considerar duas casas decimais.
// Exemplo de Entrada
// 10:00:00 2.0 10:00:02 1.0 10:00:02  -1
// 10:00:00 3.0 10:00:02 1.0 10:00:02 -1
// Exemplo de Saída
// 2.00 1.00 3.00 1.00
// 2.00 3.00 1.00

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;

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

void inserirLista(Lista* lista, void* info){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> info = info;
	elemento -> prox = NULL;

	if(lista -> quant == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
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

typedef struct{

	int hora, min, seg;
	double ruido;

} Registro;

void imprimirRuido(void* info){

	double ruido = ((Registro*) info) -> ruido;

	printf("%.2lf ", ruido);

}

int main(void){

	Lista* listaSensor1 = criarLista();

	Registro* registro = (Registro*) malloc(sizeof(Registro));

	scanf("%d:%d:%d %lf", registro -> hora, registro -> min, registro -> seg, registro -> ruido);

	while(registro -> ruido >= 0){

		inserirLista(listaSensor1, registro);

		registro = (Registro*) malloc(sizeof(Registro));

		scanf("%d:%d:%d %lf", registro -> hora, registro -> min, registro -> seg, registro -> ruido);

	}

	Lista* listaSensor2 = criarLista();

	scanf("%d:%d:%d %lf", registro -> hora, registro -> min, registro -> seg, registro -> ruido);

	while(registro -> ruido >= 0){

		inserirLista(listaSensor2, registro);

		registro = (Registro*) malloc(sizeof(Registro));

		scanf("%d:%d:%d %lf", registro -> hora, registro -> min, registro -> seg, registro -> ruido);

	}

	free(registro);

	imprimirLista(listaSensor1, imprimirRuido); imprimirLista(listaSensor2, imprimirRuido); printf("\n");

	Lista* listaFusao = criarLista();

	Elemento* elemento1 = listaSensor1 -> inicio;
	Elemento* elemento2 = listaSensor2 -> inicio;

	while(elemento1 != NULL && elemento2 != NULL){

		double ruido1 = ((Registro*) (elemento1 -> info)) -> ruido;
		double ruido2 = ((Registro*) (elemento2 -> info)) -> ruido;

		inserirLista(listaFusao, elemento1 -> info);

		if(ruido1 != ruido2) inserirLista(listaFusao, elemento2 -> info);

		elemento1 = elemento1 -> prox;
		elemento2 = elemento2 -> prox;

	}

	if(listaFusao -> quant > 0) imprimirLista(listaFusao, imprimirRuido);
	else printf("sala absolutamente silenciosa\n");

	return 0;

}