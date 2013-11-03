#ifndef CELL_H
#define CELL_H
class Cell
{
    inline bool operator==(const Cell& otherCell)
    {
        if(this->X == otherCell.X && this->Y == otherCell.Y)
            return true;
        return false;
    }
public:
    Cell();
    Cell(int x, int y);
    int X;
    int Y;
private:
};

#endif // CELL_H
