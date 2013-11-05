#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "../Domain/world.h"
#include "../Domain/cell.h"
#include <QQuickItem>
#include <QQmlContext>
#include <QList>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    World world;
    for (int i = 0; i < 500; i++)
    {
        int x = qrand() % ((2500 + 1) - 0) + 0;
        int y = qrand() % ((2500 + 1) - 0) + 0;
        if(!world.ContainsCellAt(x, y))
            world.AddCell(x,y);
    }

    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("world", &world);
    viewer.setMainQmlFile(QStringLiteral("qml/UI/main.qml"));
    viewer.showExpanded();

    auto rootobject = viewer.rootObject();
    QObject::connect(rootobject, SIGNAL(evolve()), &world, SLOT(Evolve()));

    return app.exec();
}
