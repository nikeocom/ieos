#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "objectpositions.h"
#include "simulation.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Simulation s;
    ObjectPositions op;

    QObject::connect(&s, &Simulation::newCoordinate, &op, &ObjectPositions::addCoordinate);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("simulation", &s);
    engine.rootContext()->setContextProperty("objectPositions", &op);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
