#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>
#include "Game.h"

Game::Game(int COLUMNS, int ROWS)
    : mCOLUMNS{COLUMNS},
      mROWS{ROWS},
      mBoard(ROWS, std::vector<int>(COLUMNS, 0))
    {
        //empty constructor
    };


void Game::InitBoard() 
{    
    for(int x = 0; x < mCOLUMNS; x++){
        for(int y = 0; y < mROWS; y++){
            mBoard[x][y] = 0;
        }
    }
}

int Game::GetPosition(int COL, int ROW)
{
    return mBoard[COL][ROW];
}

int Game::SetPosition(int COL, int ROW, int VALUE)
{
    mBoard[COL][ROW] = VALUE;
    return mBoard[COL][ROW];
}

int Game::GetFreeRowInColumn(int COL)
{
    for(int ROW = mROWS - 1; ROW >= 0; ROW--){
        if(Game::GetPosition(COL, ROW) == 0){
            return ROW;
        }
    }
    return -1;
}

int Game::GetPlayer()
{
    return mPlayer;
}

int Game::SwitchPlayer()
{
    if(mPlayer == 1) {mPlayer = 2;} else {mPlayer = 1;};
    return mPlayer;
}

bool Game::CheckWin(int player)
{
    // Check horizontal -3 to 3
    // Check vertical -3 to 3
    // Check diagonal -3,-3 to +3,+3
    // Check diagonal -3,+3 to +3,-3
       
    int count = 0;
    for (int x = 0; x < mCOLUMNS; x++){
        for (int y = 0; y < mROWS; y++){

            //test current board position
            if(GetPosition(x,y) != player) continue;
                                    
            //horizontal
            count = 0;
            for(int offset = -3; offset < 4; offset++){
                int  xOffset = x + offset;
                if(xOffset < 0 || xOffset >= mCOLUMNS) continue;
                if(GetPosition(xOffset,y) == player) {
                    count++;
                    if (count >= 4) return true;
                } else {
                    count = 0;
                }
            }

            //vertical
            count = 0;
            for(int offset = -3; offset < 4; offset++){
                int yOffset = y + offset;
                if(yOffset < 0 || yOffset >= mROWS) continue;
                if(GetPosition(x, yOffset) == player){
                    count++;
                    if (count >= 4) return true;
                } else {
                    count = 0;
                }
            }

            //diagonal down-right
            count = 0;
            for(int offset = -3 ; offset < 4; offset++){

                    int xOffset = x + offset;
                    int yOffset = y + offset;
                                        
                    if(xOffset < 0 || xOffset >= mCOLUMNS || yOffset < 0 || yOffset >= mROWS) continue;
                    if(GetPosition(xOffset, yOffset) == player) {
                        count++;
                        if (count >= 4) return true;
                    } else {
                        count=0;
                    }
            }

            //diagonal down-left
            count = 0;
            for(int offsetX = 3, offsetY = -3; offsetX >-4, offsetY < 4; offsetX--, offsetY++){
                    int xOffset = x + offsetX;
                    int yOffset = y + offsetY;                 
                    if(xOffset < 0 || xOffset >= mCOLUMNS || yOffset < 0 || yOffset >= mROWS) continue;
                    if(GetPosition(xOffset, yOffset) == player) {
                        count++;
                        if (count >= 4) return true;
                    } else {
                        count=0;
                    }    
            }

        }
    }
    return false;
        
}
