#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include "player.h"
#include "game.h"
using namespace std;

void changeSpot(Player Player, Game Game, string person)
{
}

int main()
{
    Player player1;
    Player player2;
    Game NewGame;
    string range = "123456789";

    cout << "hello and welcome to tic tac toe in c++ (Please help oh god this language sucks) \n";
    cout << "player 1 please enter your name: ";
    getline(cin, player1.playerName);
    cout << "hello " << player1.playerName << "\n";
    cout << "player 2 please enter your name: ";
    getline(cin, player2.playerName);
    cout << "hello " << player2.playerName << "\n";
    cout << "begin!!!"
         << "\n";

    NewGame.printBoard();
    bool GameStarted = true;
    while (GameStarted == true)
    {
        string spot = player1.place(range);
        int NumSpot = stoi(spot) - 1;
        int NumSpot2 = 0;
        if (NumSpot > 2)
        {

            NumSpot = NumSpot - 3;
            NumSpot2 = 1;
            if (NumSpot > 2)
            {
                NumSpot = NumSpot - 3;
                NumSpot2 = 2;
            }
        }
        // remove spot from range (Player1)
        char arr[spot.length() + 1];
        strcpy(arr, spot.c_str());
        int temp = stoi(spot);
        char character = arr[0];
        range.erase(remove(range.begin(), range.end(), character), range.end());
        // make move (Player1)
        NewGame.Board[NumSpot2][NumSpot] = "o";
        NewGame.printBoard();
        string win = NewGame.CheckIfPlayerWon();
        if (win == "player 1 wins")
        {
            string exit;
            cout << "PLAYER ONE WINS PRESS ANY BUTTON TO QUIT";
            cin >> exit;
            GameStarted = false;
            break;
        }
        else if (win == "TIE")
        {
            string exit;
            cout << "TIE PRESS ANY BUTTON TO QUIT";
            cin >> exit;
            GameStarted = false;
            break;
        }
        spot = player2.place(range);
        NumSpot = stoi(spot) - 1;
        NumSpot2 = 0;
        if (NumSpot > 2)
        {
            NumSpot = NumSpot - 3;
            NumSpot2 = 1;
            if (NumSpot > 2)
            {
                NumSpot = NumSpot - 3;
                NumSpot2 = 2;
            }
        }
        // remove spot from range (Player2)
        arr[spot.length() + 1];
        strcpy(arr, spot.c_str());
        temp = stoi(spot);
        character = arr[0];
        range.erase(remove(range.begin(), range.end(), character), range.end());
        // make move (Player2)
        NewGame.Board[NumSpot2][NumSpot] = "x";

        NewGame.printBoard();
        win = NewGame.CheckIfPlayerWon();
        if (win == "player 2 wins")
        {
            string exit;
            cout << "PLAYER TWO WINS PRESS ANY BUTTON TO QUIT";
            cin >> exit;
            GameStarted = false;
            break;
        }
        else if (win == "TIE")
        {
            string exit;
            cout << "TIE PRESS ANY BUTTON TO QUIT";
            cin >> exit;
            GameStarted = false;
            break;
        }
    }

    return 0;
}