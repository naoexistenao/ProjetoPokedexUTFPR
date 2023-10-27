#include <raylib.h>

//gcc -o pokemon main.c -lraylib
// ./pokemon

// na pasta mundo-pokemon
// git add .
// git commit -m "qual a atualização"
// git push origin main

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exemplo de Sprite no Raylib");

    Texture sprite = LoadTexture("./assets/img/pokemons.png");

    int frameWidth = sprite.width / 2;
    int frameHeight = sprite.height / 6;

    Rectangle sourceRect = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRect = { (screenWidth - frameWidth) / 2, (screenHeight - frameHeight) / 2, (float)frameWidth, (float)frameHeight };

    int frame_atual_x = 1;
    int frame_atual_y = 1;
    int contar_frame = 0;
    int framesSpeed = 8;
    int frames = 6 * 2; // Total de frames na sprite

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        sourceRect.x = (float)(frame_atual_x) * frameWidth;
        sourceRect.y = (float)(frame_atual_y) * frameHeight;
        

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenhe o sprite atual
        DrawTextureRec(sprite, sourceRect, (Vector2){destRect.x, destRect.y}, RAYWHITE);

        EndDrawing();
    }

    UnloadTexture(sprite);
    CloseWindow();

    return 0;
}
