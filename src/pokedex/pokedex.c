/*
 Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: número (inteiro),
nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro),
ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro),
lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima
evolução (inteiro), pŕe-evolução (inteiro). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"
#include <string.h>

void inserir(Pokemon pokedex[], int *num_pokemons_alocacao);
void listar(Pokemon pokedex[], int num_pokemons_alocacao);
void pesquisar(Pokemon pokedex[], int num_pokemons_alocacao);
void alterar(Pokemon pokedex[], int num_pokemons_alocacao);
void excluir(Pokemon pokedex[], int *num_pokemons_alocacao);

void pokedex() {

    int num_pokemons_alocacao = 722;
    Pokemon *pokedex = (Pokemon*)calloc(num_pokemons_alocacao, sizeof(Pokemon));
    if(pokedex == NULL){
        perror("Erro memoria Insuficiente!!\n");
        exit(1);
    }//if

    FILE *arquivo_bin = fopen("../data/pokedex.bin", "rb");
    if (arquivo_bin == NULL) {
        perror("Erro ao carregar arquivo.bin:");
        exit(1);
    }//if

    fread(pokedex, sizeof(Pokemon), num_pokemons_alocacao, arquivo_bin);
    fclose(arquivo_bin);

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
                inserir(pokedex, &num_pokemons_alocacao);
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
                excluir(pokedex, &num_pokemons_alocacao);
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


void inserir(Pokemon pokedex[], int *num_pokemons_alocacao){
    (*num_pokemons_alocacao)++;
    pokedex = (Pokemon*)realloc(pokedex, *num_pokemons_alocacao * sizeof(Pokemon));
    if(pokedex == NULL){
        printf("erro sem espaço na memoria\n");
    }
    Pokemon *novo_pokemon = &pokedex[*num_pokemons_alocacao - 1];
    //nome
        printf("Digite o nome do pokemon: ");
        setbuf(stdin, NULL);
        fgets(novo_pokemon[*num_pokemons_alocacao].nome_pokemon,20,stdin);
        novo_pokemon[*num_pokemons_alocacao].nome_pokemon[strcspn(novo_pokemon[*num_pokemons_alocacao].nome_pokemon,"\n")] = '\0';
        setbuf(stdin, NULL);

    //id
        novo_pokemon[*num_pokemons_alocacao].id = *num_pokemons_alocacao+1;

    //tipo1
        printf("Digite o 1º tipo do seu pokemon: ");
        fgets(novo_pokemon[*num_pokemons_alocacao].tipo1,10,stdin);
        novo_pokemon[*num_pokemons_alocacao].tipo1[strcspn(novo_pokemon[*num_pokemons_alocacao].tipo1, "\n")] = '\0';
        setbuf(stdin, NULL);

    //tipo2
        printf("Digite o 2º tipo do seu pokemon: ");
        fgets(novo_pokemon[*num_pokemons_alocacao].tipo2,10,stdin);
        novo_pokemon[*num_pokemons_alocacao].tipo2[strcspn(novo_pokemon[*num_pokemons_alocacao].tipo2, "\n")] = '\0';
        setbuf(stdin, NULL);

    //vida
        printf("Digite a vida do pokemon: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].vida);

    //ataque
        printf("Digite o valor de ataque do pokemon: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].ataque);

    //defesa
        printf("Digite o valor da defesa: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].defesa);

    //ataque_especial
        printf("Digite o valor do ataque especial: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].ataque_especial);

    //defesa_especial
        printf("Digite o valor da defesa especial: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].defesa_especial);

    //velocidade
        printf("Digite o valor da velocidade do pokemon: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].velocidade);

    //geração
        printf("Digite a geração do pokemon: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].geracao);

    //lendário (1 se for lendário e 0 se não for(boleano))
        printf("Digite 1 se o pokemon for lendário e 0 se não for: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].lendario);

    //cor[10]
        setbuf(stdin, NULL);
        printf("Digite a cor do pokemon: ");
        fgets(novo_pokemon[*num_pokemons_alocacao].cor, 10, stdin);
        novo_pokemon[*num_pokemons_alocacao].cor[strcspn(novo_pokemon[*num_pokemons_alocacao].cor, "\n")] = '\0';

    //altura float
        printf("Digite a altura do pokemon: ");
        scanf("%f", &novo_pokemon[*num_pokemons_alocacao].altura);
        
    //peso float
        printf("Digite o peso do pokemon: ");
        scanf("%f", &novo_pokemon[*num_pokemons_alocacao].peso);
        
    //taxa de captura
        printf("Digite a taxa de captura: ");
        scanf("%d", &novo_pokemon[*num_pokemons_alocacao].taxa_captura);

    //próxima evolução


    //pré evolução

    //total (soma = ataque, ataque_especial, defesa, defesa_especial, velocidade e vida)
        novo_pokemon[*num_pokemons_alocacao].total = novo_pokemon[*num_pokemons_alocacao].ataque + novo_pokemon[*num_pokemons_alocacao].ataque_especial + novo_pokemon[*num_pokemons_alocacao].defesa + novo_pokemon[*num_pokemons_alocacao].defesa_especial + novo_pokemon[*num_pokemons_alocacao].velocidade + novo_pokemon[*num_pokemons_alocacao].vida;

        pokedex[*num_pokemons_alocacao] = novo_pokemon[*num_pokemons_alocacao - 1];

        printf("Novo pokemon adicionado\n");
}//cadastro

void listar(Pokemon pokedex[], int num_pokemons_alocacao){
    
    for(int i = 1; i < num_pokemons_alocacao; i++){
        printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);
    }

}

void pesquisar(Pokemon pokedex[], int num_pokemons_alocacao){
    
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja pesquisar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';
    
    for(int i = 1; i < num_pokemons_alocacao; i++){
        int pesquisa = 0;
        if(pesquisa == 0){
            printf("Pesquisar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);

            break;
        }
    }
    
}

void alterar(Pokemon pokedex[], int num_pokemons_alocacao){
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do Pokémon que deseja alterar: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';

    for(int i = 1; i < num_pokemons_alocacao; i++){
        if(strcmp(pokedex[i].nome_pokemon, pesquisar) == 0){
            printf("Alterar pokemon\n");    
            printf("%d %s %s %s %d %d %d %d %d %d %d %d %d %s %.2f %.2f %d\n", pokedex[i - 1].id, pokedex[i - 1].nome_pokemon, pokedex[i - 1].tipo1, pokedex[i - 1].tipo2, pokedex[i - 1].total, pokedex[i - 1].vida, pokedex[i - 1].ataque, pokedex[i - 1].defesa, pokedex[i - 1].ataque_especial, pokedex[i - 1].defesa_especial, pokedex[i - 1].velocidade, pokedex[i - 1].geracao, pokedex[i - 1].lendario, pokedex[i - 1].cor, pokedex[i - 1].altura, pokedex[i - 1].peso, pokedex[i - 1].taxa_captura);

            printf("\n=====================================================\n");

            setbuf(stdin, NULL);
            printf("Digite o nome do pokemon: ");
            fgets(pokedex[num_pokemons_alocacao].nome_pokemon,20,stdin);
            pokedex[num_pokemons_alocacao].nome_pokemon[strcspn(pokedex[i - 1].nome_pokemon,"\n")] = '\0';

            break;
        }
        else{
            printf("Fudeu\n");
        }
    }
    
    
}

void excluir(Pokemon pokedex[], int *num_pokemons_alocacao){
    char pesquisar[20];
    setbuf(stdin, NULL);
    printf("Digite o nome do pokemón que deseja excluir: ");
    fgets(pesquisar, 20, stdin);
    pesquisar[strcspn(pesquisar, "\n")] = '\0';

        for(int i = 1; i < *num_pokemons_alocacao; i++){
            if(strcmp(pesquisar, pokedex[i - 1].nome_pokemon) == 0){
                printf("Excluiu pokemon\n");
                // Exclua o Pokémon da pokedex[i].
                for (int j = i; j < *num_pokemons_alocacao - 1; j++) {
                    pokedex[j] = pokedex[j + 1];
                    }
                (*num_pokemons_alocacao)--;
                pokedex = (Pokemon*)realloc(pokedex, *num_pokemons_alocacao * sizeof(Pokemon));
                break;
            }//if

        }//for
}//excluir