// Enunciado
// Na apuração das notas de um desfile de escolas de samba utiliza-se um sistema
// em que são desprezadas a nota mais baixa e a mais alta,
// para evitar perseguições ou favorecimentos.
// Dadas as 4 notas de um quesito qualquer (bateria, evolução, ...),
// obter a média das duas notas que não foram desprezadas.
// Se houver notas iguais, considerar a primeira ocorrência da nota.
// Exemplo de Entrada
// 8.0 6.0 7.0 10.0
// Exemplo de Saída
// 7.50

#include <stdio.h>

int main(void){

	double maior, menor, media, aux;

	scanf("%lf %lf", &maior, &menor);

	media = maior + menor;

	if(menor > maior){

		aux = maior;
		maior = menor;
		menor = aux;

	}

	scanf("%lf", &aux);

	media = media + aux;

	if(aux > maior) maior = aux;
	else if(aux < menor) menor = aux;

	scanf("%lf", &aux);

	media = media + aux;

	if(aux > maior) maior = aux;
	else if(aux < menor) menor = aux;

	media = (media - (maior + menor))/2.0;

	printf("%.2lf\n", media);

	return 0;

}