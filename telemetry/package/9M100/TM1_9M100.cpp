#include "TM1_9M100.h"

#include <QObject>
QString TM1_9M100::header() const
{
    return QObject::tr(" /*It has been deleted*/");
}

QString TM1_9M100::fileName() const
{
    return "TM1.txt";
}

#include "../Column.h"
void TM1_9M100::createRows(const QStringList& paths)
{
    for(int i=0; i<paths.size(); ++i){
        if( i==26 || i==27 || i==28 || i==29){
            boolReader->createRows(paths[i]);
            boolReader->append(rows);
        }
        else{
            floatReader->createRows(paths[i]);
            floatReader->append(rows);
        }
    }
}

Package::Type TM1_9M100::getType() const
{
    return Package::TM1_9M100;
}
