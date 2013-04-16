#include <QApplication>
#include "../../telemetry/package/PackagesMaker.h"
#include "../../paths/Paths.h"
#include <QFileDialog>
#include <QListWidget>

int main(int argc, char** argv)
{
    QApplication TM1Reader(argc, argv);
        QString dir = QFileDialog::getExistingDirectory();
        Package* tm1 = PackagesMaker::makeAndFillPackage(Package::TM1_9M100, dir);
        tm1->writeRows(dir);
        QListWidget lw;
        lw.addItems(tm1->getRows());
        lw.show();
        delete tm1;
    return TM1Reader.exec();
}
