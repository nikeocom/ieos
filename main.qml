import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtPositioning 5.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Location path")

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Connections {
        target: objectPositions
        onCurrentCoordinateChanged: {
           polyline.addCoordinate(objectPositions.currentCoordinate)
        }
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 5
        center: objectPositions.currentCoordinate

        MapPolyline {
            id: polyline
            line.color: "green"
            line.width: 3

            path: objectPositions.coordinates
        }


        MapQuickItem {
            id: currentPossitionMarker
            anchorPoint.x: 0
            anchorPoint.y: img.height
            coordinate: objectPositions.currentCoordinate
            sourceItem: Image {
                id: img
                width: 10
                height: 20
                source: "running_man.png"
            }
        }
    }

    Column {
        spacing: 10
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
        Rectangle {
            width: startSimText.width + 20
            height: 40
            color: "black"
            radius: 20
            Text {
                id: startSimText
                anchors.centerIn: parent
                color: "white"
                text: qsTr("simulation start")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: simulation.start()
            }
        }

        Rectangle {
            width: stopSimText.width + 20
            height: 40
            color: "black"
            radius: 10
            Text {
                id: stopSimText
                anchors.centerIn: parent
                color: "white"
                text: qsTr("simulation stop")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: simulation.stop()
            }
        }
    }
}
