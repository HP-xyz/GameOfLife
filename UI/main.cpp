#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "../Domain/world.h"
#include <QQuickItem>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    World world;

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/UI/main.qml"));
    viewer.showExpanded();

    auto rootobject = viewer.rootObject();
    QObject::connect(rootobject, SIGNAL(StartGame()), &world, SLOT(Evolve()));
    //QObject::connect(&world, SIGNAL(EvolveComplete()), rootObject, SLOT(EvolveComplete()));

    return app.exec();
}
