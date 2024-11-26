#include <stdio.h>
#include <stdlib.h>
#include "Batalha.h"

void menuTreinadores();
void menuPokemons();
void menuGinasios();
void menuBatalhas();
void clear();
int o;

int main(int argc, char *argv[]) {
	InicializarTreinadores();
	InicializarPokemons();
	InicializarGinasios();
	InicializarBatalhas();
	
	int opcao;
    
    do {
        clear();
        printf("0 - Sair\n");
        printf("1 - Treinadores\n");
        printf("2 - Pokemons\n");
        printf("3 - Ginasios\n");
        printf("4 - Batalhas\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
            	clear();
                menuTreinadores();
                break;
            case 2:
            	clear();
                menuPokemons();
                break;
            case 3:
            	clear();
                menuGinasios();
                break;
            case 4:
            	clear();
                menuBatalhas();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    EncerraTreinadores();
    EncerraPokemons();
    EncerrarGinasios();
    EncerrarBatalhas();
    return 0;
}	

void menuTreinadores() {
   	int opcao;
    
    do {
        printf("0 - Voltar\n");
        printf("1 - Listar treinadores\n");
        printf("2 - Cadastrar treinador\n");
        printf("3 - Atualizar treinador pelo codigo\n");
        printf("4 - Excluir treinador pelo codigo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
            	//LISTAR TREINADORES
                clear();
                int i;
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t->nome, t->codigo, t->bonusAtq, t->bonusDef);
					free(t);
				}
                break;
            case 2:
            	//CADASTRO TREINADOR
            	clear();
                Treinador* t = malloc(sizeof(Treinador));
                t->codigo = 0;
                
                printf("Nome:\n");
                scanf("%s", &t->nome);
                printf("Bonus ATQ:\n");
                scanf("%f", &t->bonusAtq);
                printf("Bonus DEF:\n");
                scanf("%f", &t->bonusDef);
                
                SalvarTreinador(*t);
                free(t);
                break;
            case 3:
            	//ATUALIZAR TREINADOR
            	clear();
            	printf("Qual treinador deseja atualizar? (codigo)\n");
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t->nome, t->codigo, t->bonusAtq, t->bonusDef);
					free(t);
				}
				scanf("%d", &o);
                Treinador *tr = ObterTreinadorPeloCodigo(o);
                printf("Nome:\n");
                scanf("%s", &tr->nome);
                printf("Bonus ATQ:\n");
                scanf("%f", &tr->bonusAtq);
                printf("Bonus DEF:\n");
                scanf("%f", &tr->bonusDef);
                AtualizarTreinador(*tr);
                free(tr);
                break;
            case 4:
                printf("Qual treinador deseja excluir? (codigo)\n");
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t->nome, t->codigo, t->bonusAtq, t->bonusDef);
					free(t);
				}
                scanf("%d", &o);
                bool podeApagar = true;
                for(i = 0; i < QuantidadePokemon(); i++) {
                	if(ObterPokemonPeloCodigo(i+1)->dono == o) {
                		printf("Este treinador possui pokemons.\n");
                		podeApagar = false;
                		break;
					}
				}
				for(i = 0; i < QuantidadeBatalhas(); i++) {
                	if(ObterPokemonPeloCodigo(ObterBatalhaPeloCodigo(i+1)->p1.codigo)->dono == o || ObterPokemonPeloCodigo(ObterBatalhaPeloCodigo(i+1)->p2.codigo)->dono == o) {
                		printf("Este treinador ja batalhou.\n");
                		podeApagar = false;
                		break;
					}
				}
				if(podeApagar)
                ApagarTreinadorPeloCodigo(o);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void menuPokemons() {
    int opcao;
    
    do {
        printf("0 - Voltar\n");
        printf("1 - Listar Pokemons\n");
        printf("2 - Cadastrar Pokemon\n");
        printf("3 - Pesquisar Pokemon pelo nome\n");
        printf("4 - Excluir Pokemon pelo codigo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
                //LISTAR POKEMONS
                clear();
                int i;
                for(i = 0; i < QuantidadePokemon(); i++) {
                	Pokemon* p = ObterPokemonPeloCodigo(i+1);
                	if(p->codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p->nome, p->codigo, p->vida, p->ataque, p->defesa, p->dono, ObterTreinadorPeloCodigo(p->dono)->nome);
					free(p);
				}
                break;
            case 2:
                clear();
                Pokemon* p = malloc(sizeof(Pokemon));
                printf("Nome:\n");
                scanf("%s", &p->nome);
				printf("Codigo do dono?:\n");
				for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d\n", t->nome, t->codigo);
                	free(t);
				}
                scanf("%d", &p->dono);
				printf("Vida:\n");
                scanf("%f", &p->vida);
				printf("Ataque:\n");
                scanf("%f", &p->ataque);
				printf("Defesa:\n");
                scanf("%f", &p->defesa);
        		SalvarPokemon(*p);
        		free(p);
                break;
            case 3:
                //PESQUISAR POKEMON PELO NOME.
                clear();
                int encontrado = 0;
                printf("Qual o nome do pokemon?");
                char* nome = malloc(30);
                scanf("%s", nome);
                Pokemon* array = listaPokemon();
                for(i = 0; i < QuantidadePokemon(); i++) {
                	if(strcmp(nome, array[i].nome) == 0) {
                		Pokemon p = array[i];
                		clear();
                		printf("Pokemon encontrado!\n");
                		printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p.nome, p.codigo, p.vida, p.ataque, p.defesa, p.dono, ObterTreinadorPeloCodigo(p.dono)->nome);
                		encontrado = 1;
						break;
					}
				}
				if(encontrado == 0)
					printf("Pokemon nao encontrado.\n");
				free(nome);
                break;
            case 4:
            	//APAGAR POKEMON
            	clear();
                printf("Qual pokemon deseja excluir? (codigo)\n");
                for(i = 0; i < QuantidadePokemon(); i++) {
                	Pokemon *p = ObterPokemonPeloCodigo(i+1);
                	if(p->codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p->nome, p->codigo, p->vida, p->ataque, p->defesa, p->dono, ObterTreinadorPeloCodigo(p->dono)->nome);
					free(p);
				}
                scanf("%d", &o);
                bool podeApagar = true;
                for(i = 0; i < QuantidadeBatalhas(); i++) {
                	if(ObterBatalhaPeloCodigo(i+1)->p1.codigo == o || ObterBatalhaPeloCodigo(i+1)->p2.codigo == o) {
                		printf("Este pokemon ja batalhou.\n");
                		podeApagar = false;
                		break;
					}
				}
				if(podeApagar)
                ApagarPokemonPeloCodigo(o);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void menuGinasios() {
    int opcao;
    
    do {
        printf("0 - Voltar\n");
        printf("1 - Listar Ginasios\n");
        printf("2 - Cadastrar Ginasio\n");
        printf("3 - Pesquisar Ginasio\n");
        printf("4 - Excluir Ginasio\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
                //LISTAR GINASIOS
                clear();
                int i;
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	Ginasio *g = ObterGinasioPeloCodigo(i+1);
                	if(g->codigo != 0) 
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g->nome, g->codigo, g->capacidade, g->bairro);
                	free(g);
				}
                break;
            case 2:
            	clear();
                Ginasio* g = malloc(sizeof(Ginasio));
                printf("Nome:\n");
                scanf("%s", &g->nome);
                printf("Bairro:\n");
                scanf("%s", &g->bairro);
                printf("Capacidade:\n");
                scanf("%d", &g->capacidade);
                SalvarGinasio(*g);
                free(g);
                break;
            case 3:
            	//PESQUISAR GINASIO
                clear();
                int encontrado = 0;
                printf("Qual o bairro do ginasio?\n");
                char *bairro = malloc(30);
                scanf("%s", bairro);
                Ginasio* array = listaGinasios();
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	if(strcmp(bairro, array[i].bairro) == 0) {
                		Ginasio *g = ObterGinasioPeloCodigo(i+1);
                		clear();
                		printf("Ginasio no bairro %s encontrado!\n", bairro);
                		printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g->nome, g->codigo, g->capacidade, g->bairro);
                		encontrado = 1;
						break;
					}
				}
				if(encontrado == 0)
					printf("Ginasio nao encontrado neste bairro.\n");
				free(bairro);
				free(array);
                break;
            case 4:
                //APAGAR GINASIO
            	clear();
                printf("Qual ginasio deseja excluir? (codigo)\n");
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	Ginasio *g = ObterGinasioPeloCodigo(i+1);
                	if(g->codigo != 0) 
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g->nome, g->codigo, g->capacidade, g->bairro);
                	free(g);
				}
                scanf("%d", &o);
                ApagarGinasioPeloCodigo(o);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void menuBatalhas() {
    int opcao;
    
    do {
        printf("0 - Voltar\n");
        printf("1 - Listar batalhas do treinador\n");
        printf("2 - Listar batalhas do ginasio\n");
        printf("3 - Vitorias e derrotas do treinador\n");
        printf("4 - Realizar uma batalha\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                break;
            case 1:
            	clear();
                printf("Qual treinador deseja ver as batalhas? (codigo)\n");
                int i;
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d\n", t->nome, t->codigo);
                	free(t);
				}
                scanf("%d", &o);
                for(i = 0; i < QuantidadeBatalhas(); i++) {
                	Batalha b = listaBatalhas()[i];
                	if(b.codigo != 0 && (b.p1.dono==o || b.p2.dono==o)) 
                	printf("Batalha: %d Ginasio: %s Pokemon 1: %s Pokemon 2: %s Vencedor: %s\n", b.codigo, b.g.nome, b.p1.nome, b.p2.nome, b.vencedor.nome);
				}
                break;
            case 2:
            	clear();
                printf("Qual ginasio deseja ver as batalhas? (codigo)\n");
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	Ginasio *g = ObterGinasioPeloCodigo(i+1);
                	if(g->codigo != 0)
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g->nome, g->codigo, g->capacidade, g->bairro);
                	free(g);
                }
                scanf("%d", &o);
                for(i = 0; i < QuantidadeBatalhas(); i++) {
                	Batalha* b = ObterBatalhaPeloCodigo(i+1);
                	if(b->codigo != 0 && b->g.codigo==o) 
                	printf("Batalha: %d Ginasio: %s Pokemon 1: %s Pokemon 2: %s Vencedor: %s\n", b->codigo, b->g.nome, b->p1.nome, b->p2.nome, b->vencedor.nome);
					free(b);
				}
                break;
            case 3:
            	clear();
                printf("Qual treinador deseja ver os resultados? (codigo)\n");
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador* t = ObterTreinadorPeloCodigo(i+1);
                	if(t->codigo != 0) 
                	printf("Treinador: %s, Cod: %d\n", t->nome, t->codigo);
                	free(t);
				}
				scanf("%d", &o);
                printf("Vitorias: %d Derrotas %d\n", ObterTreinadorPeloCodigo(o)->vitorias, ObterTreinadorPeloCodigo(o)->derrotas);
                break;
            case 4:
            	clear();
            	printf("Qual ginasio deseja realizar a batalha? (codigo)\n");
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	Ginasio *g = ObterGinasioPeloCodigo(i+1);
                	if(g->codigo != 0)
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g->nome, g->codigo, g->capacidade, g->bairro);
                	free(g);
                }
                int gym;
                scanf("%d", &gym);
                printf("Qual pokemon deseja que batalhe? (codigo)\n");
                for(i = 0; i < QuantidadePokemon(); i++) {
                	Pokemon *p = ObterPokemonPeloCodigo(i+1);
                	if(p->codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p->nome, p->codigo, p->vida, p->ataque, p->defesa, p->dono, ObterTreinadorPeloCodigo(p->dono)->nome);
					free(p);
				}
				int pokemon1;
                scanf("%d", &pokemon1);
                printf("Qual pokemon deseja que batalhe? (codigo)\n");
                for(i = 0; i < QuantidadePokemon(); i++) {
                	Pokemon *p = ObterPokemonPeloCodigo(i+1);
                	if(p->codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p->nome, p->codigo, p->vida, p->ataque, p->defesa, p->dono, ObterTreinadorPeloCodigo(p->dono)->nome);
					free(p);
				}
				int pokemon2;
                scanf("%d", &pokemon2);
                if(pokemon1 == pokemon2){
                	clear();
                	printf("O pokemon nao pode batalhar com ele mesmo.\n");
                	break;
				} else {
					Pokemon* p1 = ObterPokemonPeloCodigo(pokemon1);
					Pokemon* vencedor = RealizarBatalha(*p1, *ObterPokemonPeloCodigo(pokemon2), *ObterGinasioPeloCodigo(gym));
					printf("Vencedor: %s\n", vencedor->nome);
					free(p1);
					//free(vencedor);
				}
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void clear() {
    int* contador = malloc(sizeof(int));
    for (*contador = 0; *contador < 50; (*contador)++)
	printf("\n");
	free(contador);
}
