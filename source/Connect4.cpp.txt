#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <limits>

const int COLUMNS  = 7;
const int ROWS = 6;

enum PositionState {
    EMPTY,
    NOUGHT,
    CROSS
};

class Game {

    public:

        // Fill board with EMPTY positions
        void initBoard(){
            for (int x = 0; x < COLUMNS; x++){
                for (int y = 0; y < ROWS; y++){
                    board[x][y] = EMPTY;
                }
            }
        }

        void displayBoard(){

            std::cout << "\n\n\n\n\n";

            // Print Column heading numbers
            for(int x =0; x < COLUMNS; x++){
                std::cout << "\t" << x + 1;
            }

            // Print board row by row
            for (int y = 0; y < ROWS; y++){

                std::cout << "\n\n";

                for (int x = 0; x < COLUMNS; x++){

                        switch(getPosition(x,y)){
                            case 1:
                                std::cout << "\tO";
                                break;
                            case 2:
                                std::cout << "\tX";
                                break;
                            default:
                                std::cout << "\t.";
                        }
                        
                    }
                }
        }

        PositionState getPosition(int x, int y){
            return board[x][y];
        };

        bool isColumnFull(int x){
            if(board[x][0] != EMPTY){
                return true;
            }
            return false;
        }

        int getFreeRowInColumn(int x){
            for(int y = ROWS - 1; y >= 0; y--){
                if(getPosition(x,y) == EMPTY){
                    return y;
                }
            }
            return -1;
        }

        void setPosition(int x, int y, PositionState state){
            board[x][y] = state;
        }

        // Checking for 4 in a row
        // Check x,y - if not == player move on
        // Check horizontal -3 to 3
        // Check vertical -3 to 3
        // Check diagonal -3,-3 to +3,+3
        // Check diagonal -3,+3 to +3,-3
        bool checkForWin(PositionState player){
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

    private:
        PositionState board[COLUMNS][ROWS];
        
};

int main(){
    
    std::cout << "\n\nConnect 4\n\n";
    
    Game game = Game();
    game.initBoard();
        
    bool run = true;
    PositionState player = NOUGHT;
    int turns = 0;
    while(run){

        //Get input from current player, keep looping until valid input
        bool takingTurn = true;
        do{
            game.displayBoard(); 
            
            // Get user input for current round
            int posx = 0;
            std::cout << "\n\nPlayer "<< player <<", enter a column number, then press Return/Enter: ";
            std::cin >> posx;

            if (std::cin.fail()) {
                std::cerr << "\n\nSorry, I cannot read that. Please try again.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if(posx < 1 && posx > COLUMNS){
                std::cout << "\n\nInvalid column, try again!";
                continue;
            }

            posx--; //adjust column to array dimensions

            //Test for room in column
            if(game.isColumnFull(posx) == true){
                std::cout << "\n\nColumn full, try again!";
                continue;
            }
                
            //Column is valid and has space, therefore place piece              
            game.setPosition(posx,game.getFreeRowInColumn(posx),player);
            takingTurn = false;

        } while (takingTurn);

        //Check for win
        if(game.checkForWin(player) == true){

            game.displayBoard(); 
            std::cout << "\n\nPlayer " << player << " wins!\n\n";
            run = false;
            continue;
        };

        //Switch player
        if (player == NOUGHT) {player = CROSS;} else {player = NOUGHT;};

        //Test to see if the board is full, end if so
        turns++;
        int maxTurns = ROWS * COLUMNS;
        if(turns >= maxTurns){
            game.displayBoard(); 
            std::cout << "\n\nStalemate - no one wins!\n\n";
            run = false;
        }
              
    }

    return 0;
}
