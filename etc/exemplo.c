//importando bibliotecas
#include <raylib.h>


int main() {
    //definindo tamanho da janela
    const int largura_janela = 800;
    const int altura_janela = 600;

    //criando janela com os tamanhos definidos
    InitWindow(largura_janela, altura_janela, "Mundo Pokemon");

    //funcao para que a tecla Esc nao faça a janela fechar
    SetExitKey(0);

    //carregar imagem
    Texture fundo = LoadTexture("./assets/img/fundos/fundo.png");
    Texture texto = LoadTexture("./assets/img/fundos/texto.png");

    //verificar se as imagem foram carregadas
    if(fundo.id == 0 || texto.id == 0){
        perror("Erro carregar imagem:");
        exit(1);
    }

    //definindo fps
    SetTargetFPS(60);

    //loop que ficar ate a janela ser fechada
    while (!WindowShouldClose()) {

        //logica do programa(açao de alguma tecla, navegar pelo menus etc..)

        //exemplo que navegação pelo menu
        /* 
        if (gameState == STATE_MENU) {
                if (IsKeyPressed(KEY_W)) {
                    opcao_selecionada--;
                    if (opcao_selecionada < 0) {
                        opcao_selecionada = 2;
                    }
                } else if (IsKeyPressed(KEY_S)) {
                    opcao_selecionada++;
                    if (opcao_selecionada > 2) {
                        opcao_selecionada = 0;
                    }
                }
            }
        */

        ///

        //desenhando na janela de acordo com a logica do programa
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(fundo, 0, 0, RAYWHITE);
        DrawTexture(texto, 0, 450, RAYWHITE);

        EndDrawing();

        ///
    }

    //função usada para descarregar imagem, para nao bugar
    /*
    UnloadTexture(fundo_iniciar);
    UnloadTexture(fundo_configuracoes);
    UnloadTexture(fundo_mochila);
    UnloadTexture(fundo_menu);
    UnloadTexture(fundo_pokemon);
    UnloadTexture(personagem);
    */

    //fechando janela
    CloseWindow();

    return 0;
}