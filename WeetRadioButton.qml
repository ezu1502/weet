import QtQuick
import QtQuick.Controls.Basic

RadioButton {
    id: root

    indicator: Rectangle {
        visible: false
    }

    width: 120
    height: 50

    background: Rectangle {
        color: "transparent"
        border.width: 1
        border.color: root.checked ? "#488497" :"#555555" 
        radius: 3

        Behavior on border.color {
            ColorAnimation {
                duration: 50
            }
        }
    }

    contentItem: Text {
        text: root.text

        font.family: "Aptos"
        font.pixelSize: 14

        color: "#EEEEEE"

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}