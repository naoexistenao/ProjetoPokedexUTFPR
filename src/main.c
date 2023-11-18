/**
 * @file main.c
 * @author Caio Eduardo (caioeduardo@alunos.utfpr.edu.br)
 * @author Eduardo Garcia da Costa (duardogarciacosta@alunos.utfpr.edu.br)
 * @author Estevan Garrido Hernandes Sastre (sastre@alunos.utfpr.edu.br) 
 * @brief 
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "./pokedex/pokedex.h"
#include "./colecao/colecao.h"
#include "./mochila/mochila.h"
#include "./batalha/batalha.h"

void escolha_primeiro_pokemon();

int main() {
    //criando variaveis
    int opcao = 0;
    //o usuario selecionar 

    printf("ola seja bem vindo otario kkkkk\n");
    escolha_primeiro_pokemon();

    do {
        printf("Escolha uma opção:\n1 - Pokedex\n2 - Coleção\n3 - Mochila\n4 - Batalha\n5 - Sair\n");
        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 5) {
            printf("Escolha entre 1 a 5\n");
            printf("Escolha uma opção:\n1 - Pokedex\n2 - Coleção\n3 - Mochila\n4 - Batalha\n5 - Sair\n");
            scanf("%d", &opcao);
            
        }//while
        switch (opcao) {
            case 1:
                pokedex();
                break;
            case 2:
                colecao();
                break;
            case 3:
                mochila();
                break;
            case 4:
                batalha();
                break;

        }//switch
    } while (opcao != 5);//while

    return 0;
}//main

void escolha_primeiro_pokemon(){

    
    FILE *arquivo_bin = fopen("../data/pokedex.bin", "rb");
    if (arquivo_bin == NULL) {
       perror("Erro ao carregar arquivo.bin:");
       exit(1);
    }//if

    FILE *arq_meus_pokemons = fopen("../data/meus_pokemons.bin", "wb");
    if (arq_meus_pokemons == NULL) {
       perror("Erro ao carregar arquivo.bin:");
       exit(1);
    }//if

    Pokemon *pokedex = (Pokemon*)calloc(151, sizeof(Pokemon));
    if(pokedex == NULL){
        perror("Erro memoria Insuficiente!!\n");
        exit(1);
        }//if
    fseek(arquivo_bin, 0, SEEK_SET);

    fread(pokedex, sizeof(Pokemon), 151, arquivo_bin);
    fclose(arquivo_bin);

    for(int i = 1; i <= 151; i++){
       printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);
    }//for

    int escolha_pokemon = 0;
    printf("Escolha o id de 1 pokemon inicial: ");
    scanf("%d", &escolha_pokemon);

    fwrite(&pokedex[escolha_pokemon-1], sizeof(Pokemon), 1, arq_meus_pokemons);
    fclose(arq_meus_pokemons);
    free(pokedex);

    return;
}