// Enunciado
// Monitorando o uso da sala de descanso
// Toda vez que o sistema de iluminação de uma sala de descanso é ligado
// registra-se que tal evento ocorreu, e toda vez que esse mesmo sistema
// foi desligado, também se registra o evento. De tal forma que ao final
// de um certo período de monitoramento tem-se o histórico de uso daquele sistema.
// Escreva um programa que encontre, nos registros do histórico, o maior intervalo
// de tempo que o sistema de iluminação da sala ficou ligado.
// Os registros são da seguinte forma:
// 1 10:00:00
// 0 10:10:00
// 1 10:25:00
// 0 12:00:00
// 2
// Cada linha registra o tipo de evento (acionou=1 desligou=0) e a hora em que ele ocorreu.
// Um tipo de evento igual a 2 (desconhecido) sinaliza que chegou-se ao fim do histórico de eventos.
// A saída do programa deve ser o maior tempo em segundos.
// Dicas
// Use o bizu passado em sala de aula.
// Quem é o candidato a maior intervalo?
// Trabalhe com segundos;
// Considere que o monitoramento começou e terminou no mesmo dia (24 horas).
// Exemplo de Entrada
// 1 10:00:00
// 0 10:10:00
// 1 10:25:00
// 0 10:30:00
// 2
// Exemplo de Saída
// 600

#include <stdio.h>

int segundos(int hora, int min, int seg){

	return hora * 3600 + min * 60 + seg;

}

int main(void){

	int tipo, maiorIntervalo = 0;

	scanf("%d", &tipo);

	while(tipo != 2){

		int hora, min, segInicio, segFim, intervalo;

		scanf("%d:%d:%d", &hora, &min, &segInicio);
		segInicio = segundos(hora, min, segInicio);

		scanf("%d %d:%d:%d", &tipo, &hora, &min, &segFim);
		segFim = segundos(hora, min, segFim);

		intervalo = segFim - segInicio;

		if(intervalo > maiorIntervalo) maiorIntervalo = intervalo;

		scanf("%d", &tipo);

	}

	printf("%d\n", maiorIntervalo);

	return 0;

}