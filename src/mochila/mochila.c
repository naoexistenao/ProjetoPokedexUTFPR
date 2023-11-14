/*
Defina uma estrutura Mochila que deve armazenar a relação de até 6 Pokémons já
capturados e que poderão ser utilizados em batalha, para isso armazene apenas o
número(códigos).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../colecao/colecao.h"

void mochila(){

    int pokemons_batalha[6];
    int num_pokemons_alocacao = 5;
    Colecao *meus_pokemons = (Colecao*)calloc(num_pokemons_alocacao, sizeof(Colecao));
    if(meus_pokemons == NULL){
        perror("Erro memoria Insuficiente!!\n");
        exit(1);
    }//if

    FILE *arquivo_bin = fopen("../data/meus_pokemons.bin", "rb");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    FILE *arq_pokemons_batalha = fopen("../data/pokemons_batalha.bin", "r+b");
    if (arq_pokemons_batalha == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fread(meus_pokemons, sizeof(Colecao), num_pokemons_alocacao, arquivo_bin);
    fclose(arquivo_bin);

    listar_colecao(meus_pokemons, num_pokemons_alocacao);

    escolher_pokemons(pokemons_batalha, &arq_pokemons_batalha);

    return;
}

void escolher_pokemons(int pokemons_batalha[], FILE* arq_pokemons_batalha){

    printf("Escolha o id de 6 pokemons dessa lista para batalha: ");
    for(int i = 0; i < 6; i++){
        printf("Pokemon %d: ",i+1);
        scanf("%d", &pokemons_batalha[i]);
    }
    fwrite(pokemons_batalha, sizeof(int), 6, arq_pokemons_batalha);
    fclose(arq_pokemons_batalha);

    return;
}
void listar_mochila(Colecao meus_pokemons[], int num_pokemons_alocacao){
    
    for(int i = 1; i < num_pokemons_alocacao; i++){
        printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);
    }

}