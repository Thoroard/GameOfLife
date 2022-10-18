#include "GOF.hpp"

GofBoardTorus::GofBoardTorus(int SourceHigh, int SourceWidth, int high, int width)
        : GofBoard( SourceHigh, SourceWidth), high(high), width(width) {}

int GofBoardTorus::checkNeighbours(int row, int col) {
    int Neighbour = 0;

    if (rowIsValid((row - 1 + high) % high) && colIsValid((col - 1 + width) % width))
    {
        if (board[(row - 1 + high) % high][(col - 1 + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row - 1 + high) % high) && colIsValid((col + width) % width))
    {
        if (board[(row - 1 + high) % high][(col + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row - 1 + high) % high) && colIsValid((col + 1 + width) % width))
    {
        if (board[(row - 1 + high) % high][(col + 1 + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + high) % high) && colIsValid((col - 1 + width) % width))
    {
        if (board[(row + high) % high][(col - 1 + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + high) % high) && colIsValid((col - 1 + width) % width))
    {
        if (board[(row + high) % high][(col +1  + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid((col - 1 + width) % width))
    {
        if (board[(row + 1 + high) % high][(col - 1 + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid((col + width) % width))
    {
        if (board[(row + 1 + high) % high][(col + width) % width].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid((col + 1 + width) % width))
    {
        if (board[(row + 1 + high) % high][(col + 1 + width) % width].isAlive)
        {
            Neighbour++ ;
        }
    }
    return Neighbour;
}





