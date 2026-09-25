import QtQuick
import QtQuick.Controls.Basic

ApplicationWindow {
    id: window
    width: 750
    height: 600

    visible: true
    title: "Weet"

    color: "#222222"


    WeetButton {
        property bool playing: false

        text: playing ? "Stop" : "Start"

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        anchors.topMargin: 20

        onClicked: {
            if (playing){
                audio.stop();
            }
            else {
                audio.start();
            }

            playing = !playing
        }
    }

    Knob {
        name: "Gain"
    }
}

