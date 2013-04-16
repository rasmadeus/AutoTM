#ifndef ITEM_H
#define ITEM_H

#include <QStringList>

class Item
{
public:
    void append(QStringList& package) const;
    const QStringList& getRows() const;
    void createItems(QStringList& package);
protected:
    QStringList rows;
};

#endif // ITEM_H
