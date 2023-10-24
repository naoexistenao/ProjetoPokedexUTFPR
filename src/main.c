/*
Executar o programa: gcc -o pokemon main.c -lraylib -lm
Abrir arquivo executavel: ./pokemon
*/

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exemplo de Barra de Rolagem no Raylib");

    const int contentWidth = 2000;
    const int contentHeight = 1500;

    Rectangle horizontalBar = {0, screenHeight - 20, screenWidth, 20};
    Rectangle verticalBar = {screenWidth - 20, 0, 20, screenHeight};

    Rectangle content = {0, 0, contentWidth, contentHeight};
    Camera2D camera = {0};
    camera.target = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    // Vamos criar alguns marcadores verdes aleatórios
    Rectangle markers[20];
    for (int i = 0; i < 20; i++) {
        markers[i].x = GetRandomValue(0, contentWidth - 50); // Ajuste o tamanho do quadro como necessário
        markers[i].y = GetRandomValue(0, contentHeight - 50); // Ajuste o tamanho do quadro como necessário
        markers[i].width = 50;
        markers[i].height = 50;
    }

    while (!WindowShouldClose()) {
        camera.target.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 5;
        camera.target.y += (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 5;

        if (camera.target.x < screenWidth / 2.0f)
            camera.target.x = screenWidth / 2.0f;
        if (camera.target.x > contentWidth - screenWidth / 2.0f)
            camera.target.x = contentWidth - screenWidth / 2.0f;
        if (camera.target.y < screenHeight / 2.0f)
            camera.target.y = screenHeight / 2.0f;
        if (camera.target.y > contentHeight - screenHeight / 2.0f)
            camera.target.y = contentHeight - screenHeight / 2.0f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        DrawRectangle(0, 0, contentWidth, contentHeight, LIGHTGRAY);

        // Desenhe os marcadores
        for (int i = 0; i < 20; i++) {
            DrawRectangleRec(markers[i], GREEN);
        }

        EndMode2D();

        DrawRectangleRec(horizontalBar, DARKGRAY);
        DrawRectangleRec(verticalBar, DARKGRAY);

        horizontalBar.x = -camera.target.x;
        verticalBar.y = -camera.target.y;

        Vector2 mousePoint = GetMousePosition();
        bool horizontalBarHover = CheckCollisionPointRec(mousePoint, horizontalBar);
        bool verticalBarHover = CheckCollisionPointRec(mousePoint, verticalBar);

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            if (horizontalBarHover) {
                float scrollX = (GetMouseX() - horizontalBar.x - horizontalBar.width / 2) * contentWidth / screenWidth;
                camera.target.x = scrollX + screenWidth / 2;
            } else if (verticalBarHover) {
                float scrollY = (GetMouseY() - verticalBar.y - verticalBar.height / 2) * contentHeight / screenHeight;
                camera.target.y = scrollY + screenHeight / 2;
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
