#include <QApplication>

#include <QListWidget>
#include <QFileDialog>
#include "../../paths/Paths.h"

int main(int argc, char** argv)
{
    QApplication PathsTest(argc, argv);
        QListWidget lw;
        lw.setWindowTitle("Paths test");
        lw.show();
        lw.addItems(Paths().getPaths(QFileDialog::getExistingDirectory(), Package::TM1_9M100));
    return PathsTest.exec();
}
