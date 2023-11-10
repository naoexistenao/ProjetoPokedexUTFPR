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


// //importando bibliotecas
// #include <raylib.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>


// //enum das "paginas" do jogo
// typedef enum{

//     ESTADO_INTRO,
//     ESTADO_NOME,
//     ESTADO_START,
//     ESTADO_MENU,
//     ESTADO_MAPA,
//     ESTADO_POKEDEX,
//     ESTADO_MOCHILA,
//     ESTADO_COLECAO,
//     ESTADO_BATALHA,
//     ESTADO_CREDITOS

// }ESTADO_JOGO;


// int main(){

//     //definindo dimeções da janela
//     const int largura_janela = 800;
//     const int altura_janela = 600;

//     //criando janela com as dimeçoes definidas
//     InitWindow(largura_janela, altura_janela, "Mundo Pokemon");

//     //funcao para que a tecla Esc nao feche a janela
//     SetExitKey(0);

//     //carregando fonte
//     /*Font fonte = LoadFont("./assets/fontes/fonte3.otf");
//     if(fonte.texture.id == 0){
//         perror("Erro ao carregar fonte::");
//         exit(1);
//     }*/

//     //carregando arquivo binario de dados de salvamentos
//     FILE *arquivo_usuario = fopen("../data/arquivo_usuario.bin", "r+b");
//     if(arquivo_usuario == NULL){
//         perror("Erro ao carregar arquivo usuario.bin::");
//         exit(1);
//     }

//     //funcao para definir icon da janela
//     Image icon = LoadImage("./assets/img/icon/icon.png");
//     //verificando se imagem foi carregada com sucesso
//     if(icon.data == NULL){
//         perror("Erro ao carregar icon:");
//         exit(1);
//     }
//     SetWindowIcon(icon);
//     UnloadImage(icon);

//     //carregando sprite de intro
//     Texture2D intro = LoadTexture("./assets/img/fundos/intro.png");
//     if(intro.id == 0){
//         perror("Erro ao carregar imagem intro::");
//         exit(1);
//     }
//     int largura_intro = intro.width, altura_intro = intro.height / 17,
//         frame_atual = 0, time_frame = -10.0f, velocidade_frame = 0.9f;

//     //vetor para todas as imagem de fundo das paginas mapa
//     int qtd_imagens_fundo = 4;
//     Texture fundos_mapa[qtd_imagens_fundo];
//     fundos_mapa[0] = LoadTexture("./assets/img/fundos/fundo_start.png");//fundo imagem de start
//     fundos_mapa[1] = LoadTexture("./assets/img/fundos/fundo_nome.png");//fundo imagem fundo nome
//     fundos_mapa[2] = LoadTexture("./assets/img/fundos/fundo_menu.png");//fundo imagem fundo menu
//     fundos_mapa[3] = LoadTexture("./assets/img/fundos/mapa_terra.png");//fundo imagem fundo menu

//     for(int i = 0; i < qtd_imagens_fundo; i++){
//         if(fundos_mapa[i].id == 0){
//             perror("Erro ao carregar imagem::");
//             exit(1);
//         }
//     }

//     //add nome/apelido
//     char verifica_nome;
//     fread(&verifica_nome, sizeof(char), 1, arquivo_usuario);
//     if(verifica_nome <= 'n'){
//         verifica_nome = 'n';
//         fwrite(&verifica_nome, 0, 1, arquivo_usuario);
//     }    
//     char input_nome[10] = {0};

//     //Personagem
//     Texture2D personagem_img = LoadTexture("./assets/img/personagem/personagem2.png");
//     int largura_frame_personagem = personagem_img.width / 4;
//     int altura_frame_personagem = personagem_img.height / 4;
//     int frame_atual_personagem = 0;
//     int direcao_personagem = 0;
//     Vector2 posicao_personagem = {(float)(largura_janela) / 2, (float)(altura_janela) / 2};
    
//     //variavel para navegar pelo menu
//     int opcao_selecionada = 0;

//     //verificação de sair do jogo
//     bool sair = false;

//     //definindo fps
//     SetTargetFPS(30);

//     //iniciar o jogo no start
//     ESTADO_JOGO estado_jogo = ESTADO_INTRO;

//     //loop ate a janela for fechada
//     while(!WindowShouldClose() && sair == false){

//         //logica


//         //se usuario clicar espaço faça as ações
//         if(IsKeyPressed(KEY_SPACE)){
//             if(estado_jogo == ESTADO_START){
//                 if(verifica_nome == 'n'){
//                     estado_jogo = ESTADO_NOME;
//                     verifica_nome = 's';
//                     fseek(arquivo_usuario, 0, SEEK_SET);
//                     fwrite(&verifica_nome, sizeof(char), 1, arquivo_usuario);

//                 }
//                 else{
//                     estado_jogo = ESTADO_MENU;
//                 }
//             }
//             else if(estado_jogo == ESTADO_MENU){
//                 switch (opcao_selecionada) {
//                     case 0:
//                         estado_jogo = ESTADO_MAPA;
//                         break;
//                     case 1:
//                         estado_jogo = ESTADO_CREDITOS;
//                         break;
//                     case 2:
//                         sair = true;
//                         break;
//                 }
//             }
//         }

//         else{
//             //intro do inicio
//             if(estado_jogo == ESTADO_INTRO){
//                 if(frame_atual < 17){
//                     time_frame += GetFrameTime();
//                     if(time_frame >= velocidade_frame){
//                         frame_atual++;
//                         time_frame = -8.0f;
//                     }
//                 }
//                 else{
//                     estado_jogo = ESTADO_START;
//                 }
//             }

