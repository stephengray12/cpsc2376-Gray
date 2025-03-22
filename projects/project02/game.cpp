#include "game.h"

Game::Game() {
    resetBoard();
}

void Game::resetBoard() {
    board = std::vector<std::vector<Player>>(ROWS, std::vector<Player>(COLS, NONE));
    currentPlayer = PLAYER_1;
}

void Game::play(int col) {
    // Ignore invalid move (outside column or column full)
    if (col < 0 || col >= COLS || board[0][col] != NONE) {
        return;
    }

    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == NONE) {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

Status Game::status() const {
    // Check win conditions
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            Player token = board[row][col];
            if (token == NONE) continue;

            // Horizontal
            if (col <= COLS - 4 &&
                token == board[row][col + 1] &&
                token == board[row][col + 2] &&
                token == board[row][col + 3]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Vertical
            if (row <= ROWS - 4 &&
                token == board[row + 1][col] &&
                token == board[row + 2][col] &&
                token == board[row + 3][col]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Diagonal /
            if (row >= 3 && col <= COLS - 4 &&
                token == board[row - 1][col + 1] &&
                token == board[row - 2][col + 2] &&
                token == board[row - 3][col + 3]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Diagonal \
            if (row <= ROWS - 4 && col <= COLS - 4 &&
            token == board[row + 1][col + 1] &&
                token == board[row + 2][col + 2] &&
                token == board[row + 3][col + 3]; {
                    return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    // Check for draw
    for (const auto& row : board) {
        for (Player cell : row) {
            if (cell == NONE) return ONGOING;
        }
    }
    return DRAW;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
}

Player Game::getCurrentPlayer() const {
    return currentPlayer;
}

// Optional: display method via ostream operator
std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "\n 1 2 3 4 5 6 7\n";
    os << "---------------\n";
    for (const auto& row : game.board) {
        for (const auto& cell : row) {
            char symbol = '.';
            if (cell == PLAYER_1) symbol = 'X';
            else if (cell == PLAYER_2) symbol = 'O';
            os << " " << symbol;
        }
        os << "\n";
    }
    os << "---------------\n";
    return os;
}
