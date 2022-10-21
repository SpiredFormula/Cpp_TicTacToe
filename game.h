
#include <iostream>
using namespace std;

class Game
{
public:
    string Board[3][3]{
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}};
    string test = "no";
    string currentPlayersTurn = "1";
    string CheckIfPlayerWon()
    {
        // check rows
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {
            string row = "";
            for (int j = 0; j <= sizeof(Board[i]) / sizeof(string) - 1; j++)
            {

                row = row + Board[i][j];
            };
            if (row == "xxx")
            {
                return "player 2 wins";
            }
            else if (row == "ooo")
            {
                return "player 1 wins";
            }
        };
        // check collums
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {
            string collum = "";
            for (int j = 0; j <= sizeof(Board[i]) / sizeof(string) - 1; j++)
            {
                collum = collum + Board[j][i];
            };
            if (collum == "xxx")
            {
                return "player 2 wins";
            }
            else if (collum == "ooo")
            {
                return "player 1 wins";
            }
        };
        // check Dingles
        string dingle1 = "";
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {
            dingle1 = dingle1 + Board[i][i];
        }
        if (dingle1 == "xxx")
        {
            return "player 2 wins";
        }
        else if (dingle1 == "ooo")
        {
            return "player 1 wins";
        }
        string dingle2 = "";
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {
            dingle2 = dingle2 + Board[i][sizeof(Board) / sizeof(Board[0]) - 1 - i];
        }
        if (dingle2 == "xxx")
        {
            return "player 2 wins";
        }
        else if (dingle2 == "ooo")
        {
            return "player 1 wins";
        }
        // Check for tie
        string grid = "";
        string range[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {
            for (int j = 0; j <= sizeof(Board[i]) / sizeof(string) - 1; j++)
            {
                grid = grid + Board[i][j];
            };
        };
        string check = "";
        for (int i = 0; i < sizeof(range) / sizeof(string); i++)
        {
            if (grid.find(range[i]) != string::npos)
            {
                check = check + "0";
            }
            else
            {
                check = check + "1";
            }
        }
        if (check == "111111111")
        {
            return "TIE";
        }
        return "No winner";
    };
    void printBoard()
    {
        for (int i = 0; i <= sizeof(Board) / sizeof(Board[0]) - 1; i++)
        {

            for (int j = 0; j <= sizeof(Board[i]) / sizeof(string) - 1; j++)
            {
                cout << Board[i][j];
            };
            cout << "\n";
        };
    };
};