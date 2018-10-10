// Enunciado
// DISTÂNCIA EUCLIDIANA: RECOMENDAÇÃO DE PRODUTOS
// O grau de similaridade entre dois vetores
// pode ser calculado pela distância Euclidiana, como definida a seguir:
// O site de e-commerce Pilhados usa a distância euclidiana para calcular a similaridade
// entre produtos e recomendar aos seus clientes em vitrines do tipo "Produtos que talvez você tenha interesse".
// Sete características dos produtos são codificadas, usando valores inteiros, e geram uma série S de 7-tuplas.
// Alice acabou de comprar um produto no site Pilhados e terá uma vitrine gerada para ela.
// A sua tarefa é escrever um programa que recebe uma 7-tupla, que descreve o produto comprado
// por Alice, e as 7-tuplas que descrevem os produtos do site, para posteriormente indicar o
// grau de similaridade dos produtos do site e o comprado por Alice.
// Considere:
// 1) A Vitrine em questão comporta no máximo 10 produtos, portanto ela poderá ter ATÉ 10 produtos similares;
// 2) Quanto menor o valor da distância Euclidiana mais similar são os produtos comparados;
// 3) As 7-tuplas de S encerram quando o valor -5000 for informado como o valor da primeira característica.
// Exemplo de Entrada
// 601 283 319 829 363 121 504
// 486 997 923 91 169 199 228
// 637 225 615 334 641 560 697
// 570 785 448 816 213 597 290
// 600 490 474 901 568 877 511
// 168 401 172 852 593 158 256
// 725 224 495 601 146 200 488
// 474 442 70 999 804 724 701
// 76 22 786 882 458 128 238
// 288 844 191 292 640 780 513
// 160 459 233 511 552 546 727
// 820 35 70 11 189 733 272
// 221 7 969 39 388 162 309
// -5000
// Exemplo de Saída
// Os da vitrine:
// 394.2119
// 582.5152
// 751.4300
// 774.6302
// 802.7914
// 802.8418
// 828.0513
// 853.9379
// 1108.3925
// 1139.8395

#include <stdio.h>
#include <math.h>

double dist(int* produtoComprado, int* produtoSugerido){

	int i; 
	double dist = 0.0;

	for(i = 0; i < 7; i++) dist += pow(produtoComprado[i] - produtoSugerido[i], 2);

	return sqrt(dist);

}

void selsort(double* vet, int n){

	int i, j, imenor;
	double aux;

	for(i = 0; i < n - 1; i++){

		imenor = i;

		for(j = i + 1; j < n; j++) if(vet[imenor] > vet[j]) imenor = j;

		aux = vet[i];
		vet[i] = vet[imenor];
		vet[imenor] = aux;

	}

}

int main(void){

	int i, cont, atr, produtoComprado[7], produtoSugerido[7];
	double similaridade, vitrine[10];

	for(i = 0; i < 7; i++){
		
		scanf("%d", &atr); 
		produtoComprado[i] = atr;

	}

	scanf("%d", &atr);

	for(cont = 0; atr != -5000; cont++){
		
		produtoSugerido[0] = atr;

		for(i = 1; i < 7; i++){
			
			scanf("%d", &atr);
			produtoSugerido[i] = atr;
			
		}
		
		vitrine[cont] = dist(produtoComprado, produtoSugerido);
		selsort(vitrine, cont + 1);

		scanf("%d", &atr);
	
	}

	printf("Os da vitrine:\n");

	for(i = 1; i <= 10; i++) printf("%.4lf\n", vitrine[i]);

	return 0;

}