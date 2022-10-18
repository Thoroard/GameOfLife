//
// Created by Xardav on 18.05.2022.
//

#include "GOF.hpp"

std::string UserCommands::next_command()
{
    int a;

    std::cout << std::endl;
    std::cout << "Wybierz czynnosc:" << std::endl << "1.Kontynuuj" << std::endl << "2.Koniec" << std::endl;

    std::cin >> a;
    if (a == 1)
    return "next";

    else if (a == 2)
    return "quit";

    else {
        std::cout << "Podano zła wartosc wybierz ponownie";
        return UserCommands::next_command();

    }
}
