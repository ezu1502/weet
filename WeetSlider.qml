import QtQuick
import QtQuick.Controls.Basic

Item {
    id: root

    signal valueUpdate(real value)

    property string name: "Null"

    property real value: 0.5

    property real maximumValue: 1.0
    property real minimumValue: 0.0

    property real maxValue: 100
    property real minValue: 0

    property string unit: "%"

    property bool percentageValue: true

    width: 200
    height: 70

    
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
        id: trail

        width: 150
        height: 15

        radius: 0

        color: '#181818' 

        anchors.centerIn: parent

        // border.width: 1
        // border.color: "#488497"

        MouseArea {
            id: mA

            hoverEnabled: true

            anchors.fill: parent

            property real startValue
            property real startX

            onPressed: {
                startValue = root.value
                startX = mouseX
            }

            onPositionChanged: {
                if (!pressed)
                    return

                var delta = (mouseX - startX) / trail.width

                root.value = Math.max(
                    root.minimumValue,
                    Math.min(root.maximumValue, startValue + delta)
                )
            }

            onReleased: {
                root.valueUpdate(root.minValue + root.value * (root.maxValue - root.minValue))
            }
        }

        Rectangle {
            anchors.left: parent.left
            height: parent.height
            width: (root.value - root.minimumValue) / (root.maximumValue - root.minimumValue) * parent.width
            color: '#254258'
        }
    }

    Rectangle {
        width: 8
        height: 20

        radius: 2

        color: mA.pressed ? "#00e1ff" : mA.containsMouse ? '#157c9b' : "#488497"

        anchors.verticalCenter: trail.verticalCenter
        anchors.horizontalCenter: trail.left

        transform: Translate {x: (root.value / root.maximumValue) * trail.width}

        Behavior on color {
            ColorAnimation {
                duration: 200
            }
        }
    }

    Text {
        id: valueText
        
        color: "#EEEEEE"

        font.family: "Aptos"
        font.pixelSize: 12

        text: root.percentageValue ? `${(root.value * 100).toFixed(0)}%`
        :  `${(root.minValue + root.value * (root.maxValue - root.minValue)).toFixed(2)}${root.unit}`

        anchors.bottom: root.bottom

        anchors.horizontalCenter: root.horizontalCenter

        anchors.bottomMargin: 5


        // horizontalAlignment: Text.AlignHCenter
        // verticalAlignment: Text.AlignBottom
    }
}