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
    Row {
        spacing: 20
        anchors.centerIn: parent

        
        Knob {
            name: "Gain"

            percentageValue: false
            
            value: 0.5
            minValue: 0
            maxValue: 200

            unit: "%"

            onValueUpdate: function(value){
                audio.set_gain(value/100)
            }
        }

        WeetSlider {
            name: "Frequency"

            percentageValue: false
            
            value: 440 / 22000
            minValue: 0
            maxValue: 22000


            unit: "Hz"

            onValueUpdate: function(value) {
                audio.set_frequency(value)
            }
        }
    }
    
}

