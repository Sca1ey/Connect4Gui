#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>

class Game {
    public:
        Game();

    private:
        int COLUMNS = 7;
        int ROWS = 6;
        enum PositionState {
            EMPTY,
            NOUGHT,
            CROSS
        };
};