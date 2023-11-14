/*
 Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
capturados, para isso armazene apenas o número(códigos). Essa relação deve
aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
já capturados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pokedex/pokedex.h"
#include "colecao.h"

void colecao(){

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

    fread(meus_pokemons, sizeof(Colecao), num_pokemons_alocacao, arquivo_bin);
    fclose(arquivo_bin);

    return;
}//main


void listar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    
    for(int i = 1; i < num_pokemons_alocacao; i++){
        printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);
    }//for

}//listar

void pesquisar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja pesquisar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';
    
    for(int i = 1; i < num_pokemons_alocacao; i++){
        if(strcmp(pesquisar, meus_pokemons[i].nome_pokemon) == 0){
            printf("Pesquisar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);

            break;
        }
    }
    
}

void alterar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja alterar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';

    for(int i = 1; i < num_pokemons_alocacao; i++){
        if(strcmp(meus_pokemons[i].nome_pokemon, pesquisar) == 0){
            printf("Alterar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);

            printf("\n=====================================================\n");

            setbuf(stdin, NULL);
            printf("Digite o nome do pokemon: ");
            fgets(meus_pokemons[num_pokemons_alocacao].nome_pokemon,20,stdin);
            meus_pokemons[num_pokemons_alocacao].nome_pokemon[strcspn(meus_pokemons[i - 1].nome_pokemon,"\n")] = '\0';

            break;
        }
        else{
            printf("Fudeu\n");
        }
    }
    
    
}

void excluir_colecao(Pokemon meus_pokemons[], int *num_pokemons_alocacao){
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do pokemón que deseja excluir: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';

        for(int i = 1; i < *num_pokemons_alocacao; i++){
            if(strcasecmp(pesquisar, meus_pokemons[i - 1].nome_pokemon) == 0){
                printf("Excluiu pokemon\n");
                // Exclua o Pokémon da meus_pokemons[i].
                for (int j = i; j < *num_pokemons_alocacao - 1; j++) {
                    meus_pokemons[j] = meus_pokemons[j + 1];
                    }//for
                (*num_pokemons_alocacao)--;
                meus_pokemons = (Pokemon*)realloc(meus_pokemons, *num_pokemons_alocacao * sizeof(Pokemon));
                break;
            }//if

        }//for
}//excluir
