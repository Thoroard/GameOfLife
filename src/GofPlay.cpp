//
// Created by Xardav on 17.05.2022.
//

#include "GOF.hpp"
#include <cstdlib>
GofPlay::GofPlay(GofBoard &InnerBoard, BoardDisplay &InnerDisplay):board(InnerBoard),display(InnerDisplay)
{
    int h = board.getHigh();
    int w = board.getWidth();

    for (int column = 0; column < h; column++)
    {
        next.emplace_back();

        for (int row = 0; row < w; row++) {
            next[column].push_back({false});
        }
    }
}
void GofPlay::turn(CommandSource &CS){
    while (true)
    {
        system ("clear");
        display.display();
        std::cout << std::endl;
        std::string command = CS.next_command();
        int h = board.getHigh();
        int w = board.getWidth();

        for (int column = 0; column < h; column++) {
            for (int row = 0; row < w; row++) {
                if (board.IsAlive(row, column)) {
                    if (board.doesSurvive(row, column)) {
                        next[row][column].isAlive = true;
                    } else {
                        next[row][column].isAlive = false;
                    }
                } else if (board.doesResurrect(row, column)) {
                    next[row][column].isAlive = true;
                } else {
                    next[row][column].isAlive = false;
                }
            }
        }

        for (int column = 0; column < h; column++)
        {
            for (int row = 0; row < w; row++)
                board.board[row][column].isAlive = next[row][column].isAlive;


        }

        if (command == "quit") break;
        else if (command == "next") continue;

    }}

