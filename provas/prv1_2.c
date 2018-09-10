// Enunciado
// O projeto de um motor vem sendo avaliado visando melhorias na sua eficiência.
// A medida usada para aferir a eficiência é a retomada de rotação, em testes de
// aceleração e desaceleração, que são representados por PICOS definidos por
// valores consecultivos de uma tripla (ri-1, ri, ri+1) onde ri é maior que os
// outros dois valores ri-1 e ri+1 (ver figura abaixo). A altura de cada pico é
// dada pela diferença entre as medições ri-1 e ri. Por exemplo, o pico definido
// pelas rotações (8, 15, 10), com inicio no tempo 6,  tem altura 15-8=7.
// Em um serie S foi registrado as rotações observadas durante os testes.
// Projete e implemente um programa que encontre os eventos de retormada de
// rotação que ateste a eficiência do motor. Eventos de retomada são aqueles
// representados no gráfico acima por picos consecultivos, Pk e Pk+1.
// Considere que uma retomada de aceleração eficiente é caracterizada da seguinte
// forma: pico Pk+1 tem altura maior que o pico Pk. No gráfico acima tem-se 6 picos,
// P1=(0,3,1), P2=(1,3,0), P3=(8,5,15), P4=(5,12,3), P5=(0,10,5) e P6=(5,15,0).
// Os picos P4 e P6 são exemplos de retomadas de aceleração eficiente.
// O pico P2=(1,3,0) não caracteriza uma retomada de rotação eficiente.
// Dicas
// No caso de Não ocorrer o evento que ateste a melhoria de eficiência
// a seguinte mensagem deve ser impressa: sem eventos
// A série S encerra quando um valor negativo -1 for lido
// Exemplo de Entrada
// 10 15 10 16 6  7 8 8 10 3 -1
// Exemplo de Saída
// 10 16 6

#include <stdio.h>

int main(void){

	int rot1, rot2, rot3;
	int alt, altPicoAnt, tempoPicoAnt = 0, tempo = 3, eventos = 0;
	short primVez = 1;

	scanf("%d %d %d", &rot1, &rot2, &rot3);

	while(rot3 >= 0){

		if(rot1 < rot2 && rot2 > rot3){

			alt = rot2 - rot1;

			if(primVez){

				primVez = 0;

			}else if((alt >= altPicoAnt) && ((tempo - tempoPicoAnt) == 2)){

				printf("%d %d %d\n", rot1, rot2, rot3);
				eventos++;

			}

			altPicoAnt = alt;
			tempoPicoAnt = tempo;

		}

		rot1 = rot2;
		rot2 = rot3;

		scanf("%d", &rot3);

		tempo++;

	}

	if(!eventos) printf("sem eventos\n");

	return 0;

}