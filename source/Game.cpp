#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
#include "Game.h"

Game::Game(int COLUMNS, int ROWS)
    : mCOLUMNS{COLUMNS},
      mROWS{ROWS} 
    {
        InitBoard(mCOLUMNS, mROWS);
    };

Game::Game()
    {
        InitBoard(mCOLUMNS, mROWS);
    };

void Game::InitBoard(int COLUMNS, int ROWS)
    
{
    for (int x = 0; x < COLUMNS; x++){
                for (int y = 0; y < ROWS; y++){
                    board[x][y] = 0;
                }
    }
}
