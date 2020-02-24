#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QGeoCoordinate>
#include <QTimer>

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = nullptr);

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void newCoordinate(const QGeoCoordinate &);

private:
    QTimer m_timer;
};

#endif // SIMULATION_H
