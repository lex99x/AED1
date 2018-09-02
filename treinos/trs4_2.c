// Enunciado
// Um projeto de motor vem sendo ajustado para que se torne mais eficiente.
// A medida usada para aferir a eficiência é a retomada de rotação, em testes
// de aceleração e desaceleração do motor, que são representados por PICOS
// definidos por valores consecultivos de uma tripla (ri-1, ri, ri+1) onde ri
// é maior que os outros dois valores ri-1 e ri+1 (ver figura abaixo). A altura
// de cada pico é dada pela diferença entre as medições ri-1 e ri. Por exemplo,
// o pico definido pelas rotações (8, 15, 10) tem altura 15-8=7.
// Em um serie S foram registradas as rotações observadas durante os testes.
// Projete e implemente um programa que encontre os eventos de retormada de
// rotação que ateste a eficiência do motor. Eventos de retomada são aqueles
// representados no gráfico acima por picos consecultivos, Pk e Pk+1.
// Nesse caso será considerado uma retomada eficiente se o pico Pk+1 tiver
// altura maior que o pico Pk.
// Exemplo de Entrada
// 10 15 10 16 6  7 8 8 10 3 -1
// Exemplo de Saída
// 10 16 6

#include <stdio.h>

int main(void){

	int rot1, rot2, rot3, alt, altAnt, contPicoAnt = 0, cont = 3;
	short primVez = 1, eventos = 0;

	scanf("%d %d %d", &rot1, &rot2, &rot3);

	while(rot3 >= 0){

		if(rot1 < rot2 && rot2 > rot3){

			alt = rot2 - rot1;

			if(primVez){

				primVez = 0;

			}else if((alt >= altAnt) && ((cont - contPicoAnt) == 2)){

				eventos = 1;
				printf("%d %d %d\n", rot1, rot2, rot3);

			}

			altAnt = alt;
			contPicoAnt = cont;

		}

		rot1 = rot2;
		rot2 = rot3;

		scanf("%d", &rot3);

		cont++;

	}

	if(!eventos) printf("sem eventos\n");

	return 0;

}