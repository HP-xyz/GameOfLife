#ifndef WORLD_H
#define WORLD_H
#include <QList>
#include "cell.h"
#include "domain_global.h"

class DOMAINSHARED_EXPORT World
{
public:
    World();
    int CellCount();
    void AddCell(int x, int y);
    int NeighbourCount(int x, int y);
private:
    int _xDimension;
    int _yDimension;
    QList<Cell*> _cells;
    int _neighbourCount(Cell* cell);
};

#endif // WORLD_H
