#include <stdbool.h>

struct pokemon{
	int codigo, dono;
	char nome[30];
	float vida, ataque, defesa;
};

typedef struct pokemon Pokemon;

bool InicializarPokemons();
bool EncerraPokemons();
Pokemon* listaPokemon();
bool SalvarPokemon(Pokemon p);
int QuantidadePokemon();
Pokemon* ObterPokemonPeloCodigo(int codigo);
bool AtualizarPokemon(Pokemon p);
bool ApagarPokemonPeloCodigo(int codigo);


