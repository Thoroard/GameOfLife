
#include "GOF.hpp"


GofBoard::GofBoard(int high, int width):high(high),width(width) {
for (int column = 0; column < high; column++)
    {
        board.emplace_back();

        for (int row = 0; row < width; row++)
        {
            board[column].push_back({false});
        }
    }
    // Block
    board[0][0].isAlive = true;
    board[1][0].isAlive = true;
    board[0][1].isAlive = true;
    board[1][1].isAlive = true;
    //Block

    //Tub
    board[0][5].isAlive = true;
    board[1][4].isAlive = true;
    board[2][5].isAlive = true;
    board[1][6].isAlive = true;
    //Tub

    //Blinker
    board[7][0].isAlive = true;
    board[7][1].isAlive = true;
    board[7][2].isAlive = true;
    //Blinker

    //Beacon
    board[6][6].isAlive = true;
    board[7][6].isAlive = true;
    board[6][7].isAlive = true;
    board[7][7].isAlive = true;

    board[8][8].isAlive = true;
    board[9][8].isAlive = true;
    board[8][9].isAlive = true;
    board[9][9].isAlive = true;
    //Beacon



}
/*void GofBoard::debugDisplay() {
    std::cout << std::endl << std::endl;
 for (int column = 0; column<width; column++)
    {
        for (int row = 0; row < high; row++)
        {
            if (board[row][column].isAlive)
                std::cout << "# ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
 std::cout << std::endl;

}*/
bool GofBoard::IsAlive(int row,int col){
   return board[row][col].isAlive;
}
bool GofBoard::doesSurvive(int row,int col) {
    if (checkNeighbours(row, col) == 2 || checkNeighbours(row, col) == 3)
        return true;
    else
        return false;

}
bool GofBoard::doesResurrect(int row, int col) {
    if (checkNeighbours(row,col) == 3)
        return true;
    else
    return false;
}
int GofBoard::checkNeighbours(int row, int col) {
    int Neighbour = 0;

    if (rowIsValid(row-1) && colIsValid(col-1))
    {
        if (board[row-1][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid(row-1) && colIsValid(col))
    {
        if (board[row-1][col].isAlive){
            Neighbour++;}}
    if (rowIsValid(row-1) && colIsValid(col+1))
    {
        if (board[row-1][col+1].isAlive){
            Neighbour++;}}
    if (rowIsValid(row) && colIsValid(col-1))
    {
        if (board[row][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid(row) && colIsValid(col+1))
    {
        if (board[row][col+1].isAlive){
            Neighbour++;}}
    if (rowIsValid(row+1) && colIsValid(col-1))
    {
        if (board[row+1][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid(row+1) && colIsValid(col))
    {
        if (board[row+1][col].isAlive){
            Neighbour++;}}
    if (rowIsValid(row+1) && colIsValid(col+1))
    {
        if (board[row+1][col+1].isAlive)
        {
            Neighbour++ ;
        }
    }
    return Neighbour;
}
bool GofBoard::rowIsValid(int row) const{
    return (row >=0 && row < high);
}
bool GofBoard::colIsValid(int col) const{
    return (col >=0 && col < width);
}
int GofBoard::getHigh() const {
    return high;
}
int GofBoard::getWidth() const {
    return width;
}
void GofBoard::FieldInfo(int row, int col) {
    if (board[row][col].isAlive)
        std::cout << "# ";
    else if (!board[row][col].isAlive)
        std::cout << ". ";
}
