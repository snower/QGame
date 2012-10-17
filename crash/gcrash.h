#ifndef GCRASH_H
#define GCRASH_H

#include "../element/gmover.h"

class GCrash
{
public:
    GCrash();

    static bool IsCrash(GMover *left, GMover *right);
    static bool LeftRight(GMover *left, GMover *right);
    static bool RightLeft(GMover *left, GMover *right);
    static bool TopBottom(GMover *left, GMover *right);
    static bool BottomTop(GMover *left, GMover *right);
};

#endif // GCRASH_H
