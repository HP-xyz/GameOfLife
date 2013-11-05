#include "world.h"

QVariantList World::toVariantList(const QList<Cell> &list)
{
    QVariantList newList;
    foreach( const Cell &item, list )
    {
        QJsonObject jsonObject;
        jsonObject.insert("X", item.X);
        jsonObject.insert("Y", item.Y);
        newList << QVariant(jsonObject);
    }
    return newList;
}

bool World::ContainsCellAt(int x, int y)
{
    return _cells.contains(Cell(x, y));
}

World::World()
{
}

int World::CellCount()
{
    return _cells.length();
}

void World::AddCell(int x, int y)
{
    _cells.append(Cell(x, y));
}

int World::NeighbourCount(int x, int y)
{
    int neededCellIndex = _cells.indexOf(Cell(x, y));
    return World::_neighbourCount(_cells[neededCellIndex]);
}

void World::Evolve()
{
    foreach(Cell cell, _cells)
        HandleCell(cell);
    HandleCellCreation();
    _cells = _evolvedCells;
    _evolvedCells.clear();
    emit evolveComplete(toVariantList(_cells));
}

int World::_neighbourCount(Cell& cell)
{
    int neigbourCount = 0;
    for(int i = cell.X - 1; i <= cell.X +1; i++)
        for(int j = cell.Y - 1; j <= cell.Y +1; j++)
            if(_cells.contains(Cell(i, j)) && !IsThisCell(i, j, cell))
                neigbourCount += 1;
    return neigbourCount;
}

bool World::IsThisCell(int i, int j, Cell &cell)
{
    if(cell.X == i && cell.Y == j)
        return true;
    return false;
}

void World::HandleCell(Cell &cell)
{
    auto neighbourCount = _neighbourCount(cell);
    KillCellIfNeigbourCountIsBad(cell, neighbourCount);
}

void World::KillCellIfNeigbourCountIsBad(Cell &cell, int neighbourCount)
{
    if(neighbourCount == CELL_LIVE_STATE::ALIVE_2
       || neighbourCount == CELL_LIVE_STATE::ALIVE_3)
        _evolvedCells.append(cell);
}

void World::CreateCellIfPossible(int i, int j)
{
    auto cell = Cell(i, j);
    if(!_cells.contains(cell))
    {
        auto neighbourCount = _neighbourCount(cell);
        if(neighbourCount == CELL_LIVE_STATE::ALIVE_3
           && !_evolvedCells.contains(cell))
            _evolvedCells.append(cell);
    }
}

void World::HandleCellCreation()
{
    foreach(Cell cell, _cells)
    {
        for(int i = cell.X - 1; i <= cell.X +1; i++)
        {
            for(int j = cell.Y - 1; j <= cell.Y +1; j++)
            {
                CreateCellIfPossible(i, j);
            }
        }
    }
}
