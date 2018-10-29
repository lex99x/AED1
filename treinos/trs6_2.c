#include <stdio.h>

int main(void){

	int quantTotal, quantS2;

	scanf("%d %d", &quantTotal, &quantS2);

	int quantS1 = quantTotal - quantS2, S[quantTotal], cont;

	for(cont = 0; cont < quantS1; cont++) scanf("%d", &S[cont]);

	int comp = 0, mov = 0;

	for(cont = quantS1; cont <= quantS2; cont++){

		scanf("%d", &S[cont]);

		// Ordenação por seleção a cada inserção

		int i, j, imenor, aux;

		for(i = 0; i < cont; i++){

			imenor = i;

			for(j = i + 1; j <= cont; j++){

				if(S[j] < S[imenor]){

					imenor = j;
					comp++;

				}

			}

			if(imenor != i){

				aux = S[i];
				S[i] = S[imenor];
				S[imenor] = aux;
				mov++;

			}

		}

	}

	for(cont = 0; cont < quantTotal; cont++) printf("%.2lf ", S[cont]/100.0);

	printf("\ncomparou: %d\n", comp);
	printf("movimentou: %d\n", mov);

	return 0;

}