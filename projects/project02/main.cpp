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

            // Input validation
            if (!std::cin || colInput < 1 || colInput > 7) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter a number from 1 to 7.\n";
                continue;
            }

            int col = colInput - 1; // Convert to 0-based index
            if (!game.play(col)) {
                std::cout << "Column full or invalid. Try again.\n";
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
