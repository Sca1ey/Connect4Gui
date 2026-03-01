#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Game.h"

Game::Game(int COLUMNS, int ROWS){}

Game::InitBoard(int COL, int ROW)
{
    for (int x = 0; x < COL; x++){
                for (int y = 0; y < ROW; y++){
                    board[x][y] = EMPTY;
                }
            }
}
