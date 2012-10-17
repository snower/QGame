#ifndef GVECTORITERATOR_H
#define GVECTORITERATOR_H

#include "gvector.h"

class GVectorIterator
{
public:
    GVectorIterator(GVector *vector);
    ~GVectorIterator();

    void* Next();
    bool HasNext();
    bool HasPrevious();
    void* Previous();
    void ToFront();
    void ToBack();

private:
    QListIterator<int> *iterator;
};

#endif // GVECTORITERATOR_H
