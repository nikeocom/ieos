#include "objectpositions.h"

ObjectPositions::ObjectPositions(QObject *parent)
    : QObject(parent)
{
    m_coordinates.addCoordinate(QGeoCoordinate(-27, 153.0 ));
    m_coordinates.addCoordinate(QGeoCoordinate(-27, 154.1));
    m_coordinates.addCoordinate(QGeoCoordinate(-28, 153.5));
    m_coordinates.addCoordinate(QGeoCoordinate(-29, 153.5));
}

Coordinate ObjectPositions::getCurrentPosition() const
{
    return Coordinate(m_coordinates.coordinateAt(m_coordinates.size() - 1));
}

QGeoCoordinate ObjectPositions::currentCoordinate() const
{
    return m_coordinates.coordinateAt(m_coordinates.size() - 1);
}

QVariantList ObjectPositions::getCoordinates() const
{
    return m_coordinates.variantPath();
}

void ObjectPositions::addCoordinate(const QGeoCoordinate &coordinate)
{
    m_coordinates.addCoordinate(coordinate);
    emit currentCoordinateChanged();
}
void ObjectPositions::setCoordinates(const QGeoPath &coordinates)
{
    m_coordinates.setPath(coordinates.path());
    emit coordinatesChanged();
}
