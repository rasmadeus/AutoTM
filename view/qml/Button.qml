import QtQuick 1.0
Rectangle {
    property string caption: "Button"
    signal buttonClick
    id: button
    color: mouse.pressed ? "#ddd" : "#aaa"
    radius: 10
    width: 70; height: 70
    border.width: 2
    Text{
        id: buttonLabel
        anchors.centerIn: parent
        text: caption
        font.bold: true
        font.pointSize: 14
        horizontalAlignment: Text.AlignHCenter
        rotation: 45
    }

    MouseArea {
        id: mouse
        hoverEnabled: true
        anchors.fill: parent
        onEntered:{ moveDown.stop(); moveUp.start();  }
        onExited: { moveUp.stop();   moveDown.start();}
        onClicked: buttonClick();
    }

    SequentialAnimation {
        id: moveUp
        running: false
        NumberAnimation { target: buttonLabel; property: "rotation"; to: -45; duration: 100}
    }
    SequentialAnimation {
        id: moveDown
        running: false
        NumberAnimation { target: buttonLabel; property: "rotation"; to: 45; duration: 100}
    }
    rotation: -45
}
