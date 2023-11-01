/*
 Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: número (inteiro),
nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro),
ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro),
lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima
evolução (inteiro), pŕe-evolução (inteiro). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.
*/

#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"



void pokedex(Pokemon *pokedex){

    FILE *arquivo_bin = fopen("../../data/pokedex.bin", "w+b");
    if(arquivo_bin == NULL){
        perror("Erro ao carregar arquivo.bin:");
        CloseWindow();
        exit(1);
    }

    fread(pokedex, sizeof(Pokemon), 721, arquivo_bin);

    
}