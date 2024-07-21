#include <iostream>
#include <cstdlib>
#include <array>
class BattleShip
{
    std::array<std::array<int, 5>, 5> Locations;
    int Gusses = 0;
    const int MaxGusses;
    int LocationX;
    int LocationY;

public:
    BattleShip(int YourMaxGusses) : MaxGusses{YourMaxGusses}
    {
        int RandomROW;
        int RandomCOL;
        // Intialize the locations with falsh
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                Locations[i][j] = false;
            }
        }
        // get random value for column from 0 to 4
        while (!((RandomCOL >= 0) && (RandomCOL < 5)))
        {
            RandomCOL = rand();
        }
        // get random value for row from 0 to 4
        while (!((RandomROW >= 0) && (RandomROW < 5)))
        {
            RandomROW = rand();
        }
        Locations[RandomROW][RandomCOL] = true;
    }
    bool BattleShip_Guess(int x, int y)
    {
        bool ret_val = false;
        int True_X;
        int True_Y;
        int UserX, UserY;
        bool Check_TimesOfGuess;

        // Increment Current Gusses
        Gusses++;
        // we need to get correct x and y
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (Locations[i][j] = true)
                {
                    True_X = i;
                    True_Y = j;
                    // need to break;
                }
            }
        }
        if ((x == True_X) && (y = True_Y))
        {
            std::cout << "You are Insane !! , You got it easy\n";
            return true;
        }
        else if ((x == (True_X - 1)) && (y = True_Y))
        {
            std::cout << "You are in the Right column and near to actual row\n";
            std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
            return false;
        }
        else if ((x > 4) || (y > 4))
        {
            std::cout << "You are out of bonds\n";
            std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
            return false;
        }
        else if ((x == True_X) && (y = True_Y - 1))
        {
            std::cout << "You are in the Right Row and near to actual Column\n";
            std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
            return false;
        }
        if (BattleShip_GameOver())
        {
            std::cout << "No More Gusses For You, GAME OVERR !!\n";
            std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
            return false;
        }
        else
        {
            std::cout << "Oh No!!,You are away,Try Again\n";
            std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
            return false;
        }
        std::cout << "You have " << MaxGusses - Gusses << " Times to try\n";
        return false;
    }
    bool BattleShip_GameOver() const
    {
        bool Game_Over = false;
        if (Gusses == MaxGusses)
        {
            Game_Over = true;
        }
        else
        {
            Game_Over = false;
        }
        return Game_Over;
    }
    int BattleShip_GetGusses() const
    {
        return Gusses;
    }
};

int main()
{
    BattleShip MyGame(5);
    int PlayerX, PlayerY;

    while (!(MyGame.BattleShip_GameOver()))
    {
        std::cout << "Please Enter Your X Coordinate Location : ";
        std::cin >> PlayerX;
        std::cout << "Please Enter Your Y Coordinate Location : ";
        std::cin >> PlayerY;
        MyGame.BattleShip_Guess(PlayerX, PlayerY);
    }

    return 0;
}