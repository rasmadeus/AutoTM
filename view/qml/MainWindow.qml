import QtQuick 1.0

Rectangle {
    width : 340
    height: 200
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#fff"
        }
        GradientStop {
            position: 1
            color: "#111"
        }
    }

    Menu{
        id: menu
        anchors.margins: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        objectName: "menu"
    }

    Text {
        id: instruction
        color: "#d7c6c6"
        opacity: 0
        anchors.top:  menu.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        text: qsTr("За инструкцией по использованию <br> обратитесь в /*It was deleted*/.")
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 12
        SequentialAnimation {
            running: true
            NumberAnimation { target: instruction; property: "opacity"; to: 1.0; duration: 8000}
        }
    }

    Text{
        id: header
        opacity: 0
        color: "#fff"
        text: qsTr("Сборщик файлов")
        anchors.bottom: parent.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 20
        SequentialAnimation {
            running: true
            NumberAnimation { target: header; property: "opacity"; to: 1.0; duration: 8000}
        }
    }
}

