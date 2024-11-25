#include <String.h>
#include <stdlib.h>
#include "Ginasio.h"

#define INICIAL_QTD_GINASIOS 6

int qtdGinasios = INICIAL_QTD_GINASIOS;
int tamArrayGinasios = INICIAL_QTD_GINASIOS;
Ginasio* arrayGinasio;

bool InicializarGinasios() {
	arrayGinasio = (Ginasio*)malloc(tamArrayGinasios * sizeof(Ginasio));
    if (arrayGinasio == NULL) {
        return false; 
    }


    for (int i = 0; i < tamArrayGinasios; i++) {
        arrayGinasio[i].codigo = 0;
        strcpy(arrayGinasio[i].nome, "");
        strcpy(arrayGinasio[i].bairro, "");
        arrayGinasio[i].capacidade = 0;
    }
    
    arrayGinasio[0].codigo = 1;
    strcpy(arrayGinasio[0].nome, "Matriz Gymnasium");
    strcpy(arrayGinasio[0].bairro, "Centro");
    arrayGinasio[0].capacidade = 100;
    
    arrayGinasio[1].codigo = 2;
    strcpy(arrayGinasio[1].nome, "IFRS Gymanium");
    strcpy(arrayGinasio[1].bairro, "Albatroz");
    arrayGinasio[1].capacidade = 70;
}


bool EncerrarGinasios() {
	free(arrayGinasio);
}


Ginasio* listaGinasios() {
	Ginasio* temp = malloc(sizeof(Ginasio));
	temp = arrayGinasio;
	return temp;
}


bool SalvarGinasio(Ginasio g) {
	// guardar no array
	// se necessario, aumentar o array para guardar (realloc)
	int i;
	for(i = 0; i < qtdGinasios; i++) {
		if(arrayGinasio[i].codigo == 0) {
			arrayGinasio[i].codigo = i+1;
			strcpy(arrayGinasio[i].nome, g.nome);
			strcpy(arrayGinasio[i].bairro, g.bairro);
    		arrayGinasio[i].capacidade = g.capacidade;

			break;
		}
		if(i == qtdGinasios-1) {
			qtdGinasios++;
			Ginasio* temp = realloc(arrayGinasio, qtdGinasios*sizeof(Ginasio));
			if(temp != NULL)
			arrayGinasio = temp; 
			arrayGinasio[qtdGinasios-1].codigo = 0;
		}
	}
}


int QuantidadeGinasios() {
	return qtdGinasios;
}

Ginasio* ObterGinasioPeloCodigo(int codigo) {
	Ginasio* temp = malloc(sizeof(Ginasio));
	*temp = arrayGinasio[codigo-1];
	return temp;
}

bool ApagarGinasioPeloCodigo(int codigo) {
	int indice = -1;
    
    for (int i = 0; i < qtdGinasios; i++) {
        if (arrayGinasio[i].codigo == codigo) {
            indice = i;
            break;
        }
    }
    
    if (indice == -1) {
        return false;
    }

    for (int i = indice; i < qtdGinasios - 1; i++) {
        arrayGinasio[i] = arrayGinasio[i + 1];
        if(arrayGinasio[i].codigo != 0)
        arrayGinasio[i].codigo--;
    }

    qtdGinasios--;

    if (qtdGinasios < tamArrayGinasios / 2 && tamArrayGinasios > 3) {
        tamArrayGinasios /= 2;
        Ginasio* temp = (Ginasio*)realloc(arrayGinasio, tamArrayGinasios * sizeof(Ginasio));
        if (temp != NULL) {
            arrayGinasio = temp;
        }
    }
}
