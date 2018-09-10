// Enunciado
// Consolidação de Dados
// Em grandes fabricas existem espaços de convergências de trabalhadores
// de diferentes setores, seja por conta de atividades de convívio, seja por
// atividades relacionados as tarefas do trabalho.  O setor de segurança do
// trabalho detectou que existem situações, com grande fluxo, que pode ocasionar
// acidentes. Para confirmar essa suspeita foi instalado um sensor que consegue
// identificar o momento em que uma pessoa passa pela área. O sensor detecta se
// a pessoa está entrando ou saindo da área do espaço, e a hora em que ocorreu o evento.
// O sensor também é capaz de identificar o setor aonde a pessoa trabalha,
// administração ou chão da fabrica, fazendo a leitura da tag RFID instalado no crachá.
// Neste caso, o sensor trabalha gerando observações com base na movimentação, indicando,
// por setor, a quantidade de pessoas que entrou e saiu do espaço.
// Considere que:
// 1) A sequência gerada pelo sensor encerra-se quando um valor
// negativo for lido na coluna do tempo
// 2) Cada linha da entrada é formada por uma quintupla
// {tempo, entrandoADM, saindoADM, entrandoCHAO, saindoCHAO}
// 3) O tempo é dado em segundo desde o instante inicial do dia que gerou a sequência.
// Escreva um programa que consolide os dados de fluxo de pessoas no espaço monitorado.
// Deseja-se saber o total de entradas e saídas por setor, a média de pessoas que circulam
// no espaço por minuto, quando se teve a maior média de circulação, qual foi o intervalo
// de tempo que apresentou a maior média de circulação. Para responder as duas últimas
// questões, considere um intervalo de tempo de 60 segundos.
// Exemplo de Entrada
// 39837 18 1 95 4
// 39843 11 8 81 18
// 39847 16 3 78 21
// -1
// Exemplo de Saída
// ADM: 57
// CHO: 297
// Maior Fluxo: 5.90\min
// Periodo do Maior Fluxo: (11:03:57 - 11:04:57)

#include <stdio.h>
#define TIME_CONST 60.0

int main(void){

	int tempo, entrandoAdm, saindoAdm, entrandoCho, saindoCho;
	int tempoInicialFluxo, tempoMaiorFluxo, admFluxo, choFluxo, admTotal = 0, choTotal = 0;
	double fluxo, maiorFluxo, hora, min, seg;
	short primTupla = 1, primFluxo = 1;

	scanf("%d", &tempo);

	while(tempo >= 0){

		scanf("%d %d %d %d", &entrandoAdm, &saindoAdm, &entrandoCho, &saindoCho);

		admTotal += entrandoAdm + saindoAdm;
		choTotal += entrandoCho + saindoCho;

		if(primTupla){

			primTupla = 0;
			tempoInicialFluxo = tempo;
			admFluxo = entrandoAdm + saindoAdm;
			choFluxo = entrandoCho + saindoCho;

		}else{

			if((tempo - tempoInicialFluxo) > TIME_CONST){

				if(primFluxo){

					primFluxo = 0;
					maiorFluxo = fluxo;
					tempoMaiorFluxo = tempoInicialFluxo;

				}else if(fluxo > maiorFluxo){

					maiorFluxo = fluxo;
					tempoMaiorFluxo = tempoInicialFluxo;

				}

				tempoInicialFluxo = tempo;
				admFluxo = entrandoAdm + saindoAdm;
				choFluxo = entrandoCho + saindoCho;

			}else{

				admFluxo += entrandoAdm + saindoAdm;
				choFluxo += entrandoCho + saindoCho;

			}

		}

		fluxo = (admFluxo + choFluxo)/TIME_CONST;

		scanf("%d", &tempo);

	}

	if(primFluxo || (fluxo > maiorFluxo)){

		maiorFluxo = fluxo;
		tempoMaiorFluxo = tempoInicialFluxo;

	}

	hora = tempoMaiorFluxo/(TIME_CONST * TIME_CONST);
	min = (hora - (int) hora) * TIME_CONST;
	seg = (min - (int) min) * TIME_CONST;

	printf("ADM: %d\n", admTotal);
	printf("CHO: %d\n", choTotal);
	printf("Maior Fluxo: %.2lf\\min\n", maiorFluxo);
	printf("Periodo do Maior Fluxo: (%02d:%02d:%02d - %02d:%02d:%02d)\n", (int) hora,
	(int) min, (int) seg, (int) hora, (int) min + 1, (int) seg);

	return 0;

}