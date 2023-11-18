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
#include <string.h>
#include <time.h>
#include "./pokedex/pokedex.h"
#include "./colecao/colecao.h"
#include "./mochila/mochila.h"
#include "./batalha/batalha.h"

void escolha_primeiro_pokemon();
void verificar_primeira_vez();

int main() {
    //criando variaveis
    int opcao = 0;
    //o usuario selecionar 

    printf("ola seja bem vindo otario kkkkk\n");
    verificar_primeira_vez();

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

void verificar_primeira_vez(){

    char verifica_primeira_vez;
    char nome_jogador[20];
    FILE *arquivo_usuario = fopen("../data/arquivo_usuario.bin", "r+b");
    if (arquivo_usuario == NULL) {
       perror("Erro ao carregar arquivo.bin:");
       exit(1);
    }//if

    fread(&verifica_primeira_vez, sizeof(char), 1, arquivo_usuario);

    if(verifica_primeira_vez == 'n'){
        printf("Digite seu nome: ");
        setbuf(stdin, NULL);
        fgets(nome_jogador, 20, stdin);
        nome_jogador[strcspn(nome_jogador, "\n")] = '\0';

        escolha_primeiro_pokemon();
        verifica_primeira_vez = 's';

        fseek(arquivo_usuario, 0, SEEK_SET);
        fwrite(&verifica_primeira_vez, sizeof(char), 1, arquivo_usuario);

        fseek(arquivo_usuario, sizeof(char), SEEK_SET);
        fwrite(&nome_jogador, sizeof(char), sizeof(nome_jogador), arquivo_usuario);
    }
    else if(verifica_primeira_vez == 's'){
        
    }

    fclose(arquivo_usuario);
    return;
}

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

    int pokemons_escolher[3];

    srand((unsigned int)time(NULL));
    for(int i = 0; i < 3; i++){
        pokemons_escolher[i] = rand() % 151 + 1;
    }

    for(int i = 0; i < 3; i++){

       printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[pokemons_escolher[i]].id, pokedex[pokemons_escolher[i]].nome_pokemon, pokedex[pokemons_escolher[i]].tipo1, pokedex[pokemons_escolher[i]].tipo2, pokedex[pokemons_escolher[i]].total, pokedex[pokemons_escolher[i]].vida, pokedex[pokemons_escolher[i]].ataque, pokedex[pokemons_escolher[i]].defesa, pokedex[pokemons_escolher[i]].ataque_especial, pokedex[pokemons_escolher[i]].defesa_especial, pokedex[pokemons_escolher[i]].velocidade, pokedex[pokemons_escolher[i]].geracao, pokedex[pokemons_escolher[i]].lendario, pokedex[pokemons_escolher[i]].cor, pokedex[pokemons_escolher[i]].altura, pokedex[pokemons_escolher[i]].peso, pokedex[pokemons_escolher[i]].taxa_captura);
    }//for

    int escolha_pokemon = 0;
    printf("Escolha o id de 1 pokemon inicial: ");
    scanf("%d", &escolha_pokemon);

    fwrite(&pokedex[escolha_pokemon-1], sizeof(Pokemon), 1, arq_meus_pokemons);
    fclose(arq_meus_pokemons);
    free(pokedex);

    return;
}