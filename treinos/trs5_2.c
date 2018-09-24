// Enunciado
// ACHE AS NOTAS DO QUINTO SUPERIOR
// Uma sequência S contém notas de duas turmas da disciplina AED-1.
// Embora se saiba que cada turma teria no máximo 60 alunos, o número
// de alunos a cada semestre é variável, portanto a sequência contém
// o valor -1 ao final do grupo de notas de cada uma das turmas para
// indicar seu fim de dados.
// Escreva um programa que leia S e imprima numa nova linha cada notas
// obtidas pelos alunos que se encontram no “Quinto superior” ou o estrato
// superior correspondente ao 20% de alunos com melhor desempenho.
// É vetada a impressão de valores de desempenho iguais.
// Por exemplo, no estrato superior formado pelas notas: 9.0 9.0 8.5, apenas
// as notas 9.0 e 8.5 deverão ser impressas. Imprima uma nota por linha.
// Dicas
// Use os algoritmos apresentados no segundo módulo da disciplina;
// Considere sempre a parte inteira do cálculo dos 20%, ao quantificar os desempenhos.
// Por exemplo, para o caso de um total de 12 alunos, a restrição de 20% implicará nos
// dois melhores desempenhos;
// Pertencer ao "Quinto superior" significa que as notas do aluno estão no primeiro quinto
// contendo as notas mais altas da turma.  Por exemplo, si Paulo está no quinto superior
// de um grupo de 50 alunos, significa que as suas notas estão entre as 10 melhores do grupo.
// Exemplo de Entrada
// 9.00 4.00 5.00 8.60 7.01 7.00 8.50 6.00 7.01 6.00 -1
// 3.10 6.00 9.00 8.50 1.02 7.00 8.50 6.50 7.80 6.50 -1
// Exemplo de Saída
// 9.00
// 8.60
// 8.50

#include <stdio.h>

void ordenar(double* vet, int n){

	int i, j, imenor;
	double aux;

	for(i = 0; i < n - 1; i++){

		imenor = i;

		for(j = i + 1; j < n; j++){

			if(vet[imenor] < vet[j]) imenor = j;

		}

		aux = vet[i];
		vet[i] = vet[imenor];
		vet[imenor] = aux;

	}

}

int main(void){

	double ant, nota, notas[120];
	int quinto, cont, contA, contB;

	scanf("%lf", &nota);

	for(contA = 0; nota != -1; contA++){

		notas[contA] = nota;

		scanf("%lf", &nota);

	}

	scanf("%lf", &nota);

	for(contB = contA; nota != -1; contB++){

		notas[contB] = nota;

		scanf("%lf", &nota);

	}

	ordenar(notas, contB);

	quinto = contB/5;

	ant = notas[0];

	printf("%.2lf\n", ant);

	for(cont = 1; cont < quinto; cont++){

		if(notas[cont] != ant){

			printf("%.2lf\n", notas[cont]);

			ant = notas[cont];

		}

	}

	return 0;

}