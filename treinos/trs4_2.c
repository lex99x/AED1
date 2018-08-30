// Enunciado
// O projeto do motor vem sendo ajustado para que se torne mais eficiente
// na retomada de rotação.  Em um serie S foram registradosas rotações
// alcanças durante os testes, na escala de 1(um) segundo. A série S foi
// apresentada para você com um pedido: projeto um programa que encontre
// os eventos de retormada de rotação, que tenham como característica valor
// maior ou igual ao registrado antes da redução da rotação. A série S termina
// quando um valor Negativo para as rotações for lido e quando não houver
// registro de evento, a seguinte mensagem deve ser gerada: sem eventos
// Exemplo de Entrada
// 10 15 10 16 6  7 8 8 10 3 -1
// Exemplo de Saída
// 10 16 6

#include <stdio.h>

int main(void){

	int rot1, rot2, rot3, alt;
	int mrot1, mrot2, mrot3, malt;
	short primVez =  1, mpico = 0;

	scanf("%d %d %d", &rot1, &rot2, &rot3);

	alt = malt = rot2 - rot1;

	while(rot3 >= 0){

		if(rot2 > rot1 && rot2 > rot3){

			alt = rot2 - rot1;

			if(alt >= malt){

				malt = alt;
				mrot1 = rot1;
				mrot2 = rot2;
				mrot3 = rot3;

				if(primVez) primVez = 0;
				else mpico = 1;

			}

		}

		rot1 = rot2;
		rot2 = rot3;

		scanf("%d", &rot3);

	}

	if(mpico) printf("%d %d %d\n", mrot1, mrot2, mrot3);
	else printf("sem eventos\n");

	return 0;

}