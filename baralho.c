#include <stdio.h>
#define TAM_BARALHO 52

typedef struct carta {
	char naipe;
	int valor;
} Carta;

typedef struct baralho {
	Carta cartas[TAM_BARALHO];
	int posicao;
} Baralho;


//funcao auxiliar para retornar o valor da carta recebendo o nome
int valor_carta(char x){ 
    if (x=='A') return 1;
    else if (x=='J'|| x=='K' || x=='Q' || x=='0') return 10;
    return x-48; //convertendo o char para inteiro, baseado na tabela ascii q tem o 0 como 48
}


// le os valores das 52 cartas dados pela entrada padrão
Baralho leituraBaralho(){
	char Naipe, nome;
	Baralho deck;
	for (int i=0; i<52; i++){
		scanf(" %c%c", &nome, &Naipe);
		deck.cartas[i].naipe = Naipe;
		deck.cartas[i].valor = valor_carta(nome);
	}
	deck.posicao = 0;
	return deck;
}

// retorna a proxima carta do deck
int sorteiaCarta(Baralho *b){
	int Valor;
	int pos = b->posicao;
	Valor = b->cartas[pos].valor;
	b->posicao++;
	printf("Carta: %d-%c\n", Valor, b->cartas[pos].naipe);
	return Valor;
	}