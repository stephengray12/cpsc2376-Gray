#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

// Plain enums as required
enum Player { NONE, PLAYER_1, PLAYER_2 };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game {
public:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;

public:
    Game();                         // Constructor
    void resetBoard();              // Resets the board and sets player 1
    void play(int col);             // Executes a move for current player
    Status status() const;          // Returns current game status
    void switchPlayer();            // Switches to the other player
    Player getCurrentPlayer() const; // Returns current player (for display)

    friend std::ostream& operator<<(std::ostream& os, const Game& game); // For board display
};

#endif
