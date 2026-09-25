import QtQuick
import QtQuick.Controls.Basic

Item {
    id: root

    property string name: "Null"

    property real value: 0.5

    property real minimumValue: 0.0

    property real maximumValue: 1.0

    property real sensitivity: 10

    width: 90
    height: 110

    
    Rectangle {
        id: rootRect

        z: -1

        color: "transparent"
        anchors.fill: parent

        radius: 3
        border.width: 1
        border.color: "#555555" 
    }


    Text {
        id: valueNameText
        
        color: "#EEEEEE"

        font.family: "Aptos"
        font.pixelSize: 12

        text: root.name

        anchors.top: root.top

        anchors.topMargin: 8

        anchors.horizontalCenter: root.horizontalCenter

        // horizontalAlignment: Text.AlignHCenter
        // verticalAlignment: Text.AlignBottom
    }

    Rectangle {
        id: knob

        width: 50
        height: width

        radius: width / 2

        color: '#181818' 

        anchors.centerIn: parent

        border.width: 1
        border.color: "#488497"

        MouseArea {
            id: mA

            anchors.fill: parent


            property real startValue
            property real startY

            onPressed: {
                startValue = root.value
                startY = mouseY
            }

            onPositionChanged: {
                if (!pressed)
                    return

                var delta = (startY - mouseY) * (root.sensitivity / 2000)

                root.value = Math.max(
                    root.minimumValue,
                    Math.min(root.maximumValue, startValue + delta)
                )
            }
        }
    }

    Rectangle {
        width: 3
        height: knob.width / 2 - 2

        radius: 1.5

        color: "#488497"

        anchors.horizontalCenter: knob.horizontalCenter
        anchors.bottom: knob.verticalCenter

        transformOrigin: Item.Bottom

        rotation: -110 + (root.value * 220)
    }

    Text {
        id: valueText
        
        color: "#EEEEEE"

        font.family: "Aptos"
        font.pixelSize: 12

        text: `${(root.value * 100).toFixed(2)}%`

        anchors.bottom: root.bottom

        anchors.horizontalCenter: root.horizontalCenter

        anchors.bottomMargin: 5


        // horizontalAlignment: Text.AlignHCenter
        // verticalAlignment: Text.AlignBottom
    }
}