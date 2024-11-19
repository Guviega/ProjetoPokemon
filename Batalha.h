#include <stdbool.h>
#include "Treinador.h"
#include "Pokemon.h"
#include "Ginasio.h"

struct batalha{
	int codigo;
	Pokemon p1, p2, vencedor;
	Ginasio g;
};

typedef struct batalha Batalha;

bool InicializarBatalhas();
bool EncerrarBatalhas();
Batalha* listaBatalhas();
Pokemon* RealizarBatalha(Pokemon p1, Pokemon p2, Ginasio g);
float getAtqTotalP1();
float getDefTotalP2();
float getAtqTotalP1();
float getDefTotalP2();
int QuantidadeBatalhas();
int BatalhasDoTreinador(int codigo);
int BatalhasDoGinasio(int codigo);
Batalha* ObterBatalhaPeloCodigo(int codigo);


