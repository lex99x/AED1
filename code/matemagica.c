#include <stdio.h>

int proximo_numero(int tab, int lin, int col, int ant){

	if(tab == 0) return ant + 2;

	if(tab == 1 && col % 2 == 0) return ant + 3;

	if(tab == 2 && col == 0) return ant + 5;

	if(tab == 3 && lin % 2 == 0 && col == 0) return ant + 9;

	if(tab == 4 && lin == 4 && col == 0) return ant + 17;

	return ant + 1;

}

void imprimir_tabelas(void){

	int prim = 1, ant = 0, num = 0;
	int aux[6];

	for(int i = 1; i <= 6; i++) printf("    (%d)       ", i);

	printf("\n\n");

	for(int lin = 0; lin < 8; lin++){

		for(int tab = 0; tab < 6; tab++){

			for(int col = 0; col < 4; col++){

				// Atribuição de num:

				if(lin == 0 && col == 0) num = prim;
				else if(col == 0) num = proximo_numero(tab, lin, col, aux[tab]);
				else num = proximo_numero(tab, lin, col, ant);

				// Impressão de num

				if(num < 10) printf("0");

				printf("%d ", num);

				if(col == 3) printf("  "); aux[tab] = num;

				ant = num;

			}

			prim *= 2;

		}

	}

	printf("\n");

}

int validar_bool(char bool){

	return bool == 's' || bool == 'n';

}

// Protótipos de funções:

// Função que retorna o próximo número a partir do anterior
int proximo_numero(int tab, int lin, int col, int ant);

// Função que imprime as tabelas na tela
void imprimir_tabelas(void);

// Função para validar entradas do usuário
int validar_bool(char bool);

// Gambiarra
void __fpurge();

int main(void){

	printf("Matemágica, by @lex99_\n\nSeja bem-vindo ao meu jogo de adivinhação!\n");
	printf("\nPara jogar você deve pensar em um número de 1 a 63\ne a máquina irá adivinhar qual número você pensou!\n");
	printf("\nQuando estiver pronto, informe quais tabelas abaixo contém o seu número...\n\n");

	int prim = 1, num = 0, cont = 0;
	char bool = 's';

	imprimir_tabelas();

	while(cont < 6){

		printf("\nO seu número está na tabela %d? (s/n): ", cont + 1);

		bool = getchar(); fflush(stdin); __fpurge(stdin);

		if(validar_bool(bool)){

			if(bool == 's') num += prim;

			prim *= 2;
			cont++;

		}else printf("\nEntrada inválida! Digite 's' para SIM ou 'n' para NÃO!\n");

	}

	if(num) printf("\nO número que você pensou foi: %d\n", num);
	else printf("\nVocê não pensou em um número... :(\n");

	return 0;

}