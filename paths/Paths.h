#ifndef PATHS_H
#define PATHS_H

#include "../telemetry/package/Package.h"
#include <QStringList>

class Paths
{
public:
    static QStringList getAbsolutePaths(const QString& path, Package::Type type);
    static QStringList getPaths(const QString& path, Package::Type type);
    static void createAbsolutePath(QStringList& paths, const QString& dir);
private:
    static QStringList getFilter(Package::Type type);
    static QStringList createPathsList();
    static QStringList sortPaths(const QStringList& paths);
    static int pathNumber(const QString& path);
};

#endif // PATHS_H
