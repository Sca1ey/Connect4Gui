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
                    mBoard.push_back({0});
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

bool Game::CheckWin(int COL, int ROW)
{
    // Check horizontal -3 to 3
        // Check vertical -3 to 3
        // Check diagonal -3,-3 to +3,+3
        // Check diagonal -3,+3 to +3,-3
       
            int count = 0;
            //loop through board x,y
            for (int x = 0; x < COLUMNS; x++){
                for (int y = 0; y < ROWS; y++){

                    //test current board position
                    if(getPosition(x,y) != player) continue;
                                    
                    //horizontal
                    count = 0;
                    for(int offset = -3; offset < 4; offset++){
                        int  xOffset = x + offset;
                        if(xOffset < 0 || xOffset >= COLUMNS) continue;
                        if(getPosition(xOffset,y) == player) {
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
                        if(yOffset < 0 || yOffset >= ROWS) continue;
                        if(getPosition(x, yOffset) == player){
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
                                                
                            if(xOffset < 0 || xOffset >= COLUMNS || yOffset < 0 || yOffset >= ROWS) continue;
                            if(getPosition(xOffset, yOffset) == player) {
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
                            if(xOffset < 0 || xOffset >= COLUMNS || yOffset < 0 || yOffset >= ROWS) continue;
                            if(getPosition(xOffset, yOffset) == player) {
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
