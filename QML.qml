import QtQuick 2.15

            import QtPositioning 5.15
import QtLocation 5.15

            Item {
                Plugin {
                    id: mapPlugin
                    name: "osm"
                }

                Map {
                    id: map
                    anchors.fill: parent
                    plugin: mapPlugin
                    center: QtPositioning.coordinate(36.8065, 10.1815) // Tunis coordinates
                    zoomLevel: 10

                    // Add markers for each supplier
                    MapItemView {
                        model: supplierNames.length
                        delegate: MapQuickItem {
                            coordinate: QtPositioning.coordinate(
                                supplierLatitudes[index],
                                supplierLongitudes[index]
                            )
                            anchorPoint.x: rect.width/2
                            anchorPoint.y: rect.height

                            sourceItem: Rectangle {
                                id: rect
                                width: 20
                                height: 20
                                radius: 10
                                color: "red"
                                border.color: "black"
                                border.width: 2

                                Text {
                                    anchors.centerIn: parent
                                    text: "S"
                                    color: "white"
                                    font.bold: true
                                }

                                // Tooltip on hover
                                MouseArea {
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    ToolTip.visible: containsMouse
                                    ToolTip.text: supplierNames[index]
                                }
                            }
                        }
                    }
                }
            }

