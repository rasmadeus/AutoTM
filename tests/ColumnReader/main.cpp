#include <QApplication>

#include "../../telemetry/package/Column.h"
#include <QAction>
#include <QListWidget>

void setWindowTitle(Column::Type type, QListWidget* lw)
{
    switch(type){
        case Column::TIME_VALUE    : lw->setWindowTitle("Time");    break;
        case Column::FLOAT_VALUE   : lw->setWindowTitle("Float");   break;
        case Column::BOOLEAN_VALUE : lw->setWindowTitle("Boolean"); break;
    }
}

void fill(Column::Type type, QListWidget* lw, const QString& path){
    Column* column = Column::make(type);
        column->createRows(path);
        setWindowTitle(type, lw);
        lw->show();
        lw->addItems(column->getRows());
    delete column;
}

int main(int argc, char** argv)
{
    QApplication ColumnReader(argc, argv);
    QListWidget fw, bw, tw;
    fill(Column::FLOAT_VALUE, &fw, ":/float.txt");
    fill(Column::BOOLEAN_VALUE, &bw, ":/boolean.txt");
    fill(Column::TIME_VALUE, &tw, ":/float.txt");
    return ColumnReader.exec();
}