//             //add nome
//             if(estado_jogo == ESTADO_NOME){
//                 int letra = GetKeyPressed();
//                 if(letra != 0){
//                     // Verificar se a tecla pressionada é um caractere imprimível
//                     if ((letra >= 32) && (letra <= 125) && (strlen(input_nome) < 10)) {
//                         input_nome[strlen(input_nome)] = (char)letra;
//                     }
//                     // Verificar se a tecla Enter foi pressionada para limpar o texto
//                     else if (letra == KEY_ENTER) {
//                         fseek(arquivo_usuario, sizeof(char)*1, SEEK_SET);
//                         fwrite(input_nome, sizeof(input_nome), 1, arquivo_usuario);
//                         estado_jogo = ESTADO_MENU;
//                     }
//                     // Verificar se a tecla Backspace foi pressionada para apagar o último caractere
//                     else if (letra == KEY_BACKSPACE) {
//                         if (strlen(input_nome) > 0) {
//                             input_nome[strlen(input_nome) - 1] = '\0';
//                         }
//                     }
//                 }
//             }

//             if(estado_jogo == ESTADO_MENU){
//                 if (IsKeyPressed(KEY_W)) {
//                     opcao_selecionada--;
//                     if (opcao_selecionada < 0) {
//                         opcao_selecionada = 2;
//                     }
//                 } else if (IsKeyPressed(KEY_S)) {
//                     opcao_selecionada++;
//                     if (opcao_selecionada > 2) {
//                         opcao_selecionada = 0;
//                     }
//                 }
//             }

//             if(estado_jogo == ESTADO_MAPA){
//                 if(IsKeyPressed(KEY_ESCAPE)){
//                     estado_jogo = ESTADO_MENU;
//                 }
//                 if (IsKeyDown(KEY_W)) {
//                     posicao_personagem.y -= 5;
//                     direcao_personagem = 3;
//                     frame_atual_personagem++;
//                 }
//                 if (IsKeyDown(KEY_S)) {
//                     posicao_personagem.y += 5;
//                     direcao_personagem = 0;
//                     frame_atual_personagem++;
//                 }
//                 if (IsKeyDown(KEY_A)) {
//                     posicao_personagem.x -= 5;
//                     direcao_personagem = 1;
//                     frame_atual_personagem++;

//                 }
//                 if (IsKeyDown(KEY_D)) {
//                     posicao_personagem.x += 5;
//                     direcao_personagem = 2;
//                     frame_atual_personagem++;
//                 }

//             }

//             if(estado_jogo == ESTADO_CREDITOS){
//                 if(IsKeyPressed(KEY_ESCAPE)){
//                     estado_jogo = ESTADO_MENU;
//                 }
//             }

//         }


//         //fim logica

//         //desenhando
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         if(estado_jogo == ESTADO_INTRO){
//             //intro do inicio
//             if(frame_atual < 17){
//                 Rectangle sourceRect = {
//                     0, 
//                     frame_atual * altura_intro,
//                     largura_intro,
//                     altura_intro
//                 };
//                 ClearBackground(BLACK);
//                 DrawTextureRec(intro, sourceRect, (Vector2){0, 100}, RAYWHITE);
//             }
//         }

//         else if(estado_jogo == ESTADO_START){
//             DrawTexture(fundos_mapa[0], 0, 0, RAYWHITE);
//             DrawText("Clique espaço...",largura_janela / 2 - MeasureText("Clique espaço...", 35) / 2, 250, 35, BLACK);
//         }
        
//         else if(estado_jogo == ESTADO_NOME){
//             DrawTexture(fundos_mapa[1], 0, 0, RAYWHITE);
//             DrawText("Clique Enter para confimar", largura_janela / 2 - MeasureText("Clique Enter para confirmar", 30) / 2, 540, 30, WHITE);
//             DrawText(input_nome, 365, 290, 20, WHITE);
//         }

//         else if(estado_jogo == ESTADO_MENU){
//             DrawTexture(fundos_mapa[2], 0, 0, RAYWHITE);
//             DrawText(TextFormat(opcao_selecionada == 0 ? "> Iniciar" : "Iniciar"), largura_janela / 5 - MeasureText("Iniciar", 20) - 25, altura_janela - 480, 20, WHITE);
//             DrawText(TextFormat(opcao_selecionada == 1 ? "> Creditos" : "Creditos"), largura_janela / 5 - MeasureText("Creditos", 20), altura_janela - 440, 20, WHITE);
//             DrawText(TextFormat(opcao_selecionada == 2 ? "> Sair" : "Sair"), largura_janela / 5 - MeasureText("Sair", 20) - 45, altura_janela - 400, 20, WHITE);

//         }

//         else if(estado_jogo == ESTADO_MAPA){
//             DrawTexture(fundos_mapa[3], 0, 0, RAYWHITE);

//             Rectangle Rec = {frame_atual_personagem * largura_frame_personagem, direcao_personagem * altura_frame_personagem, largura_frame_personagem, altura_frame_personagem};

//             DrawTextureRec(personagem_img, Rec, posicao_personagem, WHITE);
//         }

//         EndDrawing();
//         //fim desenhando

//     }

//     //liberando imagens
//     for(int i = 0; i < qtd_imagens_fundo; i++){
//         UnloadTexture(fundos_mapa[i]);
//     }
//     UnloadTexture(intro);

//     //
//     fclose(arquivo_usuario);

//     //fechando janela
//     CloseWindow();

//     return 0;
// }//main()
