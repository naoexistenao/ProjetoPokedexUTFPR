/*
 Defina uma estrutura Coleção que deve armazenar a relação dos Pokémons já
capturados, para isso armazene apenas o número(códigos). Essa relação deve
aumentar e diminuir dinamicamente. Você deve prever o caso de Pokémons duplicados.
O sistema deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) os pokémons
já capturados.
*/
#ifndef COLECAO_H
#define COLECAO_H
typedef struct{
    int id;
    char nome_pokemon[20];
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
} Colecao;

void colecao();

#endif