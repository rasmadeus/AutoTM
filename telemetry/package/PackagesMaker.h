#ifndef PACKAGESMAKER_H
#define PACKAGESMAKER_H

#include "Package.h"
class PackagesMaker
{
public:
    static Package* makeAndFillPackage(Package::Type type, const QString& dir);
    static Package* makePackage(Package::Type type);
};

#endif // PACKAGESMAKER_H
