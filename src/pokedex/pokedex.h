/*
 Para gerenciar a Pokedex, defina uma estrutura Pokémon contendo: número (inteiro),
nome (texto), tipo1 (texto), tipo2 (texto), total (inteiro), ataque (inteiro), defesa (inteiro),
ataque especial (inteiro) , defesa especial (inteiro), velocidade (inteiro), geração (inteiro),
lendário (boleano), cor (texto), altura (real), peso (real), taxa de captura (inteiro), próxima
evolução (inteiro), pŕe-evolução (inteiro). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.
*/

#ifndef POKEMON_H
#define POKEMON_H

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

void pokedex(Pokemon *pokedex);

#endif