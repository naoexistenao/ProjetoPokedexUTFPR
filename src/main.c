#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//gcc -o pokemon main.c -lraylib
// ./pokemon

// na pasta mundo-pokemon
// git add .
// git commit -m "qual a atualização"
// git push origin main

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

}Pokemon;


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Mundo Pokemon");

    Texture fundo = LoadTexture("./assets/img/fundos/fundo.png");
    Texture texto = LoadTexture("./assets/img/fundos/texto.png");

    Texture estevan = LoadTexture("./assets/img/pokemons/34.png");
    Texture caio = LoadTexture("./assets/img/pokemons/68c.png");

    SetTargetFPS(60);

    Pokemon pokedex[3];

    FILE *arq = fopen("data/pokedex.csv", "r");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo:");
        exit(1);
    }

    for(int i = 0; i < 3; i++){
        // fscanf(arq, "%d, %s, %s, %s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %s, %f, %f, %d \n", &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total, &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial, &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);
        
        // fscanf(arq, "%d%s%s%s%d%d%d%d%d%d%d%d%d%s%f%f%d\n", &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total, &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial, &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);

        // fscanf(arq, "%d %s %s %s %d %d %d %d %d %d %d %d %d %s %f %f %d",
        //    &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total,
        //    &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial,
        //    &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario,
        //    pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);

    }

    int i = 0;

    printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %f %f %d\n", pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, pokedex[i].total, pokedex[i].vida, pokedex[i].ataque, pokedex[i].defesa, pokedex[i].ataque_especial, pokedex[i].defesa_especial, pokedex[i].velocidade, pokedex[i].geracao, pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso, pokedex[i].taxa_captura);

    while (!WindowShouldClose()) {


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(fundo, 0, 0, RAYWHITE);
        DrawTexture(texto, 0, 450, RAYWHITE);

        DrawTexture(estevan, 430, 40, RAYWHITE);
        DrawTexture(caio, 80, 190, RAYWHITE);
        

        EndDrawing();
    }

    CloseWindow();

    fclose(arq);

    return 0;
}
