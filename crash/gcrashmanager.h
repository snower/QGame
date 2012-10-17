#ifndef GCRASHMANAGER_H
#define GCRASHMANAGER_H

#include <QMap>
#include <QStack>
#include <QMutex>
#include "../tools/gvector.h"
#include "../element/gmover.h"
#include "gcrashqueue.h"
#include "gcrashworker.h"

class GCrashManager
{
public:
    GCrashManager();

    void RegisterCrash(int groupName,GMover *mover);
    void UnRegisterCrash(int groupName,GMover *mover);
    GCrashQueue* GetQueue();
    void RefreshWorker();
    int GetMaxWork();

private:
    void Ergodic();
    void ErgodicGroup(GCrashQueue *queue,GVector *o,GVector *u);
    void IsCrash(GCrashQueue *queue,GMover *left,GMover* right);

private:
    QMap<int,GVector> groups;
    GCrashQueue *queue;
    int maxWork;
    int maxWorker;
    QStack<int> worker;
    QMutex mutex;
};

#endif // GCRASHMANAGER_H
