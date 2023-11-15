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
#include "./pokedex/pokedex.h"
#include "./colecao/colecao.h"
#include "./mochila/mochila.h"
#include "./batalha/batalha.h"

int main() {
    //criando variaveis
    int opcao = 0;

    //o usuario selecionar 
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
