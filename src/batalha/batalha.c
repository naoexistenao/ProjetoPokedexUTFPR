//Importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "batalha.h"
#include "../pokedex/pokedex.h"
#include "../mochila/mochila.h"

void luta(Pokemon* pokedex_inimigo, Colecao* meus_pokemons, int id_pokemon_inimigo, int id_meu_pokemon);

void batalha(){

    int id_pokemon = 0;
    Pokemon* pokedex_inimigo = malloc(sizeof(Pokemon));
    Colecao* meus_pokemons = malloc(6*sizeof(Colecao));

    FILE *arquivo_bin = fopen("../data/pokedex.bin", "rb");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fseek(arquivo_bin, 0, SEEK_END);
    long int quantidade_arquivo = ftell(arquivo_bin);
    int num_pokemons = quantidade_arquivo / sizeof(Pokemon);
    fseek(arquivo_bin, 0, SEEK_SET);
    printf("num pokemons inimigo: %d\n", num_pokemons);


    srand((unsigned int)time(NULL));
    int pokemon_oponente = rand() % num_pokemons + 1;
    printf("id inimigo: %d\n", pokemon_oponente);
    id_pokemon = pokemon_oponente;

    fseek(arquivo_bin, (pokemon_oponente - 1)*sizeof(Pokemon), SEEK_SET);

    fread(pokedex_inimigo, sizeof(Pokemon), 1, arquivo_bin);
    fclose(arquivo_bin);

    printf("abrindo arquivo pokemons batalha\n");
    FILE *arq_pokemons_batalha = fopen("../data/meus_pokemons.bin", "rb");
    if (arq_pokemons_batalha == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fseek(arq_pokemons_batalha, 0, SEEK_END);
    quantidade_arquivo = ftell(arq_pokemons_batalha);
    num_pokemons = quantidade_arquivo / sizeof(Pokemon);
    fseek(arq_pokemons_batalha, 0, SEEK_SET);
    printf("num pokemons meus: %d\n", num_pokemons);

    fread(meus_pokemons, sizeof(Pokemon), num_pokemons, arquivo_bin);
    fclose(arq_pokemons_batalha);

    printf("%d %s %s vida: %d ataque: %d defesa: %d\n", pokedex_inimigo->id, pokedex_inimigo->nome_pokemon, pokedex_inimigo->tipo1, pokedex_inimigo->vida, pokedex_inimigo->ataque, pokedex_inimigo->defesa);

    int i = 0;
    printf("%d %s %s vida: %d ataque: %d defesa: %d\n", meus_pokemons[i].id, meus_pokemons[i].nome_pokemon, meus_pokemons[i].tipo1, meus_pokemons[i].vida, meus_pokemons[i].ataque, meus_pokemons[i].defesa);

    // captura(pokedex_inimigo, id_pokemon);

    luta(pokedex_inimigo, meus_pokemons, id_pokemon, i);

    free(pokedex_inimigo);
    free(meus_pokemons);

    return;
}

void luta(Pokemon* pokedex_inimigo, Colecao* meus_pokemons, int id_pokemon_inimigo, int id_meu_pokemon){

    id_pokemon_inimigo -= 1;

    printf("%s VS %s\n", pokedex_inimigo[id_pokemon_inimigo].nome_pokemon, meus_pokemons[id_meu_pokemon].nome_pokemon);

    int venceu = 0;
    while(venceu == 0){
        int dano_inimigo = 0;
        int dano = meus_pokemons[id_meu_pokemon].ataque - pokedex_inimigo[id_pokemon_inimigo].defesa;
        if(dano <= 0){
            dano = 0;
            dano_inimigo = pokedex_inimigo[id_pokemon_inimigo].ataque - meus_pokemons[id_meu_pokemon].defesa;
            if(dano_inimigo <= 0){
                printf("Impate!!\n");
                venceu = 1;
            }
        }
        printf("dano: %d\n", dano);
        pokedex_inimigo[id_pokemon_inimigo].vida -= dano;

        printf("vida inimigo: %d\n", pokedex_inimigo[id_pokemon_inimigo].vida);

        if(pokedex_inimigo[id_pokemon_inimigo].vida <= 0){
            printf("parabens voce ganhou!!!\n");
            venceu = 1;
        }

        meus_pokemons[id_meu_pokemon].vida -= dano_inimigo;
        printf("vida meu: %d\n", meus_pokemons[id_meu_pokemon].vida);

        if(meus_pokemons[id_meu_pokemon].vida <= 0){
            printf("pena voce perdeu!!!\n");
            venceu = 1;
        }

    }

    return;
}