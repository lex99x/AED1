// Enunciado
// Mateus, um calouro de engenharia, está desenvolvendo uma nova notação
// posicional para representar números inteiros. Ele o apelidou de
// "A Curious Method" ("Um Método Curioso"), representado pela sigla ACM.
// A notação ACM usa os mesmos dígitos que a notação decimal, isto é, de 0 a 9.
// Para converter um número A da notação ACM para a notação decimal, você deve
// adicionar k termos, onde k é o número de dígitos de A (na notação ACM),
// O valor do i-ésimo termo, correspondente ao i-ésimo dígito ai, contando da
// direita para a esquerda, é ai × i!. Por exemplo, 719ACM é equivalente a 5310,
// já que 7 × 3! + 1 × 2! + 9 × 1! = 53.
// Mateus acabou de iniciar seus estudos sobre teoria dos números, e provavelmente
// não sabe quais propriedades um sistema numérico deve ter, mas no momento, ele só
// está interessado em converter um número de ACM para decimal. Você pode ajudá-lo?
// Dicas
// Entrada
// Cada caso de teste é dado por uma única linha não-nula contendo, no máximo,
// 5 dígitos, representando um número na notação ACM. A linha não possui zeros no início.
// O último caso de teste é representado por uma linha contendo um único zero.
// Saída
// Para cada caso de teste, escreva uma única linha contendo a representação decimal
// do número ACM correspondente.
// Exemplo de Entrada
// 719
// 1
// 15
// 110
// 102
// 0
// Exemplo de Saída
// 53
// 1
// 7
// 8
// 8

#include <stdio.h>
#include <math.h>

int fat(int num){

	if(num == 0){

		return 1;

	}else return num * fat(num - 1);

}

int dig(int num){

	if(num >= 1 && num <= 9){

		return 1;

	}else if(num >= 10 && num <= 99){

		return 2;

	}else if(num >= 100 && num <= 999){

		return 3;

	}else if(num >= 1000 && num <= 9999){

		return 4;

	}else{

		return 5;

	}

}

int dec(int acm){

	int prim, div, dec = 0, digQuant;

	digQuant = dig(acm);

	while(digQuant > 0){

		div = pow(10, digQuant - 1);
		prim = acm/div;
		dec += prim * fat(digQuant);
		acm -= prim * div;
		digQuant--;

	}

	return dec;

}

int main(void){

	int acm;

	scanf("%d", &acm);

	while(acm != 0){

		printf("%d\n", dec(acm));

		scanf("%d", &acm);

	}

	return 0;

}