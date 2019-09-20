// Enunciado
// O Mecanismo de controle de congestionamento do protocolo de transporte
// orientado a conexão da PIlha TCP/IP, atual para evita o congestionamento
// da Internet, em um cenário em que todas as fontes (computadores) conectados
// transmitissem seus dados com base na Capacidade nominal de suas conexões.
// O mecanismo de controle, portanto, usando de uma Janela de transmissão,
// envia uma certa quantidade de dados, limitado pelo tamanho da Janela, e
// guarda a confirmação de recebimento. Dois eventos podem indicar que houve
// problemas na última transmissão, ACK duplicados e TimeOut. De acordo com
// esses eventos o mecanismo diminui o tamanho da janela. Se o evento for um
// ACK duplicado então o tamanho da Janela é reduzida pela Metada, caso seja
// um evento de TimeOut o tamanho da janela é resetado para UMA unidade.
// O crescimento do tamanho da Janela é feito de forma exponencial, sendo
// 2(dois) a base da potência, e seu expoente é a rodada de transmissão,
// que é iniciada com valor 0. Esse padrão de crescimento é alterando, para
// um crescimento linear, quando em rodadas anteriores ocorreu qualquer um
// dos eventos de perdas, então um limite é estabelecido para o crescimento
// exponencial. Tal limite é definido como sendo metade do tamanho da janela,
// na rodada de transmissão, aonde ocorreu o evento de perda, ACK Duplicado
// ou TimeOut.
// Neste trabalho você deve analisar um sequência de número que mostra a evolução
// do tamanho da janela de congestionamento, durante uma sessão de transmissão,
// e identificar os eventos de ACK Duplicados, e os eventos de TimeOut. A sequência
// será encerrada quando um valor menor que 1 for encontrado.

// Exemplo de Entrada
// 1 2 4 8 16 32 64 128 64 65 66 67 68 34 35 36 37 38 19 20 21 22 1 2 4 8 11 12 13 14 15 16 1 2 4 8 9 10 11 -1
// Exemplo de Saída
// AckD: 3
// TimeOut: 2

#include <stdio.h>

int main(void){

	int num, ack = 0, timeout = 0;

	scanf("%d", &num);

	while(num >= 1){

		int ant = num;

		scanf("%d", &num);

		if(num == ant/2) ack++;
		else if(num == 1) timeout++;

	}

	printf("AckD: %d\n", ack);
	printf("TimeOut: %d\n", timeout);

	return 0;

}