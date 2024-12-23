#include <String.h>
#include <stdlib.h>
#include "Batalha.h"

#define INICIAL_QTD_BATALHAS 6

int qtdBatalhas = INICIAL_QTD_BATALHAS;
int tamArrayBatalhas = INICIAL_QTD_BATALHAS;
Batalha* arrayBatalhas;

bool InicializarBatalhas() {
	arrayBatalhas = (Batalha*)malloc(tamArrayBatalhas * sizeof(Batalha));
    if (arrayBatalhas == NULL) {
        return false; 
    }


    for (int i = 0; i < tamArrayBatalhas; i++) {
        arrayBatalhas[i].codigo = 0;
    }
}

bool EncerrarBatalhas() {
	free(arrayBatalhas);
}

Batalha* listaBatalhas() {
	Batalha* temp = arrayBatalhas;
	return temp;
}

Pokemon* RealizarBatalha(Pokemon p1, Pokemon p2, Ginasio g) {

	Pokemon* vencedor = malloc(sizeof(Pokemon));
	
	float scorePokemon1 = (p1.ataque*(1+ObterTreinadorPeloCodigo(p1.dono)->bonusAtq)) + (p1.defesa*(1+ObterTreinadorPeloCodigo(p1.dono)->bonusDef)) * p1.vida / 100;
	float scorePokemon2 = (p2.ataque*(1+ObterTreinadorPeloCodigo(p2.dono)->bonusAtq)) + (p2.defesa*(1+ObterTreinadorPeloCodigo(p2.dono)->bonusDef)) * p2.vida / 100;
	
	Treinador* t1 = ObterTreinadorPeloCodigo(p1.dono);
	Treinador* t2 = ObterTreinadorPeloCodigo(p2.dono);
	
	if(scorePokemon1 > scorePokemon2) {
		vencedor = &p1;
		t1->vitorias++;
		t2->derrotas++;
	}
	else if(scorePokemon2 > scorePokemon1) {
		vencedor = &p2;
		t2->vitorias++;
		t1->derrotas++;
	}
	else if(scorePokemon1 == scorePokemon2)
		vencedor = NULL;
	
	AtualizarTreinador(*t1); AtualizarTreinador(*t2);
	free(t1); free(t2);
		
	int i;
	for(i = 0; i < qtdBatalhas; i++) {
		if(arrayBatalhas[i].codigo == 0) {
			arrayBatalhas[i].codigo = i+1;
			arrayBatalhas[i].p1 = p1;
			arrayBatalhas[i].p2 = p2;
			arrayBatalhas[i].vencedor = *vencedor;
			arrayBatalhas[i].g = g;
			break;
		}
		if(i == qtdBatalhas-1) {
			qtdBatalhas++;
			arrayBatalhas = realloc(arrayBatalhas, qtdBatalhas*sizeof(Batalha)); 
			arrayBatalhas[qtdBatalhas-1].codigo = 0;
		}
	}
		
	return vencedor;
}

int QuantidadeBatalhas() {
	return qtdBatalhas;
}

Batalha* ObterBatalhaPeloCodigo(int codigo) {
	Batalha* temp = malloc(sizeof(Batalha));
	*temp = arrayBatalhas[codigo-1];
	return temp;
}
