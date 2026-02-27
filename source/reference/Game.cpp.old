#include <stdio.h>
#include <iostream>
#include <limits>
#include "Game.h"

Game::Game(){};

void Game::InitBoard(){
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            board[x][y] = 0;
        }
    }
}

int Game::GetPosition(int x, int y)
{
    return board[x][y];
};

void Game::SetPosition(int x, int y, int state)
{
    board[x][y] = state;
}

bool Game::CheckWin()
{
    for (int i = 0; i < 8; i++){
        int winLine[3];
        for (int j = 0; j < 3; j++){
            winLine[j] = board[ winLines[i][j][0] ][ winLines[i][j][1] ];
        }
        if(winLine[0] != 0 && winLine[0] == winLine[1] && winLine[0] == winLine[2]){                 
            return true;
        }
    }
    return false;
}

int Game::GetPlayer()
{
    return player;
}

int Game::SwitchPlayer()
{
    if(player == 1){player = 2;} else {player = 1;}
    return player;
};

int Game::AddTurn()
{
    turns += 1;
    return turns;
};

int Game::ResetTurns()
{
    turns = 0;
    return turns;
}

/*
int main (){
    Game* game = new Game();
    game->InitBoard();
    game->SetPosition(0,0,1);
    game->SetPosition(0,1,1);
    game->SetPosition(0,2,1);
    game->SwitchPlayer();
    std::cout << game->GetPlayer() << std::endl;
    std::cout << game->GetPosition(0,0) << std::endl;
    std::cout << game->CheckWin() << std::endl;
}
*/