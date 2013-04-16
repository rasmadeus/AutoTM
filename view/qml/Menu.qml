import QtQuick 1.0

Row{
    spacing: 10
    Button{
        id: fromDir
        caption: qsTr("Файлы")
        objectName: "getFilesDir"
    }
    Button{
        id: toDir
        caption: qsTr("Отчёт")
        objectName: "getReportDir"
    }
    Button{
        id: startParsing
        caption: qsTr("Старт")
        objectName: "start"
    }
    Button{
        id: exit
        caption: qsTr("Выход")
        objectName: "quit"
    }
}
