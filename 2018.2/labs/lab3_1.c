// Enunciado
// Um motor foi monitorando por um sensor que registrava a CADA segundo a rotação corrente.
// Uma série S foi coletada com o registro do sensor e apresentada a você com o seguinte pedido:
// "Projete e implemente um algoritmo em C que analise S e determine TODOS os instantes de tempo
// em que houve uma mudança no sentido da rotação." S é finalizada quando uma rotação de valor
// negativo for lida.
// Dicas
// Observe que:
// 1) a escala de tempo entre as medições é constante e igual a UM segundo.
// 2) um valor NEGATIVO pode ser qualquer valor menor que Zero
// 3) use a máscara de impressão para formatar a saída, i.e.
// printf("%ds (%d %d %d)", seg, rota1, rota2, rota3)
// Exemplo de Entrada
// 10 20 30 50 10 3 0 50 60 70 -19
// Exemplo de Saída
// 4s (30 50 10)
// 7s (3 0 50)

#include <stdio.h>

int main(void){

	int rota1, rota2, rota3, cont = 3;

	scanf("%d", &rota1);
	scanf("%d", &rota2);
	scanf("%d", &rota3);

	while(rota3 >= 0){

		if((rota2 > rota1 && rota2 > rota3) || (rota2 < rota1 && rota2 < rota3)){

			printf("%ds (%d %d %d)\n", cont - 1, rota1, rota2, rota3);

		}

		cont++;
		rota1 = rota2;
		rota2 = rota3;

		scanf("%d", &rota3);

	}

	return 0;

}