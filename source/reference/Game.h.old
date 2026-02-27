#pragma once
#include <stdio.h>
#include <iostream>
#include <limits>

class Game {

    public:
        Game();
        void InitBoard();
        int GetPosition(int, int );
        void SetPosition(int, int, int);
        bool CheckWin();
        int GetPlayer();
        int SwitchPlayer();
        int AddTurn();
        int ResetTurns();

    private:
        int turns = 0;
        int player = 1;
        int board[3][3];   
        int  winLines[8][3][2] = {
            {{0,0},{0,1},{0,2}},
            {{1,0},{1,1},{1,2}},
            {{2,0},{2,1},{2,2}},
            {{0,0},{1,0},{2,0}},
            {{0,1},{1,1},{2,1}},
            {{0,2},{1,2},{2,2}},
            {{0,0},{1,1},{2,2}},
            {{2,0},{1,1},{0,2}}
        };
};