#include "gvector.h"
#include <QListIterator>

GVector::GVector(bool isDel)
{
    this->isDel=isDel;
}

GVector::~GVector(){
    if(this->isDel) this->RemoveAll();
}

void GVector::Append(void *data){
    this->vector.append((int)data);
}

void GVector::Insert(void *data, int index){
    this->vector.insert(index,(int)data);
}

bool GVector::Remove(void* data){
    this->vector.removeOne((int)data);
    if(this->isDel) delete data;
    return true;
}

bool GVector::RemoveAll(){
    if(this->isDel){
        QListIterator<int> iterator(this->vector);
        while(iterator.hasNext()){
            delete (void*)iterator.next();
        }
    }
    this->vector.clear();
    return true;
}

void* GVector::At(int index){
    return (void*)this->vector[index];
}

int GVector::Size(){
    return this->vector.size();
}

void* GVector::GetHead(){
    return (void*)(*this->vector.begin());
}

void* GVector::GetLast(){
    return (void*)(*this->vector.end());
}

QList<int> GVector::GetVector(){
    return this->vector;
}

bool GVector::Empty(){
    return this->vector.empty();
}
