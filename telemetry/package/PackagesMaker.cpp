#include "PackagesMaker.h"

#include "../../paths/Paths.h"
Package* PackagesMaker::makeAndFillPackage(Package::Type type, const QString &dir)
{
    Package* package = makePackage(type);
    package->readRows(Paths::getPaths(dir, type));
    return package;
}

#include "9M100/TM1_9M100.h"
#include "9M100/TM2_9M100.h"
#include "9M100/TM3_9M100.h"
#include "9M100/TM4_9M100.h"
Package* PackagesMaker::makePackage(Package::Type type)
{
    switch(type){
        case Package::TM1_9M100 : return new TM1_9M100();
        case Package::TM2_9M100 : return new TM2_9M100();
        case Package::TM3_9M100 : return new TM3_9M100();
        case Package::TM4_9M100 : return new TM4_9M100();
    }
    return new TM1_9M100();
}
