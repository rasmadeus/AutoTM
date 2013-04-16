#include "TM3_9M100.h"

#include <QObject>
QString TM3_9M100::header() const
{
    return QObject::tr(" /*It has been deleted*/");
}

QString TM3_9M100::fileName() const
{
    return "TM3.txt";
}

Package::Type TM3_9M100::getType() const
{
    return Package::TM3_9M100;
}
