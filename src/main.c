// Importando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "./pokedex/pokedex.h"

int main() {
    int opcao = 0;

    do {
        printf("Escolhe um opção:\n1 - Pokedex\n2 - Coleção\n3 - Mochila\n4 - Batalha\n5 - Sair\n");
        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 5) {
            printf("Escolhe entre 1 a 5\n");
            printf("Escolhe um opção:\n1 - Pokedex\n2 - Coleção\n3 - Mochila\n4 - Batalha\n5 - Sair\n");
            scanf("%d", &opcao);
            
        }
        switch (opcao) {
            case 1:
                pokedex();
                break;

        }
    } while (opcao != 5);

    return 0;
}
