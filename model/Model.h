#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QList>
class Package;

class Model
{
public:
    Model();
    ~Model();
    void setFilesDir(const QString& filesDir);
    const QString& getFilesDir() const;
    void setReportDir(const QString& reportDir);
    const QString& getReportDir() const;
    void save();
private:
    void readRows();
    void writeRows();
private:
    QString filesDir;
    QString reportDir;
    QList<Package*> tm;
};

#endif // MODEL_H
