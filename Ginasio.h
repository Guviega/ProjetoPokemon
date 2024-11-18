#include <stdbool.h>

struct ginasio{
	int codigo;
	char nome[30], bairro[30];
	int capacidade;
};

typedef struct ginasio Ginasio;

bool InicializarGinasios();
bool EncerrarGinasios();
Ginasio* listaGinasios();
bool SalvarGinasio(Ginasio g);
int QuantidadeGinasios();
Ginasio* ObterGinasioPeloCodigo(int codigo);
bool ApagarGinasioPeloCodigo(int codigo);


