/*
Defina uma estrutura Mochila que deve armazenar a relação de até 6 Pokémons já
capturados e que poderão ser utilizados em batalha, para isso armazene apenas o
número(códigos).
*/

//importando bibliotecas
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../colecao/colecao.h"

/**
* lista_mochila - lista os pokemons disponiveis na coleção do usuario
* \param Colecao meus_pokemons - estrutura vetor de pokemons que o usuario contem
* \param int num_pokemons_alocacao - numero de pokemons que usuario tem para alocação dinamica
*/
void listar_mochila(Colecao meus_pokemons[], int num_pokemons_alocacao);

/**
* função escolher_pokemons - o usuario escolher 6 pokemons para batalha
* \param int pokemons_batalha - vetor que recebe os id dos pokemons escolhidos
* \param FILE* arq_pokemons_batalha - arquivo que contem os pokemons escolhidos para a batalha
*/
void escolher_pokemons(int pokemons_batalha[], FILE* arq_pokemons_batalha);

//enum das "paginas" do jogo
typedef enum{

    ESTADO_SAIR,
    ESTADO_OPCOES

}ESTADO_JOGO;

/**
* função mochila - contem os pokemons para batalha
*/
void mochila(){

    ESTADO_JOGO estado_jogo;
    estado_jogo = ESTADO_OPCOES;

    //criando variaveis
    int pokemons_batalha[6];

    //abrindo arquivo
    FILE *arquivo_bin = fopen("../data/meus_pokemons.bin", "rb");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fseek(arquivo_bin, 0, SEEK_END);
    long int quantidade_arquivo = ftell(arquivo_bin);
    int num_pokemons_alocacao = quantidade_arquivo / sizeof(Colecao);

    printf("num main: %d\n", num_pokemons_alocacao);
    //alocando memoria
    fseek(arquivo_bin, 0, SEEK_SET);
    Colecao *meus_pokemons = (Colecao*)calloc(num_pokemons_alocacao, sizeof(Colecao));
    if(meus_pokemons == NULL){
        perror("Erro memoria Insuficiente!!\n");
        exit(1);
    }//if

    FILE *arq_pokemons_batalha = fopen("../data/pokemons_batalha.bin", "r+b");
    if (arq_pokemons_batalha == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    //lendo dados do arquivo e colocando no vetor estrutura
    fread(meus_pokemons, sizeof(Colecao), num_pokemons_alocacao, arquivo_bin);
    fclose(arquivo_bin);

    int opcao = 0;
    //definindo dimeções da janela
    const int largura_janela = 800;
    const int altura_janela = 600;

    do{
        //se usuario clicar espaço faça as ações
        if(IsKeyPressed(KEY_SPACE)){
            if(estado_jogo == ESTADO_OPCOES){
                switch (opcao) {
                    case 0:
                        //função para listar pokemons da coleção
                        listar_mochila(meus_pokemons, num_pokemons_alocacao);
                        break;
                    case 1:
                        //função para escolher pokemons para batalha
                        escolher_pokemons(pokemons_batalha, arq_pokemons_batalha);
                        break;
                    case 2:
                        estado_jogo = ESTADO_SAIR;
                        break;
                }
            }
        }

        if(estado_jogo == ESTADO_OPCOES){
            if (IsKeyPressed(KEY_W)) {
                opcao--;
                if (opcao < 0) {
                    opcao = 2;
                }
            } else if (IsKeyPressed(KEY_S)) {
                opcao++;
                if (opcao > 2) {
                    opcao = 0;
                }
            }
        }

        //desenhando
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(0, 0, 800, 600, WHITE);
        DrawText(TextFormat(opcao == 0 ? "> Listar" : "Listar"), largura_janela / 5 - MeasureText("Listar", 20) - 25, altura_janela - 480, 20, BLACK);
        DrawText(TextFormat(opcao == 1 ? "> Escolher pokemon" : "Escolher pokemon"), largura_janela / 3 - MeasureText("Escolher pokemon", 20), altura_janela - 440, 20, BLACK);
        DrawText(TextFormat(opcao == 2 ? "> Sair" : "Sair"), largura_janela / 5 - MeasureText("Sair", 20) - 37, altura_janela - 400, 20, BLACK);

        EndDrawing();

    }while(estado_jogo != ESTADO_SAIR);

    free(meus_pokemons);
    fclose(arq_pokemons_batalha);

    return;
}//mochila

void escolher_pokemons(int pokemons_batalha[], FILE* arq_pokemons_batalha){

    //usuario escolher ate 6 pokemons para batalha
    printf("Escolha o id de 6 pokemons dessa lista para batalha\n");
    for(int i = 0; i < 6; i++){
        printf("Pokemon %d: ",i+1);
        scanf("%d", &pokemons_batalha[i]);
    }
    //escrevendo o id desses pokemons no arquivo
    fwrite(pokemons_batalha, sizeof(int), 6, arq_pokemons_batalha);
    for(int i = 0; i < 6; i++){
        printf("Vetor: %d ", pokemons_batalha[i]);
    }
        printf("\n");


    return;
}//escolher_pokemons

void listar_mochila(Colecao meus_pokemons[], int num_pokemons_alocacao){
    
    printf("\n ===========================================================\n");
    //lisatando os pokemons da coleção
    for(int i = 1; i <= num_pokemons_alocacao; i++){
        printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);
    }//for

}//listar_mochila