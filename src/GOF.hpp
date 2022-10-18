#include <vector>
#include <string>
#include <iostream>

class CommandSource {
public:
    virtual std::string next_command() = 0;
    virtual ~CommandSource() = default;

};
class AlwaysNextTurn : public CommandSource {
public:
    std::string next_command() override;

private:
    int turns_played = 0;
};
class UserCommands : public CommandSource {
public:
    std::string next_command() override;
private:

};


struct Cell
{
    bool isAlive;
};

class GofBoard {
public:
    int high;
    int width;
    std::vector<std::vector<Cell>>board;
    GofBoard(int high,int width);
    //void debugDisplay();
    virtual int checkNeighbours(int row, int col);
    bool rowIsValid(int row) const;
    bool colIsValid(int col) const;
    bool IsAlive(int row, int col);
    bool doesSurvive(int row, int col);
    bool doesResurrect(int row, int col);
    int getHigh() const;
    int getWidth() const;
    void FieldInfo(int row, int col);

};
class GofBoardRoller :public GofBoard {
public:
    int high;
    int width;
    GofBoardRoller(int high1, int width1, int high, int width);
    int checkNeighbours (int row, int col) override;



};
class GofBoardTorus:public GofBoard{
public:
    int high;
    int width;
    GofBoardTorus(int SourceHigh, int SourceWidth, int high, int width);
    int checkNeighbours (int row, int col) override;
};

class BoardDisplay{
    GofBoard & board;
public:
explicit BoardDisplay(GofBoard & DisplayBoard);
    void display();
};

class GofPlay{
    GofBoard &board;
    BoardDisplay &display;


public:
    GofPlay(GofBoard &InnerBoard,BoardDisplay &InnerDisplay);
    void turn(CommandSource &CS);
    std::vector<std::vector<Cell>>next;
};
