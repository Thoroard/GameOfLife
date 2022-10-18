#include "GOF.hpp"

BoardDisplay::BoardDisplay(GofBoard &DisplayBoard):board(DisplayBoard) {}

void BoardDisplay::display() {
    int Height = board.getHigh();
    int Width = board.getWidth();


     for(int h = 0; h < Height; h++) {
         std::cout << std::endl;
         for (int w = 0; w < Width; w++)
         {
             std::cout << "| ";
             board.FieldInfo(w,h);

         }
         std::cout << "|";
     }

}
