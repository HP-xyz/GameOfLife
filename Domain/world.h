#ifndef WORLD_H
#define WORLD_H
#include <QList>
#include "cell.h"
#include "domain_global.h"
#include <QObject>

class DOMAINSHARED_EXPORT World : public QObject
{
    Q_OBJECT
public:
    enum CELL_LIVE_STATE
    {
        ALIVE_2 = 2,
        ALIVE_3 = 3
    };
    World();
    int CellCount();
    void AddCell(int x, int y);
    int NeighbourCount(int x, int y);
    void CreateCellIfPossible(int i, int j);
public slots:
    void Evolve();
signals:
    void EvolveComplete();
private:
    int _xDimension;
    int _yDimension;
    QList<Cell> _cells;
    QList<Cell> _evolvedCells;
    int _neighbourCount(Cell& cell);
    bool IsThisCell(int i, int j, Cell& cell);
    void HandleCell(Cell& cell);
    void KillCellIfNeigbourCountIsBad(Cell&, int);
    void HandleCellCreation();
};

#endif // WORLD_H
