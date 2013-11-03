#include "world.h"

World::World()
{
}

int World::CellCount()
{
    return _cells.length();
}

void World::AddCell(int x, int y)
{
    Cell* newCell = new Cell(x, y);
    _cells.append(newCell);
}

int World::NeighbourCount(int x, int y)
{
    int neededCellIndex = _cells.indexOf(new Cell(x, y));
    return World::_neighbourCount(_cells[neededCellIndex]);
}

int World::_neighbourCount(Cell *cell)
{
    int neigbourCount = 0;
    for(int i = cell->X - 1; i <= cell->Y +1; i++)
    {
        for(int j = cell->Y - 1; j <= cell->Y +1; j++)
        {
            Cell* comparisonCell = new Cell(i, j);
            if(_cells.contains(comparisonCell))
            {
                delete comparisonCell;
                neigbourCount += 1;
            }
            delete comparisonCell;
        }
    }
    return neigbourCount;
}
