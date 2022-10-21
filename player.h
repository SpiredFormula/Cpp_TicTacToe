
#include <iostream>
using namespace std;

class Player
{
public:
    int player;
    string playerName;
    string place(string range)
    {
        string spot;

        bool turnOver = false;
        cout << "player " << playerName << "'s "
             << "turn \n";
        while (turnOver == false)
        {

            cout << "type the area you want to place: ";
            cin >> spot;
            if (range.find(spot) != string::npos)
            {
                turnOver = true;
                spot = spot;
            }
            else
            {
                cout << "Please input a valid number!!\n";
            }
        }
        return spot;
    };
};