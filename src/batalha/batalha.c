//Importando bibliotecas
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "batalha.h"
#include "../pokedex/pokedex.h"
#include "../mochila/mochila.h"
#include "../captura/captura.h"


//enum das "paginas" do jogo
typedef enum{

    ESTADO_SAIR,
    ESTADO_OPCOES,
    ESTADO_BATALHA

}ESTADO_JOGO;

void batalha(){

    ESTADO_JOGO estado_jogo;
    estado_jogo = ESTADO_OPCOES;


    int id_pokemon = 0;
    int vetor_pokemons[6];
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

    fread(meus_pokemons, sizeof(Pokemon), num_pokemons, arq_pokemons_batalha);
    fclose(arq_pokemons_batalha);

    FILE *arq_vetor_batalha = fopen("../data/pokemons_batalha.bin", "rb");
    if (arq_vetor_batalha == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if
    fread(vetor_pokemons, sizeof(int), 6, arq_vetor_batalha);
    fclose(arq_vetor_batalha);

    printf("Escolha o pokemon para a batalha\n");
    for(int j = 0; j < num_pokemons; j++){
        for(int a = 0; a < 6; a++){
            if(vetor_pokemons[a] == meus_pokemons[j].id){
                printf("%d - %s\n", j, meus_pokemons[j].nome_pokemon);
            }
        }
    }
    int i = 0;
    scanf("%d", &i);

    //definindo dimeções da janela
    const int largura_janela = 800;
    const int altura_janela = 600;

    char caminho_textura_inimigo[50];
    char caminho_textura_eu[50];

    sprintf(caminho_textura_inimigo, "./assets/img/pokemons/%d.png", pokedex_inimigo->id);
    sprintf(caminho_textura_eu, "./assets/img/pokemons/%dc.png", meus_pokemons[i].id);

    Texture pokemon_inimigo = LoadTexture(caminho_textura_inimigo);
    if(pokemon_inimigo.id == 0){
        perror("Erro ao carregar imagem pokemon_inimigo::");
        exit(1);
    }
    Texture meu_pokemon = LoadTexture(caminho_textura_eu);
    if(meu_pokemon.id == 0){
        perror("Erro ao carregar imagem meu_pokemon::");
        exit(1);
    }

    Texture fundo_batalha = LoadTexture("./assets/img/fundos/fundo_batalha.png");
    if(fundo_batalha.id == 0){
        perror("Erro ao carregar imagem fundo_batalha::");
        exit(1);
    }
    Texture fundo_batalha_texto = LoadTexture("./assets/img/fundos/fundo_texto_batalha.png");
    if(fundo_batalha_texto.id == 0){
        perror("Erro ao carregar imagem fundo_batalha_texto::");
        exit(1);
    }

    int opcao = 0;
    char quem_comeca = 'x';

    printf("%d %s %s vida: %d ataque: %d defesa: %d\n", meus_pokemons[i].id, meus_pokemons[i].nome_pokemon, meus_pokemons[i].tipo1, meus_pokemons[i].vida, meus_pokemons[i].ataque, meus_pokemons[i].defesa);

    printf("%d %s %s vida: %d ataque: %d defesa: %d\n", pokedex_inimigo->id, pokedex_inimigo->nome_pokemon, pokedex_inimigo->tipo1, pokedex_inimigo->vida, pokedex_inimigo->ataque, pokedex_inimigo->defesa);

    // captura(pokedex_inimigo, id_pokemon);

    do{

        //se usuario clicar espaço faça as ações
        if(IsKeyPressed(KEY_SPACE)){
            if(estado_jogo == ESTADO_OPCOES){
                switch (opcao) {
                    case 0:
                        pokedex_inimigo->vida -= meus_pokemons[i].ataque;
                        printf("Você atacou! Dano: %d\n", meus_pokemons[i].ataque);
                        quem_comeca = 'i';
                        break;
                    case 1:
                        pokedex_inimigo->vida -= meus_pokemons[i].ataque_especial;
                        printf("Você atacou! Dano: %d\n", meus_pokemons[i].ataque_especial);
                        quem_comeca = 'i';
                        break;
                }
            }
        }

        if(quem_comeca == 'x'){
            if(pokedex_inimigo->velocidade > meus_pokemons[i].velocidade){
                quem_comeca = 'i';
            }
            else{
                quem_comeca = 'e';
            }
        }

        if(quem_comeca == 'i'){
            if(pokedex_inimigo->vida < 60){
                meus_pokemons[i].vida -= pokedex_inimigo->ataque_especial;
                printf("Inimigo atacou! Dano: %d\n", pokedex_inimigo->ataque_especial);
            }
            else{
                meus_pokemons[i].vida -= pokedex_inimigo->ataque;
                printf("Inimigo atacou! Dano: %d\n", pokedex_inimigo->ataque);
            }
            quem_comeca = 'e';
        }
        else{
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
        }

        if(pokedex_inimigo->vida <= 0){
            captura(pokedex_inimigo->id-1);
            printf("venceu parabens!!\n");
            estado_jogo = ESTADO_SAIR;
        }
        else if(meus_pokemons[i].vida <= 0){
            printf("perdeu parabens!!\n");
            estado_jogo = ESTADO_SAIR;
        }

        //desenhando
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawTexture(fundo_batalha, 0, 0, RAYWHITE);
        DrawTexture(fundo_batalha_texto, 0, 450, RAYWHITE);
        DrawTexture(pokemon_inimigo, 500, 50, RAYWHITE);
        DrawTexture(meu_pokemon, 100, 250, RAYWHITE);
        DrawText(TextFormat("Vida: %d", pokedex_inimigo->vida), 450, 50, 20, BLACK);
        DrawText(TextFormat("Vida: %d", meus_pokemons[i].vida), 50, 310, 20, BLACK);

            DrawText(TextFormat("Você atacou! Dano: %d", meus_pokemons[i].ataque), 50, 500, 20, BLACK);
            DrawText(TextFormat("Inimigo atacou! Dano: %d", pokedex_inimigo->ataque), 50, 550, 20, BLACK);

        DrawText(TextFormat(opcao == 0 ? "> Ataque" : "Ataque"), 550 - MeasureText("Ataque", 20) - 25, 480, 20, BLACK);
        DrawText(TextFormat(opcao == 1 ? "> Ataque Especial" : "Ataque Especial"), 590 - MeasureText("Ataque Especial", 20), 540, 20, BLACK);

        EndDrawing();

    }while(estado_jogo != ESTADO_SAIR);

    UnloadTexture(pokemon_inimigo);
    UnloadTexture(meu_pokemon);
    UnloadTexture(fundo_batalha);
    UnloadTexture(fundo_batalha_texto);
    free(pokedex_inimigo);
    free(meus_pokemons);

    return;
}