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

}Pokemon;


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Mundo Pokemon");

    Texture fundo = LoadTexture("./assets/img/fundos/fundo.png");
    Texture texto = LoadTexture("./assets/img/fundos/texto.png");

    // Texture estevan = LoadTexture("./assets/img/pokemons/34.png");
    // Texture caio = LoadTexture("./assets/img/pokemons/68c.png");

    SetTargetFPS(60);

    Pokemon pokedex[722];

    // FILE *arq = fopen("../data/pokedex.csv", "r");

    // if (arq == NULL) {
    //     perror("Erro ao abrir o arquivo:");
    //     exit(1);
    // }

    // char linha[1024];
    // int contador = 1;

    // while(fgets(linha, sizeof(linha), arq) != NULL){
    //     Pokemon novo_pokemon;
    //     char *token = strtok(linha, ",");
    //     novo_pokemon.id = atoi(token);

    //     token = strtok(NULL, ",");
    //     strcpy(novo_pokemon.nome, token);

    //     token = strtok(NULL, ",");
    //     strcpy(novo_pokemon.tipo1, token);


    //     token = strtok(NULL, ",");
    //     strcpy(novo_pokemon.tipo2, token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.total = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.vida = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.ataque = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.defesa = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.ataque_especial = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.defesa_especial = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.velocidade = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.geracao = atoi(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.lendario = atoi(token);

    //     token = strtok(NULL, ",");
    //     strcpy(novo_pokemon.cor, token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.altura = atof(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.peso = atof(token);

    //     token = strtok(NULL, ",");
    //     novo_pokemon.taxa_captura = atoi(token);

    //     pokedex[contador] = novo_pokemon;
    //     contador++;

    // }

    // fclose(arq);
    
    // int i = 721;

    // printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, pokedex[i].total, pokedex[i].vida, pokedex[i].ataque, pokedex[i].defesa, pokedex[i].ataque_especial, pokedex[i].defesa_especial, pokedex[i].velocidade, pokedex[i].geracao, pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso, pokedex[i].taxa_captura);

    // FILE *arq_binario = fopen("../data/pokedex.bin", "wb");
    // if(arq_binario == NULL){
    //     perror("Erro arquivo binario::");
    //     exit(1);
    // }

    // fwrite(&pokedex[1], sizeof(Pokemon), contador - 1, arq_binario);

    // fclose(arq_binario);

    FILE *arq_binario = fopen("../data/pokedex.bin", "rb");
    if(arq_binario == NULL){
        perror("Erro arquivo binario::");
        exit(1);
    }

    fread(pokedex, sizeof(Pokemon), 721, arq_binario);

    int i = 9;
    int j = 1;

    char nome_arquivo1[30];
    char nome_arquivo2[30];

    sprintf(nome_arquivo1, "./assets/img/pokemons/%d.png", pokedex[i-1].id);
    sprintf(nome_arquivo2, "./assets/img/pokemons/%dc.png", pokedex[j-1].id);

    printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i-1].id, pokedex[i-1].nome, pokedex[i-1].tipo1, pokedex[i-1].tipo2, pokedex[i-1].total, pokedex[i-1].vida, pokedex[i-1].ataque, pokedex[i-1].defesa, pokedex[i-1].ataque_especial, pokedex[i-1].defesa_especial, pokedex[i-1].velocidade, pokedex[i-1].geracao, pokedex[i-1].lendario, pokedex[i-1].cor, pokedex[i-1].altura, pokedex[i-1].peso, pokedex[i-1].taxa_captura);

    printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[j-1].id, pokedex[j-1].nome, pokedex[j-1].tipo1, pokedex[j-1].tipo2, pokedex[j-1].total, pokedex[j-1].vida, pokedex[j-1].ataque, pokedex[j-1].defesa, pokedex[j-1].ataque_especial, pokedex[j-1].defesa_especial, pokedex[j-1].velocidade, pokedex[j-1].geracao, pokedex[j-1].lendario, pokedex[j-1].cor, pokedex[j-1].altura, pokedex[j-1].peso, pokedex[j-1].taxa_captura);


    Texture estevan = LoadTexture(nome_arquivo1);
    Texture caio = LoadTexture(nome_arquivo2);


    if (estevan.id == 0) {
        printf("Erro: a imagem %s não pôde ser carregada.\n", nome_arquivo1);
        CloseWindow();
        return 1;
    }

    fclose(arq_binario);


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


    return 0;
}













// while (fscanf(arq, "%d,%19[^,],%19[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%19[^,],%f,%f,%d\n",
    //               &pokedex[contador].id, pokedex[contador].nome, pokedex[contador].tipo1, pokedex[contador].tipo2,
    //               &pokedex[contador].total, &pokedex[contador].vida, &pokedex[contador].ataque, &pokedex[contador].defesa,
    //               &pokedex[contador].ataque_especial, &pokedex[contador].defesa_especial, &pokedex[contador].velocidade,
    //               &pokedex[contador].geracao, &pokedex[contador].lendario, pokedex[contador].cor,
    //               &pokedex[contador].altura, &pokedex[contador].peso, &pokedex[contador].taxa_captura) == 17) {
    //     contador++;
    // }

    // for(int i = 0; i < 3; i++){
    //     // fscanf(arq, "%d, %s, %s, %s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %s, %f, %f, %d \n", &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total, &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial, &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);
        
    //     // fscanf(arq, "%d%s%s%s%d%d%d%d%d%d%d%d%d%s%f%f%d\n", &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total, &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial, &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);

    //     // fscanf(arq, "%d %s %s %s %d %d %d %d %d %d %d %d %d %s %f %f %d",
    //     //    &pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, &pokedex[i].total,
    //     //    &pokedex[i].vida, &pokedex[i].ataque, &pokedex[i].defesa, &pokedex[i].ataque_especial,
    //     //    &pokedex[i].defesa_especial, &pokedex[i].velocidade, &pokedex[i].geracao, &pokedex[i].lendario,
    //     //    pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso, &pokedex[i].taxa_captura);

    // }