#include "gvectoriterator.h"

GVectorIterator::GVectorIterator(GVector *vector)
{
    this->iterator=new QListIterator<int>(vector->GetVector());
}

GVectorIterator::~GVectorIterator()
{
    delete this->iterator;
}

void* GVectorIterator::Next(){
    return (void*)this->iterator->next();
}

bool GVectorIterator::HasNext(){
    return this->iterator->hasNext();
}

bool GVectorIterator::HasPrevious(){
    return this->iterator->hasPrevious();
}

void* GVectorIterator::Previous(){
    return (void*)this->iterator->previous();
}

void GVectorIterator::ToFront(){
    this->iterator->toFront();
}

void GVectorIterator::ToBack(){
    this->iterator->toBack();
}
