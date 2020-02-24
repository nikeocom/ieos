#include "coordinate.h"

Coordinate::Coordinate()
{

}

Coordinate::Coordinate(const QGeoCoordinate &coordinate)
    : m_position(coordinate)
{

}

int Coordinate::latitude() const
{
    return qRound(m_position.latitude());
}

int Coordinate::longitude() const
{
    return qRound(m_position.longitude());
}

double Coordinate::latitudeF() const
{
    return m_position.latitude();
}

double Coordinate::longitudeF() const
{
    return m_position.longitude();
}

const QGeoCoordinate &Coordinate::coordinate() const
{
    return m_position;
}
