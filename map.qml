import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    width: 800
    height: 600

    Plugin {
        id: osmPlugin
        name: "osm" // Use OpenStreetMap
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: osmPlugin
        zoomLevel: 13

        // Dynamically add markers
        Component.onCompleted: {
            if (typeof locationData === "object") {
                for (var key in locationData) {
                    var coord = locationData[key];
                    map.addItem(createMarker(QtPositioning.coordinate(coord.x, coord.y)));
                }
            } else {
                console.error("locationData is not an object");
            }
        }

        function createMarker(coord) {
            return Qt.createQmlObject(`
                import QtQuick 2.15;
                import QtLocation 5.15;
                MapQuickItem {
                    coordinate: QtPositioning.coordinate(${coord.latitude}, ${coord.longitude})
                    anchorPoint.x: image.width / 2
                    anchorPoint.y: image.height
                    sourceItem: Image {
                        source: "qrc:/icons/marker.png"
                    }
                }
            `, map, "dynamicMarker");
        }
    }
}
