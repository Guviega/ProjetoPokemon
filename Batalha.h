#include <stdbool.h>

struct bataha{
	int codigo;
	char nome[30], bairro[30];
	int capacidade;
};

typedef struct batalha Batalha;

bool InicializarBatalhas();
bool EncerrarBatalhas();
Ginasio* listaGinasios();
bool SalvarGinasio(Ginasio g);
int QuantidadeGinasios();
Ginasio* ObterGinasioPeloCodigo(int codigo);
bool ApagarGinasioPeloCodigo(int codigo);


