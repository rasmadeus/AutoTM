#ifndef COLUMN_H
#define COLUMN_H

class QString;
#include "../Item.h"
#include <QTextStream>

class Column: public Item
{    
public:
    enum Type{
        FLOAT_VALUE,
        BOOLEAN_VALUE,
        TIME_VALUE
    };
    Column();
    static Column* make(Type type);
    virtual ~Column();
    void createRows(const QString& path);
protected:    
    virtual QString readRow(QTextStream& in) = 0;
};

#endif // COLUMN_H
