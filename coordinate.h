#ifndef COORDINATE_H
#define COORDINATE_H

#include <QGeoCoordinate>

class Coordinate
{
public:
    Coordinate();
    Coordinate(const QGeoCoordinate &coordinate);

    int latitude() const;
    int longitude() const;
    double latitudeF() const;
    double longitudeF() const;

    const QGeoCoordinate &coordinate() const;

private:
    QGeoCoordinate m_position;
};

#endif // COORDINATE_H
