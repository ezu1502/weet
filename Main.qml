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

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        anchors.bottomMargin: 20

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
   
    ButtonGroup {
        id: waveformGroup
    }
    Column {
        spacing: 20

        anchors.centerIn: parent

        Row {
            spacing: 20
            WeetRadioButton {
                text: "Sine"
                ButtonGroup.group: waveformGroup
                checked: true

                onClicked: {
                    audio.set_waveform(0)
                }
            }

            WeetRadioButton {
                text: "Square"
                ButtonGroup.group: waveformGroup

                onClicked: {
                    audio.set_waveform(1)
                }
            }

            WeetRadioButton {
                text: "Sawtooth"
                ButtonGroup.group: waveformGroup

                onClicked: {
                    audio.set_waveform(2)
                }
            }

            WeetRadioButton {
                text: "Triangle"
                ButtonGroup.group: waveformGroup

                onClicked: {
                    audio.set_waveform(3)
                }
            }

            WeetRadioButton {
                text: "Arc"
                ButtonGroup.group: waveformGroup

                onClicked: {
                    audio.set_waveform(4)
                }
            }
        }
    


        Row {
            spacing: 20
            

            
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
    
}

