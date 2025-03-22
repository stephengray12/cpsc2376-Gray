#include "game.h"
#include <iostream>

int main() {
    Game game;
    char playAgain;

    std::cout << "Welcome to Connect Four!\n";
    std::cout << "Players take turns dropping tokens into columns (1-7).\n";

    do {
        game.resetBoard();
        Status state = ONGOING;

        while (state == ONGOING) {
            std::cout << game;
            std::cout << "Player " << (game.getCurrentPlayer() == PLAYER_1 ? "1 (X)" : "2 (O)") << ", enter column (1-7): ";

            int colInput;
            std::cin >> colInput;

            // Try to play the move
            int col = colInput - 1; // Convert to 0-based index
            Game temp = game; // Copy to test if move changes the board
            game.play(col);

            // If the board didn't change, it was invalid
            if (temp.status() == game.status()) {
                continue;
            }

            state = game.status();
            if (state == ONGOING) {
                game.switchPlayer();
            }
        }

        std::cout << game;
        if (state == PLAYER_1_WINS) std::cout << "Player 1 (X) wins!\n";
        else if (state == PLAYER_2_WINS) std::cout << "Player 2 (O) wins!\n";
        else std::cout << "It's a draw!\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
