#include <stdio.h>
#include <string.h>

typedef struct jogador {
	int pont;
	int aposta;
	int total;
	char nome[100];
} Jogador;

// incializa um jogador, dado o seu nome
Jogador initJogador(char *nome){
	Jogador player;
	strcpy(player.nome, nome);
	player.aposta = 0;
	player.pont = 0;
	player.total = 0;
	return player;
}

// atualiza o valor da aposta no inicio de uma partida
void initPartida(Jogador *j, int aposta){
	j->aposta = aposta;
	j->pont = 0;
	return;
}

// impreme na tela no nome de um jogador
void imprimeJogador(Jogador j){
	printf("%s\n", j.nome);
	return;
}

// adiciona o valor de uma carta a pontuacao do jogador
void somaPonto(Jogador *j, int valor){
	j->pont+=valor;
	return;
}

// retorna o valor da pontuacao do jogador
int retornaPonto(Jogador j){
	return j.pont;
}

// imprime na tela o valor ganho ou perdido pelo jogador
void imprimeResultado(Jogador j){
	if (j.total>=0){
		printf("%s, voce ganhou %d reais.\n", j.nome, j.total);
	}
	else{
		j.total = -j.total;
		printf("%s, voce perdeu %d reais.\n", j.nome, j.total);
	}
	return;
}

// atualiza o total de dinheiro do jogador e imprime na tela que ele ganhou
void vitoria(Jogador *j){
	printf("Voce ganhou!\n");
	j->total += j->aposta;
}

// atualiza o total de dinheiro do jogador e imprime na tela que ele perdeu
void derrota(Jogador *j){
	printf("Voce perdeu!\n");
	j->total -= j->aposta;
	return;
}