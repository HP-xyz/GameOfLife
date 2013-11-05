#include <QString>
#include <QtTest>
#include "../Domain/world.h"
#include "../Domain/cell.h"

class UnitTests : public QObject
{
    Q_OBJECT

public:
    UnitTests();

private Q_SLOTS:
    void World_GivenNoData_ShouldInitialize();
    void InitializeCells_GivenListOfCells_ShouldInitializeWorldWithCells();
    void NeigbourCount_GivenCellWith8Neigbours_ShouldReturn8();
    void Evolve_GivenCellWithNoNeigbours_ShouldKillCell();
    void Evolve_GivenCellWithOneNeigbours_ShouldKillCell();
    void Evolve_GivenDeadCellWithThreeNeigbours_ShouldCreateCell();
};

UnitTests::UnitTests()
{
}

void UnitTests::World_GivenNoData_ShouldInitialize()
{
    World world;
    auto cellCount = world.CellCount();
    QVERIFY2(cellCount == 0, "World given no data has no cells");
}

void UnitTests::InitializeCells_GivenListOfCells_ShouldInitializeWorldWithCells()
{
    World world;
    world.AddCell(0,0);
    world.AddCell(0,1);
    world.AddCell(0,2);
    world.AddCell(1,0);
    world.AddCell(1,1);
    world.AddCell(1,2);
    world.AddCell(2,0);
    world.AddCell(2,1);
    world.AddCell(2,2);
    QVERIFY2(world.CellCount() == 9, "World can be initialized with 9 cells");
}

void UnitTests::NeigbourCount_GivenCellWith8Neigbours_ShouldReturn8()
{
    World world;
    world.AddCell(0,0);
    world.AddCell(0,1);
    world.AddCell(0,2);
    world.AddCell(1,0);
    world.AddCell(1,1);
    world.AddCell(1,2);
    world.AddCell(2,0);
    world.AddCell(2,1);
    world.AddCell(2,2);
    QVERIFY2(world.NeighbourCount(1,1) == 8, "Cell can have 8 neigbours");
}

void UnitTests::Evolve_GivenCellWithNoNeigbours_ShouldKillCell()
{
    World world;
    world.AddCell(0,0);
    world.Evolve();
    QVERIFY2(world.CellCount() == 0, "Cell with no neigbours should die");
}

void UnitTests::Evolve_GivenCellWithOneNeigbours_ShouldKillCell()
{
    World world;
    world.AddCell(0,0);
    world.AddCell(0,1);
    world.Evolve();
    QVERIFY2(world.CellCount() == 0, "Cell with no neigbours should die");
}

void UnitTests::Evolve_GivenDeadCellWithThreeNeigbours_ShouldCreateCell()
{
    World world;
    world.AddCell(0,0);
    world.AddCell(1,1);
    world.AddCell(2,0);
    world.Evolve();
    QVERIFY2(world.CellCount() == 2, "Three cells died");
}


QTEST_APPLESS_MAIN(UnitTests)

#include "tst_unittests.moc"
