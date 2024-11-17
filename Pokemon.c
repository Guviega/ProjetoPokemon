#include <String.h>
#include <stdlib.h>
#include "Pokemon.h"

#define INICIAL_QTD_POKEMONS 6;

int qtdPokemon = INICIAL_QTD_POKEMONS;;
int tamArrayPokemon = INICIAL_QTD_POKEMONS;
Pokemon* arrayPokemon;

bool InicializarPokemons() {
	arrayPokemon = (Pokemon*)malloc(tamArrayPokemon * sizeof(Pokemon));
    if (arrayPokemon == NULL) {
        return false; 
    }


    for (int i = 0; i < tamArrayPokemon; i++) {
        arrayPokemon[i].codigo = 0;
        strcpy(arrayPokemon[i].nome, "");
        arrayPokemon[i].vida = 0;
        arrayPokemon[i].ataque = 0;
        arrayPokemon[i].defesa = 0;
        arrayPokemon[i].dono = 0;
    }
    
    arrayPokemon[0].codigo = 1;
    strcpy(arrayPokemon[0].nome, "Pichaku");
    arrayPokemon[0].dono = 1;
    arrayPokemon[0].vida = 100;
    arrayPokemon[0].vida = 100;
    arrayPokemon[0].vida = 100;
}

bool EncerraPokemons() {	
	free(arrayPokemon);
}

Pokemon* listaPokemon() {
	return arrayPokemon;
}

bool SalvarPokemon(Pokemon p) {
	// guardar no array
	// se necessario, aumentar o array para guardar (realloc)
	int i;
	for(i = 0; i < qtdPokemon; i++) {
		if(arrayPokemon[i].codigo == 0) {
			arrayPokemon[i].codigo = i+1;
			strcpy(arrayPokemon[i].nome, p.nome);
			arrayPokemon[i].vida = p.vida;
			arrayPokemon[i].ataque = p.ataque;
			arrayPokemon[i].defesa = p.defesa;
			arrayPokemon[i].dono = p.dono;

			break;
		}
		if(i == qtdPokemon-1) {
			qtdPokemon++;
			arrayPokemon = realloc(arrayPokemon, qtdPokemon*sizeof(Pokemon)); 
			arrayPokemon[qtdPokemon-1].codigo = 0;
		}
	}
}

int QuantidadePokemon() {
	return qtdPokemon;
}

Pokemon* ObterPokemonPeloCodigo(int codigo) {
	
}

bool AtualizarPokemon(Pokemon p) {
	
}

bool ApagarPokemonPeloCodigo(int codigo) {
	int indice = -1;
    
    for (int i = 0; i < qtdPokemon; i++) {
        if (arrayPokemon[i].codigo == codigo) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        return false;
    }

    for (int i = indice; i < qtdPokemon - 1; i++) {
        arrayPokemon[i] = arrayPokemon[i + 1];
        if(arrayPokemon[i].codigo != 0)
        arrayPokemon[i].codigo--;
    }

    qtdPokemon--;

    if (qtdPokemon < tamArrayPokemon / 2 && tamArrayPokemon > 3) {
        tamArrayPokemon /= 2;
        Pokemon* temp = (Pokemon*)realloc(arrayPokemon, tamArrayPokemon * sizeof(Pokemon));
        if (temp != NULL) {
            arrayPokemon = temp;
        }
    }
}
