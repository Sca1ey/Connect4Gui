#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
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
                    board.push_back({0});
                }
    }
}

int Game::GetPosition(int COL, int ROW)
{
    return board[COL][ROW];
}

int Game::SetPosition(int COL, int ROW, int VALUE)
{
    board[COL][ROW] = VALUE;
    return board[COL][ROW];
}

bool Game::isColumnFull(int COL)
{
    if(board[COL][0] != 0){
        return true;
        }
    return false;
}

int Game::getFreeRowInColumn(int COL){
    for(int ROW = mROWS - 1; y >= 0; y--){
        if(getPosition(COL, ROW) == 0){
            return ROW;
        }
    }
    return -1;
}
