#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
número (inteiro), nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro),
ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro),
lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima
evolução (inteiro), pŕe-evolução (inteiro).
*/
typedef struct{
    
    int id;
    char nome[20];
    char tipo1[10];
    char tipo2[10];
    int total;
    int vida;
    int ataque;
    int defesa;
    int ataque_especial;
    int defesa_especial;
    int velocidade;
    int geracao;
    int lendario;
    char cor[10];
    float altura;
    float peso;
    int taxa_captura;
    int exp;

}Pokemon;


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Mundo Pokemon");

    Texture fundo = LoadTexture("./assets/img/fundos/fundo.png");
    Texture texto = LoadTexture("./assets/img/fundos/texto.png");
    // Texture fundo = LoadTexture("./assets/img/fundos/mapaterra.png");

    SetTargetFPS(60);

    Pokemon pokedex[722];
    Pokemon meus_pokemons[3];

    FILE *arq_binario = fopen("../data/pokedex.bin", "rb");
    if(arq_binario == NULL){
        perror("Erro arquivo binario::");
        exit(1);
    }

    fread(pokedex, sizeof(Pokemon), 721, arq_binario);

    for(int i = 1; i <= 3; i++){
        meus_pokemons[i] = pokedex[rand() % 100];
    }

    printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", meus_pokemons[1].id, meus_pokemons[1].nome, meus_pokemons[1].tipo1, meus_pokemons[1].tipo2, meus_pokemons[1].total, meus_pokemons[1].vida, meus_pokemons[1].ataque, meus_pokemons[1].defesa, meus_pokemons[1].ataque_especial, meus_pokemons[1].defesa_especial, meus_pokemons[1].velocidade, meus_pokemons[1].geracao, meus_pokemons[1].lendario, meus_pokemons[1].cor, meus_pokemons[1].altura, meus_pokemons[1].peso, meus_pokemons[1].taxa_captura);

    int i = 7; // meu pokemon
    int j = 6; // pokemon inimigo

    char meu_pokemon[30];
    char inimigo[30];

    if((i >= 650 && i <= 721) && (j >= 650 && j <= 721)){
        sprintf(inimigo, "./assets/img/pokemons/%d.png", pokedex[j-1].id);
    }
    else{
        sprintf(inimigo, "./assets/img/pokemons/%dc.png", pokedex[j-1].id);
    }

    sprintf(meu_pokemon, "./assets/img/pokemons/%d.png", pokedex[i-1].id);

    Texture img_pokemons[2];

    img_pokemons[0] = LoadTexture(meu_pokemon);
    img_pokemons[1] = LoadTexture(inimigo);

    if(img_pokemons[0].id == 0) {
        perror("Erro carregar imagem meu pokemon:");
        CloseWindow();
        exit(1);
    }
    if(img_pokemons[1].id == 0) {
        perror("Erro carregar imagem pokemon inimigo:");
        CloseWindow();
        exit(1);
    }

    fclose(arq_binario);


    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(fundo, 0, 0, RAYWHITE);
        DrawTexture(texto, 0, 450, RAYWHITE);

        DrawTexture(img_pokemons[0], 430, 40, RAYWHITE);
        DrawTexture(img_pokemons[1], 80, 190, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();


    return 0;
}