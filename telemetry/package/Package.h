#ifndef PACKAGE_H
#define PACKAGE_H

#include "../Item.h"
class Column;

class Package: public Item
{

public:
    enum Type{
        TM1_9M100,
        TM2_9M100,
        TM3_9M100,
        TM4_9M100
    };    
    Package();
    virtual ~Package();
    QString getHeader() const;
    virtual QString fileName() const = 0;
    void readRows(const QStringList& paths);
    void writeRows(const QString& dir) const;
    virtual Type getType() const = 0;
protected:
    virtual void createRows(const QStringList& paths) = 0;
    virtual QString header() const = 0;
private:
    void readTime(const QString& path);
protected:
    Column* floatReader;
    Column* boolReader;
private:
    Column* timeReader;
};

#endif // PACKAGE_H
