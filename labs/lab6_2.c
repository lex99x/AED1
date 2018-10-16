// Enunciado
// Temperatura média ao longo do dia
// Objetivo: Tratamento de dados para cálculo da média
// Seja S uma sequência de tuplas onde se registrou, ao longo do dia,
// as variações de temperatura de uma adega. Cada tupla em S é formada
// por uma tempo (hora:minuto:segundo) e a temperatura registrada na sala (valor real).
// Para se estimar a temperatura média da sala, além do cálculo convencional de média aritmética,
// decidiu-se excluir da sequência os outliners , isto é, a menor e a maior temperatura evitando
// assim que eles afetem a média.
// Implemente um programa que resolva este problema, considerando que uma hora igual a 25
// indica o final da sequência, essa tupla não faz parte dos valores observados.
// Seu programa deve imprimir:
// O texto "Média:" seguido do valor da média, com duas casas decimais
// O texto "Variações da Temperatura:" seguido das tuplas em S, sem os outliners
// Dicas
// outliners = os pontos fora da curva.
// valores iguais aos outliners devem ser desconsiderados da sequência no cálculo da média.
// use apenas DUAS casas decimais para gerar a saída
// use o tipo double para expressar a média das temperaturas.
// Exemplo de Entrada
// 20:18:09 26.9
// 20:58:09 32.1
// 21:15:05 28.9
// 21:18:19 27.5
// 21:38:09 27.8
// 21:58:09 30.9
// 22:00:09 18.9
// 22:10:00 19.8
// 22:18:09 18.9
// 22:22:22 32.1
// 25:00:00 500
// Exemplo de Saída
// Média: 26.97
// Variações da Temperatura:
// 20:18:09 26.9
// 21:15:05 28.9
// 21:18:19 27.5
// 21:38:09 27.8
// 21:58:09 30.9
// 22:10:00 19.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Implementação de vetor dinâmico pelo professor

typedef struct VD {
  int ocupacao, tamanho;
  void* *agregador;
} TVDinamico;

void inserir(TVDinamico *vd, void *novo, int pos){
  if (pos >= vd->tamanho){
	int anterior = vd->tamanho;

	int k = ceil(log2(pos));

	vd->tamanho = pow(2, k) + 1;
	vd->agregador = realloc(vd->agregador,vd->tamanho*sizeof(void*));
	memset(vd->agregador+anterior,'\0',(vd->tamanho-anterior)*sizeof(void*));
  }
  vd->agregador[pos] = novo;
  vd->ocupacao++;
}

void* acessar(TVDinamico vd, int indice){
	if (indice < vd.tamanho){
	  return vd.agregador[indice];
	}else
	  return NULL;
}

TVDinamico criarVD(int tamanho){
  TVDinamico vd ;
  vd.tamanho = tamanho;
  vd.ocupacao = 0;
  vd.agregador = malloc(vd.tamanho*sizeof(void*));

  memset(vd.agregador,'\0',vd.tamanho*sizeof(void*));

  return vd;
}

// Uso do vetor dinâmico

typedef struct{

	int hora;
	int min;
	int seg;
	double temp;

} Registro;

TVDinamico lerRegistros(void){

	TVDinamico registros = criarVD(5);

	Registro* registro = (Registro*) malloc(sizeof(Registro));

	int cont;

	scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> temp);

	for(cont = 0; registro -> hora != 25; cont++){

		inserir(&registros, registro, cont);

		registro = (Registro*) malloc(sizeof(Registro));

		scanf("%d:%d:%d %lf", &registro -> hora, &registro -> min, &registro -> seg, &registro -> temp);

	}

	free(registro);

	return registros;

}

int main(void){

	TVDinamico registros = lerRegistros();

	double menorTemp, maiorTemp;
	int cont;
	short primVez = 1;

	for(cont = 0; cont < registros.ocupacao; cont++){

		Registro* registro = acessar(registros, cont);

		if(primVez){

			primVez = 0;
			menorTemp = maiorTemp = registro -> temp;

		}else if(registro -> temp > maiorTemp){

			maiorTemp = registro -> temp;

		}else if(registro -> temp < menorTemp){

			menorTemp = registro -> temp;

		}

	}

	int i = 0;
	double soma = 0.0;

	for(cont = 0; cont < registros.ocupacao; cont++){

		Registro* registro = acessar(registros, cont);

		if((registro -> temp != maiorTemp) && (registro -> temp != menorTemp)){

			soma += registro -> temp;
			i++;

		}

	}

	double mediaTemp = soma/i;

	printf("Média: %.2lf\n", mediaTemp);

	printf("Variações da Temperatura:\n");

	for(cont = 0; cont < registros.ocupacao; cont++){

		Registro* registro = acessar(registros, cont);

		if((registro -> temp != maiorTemp) && (registro -> temp != menorTemp)){

			printf("%02d:%02d:%02d %.1lf\n", registro -> hora, registro -> min, registro -> seg, registro -> temp);

		}

	}

	return 0;

}