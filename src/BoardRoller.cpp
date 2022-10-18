#include "GOF.hpp"

GofBoardRoller::GofBoardRoller(int SourceHigh, int SourceWidth, int high, int width)
        : GofBoard( SourceHigh, SourceWidth), high(high), width(width) {}

int GofBoardRoller::checkNeighbours(int row, int col) {
    int Neighbour = 0;

    if (rowIsValid((row - 1 + high) % high) && colIsValid(col-1))
    {
        if (board[(row - 1 + high) % high][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid((row - 1 + high) % high) && colIsValid(col))
    {
        if (board[(row - 1 + high) % high][col].isAlive){
            Neighbour++;}}
    if (rowIsValid((row - 1 + high) % high) && colIsValid(col+1))
    {
        if (board[(row - 1 + high) % high][col+1].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + high) % high) && colIsValid(col-1))
    {
        if (board[(row + high) % high][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + high) % high) && colIsValid(col+1))
    {
        if (board[(row + high) % high][col+1].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid(col-1))
    {
        if (board[(row + 1 + high) % high][col-1].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid(col))
    {
        if (board[(row + 1 + high) % high][col].isAlive){
            Neighbour++;}}
    if (rowIsValid((row + 1 + high) % high) && colIsValid(col+1))
    {
        if (board[(row + 1 + high) % high][col+1].isAlive)
        {
            Neighbour++ ;
        }
    }
    return Neighbour;
}




