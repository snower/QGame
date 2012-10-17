#ifndef GCRASHQUEUE_H
#define GCRASHQUEUE_H

#include "../tools/gvector.h"
#include "gcrashitem.h"

class GCrashQueue
{
public:
    GCrashQueue();

    void Append(GCrashItem item);
    GCrashItem At(int index);
    int Size();

private:
    GVector left;
    GVector right;
};

#endif // GCRASHQUEUE_H
