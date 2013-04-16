#include "Column.h"

#include <QString>
Column::Column()
{
}

Column::~Column()
{
}

#include <QFile>
void Column::createRows(const QString &path)
{
    rows.clear();
    QFile file(path);
    if(!file.open(QFile::ReadOnly)) return;
    QTextStream in(&file);
    while(!in.atEnd()) rows << readRow(in);
    file.close();
}

//Children
class FloatValue: public Column
{
protected:
    QString readRow(QTextStream& in)
    {
        return readWithoutSuffix(in).append(" ");
    }
    QString readWithoutSuffix(QTextStream& in)
    {
        return in.readLine().simplified().split(" ").last();
    }
};

class BooleanValue: public FloatValue
{
protected:
    QString readRow(QTextStream& in)
    {
        QString line = readWithoutSuffix(in);
        for(int i = 0; i < line.size(); i+=2){
            line.insert(i, " ");
        }
        return line + " ";
    }
};

class TimeValue: public Column
{
    QString readRow(QTextStream& in)
    {
        return in.readLine().simplified().split(" ").first().append(" ");
    }
};

//Making function
Column* Column::make(Type type)
{
    switch(type){
        case FLOAT_VALUE: return new FloatValue();
        case TIME_VALUE : return new TimeValue();
    }
    return new BooleanValue();
}
