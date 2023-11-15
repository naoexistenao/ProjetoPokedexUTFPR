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
void captura(Pokemon* pokedex, int id_pokemon){

    //abrindo arquivo
    FILE *arquivo_bin = fopen("../data/meus_pokemons.bin", "r+b");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    //escrevendo esse id do pokemon no arquivo
    fseek(arquivo_bin, 0, SEEK_END);
    fwrite(&pokedex[id_pokemon], sizeof(Pokemon), 1, arquivo_bin);
    fclose(arquivo_bin);

    return;
}//captura