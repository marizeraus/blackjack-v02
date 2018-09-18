#include <stdio.h>
#include "baralho.h"
#include "jogador.h"

int main(){

	char nome[100];
	Jogador j;
	char jogando = 'S';
	Baralho b;

	b=leituraBaralho();

	printf("Digite seu nome:\n");
	scanf("%s", nome);
	j = initJogador(nome);

	while(jogando=='S'){
		int aposta;
		int pontos;
		printf("Digite sua aposta:\n");
		scanf("%d", &aposta);
		initPartida(&j, aposta);
		char continua = 'S';
		char turn = 'P';

		imprimeJogador(j);

		while(continua=='S'){
			int sorteada;
			sorteada = sorteiaCarta(&b);
			somaPonto(&j, sorteada);
			pontos = retornaPonto(j);			
			if (pontos==21){
				turn = 'W';
				continua = 'N';
			}
			else if (pontos>21){
				turn = 'L';
				continua = 'N';
			}
			else{
				printf("Deseja continuar (S/N):\n");
				scanf(" %c", &continua);
				if (continua=='N'){
				 	turn = 'D';
				 }
			}

		}

		int pontos_dealer = 0;
		printf("Dealer\n");

		while (turn=='D'){
			while (pontos_dealer<17){
				pontos_dealer+=sorteiaCarta(&b);
			}
			if (pontos_dealer==21) turn = 'L';
			else if (pontos_dealer>21) turn ='W';
			else{
				if (pontos_dealer>retornaPonto(j)) turn = 'L' ;
				else turn = 'W';
			}
		}

		if (turn=='W'){
			vitoria(&j);
		}
		else{
			derrota(&j);
		} 

		printf("Deseja fazer nova aposta (S/N):\n");
		scanf(" %c", &jogando);

	}

	imprimeResultado(j);



	return 0;
}