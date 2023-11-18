/*
Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: número (inteiro),
nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro),
ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro),
lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima
evolução (inteiro), pŕe-evolução (inteiro). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.
*/


//Importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"


/**
* Adiciona pokemons na pokedex
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados na pokedex
*/
void inserir(Pokemon **pokedex, int *num_pokemons_alocacao, int manter_id);


/**
* Lista os pokemons disponíveis para serem capturados
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados na pokedex
*/
void listar(Pokemon pokedex[], int num_pokemons_alocacao);


/**
* Procura por um pokemon específico da pokedex
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados na pokedex
*/
void pesquisar(Pokemon pokedex[], int num_pokemons_alocacao);


/**
* Permite alterar informações dos pokemons
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados na pokedex
*/
void alterar(Pokemon pokedex[], int num_pokemons_alocacao);


/**
* Permite excluir um pokemon da pokedex
* \param Pokemon pokedex - estrutura que armazena os dados de todos os pokemons
* \param int num_pokemons_alocacao - quantidade total de pokemons registrados na pokedex
*/
void excluir(Pokemon **pokedex, int *num_pokemons_alocacao);


/**
* Abre o arquivo da pokedex e mostra as opções disponíveis
*/
void pokedex() {


   int manter_id = 0;


   FILE *arquivo_bin = fopen("../data/pokedex.bin", "rb");
   if (arquivo_bin == NULL) {
       perror("Erro ao carregar arquivo.bin:");
       exit(1);
   }//if


   fseek(arquivo_bin, 0, SEEK_END);
   long int quantidade_arquivo = ftell(arquivo_bin);
   int num_pokemons_alocacao = quantidade_arquivo / sizeof(Pokemon);


   printf("num main: %d\n", num_pokemons_alocacao);
   Pokemon *pokedex = (Pokemon*)calloc(num_pokemons_alocacao, sizeof(Pokemon));
   if(pokedex == NULL){
       perror("Erro memoria Insuficiente!!\n");
       exit(1);
   }//if
   fseek(arquivo_bin, 0, SEEK_SET);


   fread(pokedex, sizeof(Pokemon), num_pokemons_alocacao, arquivo_bin);
   fclose(arquivo_bin);


   manter_id = num_pokemons_alocacao;
   int opcao = 0;


   do {
       printf("Escolhe um opção:\n1 - Inserir\n2 - Listar\n3 - Pesquisar\n4 - Alterar\n5 - Excluir\n6 - Sair\n");
       scanf("%d", &opcao);
       while (opcao < 1 || opcao > 6) {
           printf("Escolhe entre 1 a 6\n");
           printf("Escolhe um opção:\n1 - Inserir\n2 - Listar\n3 - Pesquisar\n4 - Alterar\n5 - Excluir\n6 - Sair\n");
           scanf("%d", &opcao);
          
       }//while
       switch (opcao) {
           case 1:
               inserir(&pokedex, &num_pokemons_alocacao, manter_id);
               break;
           case 2:
               listar(pokedex, num_pokemons_alocacao);
               break;
           case 3:
               pesquisar(pokedex, num_pokemons_alocacao);
               break;
           case 4:
               alterar(pokedex, num_pokemons_alocacao);
               break;
           case 5:
               excluir(&pokedex, &num_pokemons_alocacao);
               break;
       }//switch
   } while (opcao != 6);


   // Salve os dados da Pokedex em um arquivo binário, se necessário.
   arquivo_bin = fopen("../data/pokedex.bin", "wb");
   if (arquivo_bin == NULL) {
       perror("Erro ao salvar arquivo.bin:");
       exit(1);
   }
   fwrite(pokedex, sizeof(Pokemon), num_pokemons_alocacao, arquivo_bin);
   fclose(arquivo_bin);


   free(pokedex); // Libere a memória alocada.


   return;
}//pokedex




