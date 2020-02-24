#ifndef OBJECTPOSITIONS_H
#define OBJECTPOSITIONS_H

#include <QObject>
#include <QPointF>
#include <QVariantList>
#include <QGeoPath>
#include <QGeoCoordinate>

#include "coordinate.h"

class ObjectPositions : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList coordinates READ getCoordinates NOTIFY coordinatesChanged)
    Q_PROPERTY(QGeoCoordinate currentCoordinate READ currentCoordinate NOTIFY currentCoordinateChanged)

public:
    explicit ObjectPositions(QObject *parent = nullptr);

    Coordinate getCurrentPosition() const;
    QVariantList getCoordinates() const;

signals:
    void coordinatesChanged();
    void currentCoordinateChanged();

public slots:
    void addCoordinate(const QGeoCoordinate &coordinate);
    void setCoordinates(const QGeoPath &coordinates);

private:
    QGeoCoordinate currentCoordinate() const;

private:
    QGeoPath m_coordinates;
};

#endif // OBJECTPOSITIONS_H
