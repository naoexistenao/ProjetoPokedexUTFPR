#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




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




int main(){


   Pokemon pokedex[721];


   FILE *arq = fopen("../../data/pokedex.csv", "r");


   if (arq == NULL) {
       perror("Erro ao abrir o arquivo:");
       exit(1);
   }


   char linha[1024];
   int contador = 1;


   while(fgets(linha, sizeof(linha), arq) != NULL){
       Pokemon novo_pokemon;
       char *token = strtok(linha, ",");
       novo_pokemon.id = atoi(token);


       token = strtok(NULL, " ");
       strcpy(novo_pokemon.nome, token);


       token = strtok(NULL, ",");
       strcpy(novo_pokemon.tipo1, token);




       token = strtok(NULL, ",");
       strcpy(novo_pokemon.tipo2, token);


       token = strtok(NULL, ",");
       novo_pokemon.total = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.vida = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.ataque = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.defesa = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.ataque_especial = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.defesa_especial = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.velocidade = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.geracao = atoi(token);


       token = strtok(NULL, ",");
       novo_pokemon.lendario = atoi(token);


       token = strtok(NULL, ",");
       strcpy(novo_pokemon.cor, token);


       token = strtok(NULL, ",");
       novo_pokemon.altura = atof(token);


       token = strtok(NULL, ",");
       novo_pokemon.peso = atof(token);


       token = strtok(NULL, ",");
       novo_pokemon.taxa_captura = atoi(token);


       pokedex[contador] = novo_pokemon;
       contador++;


   }


   fclose(arq);
  
   int i = 721;


   printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i].id, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2, pokedex[i].total, pokedex[i].vida, pokedex[i].ataque, pokedex[i].defesa, pokedex[i].ataque_especial, pokedex[i].defesa_especial, pokedex[i].velocidade, pokedex[i].geracao, pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso, pokedex[i].taxa_captura);


   FILE *arq_binario = fopen("../../data/pokedex.bin", "wb");
   if(arq_binario == NULL){
       perror("Erro arquivo binario1::");
       exit(1);
   }


   fwrite(&pokedex[1], sizeof(Pokemon), contador - 1, arq_binario);


   fclose(arq_binario);


   FILE *arq_bin = fopen("../../data/pokedex.bin", "rb");
   if(arq_binario == NULL){
       perror("Erro arquivo binario2::");
       exit(1);
   }


   fread(pokedex, sizeof(Pokemon), 721, arq_binario);


   int j = 6;


   printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[j-1].id, pokedex[j-1].nome, pokedex[j-1].tipo1, pokedex[j-1].tipo2, pokedex[j-1].total, pokedex[j-1].vida, pokedex[j-1].ataque, pokedex[j-1].defesa, pokedex[j-1].ataque_especial, pokedex[j-1].defesa_especial, pokedex[j-1].velocidade, pokedex[j-1].geracao, pokedex[j-1].lendario, pokedex[j-1].cor, pokedex[j-1].altura, pokedex[j-1].peso, pokedex[j-1].taxa_captura);


   fclose(arq_bin);


   return 0;
}
