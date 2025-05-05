#define SDL_MAIN_HANDLED
#include "game.h"
#include "Engine.h"
#include <SDL2/SDL.h>

int main() {
    Engine engine("Connect Four", 700, 600, "Ubuntu-Bold.ttf", 28, "move.wav");
    Game game;
    int selectedCol = 0;
    bool running = true;
    bool gameOver = false;

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                else if (e.key.keysym.sym == SDLK_LEFT) {
                    selectedCol = (selectedCol + 6) % 7;
                }
                else if (e.key.keysym.sym == SDLK_RIGHT) {
                    selectedCol = (selectedCol + 1) % 7;
                }
                else if (e.key.keysym.sym == SDLK_RETURN || e.key.keysym.sym == SDLK_RETURN2) {
                    if (!gameOver && game.play(selectedCol)) {
                        engine.playSound();
                        if (game.status() == ONGOING) {
                            game.switchPlayer();
                        }
                        else {
                            gameOver = true;
                        }
                    }
                }
                else if (e.key.keysym.sym == SDLK_r) {
                    game = Game();  // Reset game
                    selectedCol = 0;
                    gameOver = false;
                }
            }
        }

        // Rendering
        engine.clear({ 0, 0, 0, 255 });
        game.draw(engine);

        // Draw selection indicator
        int cellSize = 80;
        int x = selectedCol * cellSize + cellSize / 2;
        engine.drawCircle(x, 40, 20, { 255, 255, 255, 255 });

        // Show result
        Status s = game.status();
        if (s != ONGOING) {
            std::string result;
            if (s == PLAYER_1_WINS) result = "Player 1 Wins!";
            else if (s == PLAYER_2_WINS) result = "Player 2 Wins!";
            else result = "Draw!";
            engine.drawText(result, 350, 550, { 255, 255, 0, 255 });
            engine.drawText("Press R to Restart", 350, 580, { 150, 150, 150, 255 });
        }

        engine.flip();
        SDL_Delay(16);
    }

    return 0;
}
