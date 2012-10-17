#ifndef GMOVER_H
#define GMOVER_H

#include "gcomponent.h"
#include "glayer.h"
#include "../tools/gmoverrunnable.h"

class GMover : public GComponent
{
    Q_OBJECT
public:
    GMover(GLayer *parent);
    ~GMover();

public slots:
    void RegisterCrash(int groupName);
    void UnRegisterCrash();
    virtual void Crash(GMover *mover);
    void Stop();
    void Start();
    virtual void run();

signals:

public:
    int crashGroupName;

protected:
    int speed;
    GMoverRunnable *runnable;
    bool isCrash;
    bool isStop;
};

#endif // GMOVER_H
