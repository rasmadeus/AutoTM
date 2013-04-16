#include <QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QTextCodec>
#include "view/Menu.h"

int main(int argc, char** argv)
{
    QApplication AutoTM(argc, argv);

        QApplication::setOrganizationName("Fakel");
        QApplication::setApplicationName("AutoTM");
        QApplication::setApplicationVersion("1.0");
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp1251"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));

        Menu menu;
        QDeclarativeView view(QUrl::fromLocalFile("view/qml/MainWindow.qml"));
        view.setWindowTitle(QObject::tr("AutoTm v.1.0."));
            QObject* main = (QObject*) view.rootObject();
            QObject* mainMenu = main->findChild<QObject*>("menu");
            QObject::connect(mainMenu->findChild<QObject*>("quit"),        SIGNAL(buttonClick()), &menu, SLOT(clickedExit()));
            QObject::connect(mainMenu->findChild<QObject*>("getFilesDir"), SIGNAL(buttonClick()), &menu, SLOT(clickedFiles()));
            QObject::connect(mainMenu->findChild<QObject*>("getReportDir"),SIGNAL(buttonClick()), &menu, SLOT(clickedReport()));
            QObject::connect(mainMenu->findChild<QObject*>("start"),       SIGNAL(buttonClick()), &menu, SLOT(clickedStart()));
       view.show();

    return AutoTM.exec();
}
