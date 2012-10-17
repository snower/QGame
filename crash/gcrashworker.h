#ifndef GCRASHWORKER_H
#define GCRASHWORKER_H

#include <QThread>
#include "../element/gmover.h"
#include "gcrashitem.h"

class GCrashManager;

class GCrashWorker : public QThread
{
public:
    GCrashWorker(GCrashManager *manager,int id);
    ~GCrashWorker();
    void run();

    void Ergodic();
    void IsCrash(GCrashItem item);
    void Stop();

private:
    GCrashManager *manager;
    int id;
    bool stoped;
};

#endif // GCRASHWORKER_H
