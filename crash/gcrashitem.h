#ifndef GCRASHITEM_H
#define GCRASHITEM_H

#include "../element/gmover.h"

class GCrashItem
{
public:
    GCrashItem();
    GCrashItem(GMover* left,GMover* right);

    GMover* left;
    GMover* right;
};

#endif // GCRASHITEM_H
