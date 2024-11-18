#include <String.h>
#include <stdlib.h>
#include "Treinador.h"

#define INICIAL_QTD_TREINADORES 6

int qtdTreinadores = INICIAL_QTD_TREINADORES;
int tamArrayTreinadores = INICIAL_QTD_TREINADORES;
Treinador* arrayTreinador;

bool InicializarTreinadores()
{
	// alocar o array (malloc)
	// criar alguns casos de teste
	//return true;
	arrayTreinador = (Treinador*)malloc(tamArrayTreinadores * sizeof(Treinador));
    if (arrayTreinador == NULL) {
        return false; 
    }


    for (int i = 0; i < tamArrayTreinadores; i++) {
        arrayTreinador[i].codigo = 0;
        strcpy(arrayTreinador[i].nome, "");
        arrayTreinador[i].bonusAtq = 0;
        arrayTreinador[i].bonusDef = 0;
    }
    
    arrayTreinador[0].codigo = 1;
    strcpy(arrayTreinador[0].nome, "Claudinho");
    
    arrayTreinador[1].codigo = 2;
    strcpy(arrayTreinador[1].nome, "Roberto");
    arrayTreinador[1].bonusAtq = 1.1;
    arrayTreinador[1].bonusDef = 1.15;
    
    return true;
}

bool EncerraTreinadores ()
{
	//liberar a memoria do array (free)
	free(arrayTreinador);
}

Treinador* listaTreinadores() {
	return arrayTreinador;
}

bool SalvarTreinador(Treinador t)
{
	// guardar no array
	// se necessario, aumentar o array para guardar (realloc)
	int i;
	for(i = 0; i < qtdTreinadores; i++) {
		if(arrayTreinador[i].codigo == 0) {
			arrayTreinador[i].codigo = i+1;
			strcpy(arrayTreinador[i].nome, t.nome);
			arrayTreinador[i].bonusAtq = t.bonusAtq;
			arrayTreinador[i].bonusDef = t.bonusDef;
			break;
		}
		if(i == qtdTreinadores-1) {
			qtdTreinadores++;
			arrayTreinador = realloc(arrayTreinador, qtdTreinadores*sizeof(Treinador)); 
			arrayTreinador[qtdTreinadores-1].codigo = 0;
		}
	}
}

int QuantidadeTreinadores(){
	return qtdTreinadores;
}

Treinador* ObterTreinadorPeloCodigo(int codigo)
{
	return &arrayTreinador[codigo - 1];
}

bool AtualizarTreinador(Treinador t)
{
	Treinador *at = &arrayTreinador[t.codigo-1]; //ANTIGO TREINADOR
	strcpy(at->nome, t.nome);
	at->bonusAtq = t.bonusAtq;
	at->bonusDef = t.bonusDef;
}

bool ApagarTreinadorPeloCodigo(int codigo)
{
	// remove do array.
	// se necessario, reorganiza os dados no array
	// se necessario, diminui o tamanho do array (realloc)
	int indice = -1;
    
    for (int i = 0; i < qtdTreinadores; i++) {
        if (arrayTreinador[i].codigo == codigo) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        return false;
    }

    for (int i = indice; i < qtdTreinadores - 1; i++) {
        arrayTreinador[i] = arrayTreinador[i + 1];
        if(arrayTreinador[i].codigo != 0)
        arrayTreinador[i].codigo--;
    }

    qtdTreinadores--;

    if (qtdTreinadores < tamArrayTreinadores / 2 && tamArrayTreinadores > 3) {
        tamArrayTreinadores /= 2;
        Treinador* temp = (Treinador*)realloc(arrayTreinador, tamArrayTreinadores * sizeof(Treinador));
        if (temp != NULL) {
            arrayTreinador = temp;
        }
    }
}
