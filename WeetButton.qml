import QtQuick
import QtQuick.Controls.Basic

Button {
    id: root

    width: 200
    height: 50

    font.family: "Aptos"
    font.pixelSize: 20

    background: Rectangle {
        color: root.pressed ? '#656565': root.hovered ? "#212121" : "#181818" 
        radius: 4

        border.width: 1
        border.color: root.pressed ? "#030303" : "#488497"
    }

    contentItem: Text {
        text: root.text
        font: root.font
        color: root.pressed ? "#030303" : "#EEEEEE"

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

    }
    
}