/*
 Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
capturados, para isso armazene apenas o número(códigos). Essa relação deve
aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
já capturados.
*/

//importando bibliotecas
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pokedex/pokedex.h"
#include "colecao.h"


/**
* listar_colecao - lista os pokemons da colecao do usuario
* \param Pokemon meus_pokedex - estrutura que armazena os dados dos pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados colecao 
*/
void listar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao);

/**
* pesquisar_colecao - usuario pesquisa pelo pokemon
* \param Pokemons meus_pokedex - estrutura que armazena os dados dos pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados
*/
void pesquisar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao);

void alterar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao);

void excluir_colecao(Pokemon **meus_pokemons, int *num_pokemons_alocacao);

//enum das "paginas" do jogo
typedef enum{

    ESTADO_SAIR,
    ESTADO_OPCOES

}ESTADO_JOGO;

/**
* colecao - os pokemons que o usuario tem
*/
void colecao(){

    ESTADO_JOGO estado_jogo;
    estado_jogo = ESTADO_OPCOES;

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
    //alocando memoria
    Pokemon *meus_pokemons = (Pokemon*)calloc(num_pokemons_alocacao, sizeof(Pokemon));
    if(meus_pokemons == NULL){
        perror("Erro memoria Insuficiente!!\n");
        exit(1);
    }//if

    //lendo dados do arquivo e salvando no vetor estrutura
    fread(meus_pokemons, sizeof(Pokemon), num_pokemons_alocacao, arquivo_bin);
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
                        // estado_jogo = ESTADO_LISTAR;
                        listar_colecao(meus_pokemons, num_pokemons_alocacao);
                        break;
                    case 1:
                        // estado_jogo = ESTADO_ALTERAR;
                        pesquisar_colecao(meus_pokemons, num_pokemons_alocacao);
                        break;
                    case 2:
                        // estado_jogo = ESTADO_EXCLUIR;
                        alterar_colecao(meus_pokemons, num_pokemons_alocacao);
                        break;
                    case 3:
                        // estado_jogo = ESTADO_EXCLUIR;
                        excluir_colecao(&meus_pokemons, &num_pokemons_alocacao);
                    break;
                    case 4:
                        estado_jogo = ESTADO_SAIR;
                        break;
                }
            }
        }

        if(estado_jogo == ESTADO_OPCOES){
            if (IsKeyPressed(KEY_W)) {
                opcao--;
                if (opcao < 0) {
                    opcao = 4;
                }
            } else if (IsKeyPressed(KEY_S)) {
                opcao++;
                if (opcao > 4) {
                    opcao = 0;
                }
            }
        }

        //desenhando
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(0, 0, 800, 600, WHITE);
        DrawText(TextFormat(opcao == 0 ? "> Listar" : "Listar"), largura_janela / 5 - MeasureText("Listar", 20) - 25, altura_janela - 480, 20, BLACK);
        DrawText(TextFormat(opcao == 1 ? "> Pesquisar" : "Pesquisar"), largura_janela / 4 - 10 - MeasureText("Pesquisar", 20), altura_janela - 440, 20, BLACK);
        DrawText(TextFormat(opcao == 2 ? "> Alterar" : "Alterar"), largura_janela / 4 + 10 - MeasureText("Alterar", 20) - 45, altura_janela - 400, 20, BLACK);
        DrawText(TextFormat(opcao == 3 ? "> Excluir" : "Excluir"), largura_janela / 4 - MeasureText("Excluir", 20) - 45, altura_janela - 360, 20, BLACK);
        DrawText(TextFormat(opcao == 4 ? "> Sair" : "Sair"), largura_janela / 5 - MeasureText("Sair", 20) - 37, altura_janela - 320, 20, BLACK);

        EndDrawing();

    }while(estado_jogo != ESTADO_SAIR);

    return;
}//main


void listar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    
    printf("\n ===========================================================\n");
    //lista os pokemons da colecao
    for(int i = 1; i <= num_pokemons_alocacao; i++){
        printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);
    }//for

}//listar

void pesquisar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    
    //criando variaveis
    //usuario pesquisar o nome do pokemons
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja pesquisar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';
    
    //verificar se pokemons foi encontrado
    for(int i = 1; i < num_pokemons_alocacao; i++){
        if(strcasecmp(pesquisar, meus_pokemons[i].nome_pokemon) == 0){
            printf("Pesquisar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);

            break;
        }//if
    }//for
    
}//pesquisar_colecao

void alterar_colecao(Pokemon meus_pokemons[], int num_pokemons_alocacao){
    //criando variaveis
    //usuario pesquisa pelo pokemon
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja alterar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';

    //verificar se pokemons foi encontrado alterado
    for(int i = 1; i < num_pokemons_alocacao; i++){
        if(strcasecmp(meus_pokemons[i].nome_pokemon, pesquisar) == 0){
            printf("Alterar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[i - 1].id, meus_pokemons[i - 1].nome_pokemon, meus_pokemons[i - 1].tipo1, meus_pokemons[i - 1].tipo2, meus_pokemons[i - 1].total, meus_pokemons[i - 1].vida, meus_pokemons[i - 1].ataque, meus_pokemons[i - 1].defesa, meus_pokemons[i - 1].ataque_especial, meus_pokemons[i - 1].defesa_especial, meus_pokemons[i - 1].velocidade, meus_pokemons[i - 1].geracao, meus_pokemons[i - 1].lendario, meus_pokemons[i - 1].cor, meus_pokemons[i - 1].altura, meus_pokemons[i - 1].peso, meus_pokemons[i - 1].taxa_captura);

            printf("\n=====================================================\n");

            //usuario mudar o nome do pokemon
            setbuf(stdin, NULL);
            printf("Digite o nome do pokemon: ");
            fgets(meus_pokemons[i].nome_pokemon,20,stdin);
            meus_pokemons[i].nome_pokemon[strcspn(meus_pokemons[i - 1].nome_pokemon,"\n")] = '\0';

            break;
        }//if
    }//for
    
    
}//alterar_colecao

void excluir_colecao(Pokemon **meus_pokemons, int *num_pokemons_alocacao){
   char pesquisar[20];
   setbuf(stdin, NULL);
   printf("Digite o nome do pokemón que deseja excluir: ");
   fgets(pesquisar, 20, stdin);
   pesquisar[strcspn(pesquisar, "\n")] = '\0';

       for(int i = 1; i <= *num_pokemons_alocacao; i++){
           if(strcasecmp(pesquisar, (*meus_pokemons)[i - 1].nome_pokemon) == 0){
               printf("Excluiu pokemon\n");
               // Exclua o Pokémon da pokedex[i].
               for (int j = i; j < *num_pokemons_alocacao; j++) {
                   (*meus_pokemons)[j-1] = (*meus_pokemons)[j];
               }//for
               (*num_pokemons_alocacao)--;
               (*meus_pokemons) = (Pokemon*)realloc((*meus_pokemons), *num_pokemons_alocacao * sizeof(Pokemon));
               break;
           }//if

        }//for
}//excluir
