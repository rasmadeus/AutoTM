#include "TM2_9M100.h"

#include <QObject>
QString TM2_9M100::header() const
{
    return QObject::tr(" /*It has been deleted*/");
}

QString TM2_9M100::fileName() const
{
    return "TM2.txt";
}

#include "../Column.h"
void TM2_9M100::createRows(const QStringList &paths)
{
    for(int i=0; i<paths.size(); ++i){
        floatReader->createRows(paths[i]);
        floatReader->append(rows);
    }
}

Package::Type TM2_9M100::getType() const
{
    return Package::TM2_9M100;
}
