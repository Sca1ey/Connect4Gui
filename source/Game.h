#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>
#include <vector>

class Game {
    public:
        Game(int COLUMNS, int ROWS);
        Game();
        void InitBoard(int COLUMNS, int ROWS);
        int GetPosition(int COL, int ROW);
        int SetPosition(int COL, int ROW, int VALUE);
        int GetFreeRowInColumn(int COL);
        int GetPlayer();
        int SwitchPlayer();
        bool CheckWin(int COL, int ROW);

    private:
        int mCOLUMNS = 7;
        int mROWS = 6;
        int mPlayer = 1;
        std::vector<std::vector<int> > mBoard;
};