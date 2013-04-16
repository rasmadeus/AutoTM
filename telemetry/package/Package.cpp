#include "Package.h"

#include "Column.h"
Package::Package():
    floatReader(Column::make(Column::FLOAT_VALUE)),
    boolReader(Column::make(Column::BOOLEAN_VALUE)),
    timeReader(Column::make(Column::TIME_VALUE))
{
}

Package::~Package()
{
    delete floatReader;
    delete boolReader;
    delete timeReader;
}


void Package::readRows(const QStringList &paths)
{
    rows.clear();
    readTime(paths.first());
    createRows(paths);
}

#include <QFile>
#include <QTextStream>
void Package::writeRows(const QString &dir) const
{
    QFile file(dir + "/" + fileName());
    if(!file.open(QFile::WriteOnly)) return;
    QTextStream out(&file);
    out << getHeader();
    foreach(QString line, rows){        
        out << line << "\r\n";
    }
    file.close();
}

void Package::readTime(const QString &path)
{
    timeReader->createRows(path);
    timeReader->createItems(rows);
    timeReader->append(rows);
}

QString Package::getHeader() const
{
    return "t,c " + header() + "\r\n";
}