void inserir(Pokemon **pokedex, int *num_pokemons_alocacao, int manter_id){
   printf("num : %d\n", *num_pokemons_alocacao);
   (*num_pokemons_alocacao)++;
   printf("num : %d\n", *num_pokemons_alocacao);
   (*pokedex) = (Pokemon*)realloc(*pokedex, *num_pokemons_alocacao * sizeof(Pokemon));
   if(*pokedex == NULL){
       printf("erro sem espaço na memoria\n");
       exit(1);
   }//if
   manter_id = ((*pokedex)[*num_pokemons_alocacao - 1].id) + 1;
   int local_certo = *num_pokemons_alocacao - 1;
   //Recebendo o nome do pokemon
       printf("Digite o nome do pokemon: ");
       setbuf(stdin, NULL);
       fgets((*pokedex)[local_certo].nome_pokemon,20,stdin);
       (*pokedex)[local_certo].nome_pokemon[strcspn((*pokedex)[local_certo].nome_pokemon,"\n")] = '\0';
       setbuf(stdin, NULL);


   //id
       (*pokedex)[local_certo].id = manter_id;


   //tipo1
       printf("Digite o 1º tipo do seu pokemon: ");
       fgets((*pokedex)[local_certo].tipo1,10,stdin);
       (*pokedex)[local_certo].tipo1[strcspn((*pokedex)[local_certo].tipo1, "\n")] = '\0';
       setbuf(stdin, NULL);


   //tipo2
       printf("Digite o 2º tipo do seu pokemon: ");
       fgets((*pokedex)[local_certo].tipo2,10,stdin);
       (*pokedex)[local_certo].tipo2[strcspn((*pokedex)[local_certo].tipo2, "\n")] = '\0';
       setbuf(stdin, NULL);


   //vida
       printf("Digite a vida do pokemon: ");
       scanf("%d", &(*pokedex)[local_certo].vida);


   //ataque
       printf("Digite o valor de ataque do pokemon: ");
       scanf("%d", &(*pokedex)[local_certo].ataque);


   //defesa
       printf("Digite o valor da defesa: ");
       scanf("%d", &(*pokedex)[local_certo].defesa);


   //ataque_especial
       printf("Digite o valor do ataque especial: ");
       scanf("%d", &(*pokedex)[local_certo].ataque_especial);


   //defesa_especial
       printf("Digite o valor da defesa especial: ");
       scanf("%d", &(*pokedex)[local_certo].defesa_especial);


   //velocidade
       printf("Digite o valor da velocidade do pokemon: ");
       scanf("%d", &(*pokedex)[local_certo].velocidade);


   //geração
       printf("Digite a geração do pokemon: ");
       scanf("%d", &(*pokedex)[local_certo].geracao);


   //lendário (1 se for lendário e 0 se não for(boleano))
       printf("Digite 1 se o pokemon for lendário e 0 se não for: ");
       scanf("%d", &(*pokedex)[local_certo].lendario);


   //cor[10]
       setbuf(stdin, NULL);
       printf("Digite a cor do pokemon: ");
       fgets((*pokedex)[local_certo].cor, 10, stdin);
       (*pokedex)[local_certo].cor[strcspn((*pokedex)[local_certo].cor, "\n")] = '\0';


   //altura float
       printf("Digite a altura do pokemon: ");
       scanf("%f", &(*pokedex)[local_certo].altura);
      
   //peso float
       printf("Digite o peso do pokemon: ");
       scanf("%f", &(*pokedex)[local_certo].peso);
      
   //taxa de captura
       printf("Digite a taxa de captura: ");
       scanf("%d", &(*pokedex)[local_certo].taxa_captura);


   //total (soma = ataque, ataque_especial, defesa, defesa_especial, velocidade e vida)
       (*pokedex)[local_certo].total = (*pokedex)[local_certo].ataque + (*pokedex)[local_certo].ataque_especial + (*pokedex)[local_certo].defesa + (*pokedex)[local_certo].defesa_especial + (*pokedex)[local_certo].velocidade + (*pokedex)[local_certo].vida;


       printf("Novo pokemon adicionado\n");
      
}//cadastro


void listar(Pokemon pokedex[], int num_pokemons_alocacao){
   printf("num listar: %d\n", num_pokemons_alocacao);
   for(int i = 1; i <= num_pokemons_alocacao; i++){
       printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);
   }//for


}//listar


void pesquisar(Pokemon pokedex[], int num_pokemons_alocacao){
  
   char pesquisar[20];
   setbuf(stdin, NULL);
   printf("Digite o nome do Pokémon que deseja pesquisar: ");
   fgets(pesquisar, 20, stdin);
   pesquisar[strcspn(pesquisar, "\n")] = '\0';
  
   for(int i = 0; i < num_pokemons_alocacao; i++){
       if(strcasecmp(pesquisar, pokedex[i].nome_pokemon) == 0){
           printf("Pesquisar pokemon\n");   
           printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i].id, pokedex[i].nome_pokemon, pokedex[i].tipo1, pokedex[i].tipo2, pokedex[i].total, pokedex[i].vida, pokedex[i].ataque, pokedex[i].defesa, pokedex[i].ataque_especial, pokedex[i].defesa_especial, pokedex[i].velocidade, pokedex[i].geracao, pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso, pokedex[i].taxa_captura);


           break;
       }//if
   }//for
  
}//pesquisar


void alterar(Pokemon pokedex[], int num_pokemons_alocacao){
   char pesquisar[20];
   setbuf(stdin, NULL);
   printf("Digite o nome do Pokémon que deseja alterar: ");
   fgets(pesquisar, 20, stdin);
   pesquisar[strcspn(pesquisar, "\n")] = '\0';


   for(int i = 1; i <= num_pokemons_alocacao; i++){
       if(strcasecmp(pokedex[i - 1].nome_pokemon, pesquisar) == 0){
           printf("Alterar pokemon\n");   
           printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);


           printf("\n=====================================================\n");


           setbuf(stdin, NULL);
           printf("Digite o nome do pokemon: ");
           fgets(pokedex[i - 1].nome_pokemon,20,stdin);
           pokedex[i - 1].nome_pokemon[strcspn(pokedex[i - 1].nome_pokemon,"\n")] = '\0';


           break;
       }//if
       else{
           printf("Fudeu\n");
       }//else
   }//for
  
}//alterar


void excluir(Pokemon **pokedex, int *num_pokemons_alocacao){
   char pesquisar[20];
   setbuf(stdin, NULL);
   printf("Digite o nome do pokemón que deseja excluir: ");
   fgets(pesquisar, 20, stdin);
   pesquisar[strcspn(pesquisar, "\n")] = '\0';


       for(int i = 1; i <= *num_pokemons_alocacao; i++){
           if(strcasecmp(pesquisar, (*pokedex)[i - 1].nome_pokemon) == 0){
               printf("Excluiu pokemon\n");
               // Exclua o Pokémon da pokedex[i].
               for (int j = i; j < *num_pokemons_alocacao; j++) {
                   (*pokedex)[j-1] = (*pokedex)[j];
               }//for
               (*num_pokemons_alocacao)--;
               (*pokedex) = (Pokemon*)realloc((*pokedex), *num_pokemons_alocacao * sizeof(Pokemon));
               break;
           }//if


       }//for
}//excluir