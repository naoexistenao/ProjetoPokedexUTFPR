#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../pokedex/pokedex.h"
#include "../colecao/colecao.h"

void captura(Pokemon* pokedex, int id_pokemon){

    FILE *arquivo_bin = fopen("../data/meus_pokemons.bin", "r+b");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fseek(arquivo_bin, 0, SEEK_END);
    fwrite(&pokedex[id_pokemon], sizeof(Pokemon), 1, arquivo_bin);
    fclose(arquivo_bin);

    return;
}//captura