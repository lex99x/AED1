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
// No caso da fusão produzir uma lista vazia você deve imprimir a mensagem:
// sala absolutamente silenciosa
// A impressão da lista deve considerar duas casas decimais.
// Exemplo de Entrada
// 10:00:00 2.0 10:00:02 1.0 10:00:02  -1
// 10:00:00 3.0 10:00:02 1.0 10:00:02 -1
// Exemplo de Saída
// 2.00 1.00 3.00 1.00
// 2.00 3.00 1.00

#include <stdio.h>
#include <stdlib.h>

typedef enum{

	INT,
	CHAR,
	LONG,
	FLOAT,
	DOUBLE,
	STRUCT,
	VOID

} Tipo;

typedef struct elemento Elemento;

struct elemento{

	Tipo tipo;
	void* info;
	Elemento* ant;
	Elemento* prox;

};

typedef struct{

	int quant;
	Tipo tipo;
	Elemento* inicio;
	Elemento* final;

} Lista;

Lista* criarLista(void){

	Lista* lista = (Lista*) malloc(sizeof(Lista));

	lista -> quant = 0;
	lista -> inicio = lista -> final = NULL;

	return lista;

}

Elemento* criarElemento(void* info, Tipo tipo){

	Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));

	elemento -> tipo = tipo;
	elemento -> info = info;

	return elemento;

}

void inserirInicioLista(Lista* lista, void* info, Tipo tipo){

	Elemento* elemento = criarElemento(info, tipo);

	elemento -> ant = NULL;
	elemento -> prox = lista -> inicio;

	if(lista -> quant == 0) lista -> final = elemento;
	else lista -> inicio -> ant = elemento;

	lista -> inicio = elemento;
	lista -> quant++;

}

void inserirFinalLista(Lista* lista, void* info, Tipo tipo){

	Elemento* elemento = criarElemento(info, tipo);

	elemento -> ant = lista -> final;
	elemento -> prox = NULL;

	if(lista -> quant == 0) lista -> inicio = elemento;
	else lista -> final -> prox = elemento;

	lista -> final = elemento;
	lista -> quant++;

}

void* removerInicioLista(Lista* lista){

	void* info = NULL;

	if(lista -> quant > 0){

		Elemento* prox = lista -> inicio -> prox;
		info = lista -> inicio -> info;
		free(lista -> inicio);
		lista -> inicio = prox;

		if(lista -> inicio == NULL) lista -> final = NULL;
		else prox -> ant = NULL;

		lista -> quant--;

	}

	return info;

}

void* removerFinalLista(Lista* lista){

	void* info = NULL;

	if(lista -> quant > 0){

		Elemento* ant = lista -> final -> ant;
		info = lista -> final -> info;
		free(lista -> final);
		lista -> final = ant;

		if(lista -> final == NULL) lista -> inicio = NULL;
		else ant -> prox = NULL;

		lista -> quant--;

	}

	return info;

}

typedef void (*Imprimir)(void*, Tipo);

void imprimirLista(Lista* lista, Imprimir imprimir){

	if(lista -> quant > 0){

		Elemento* elemento = lista -> inicio;

		while(elemento != NULL){

			imprimir(elemento -> info, elemento -> tipo);

			elemento = elemento -> prox;

		}

	}

}

typedef struct{

	int hora, min, seg;
	double ruido;

} Registro;

void imprimirRuido(void* info, Tipo tipo){

	double ruido = ((Registro*) info) -> ruido;

	printf("%.2lf ", ruido);

}

int main(void){

	Lista* sensor1 = criarLista();

	Registro* registro = (Registro*) malloc(sizeof(Registro));

	scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> ruido);

	while(registro -> ruido >= 0){

		inserirFinalLista(sensor1, registro, STRUCT);

		registro = (Registro*) malloc(sizeof(Registro));

		scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> ruido);

	}

	Lista* sensor2 = criarLista();

	scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> ruido);

	while(registro -> ruido >= 0){

		inserirFinalLista(sensor2, registro, STRUCT);

		registro = (Registro*) malloc(sizeof(Registro));

		scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> ruido);

	}

	free(registro);

	imprimirLista(sensor1, imprimirRuido); imprimirLista(sensor2, imprimirRuido); printf("\n");

	Elemento* elemento1 = sensor1 -> inicio;
	Elemento* elemento2 = sensor2 -> inicio;

	Lista* fusao = criarLista();

	while(elemento1 != NULL && elemento2 != NULL){

		double ruido1 = ((Registro*) (elemento1 -> info)) -> ruido;
		double ruido2 = ((Registro*) (elemento2 -> info)) -> ruido;

		inserirFinalLista(fusao, elemento1 -> info, DOUBLE);

		if(ruido2 != ruido1) inserirFinalLista(fusao, elemento2 -> info, DOUBLE);

		elemento1 = elemento1 -> prox;
		elemento2 = elemento2 -> prox;

	};

	if(fusao -> quant > 0) imprimirLista(fusao, imprimirRuido);
	else printf("sala absolutamente silenciosa\n");

	return 0;

}