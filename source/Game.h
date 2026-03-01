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

    private:
        int mCOLUMNS = 7;
        int mROWS = 6;
        std::vector<std::vector<int>> board;
};