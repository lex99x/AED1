#include <stdio.h>

//double maior(double n1, double n2, double n3, double n4){

	//double maior = n1;

	//if(n2 > maior){

		//maior = n2;

	//}

	//if(n3 > maior){

		//maior = n3;

	//}

	//if(n4 > maior){

		//maior = n4;

	//}

	//return maior;

//}

//double menor(double n1, double n2, double n3, double n4){

	//double menor = n1;

	//if(n2 < menor){

		//menor = n2;

	//}

	//if(n3 < menor){

		//menor = n3;

	//}

	//if(n4 < menor){

		//menor = n4;

	//}

	//return menor;

//}

//double smaior(double n1, double n2, double n3, double n4){

	//double aux, smaior = n1, maior = n2;

	//if(smaior > maior){

		//aux = smaior;
		//smaior = maior;
		//maior = aux;

	//}

	//if(n3 > maior){

		//aux = maior;
		//maior = n3;
		//smaior = aux;

	//}else if(n3 > smaior){

		//smaior = n3;

	//}

	//if(n4 > maior){

		//aux = maior;
		//maior = n4;
		//smaior = aux;

	//}else if(n4 > smaior){

		//smaior = n4;

	//}

	//return smaior;


//}

//double smenor(double n1, double n2, double n3, double n4){

	//double aux, smenor = n1, menor = n2;

	//if(smenor < menor){

		//aux = smenor;
		//smenor = menor;
		//menor = aux;

	//}

	//if(n3 < menor){

		//aux = menor;
		//menor = n3;
		//smenor = aux;

	//}else if(n3 < smenor){

		//smenor = n3;

	//}

	//if(n4 < menor){

		//aux = menor;
		//menor = n4;
		//smenor = aux;

	//}else if(n4 < smenor){

		//smenor = n4;

	//}

	//return smenor;


//}

int main(void){

	double maior, menor, smaior, smenor;

	scanf("%lf %lf", &menor, &smenor);

	if(smenor < menor){

		smaior = menor;
		menor = smenor;
		smenor = smaior;

	}

	scanf("%lf", &smaior);

	if(smaior < menor){

		maior = menor;
		menor = smaior;
		smaior = smenor;
		smenor = maior;

	}else if(smaior > menor && smaior < smenor){

		maior = smenor;
		smenor = smaior;
		smaior = maior;

	}

	scanf("%lf", &maior);

	//if(maior < menor){



	//}

	printf("%.1lf %.1lf %.1lf %.1lf\n", menor, smenor, smaior, maior);

	//M2M = (smaior(n1, n2, n3, n4) + smenor(n1, n2, n3, n4))/2.0;
	//MP = (M2M * 8 + maior(n1, n2, n3, n4) + menor(n1, n2, n3, n4))/10.0;

	//printf("%.2lf\n", MP);

	return 0;

}