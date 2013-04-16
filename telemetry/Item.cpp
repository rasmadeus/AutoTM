#include "Item.h"

#include <QString>
void Item::append(QStringList &package) const
{
    int n = qMin(rows.size(), package.size());
    for(int i=0; i<n; ++i){
        package[i].append(rows[i]);
    }
}

const QStringList& Item::getRows() const
{
    return rows;
}

void Item::createItems(QStringList& package)
{
    for(int i=0; i<rows.size(); ++i){
        package << "";
    }
}
