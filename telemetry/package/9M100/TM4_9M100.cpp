#include "TM4_9M100.h"

#include <QObject>
QString TM4_9M100::header() const
{
    return QObject::tr(" /*It has been deleted*/");
}

QString TM4_9M100::fileName() const
{
    return "TM4.txt";
}

#include "../Column.h"
void TM4_9M100::createRows(const QStringList &paths)
{
    for(int i=0; i<paths.size(); ++i){
        if( i==19 || i==20){
            boolReader->createRows(paths[i]);
            boolReader->append(rows);
        }
        else{
            floatReader->createRows(paths[i]);
            floatReader->append(rows);
        }
    }
}

Package::Type TM4_9M100::getType() const
{
    return Package::TM4_9M100;
}
