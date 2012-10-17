#ifndef GVECTOR_H
#define GVECTOR_H

#include <QList>

class GVector
{
public:
    GVector(bool isDel=true);
    ~GVector();

    void Append(void* data);
    void Insert(void *data,int index);
    bool Remove(void* data);
    bool RemoveAll();
    void* At(int index);
    int Size();
    bool Empty();
    void* GetHead();
    void* GetLast();
    QList<int> GetVector();

private:
    QList<int> vector;
    bool isDel;
};

#endif // GVECTOR_H
