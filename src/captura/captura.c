//importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pokedex/pokedex.h"
#include "../colecao/colecao.h"

/**
* captura - faz a ação de salvar o pokemon capturado salvar no arquivo
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int id_pokemon - id do pokemon a ser capturado
*/
void captura(int id_pokemon){

    FILE *arquivo_bin = fopen("../data/pokedex.bin", "rb");
   if (arquivo_bin == NULL) {
       perror("Erro ao carregar arquivo.bin:");
       exit(1);
    }//if

   fseek(arquivo_bin, 0, SEEK_END);
   long int quantidade_arquivo = ftell(arquivo_bin);
   int num_pokemons_alocacao = quantidade_arquivo / sizeof(Pokemon);

   printf("num main: %d\n", num_pokemons_alocacao);
   Pokemon *pokedex = (Pokemon*)calloc(num_pokemons_alocacao, sizeof(Pokemon));
   if(pokedex == NULL){
       perror("Erro memoria Insuficiente!!\n");
       exit(1);
    }//if
   fseek(arquivo_bin, 0, SEEK_SET);

   fread(pokedex, sizeof(Pokemon), num_pokemons_alocacao, arquivo_bin);
   fclose(arquivo_bin);

    //abrindo arquivo
    FILE *arquivo_bin_meu = fopen("../data/meus_pokemons.bin", "r+b");
    if (arquivo_bin_meu == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    //escrevendo esse id do pokemon no arquivo
    fseek(arquivo_bin_meu, 0, SEEK_END);
    printf("id: %d\n", id_pokemon);
    printf("%d %s %s vida: %d ataque: %d defesa: %d\n", pokedex[id_pokemon].id, pokedex[id_pokemon].nome_pokemon, pokedex[id_pokemon].tipo1, pokedex[id_pokemon].vida, pokedex[id_pokemon].ataque, pokedex[id_pokemon].defesa);
    fwrite(&pokedex[id_pokemon], sizeof(Pokemon), 1, arquivo_bin_meu);
    fclose(arquivo_bin_meu);

    return;
}//captura