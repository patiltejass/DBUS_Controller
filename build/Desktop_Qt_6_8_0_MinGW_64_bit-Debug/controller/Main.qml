import QtQuick 2.15
import QtQuick.Controls 2.15
// import controller 1.0

ApplicationWindow {
    id: root
    width: 900
    height: 500
    visible: true
    title: qsTr("IoT Controller")

    function toggleLight(lightId, button) {
        button.text = button.text === "OFF" ? "ON" : "OFF";
        console.log("Light", lightId, button.text === "ON" ? "ON" : "OFF");

        switch(lightId) {
            case 1:
                sender1.emitButton1();
                break;
            case 2:
                sender1.emitButton2();
                break;
            case 3:
                sender1.emitButton3();
                break;
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "#F5F5F5" // Light background

        Row {
            anchors.centerIn: parent
            spacing: 40
            Column {
                spacing: 10
                Button {
                    id: light1Button
                    text: "OFF"
                    width: 120
                    height: 120
                    font.pixelSize: 18
                    background: Rectangle {
                        color: light1Button.text === "ON" ? "#4CAF50" : "#FFC107"
                        radius: 15
                        border.color: "black"
                        border.width: 2
                    }
                    onClicked: root.toggleLight(1, light1Button)  // Add root. prefix
                }
                Text {
                    text: "Light 1"
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            Column {
                spacing: 10
                Button {
                    id: light2Button
                    text: "OFF"
                    width: 120
                    height: 120
                    font.pixelSize: 18
                    background: Rectangle {
                        color: light2Button.text === "ON" ? "#4CAF50" : "#FFC107"
                        radius: 15
                        border.color: "black"
                        border.width: 2
                    }
                    onClicked: root.toggleLight(2, light2Button)  // Add root. prefix
                }
                Text {
                    text: "Light 2"
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            Column {
                spacing: 10
                Button {
                    id: light3Button
                    text: "OFF"
                    width: 120
                    height: 120
                    font.pixelSize: 18
                    background: Rectangle {
                        color: light3Button.text === "ON" ? "#4CAF50" : "#FFC107"
                        radius: 15
                        border.color: "black"
                        border.width: 2
                    }
                    onClicked: root.toggleLight(3, light3Button)  // Add root. prefix
                }
                Text {
                    text: "Light 3"
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}
