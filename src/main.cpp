#include "GOF.hpp"

int main()
{
    //Rozmiary planszy
    int h = 10;
    int w = 10;

    //Tryby gry
    AlwaysNextTurn auto_command_source;
    UserCommands user_command_source;

    //Rodzaje dostępnej przestrzeni
    GofBoard B{h,w}; //Klasyczna
    BoardDisplay BD{B};
    GofPlay GameB{B,BD};

    GofBoardRoller BR{h,w,h,w}; //Walec
    BoardDisplay BRD{BR};
    GofPlay GameBR{BR,BRD};

    GofBoardTorus BT {h,w,h,w}; //"Donut", Torus
    BoardDisplay BTD{BT};
    GofPlay GameBT{BT,BTD};


//Wybór planszy i trybu
    std::string mode,board_mode;
    std::cout << "Wybierz tryb [user, auto]: ";
    std::cin >> mode;
    std::cout << std::endl;
    std::cout << "Wybierz rodzaj planszy [classic, roller, torus]: ";
    std::cin >> board_mode;
    std::cout << std::endl;

if (board_mode == "classic")
{
    if (mode == "user")
        GameB.turn(user_command_source);
    else if (mode == "auto")
        GameB.turn(auto_command_source);
    else
    {
        std::cout << "Podano zly tryb, koniec programu";
        return 0;
    }
}

 if (board_mode == "roller")
{
    if (mode == "user")
        GameBR.turn(user_command_source);
    else if (mode == "auto")
        GameBT.turn(auto_command_source);
    else
    {
        std::cout << "Podano zly tryb, koniec programu";
        return 0;
    }
}

 if (board_mode == "torus")
{
    if (mode == "user")
        GameBR.turn(user_command_source);
    else if (mode == "auto")
        GameBT.turn(auto_command_source);
    else
    {
        std::cout << "Podano zly tryb, koniec programu";
        return 0;
    }
}

    return 0;
}
