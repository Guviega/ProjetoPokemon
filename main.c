#include <stdio.h>
#include <stdlib.h>
#include "Treinador.h"
#include "Pokemon.h"
#include "Ginasio.h"

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
	
	//printf("Quantidade de treinadores: %d", qtdTreinadores);
	//printf("Quantidade de treinadores: %d", QuantidadeTreinadores());
	
	//int vetor[3] = {5,7,9};
	//int *ponteiro = vetor+1;
	//printf("%d", *ponteiro);
	
	//int *vetor = malloc(3*sizeof(int));
	//vetor[0] = 10;
	//free(vetor);
	//printf("%d", vetor[0]);
	
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
                	Treinador t = listaTreinadores()[i];
                	if(t.codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t.nome, t.codigo, t.bonusAtq, t.bonusDef);
				}
                break;
            case 2:
            	clear();
                printf("Cadastrando treinador...\n");
                Treinador t;
                t.codigo = 0;
                
                printf("Nome:\n");
                scanf("%s", &t.nome);
                printf("Bonus ATQ:\n");
                scanf("%f", &t.bonusAtq);
                printf("Bonus DEF:\n");
                scanf("%f", &t.bonusDef);
                
                SalvarTreinador(t);
                break;
            case 3:
            	//ATUALIZAR TREINADOR
            	clear();
            	printf("Qual treinador deseja atualizar? (codigo)\n");
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador t = listaTreinadores()[i];
                	if(t.codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t.nome, t.codigo, t.bonusAtq, t.bonusDef);
				}
				scanf("%d", &o);
                Treinador tr = listaTreinadores()[o-1];
                printf("Nome:\n");
                scanf("%s", &tr.nome);
                printf("Bonus ATQ:\n");
                scanf("%f", &tr.bonusAtq);
                printf("Bonus DEF:\n");
                scanf("%f", &tr.bonusDef);
                AtualizarTreinador(tr);
                break;
            case 4:
                printf("Qual treinador deseja excluir? (codigo)\n");
                for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador t = listaTreinadores()[i];
                	if(t.codigo != 0) 
                	printf("Treinador: %s, Cod: %d, Bonus ATQ: %.2f, Bonus DEF: %.2f\n", t.nome, t.codigo, t.bonusAtq, t.bonusDef);
				}
                scanf("%d", &o);
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
                	Pokemon p = listaPokemon()[i];
                	if(p.codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p.nome, p.codigo, p.vida, p.ataque, p.defesa, p.dono, ObterTreinadorPeloCodigo(p.dono)->nome);
				}
                break;
            case 2:
                clear();
                Pokemon p;
                printf("Nome:\n");
                scanf("%s", &p.nome);
				printf("Codigo do dono?:\n");
				for(i = 0; i < QuantidadeTreinadores(); i++) {
                	Treinador t = listaTreinadores()[i];
                	if(t.codigo != 0) 
                	printf("Treinador: %s, Cod: %d\n", t.nome, t.codigo);
				}
                scanf("%d", &p.dono);
				printf("Vida:\n");
                scanf("%f", &p.vida);
				printf("Ataque:\n");
                scanf("%f", &p.ataque);
				printf("Defesa:\n");
                scanf("%f", &p.defesa);
        		SalvarPokemon(p);
                break;
            case 3:
                //PESQUISAR POKEMON PELO NOME.
                clear();
                int encontrado = 0;
                printf("Qual o nome do pokemon?");
                char *nome = malloc(30);
                scanf("%s", nome);
                for(i = 0; i < QuantidadePokemon(); i++) {
                	if(strcmp(nome, listaPokemon()[i].nome) == 0) {
                		Pokemon p = listaPokemon()[i];
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
                	Pokemon p = listaPokemon()[i];
                	if(p.codigo != 0) 
                	printf("Pokemon: %s, Cod: %d, Vida: %.2f, ATQ: %.2f, DEF: %.2f, Dono (%d) - %s\n", p.nome, p.codigo, p.vida, p.ataque, p.defesa, p.dono, ObterTreinadorPeloCodigo(p.dono)->nome);
				}
                scanf("%d", &o);
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
                	Ginasio g = listaGinasios()[i];
                	if(g.codigo != 0) 
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g.nome, g.codigo, g.capacidade, g.bairro);
				}
                break;
            case 2:
            	clear();
                Ginasio g;
                printf("Nome:\n");
                scanf("%s", g.nome);
                printf("Bairro:\n");
                scanf("%s", g.bairro);
                printf("Capacidade:\n");
                scanf("%d", &g.capacidade);
                SalvarGinasio(g);
                break;
            case 3:
            	//PESQUISAR GINASIO
                clear();
                int encontrado = 0;
                printf("Qual o bairro do ginasio?\n");
                char *bairro = malloc(30);
                scanf("%s", bairro);
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	if(strcmp(bairro, listaGinasios()[i].bairro) == 0) {
                		Ginasio g = listaGinasios()[i];
                		clear();
                		printf("Ginasio no bairro %s encontrado!\n", bairro);
                		printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g.nome, g.codigo, g.capacidade, g.bairro);
                		encontrado = 1;
						break;
					}
				}
				if(encontrado == 0)
					printf("Ginasio nao encontrado neste bairro.\n");
				free(bairro);
                break;
                break;
            case 4:
                //APAGAR GINASIO
            	clear();
                printf("Qual ginasio deseja excluir? (codigo)\n");
                for(i = 0; i < QuantidadeGinasios(); i++) {
                	Ginasio g = listaGinasios()[i];
                	if(g.codigo != 0)
                	printf("Ginasio: %s, Cod: %d, Capacidade: %d, Bairro: %s\n", g.nome, g.codigo, g.capacidade, g.bairro);
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
                printf("Listando batalhas do treinador...\n");
                break;
            case 2:
                printf("Listando batalhas do ginasio...\n");
                break;
            case 3:
                printf("Exibindo vitorias e derrotas do treinador...\n");
                break;
            case 4:
                printf("Realizando uma batalha...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void clear() {
    int contador;
    for (contador = 0; contador < 50; contador++)
	printf("\n");
}
