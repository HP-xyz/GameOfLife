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
    world.AddCell(5,5);
    world.AddCell(4,5);
    world.AddCell(3,5);

    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("world", &world);
    viewer.setMainQmlFile(QStringLiteral("qml/UI/main.qml"));
    viewer.showExpanded();

    auto rootobject = viewer.rootObject();
    QObject::connect(rootobject, SIGNAL(evolve()), &world, SLOT(Evolve()));

    return app.exec();
}
