#ifndef TM3_9M100_H
#define TM3_9M100_H

#include "TM2_9M100.h"

class TM3_9M100 : public TM2_9M100
{
public:
    QString header() const;
    QString fileName() const;
    Type getType() const;
};

#endif // TM3_9M100_H
