import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6
Rectangle {
    property double oldLat: 25.6585
    property double oldLng: 125.3658
    Plugin {
        id: mapPlugin
        name: "osm"
    }

  Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 20
    }
  function setCenter(lat, lng){
      mapView.pan(oldLat - lat, oldLng - lng)
      oldLat = lat
      oldLng = lng
  }
}
