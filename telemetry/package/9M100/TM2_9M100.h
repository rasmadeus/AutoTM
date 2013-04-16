#ifndef TM2_9M100_H
#define TM2_9M100_H

#include "../Package.h"

class TM2_9M100 : public Package
{
public:
    QString header() const;
    QString fileName() const;
    void createRows(const QStringList& paths);
    Type getType() const;
};

#endif // TM2_9M100_H
