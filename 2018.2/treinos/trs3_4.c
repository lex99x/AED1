// Enunciado
// Um criador de cães descobriu que seus clientes estão interessados em filhotes com um
// certo perfil dentro da ninhada. Especificamente, os clientes têm mostrado interesse
// em filhotes mais velhos, os primeiros a nascer. Dado a grande quantidade de ninhadas,
// o criador tem registrado os nascimentos com data e hora de cada filhote. O criador
// gerou um registro de várias ninhadas e pediu para você escrever um programa que indique,
// para cada ninhada, a data e hora de nascimento do mais velho e o segundo mais velho filhote.
// Dicas
// Considere que:
// 1) Filhotes de uma ninhada de cachorros podem nascer com até 12 horas de diferença;
// 2) Uma ninhada encerra-se quando um registro de nascimento for igual a 0000-00-00 00:00:00,
// i.e ano igual a 0(zero)
// 3) Um ninhada vazia significa que todas as ninhadas foram processadas, e um programa deve
// então ser encerrado;
// 4) Ninhadas não vazias tiveram pelo menos 2(dois) filhotes.
// 5) Como o criatório foi aberto em 01/01/2000, uma função que calcula quanto dias se passaram
// desde a abertura do criatório e fornecida para você. Veja o código na dica.
// Exemplo de Entrada
// 2017-04-07 01:45:01
// 2017-04-07 04:30:05
// 2017-04-06 20:30:01
// 2017-04-07 06:00:21
// 2017-04-06 21:30:05
// 0000-00-00 00:00:00
// 2017-04-07 06:30:03
// 2017-04-06 23:30:07
// 2017-04-06 22:30:11
// 2017-04-07 01:30:01
// 2017-04-07 05:00:11
// 2017-04-07 02:30:02
// 2017-04-07 03:15:01
// 0000-00-00 00:00:00
// 0000-00-00 00:00:00
// Exemplo de Saída
// Ninhada:1
// 2017-04-06 20:30:01
// 2017-04-06 21:30:05
// Ninhada:2
// 2017-04-06 22:30:11
// 2017-04-06 23:30:07

#include <time.h>
#include <stdio.h>

// Exemplo de uso
// int ano=2001, mes=1, dia=1;
// int dias = emdiasdesde2000(ano, mes,dia);

int emdiasdesde2000(int ano, int mes, int dia){

	int ano2000=2000, mes01=1, dia01=1;

	struct tm dt1 = (struct tm){.tm_year=ano-1900, .tm_mon=mes-1, .tm_mday=dia};
	time_t tempo1 = mktime(&dt1);

	struct tm dt2 = (struct tm){.tm_year=ano2000-1900, .tm_mon=mes01-1, .tm_mday=dia01};
	time_t tempo2 = mktime(&dt2);

	double seconds = difftime(tempo1, tempo2);

	seconds = (seconds<0?seconds*-1:seconds);

	return seconds/(24*60*60);

}

unsigned long emsegundosdesde2000(int ano, int mes, int dia, int hora, int min, int seg){

	return emdiasdesde2000(ano, mes, dia) * 86400 + hora * 3600 + min * 60 + seg;

}

int main(void){

	int contNinhada = 1;
	int ano, mes, dia, hora, min, seg, idade;
	int anoVelho, mesVelho, diaVelho, horaVelho, minVelho, segVelho;
	int anoNovo, mesNovo, diaNovo, horaNovo, minNovo, segNovo;
	unsigned long idadeVelho, idadeNovo;

	scanf("%d-%d-%d %d:%d:%d", &anoVelho, &mesVelho, &diaVelho, &horaVelho, &minVelho, &segVelho);

	while(anoVelho != 0){

		scanf("%d-%d-%d %d:%d:%d", &anoNovo, &mesNovo, &diaNovo, &horaNovo, &minNovo, &segNovo);

		idadeVelho = emsegundosdesde2000(anoVelho, mesVelho, diaVelho, horaVelho, minVelho, segVelho);
		idadeNovo = emsegundosdesde2000(anoNovo, mesNovo, diaNovo, horaNovo, minNovo, segNovo);

		if(idadeNovo < idadeVelho){

			idade = idadeVelho; idadeVelho = idadeNovo; idadeNovo = idade;

			ano = anoVelho; mes = mesVelho; dia = diaVelho;
			hora = horaVelho; min = minVelho; seg = segVelho;

			anoVelho = anoNovo; mesVelho = mesNovo; diaVelho = diaNovo;
			horaVelho = horaNovo; minVelho = minNovo; segVelho = segNovo;

			anoNovo = ano; mesNovo = mes; diaNovo = dia;
			horaNovo = hora; minNovo = min; segNovo = seg;

		}

		scanf("%d-%d-%d %d:%d:%d", &ano, &mes, &dia, &hora, &min, &seg);
		idade = emsegundosdesde2000(ano, mes, dia, hora, min, seg);

		while(ano != 0){

	 		if(idade < idadeVelho){

				idadeNovo = idadeVelho; idadeVelho = idade;

	 			anoNovo = anoVelho; mesNovo = mesVelho; diaNovo = diaVelho;
	 			horaNovo = horaVelho; minNovo = minVelho; segNovo = segVelho;

	 			anoVelho = ano; mesVelho = mes; diaVelho = dia;
	 			horaVelho = hora; minVelho = min; segVelho = seg;

	 		}else if(idade < idadeNovo){

				idadeNovo = idade;

				anoNovo = ano; mesNovo = mes; diaNovo = dia;
				horaNovo = hora; minNovo = min; segNovo = seg;

			}

	 		scanf("%d-%d-%d %d:%d:%d", &ano, &mes, &dia, &hora, &min, &seg);
	 		idade = emsegundosdesde2000(ano, mes, dia, hora, min, seg);

	 	}

	 	printf("Ninhada:%d\n", contNinhada);
	 	printf("%4d-%02d-%02d %02d:%02d:%02d\n", anoVelho, mesVelho, diaVelho, horaVelho, minVelho, segVelho);
	 	printf("%4d-%02d-%02d %02d:%02d:%02d\n", anoNovo, mesNovo, diaNovo, horaNovo, minNovo, segNovo);

		scanf("%d-%d-%d %d:%d:%d", &anoVelho, &mesVelho, &diaVelho, &horaVelho, &minVelho, &segVelho);

		contNinhada++;

	}

	return 0;

}