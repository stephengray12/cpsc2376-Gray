#include "game.h"
#include "Engine.h"

Game::Game() {
    resetBoard();
}

void Game::resetBoard() {
    board = std::vector<std::vector<Player>>(ROWS, std::vector<Player>(COLS, NONE));
    currentPlayer = PLAYER_1;
}

bool Game::play(int col) {
    // Prevent invalid or out-of-bounds column
    if (col < 0 || col >= COLS || board[0][col] != NONE) {
        return false;
    }

    for (int row = ROWS - 1; row >= 0; --row) {
        if (board[row][col] == NONE) {
            board[row][col] = currentPlayer;
            return true;
        }
    }

    return false;
}

Status Game::status() const {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            Player token = board[row][col];
            if (token == NONE) continue;

            // Horizontal check
            if (col <= COLS - 4 &&
                token == board[row][col + 1] &&
                token == board[row][col + 2] &&
                token == board[row][col + 3]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Vertical check
            if (row <= ROWS - 4 &&
                token == board[row + 1][col] &&
                token == board[row + 2][col] &&
                token == board[row + 3][col]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Diagonal (top-left to bottom-right)
            if (row <= ROWS - 4 && col <= COLS - 4 &&
                token == board[row + 1][col + 1] &&
                token == board[row + 2][col + 2] &&
                token == board[row + 3][col + 3]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }

            // Diagonal (bottom-left to top-right)
            if (row >= 3 && col <= COLS - 4 &&
                token == board[row - 1][col + 1] &&
                token == board[row - 2][col + 2] &&
                token == board[row - 3][col + 3]) {
                return (token == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    // Check for ongoing game (any empty space left)
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

void Game::draw(Engine& engine) const {
    int cellSize = 80;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            int x = col * cellSize + cellSize / 2;
            int y = row * cellSize + cellSize + 40;

            // Draw grid background
            engine.drawRectangle(x, y, cellSize - 4, cellSize - 4, { 0, 0, 255, 255 });

            // Draw token if present
            SDL_Color color = { 0, 0, 0, 255 };
            if (board[row][col] == PLAYER_1) color = { 255, 0, 0, 255 };
            else if (board[row][col] == PLAYER_2) color = { 255, 255, 0, 255 };
            engine.drawCircle(x, y, 30, color);
        }
    }
}
