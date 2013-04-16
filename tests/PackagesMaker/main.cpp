#include <QApplication>
#include <QListWidget>
#include "../../telemetry/package/PackagesMaker.h"

int main(int argc, char** argv)
{
    QApplication PackagesMaker(argc, argv);
        Package* tm1 = PackagesMaker::makePackage(Package::TM1_9M100);
        tm1->readRows(QStringList() << ":/1.txt" << ":/2.txt" << ":/3.txt" << ":/4.txt");
        QListWidget lw;
        lw.setWindowTitle("tm test");
        lw.addItems(tm1->getRows());
        lw.show();
    return PackagesMaker.exec();
}
