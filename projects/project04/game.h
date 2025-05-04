#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>


enum Player { NONE, PLAYER_1, PLAYER_2 };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game {
private:
    static const int ROWS = 6;
    static const int COLS = 7;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;

public:
    Game();
    void resetBoard();
    bool play(int col);
    Status status() const;
    void switchPlayer();
    Player getCurrentPlayer() const;

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
    void draw(Engine& engine) const;

};

#endif
