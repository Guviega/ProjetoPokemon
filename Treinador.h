#include <stdbool.h>

struct treinador{
	int codigo;
	char nome[30];
	float bonusAtq, bonusDef;
	int vitorias, derrotas;
};

typedef struct treinador Treinador;

bool InicializarTreinadores();
bool EncerraTreinadores();
Treinador* listaTreinadores();
bool SalvarTreinador(Treinador t);
int QuantidadeTreinadores();
Treinador* ObterTreinadorPeloCodigo(int codigo);
bool ApagarTreinadorPeloCodigo(int codigo);


