#include "Model.h"

#include <QSettings>
#include "../telemetry/package/PackagesMaker.h"
Model::Model()
{
    tm << PackagesMaker::makePackage(Package::TM1_9M100)
       << PackagesMaker::makePackage(Package::TM2_9M100)
       << PackagesMaker::makePackage(Package::TM3_9M100)
       << PackagesMaker::makePackage(Package::TM4_9M100);

    QSettings settings;
    filesDir = settings.value("filesDir").toString();
    reportDir = settings.value("reportDir").toString();

}

Model::~Model()
{
    QSettings settings;
    settings.setValue("filesDir", filesDir);
    settings.setValue("reportDir", reportDir);
    qDeleteAll(tm);
}

void Model::setFilesDir(const QString& filesDir)
{
    if(filesDir.isEmpty()) return;
    this->filesDir = filesDir;
}

const QString& Model::getFilesDir() const
{
    return filesDir;
}

void Model::setReportDir(const QString& reportDir)
{
    if(reportDir.isEmpty()) return;
    this->reportDir = reportDir;
}

const QString& Model::getReportDir() const
{
    return reportDir;
}

void Model::save()
{
    if(filesDir.isEmpty()) return;
    readRows();
    writeRows();
}

#include "../paths/Paths.h"
void Model::readRows()
{
    foreach(Package* package, tm){
        QStringList paths = Paths::getAbsolutePaths(filesDir, package->getType());
        package->readRows(paths);
    }
}

#include <QDir>
void Model::writeRows()
{
    if(reportDir.isEmpty()){
        QDir dir(filesDir);
        dir.mkdir("results");
        reportDir = filesDir + "/results";
    }
    foreach(Package* package, tm){
        package->writeRows(reportDir);
    }
}
