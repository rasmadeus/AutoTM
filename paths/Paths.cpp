#include "Paths.h"

QStringList Paths::getFilter(Package::Type type)
{
    QStringList res;
        switch(type){
            case Package::TM1_9M100 : res << "*!1*.txt"; break;
            case Package::TM2_9M100 : res << "*!2*.txt"; break;
            case Package::TM3_9M100 : res << "*!3*.txt"; break;
            case Package::TM4_9M100 : res << "*!4*.txt"; break;
        }
    return res;
}

QStringList Paths::createPathsList()
{
    QStringList res;
    for(int i=1; i<33; ++i) res << "";
    return res;
}

QStringList Paths::sortPaths(const QStringList &paths)
{
    QStringList res = createPathsList();
    foreach(QString path, paths){
         res[pathNumber(path)] = path;
    }
    return res;
}

int Paths::pathNumber(const QString &path)
{
    return path.split("!").at(1).split(" ").at(1).toInt() - 1;
}

QStringList Paths::getAbsolutePaths(const QString &path, Package::Type type)
{
    QStringList res = getPaths(path, type);
    createAbsolutePath(res, path);
    return res;
}

#include <QDir>
QStringList Paths::getPaths(const QString &path, Package::Type type)
{
    return sortPaths(QDir(path).entryList(getFilter(type)));
}

void Paths::createAbsolutePath(QStringList &paths, const QString &dir)
{
    for(int i=0; i<paths.size(); ++i){
        paths[i] = dir + "/" + paths[i];
    }
}
