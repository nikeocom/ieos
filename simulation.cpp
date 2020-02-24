#include "simulation.h"

Simulation::Simulation(QObject *parent)
    : QObject(parent)
{
    m_timer.setInterval(1000);

    connect(&m_timer, &QTimer::timeout, [&]() {
        static qreal i = 153.5;
        i += 0.2;
        emit newCoordinate(QGeoCoordinate(-27, i));
    });
}

void Simulation::start()
{
    m_timer.start();
}

void Simulation::stop()
{
    m_timer.stop();
}
