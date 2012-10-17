#ifndef GMOUSEEVENTMANAGER_H
#define GMOUSEEVENTMANAGER_H

#include <QThread>
#include <QQueue>
#include <QMutex>
#include "gmouseevent.h"

class GGame;

class GMouseEventManager : public QThread
{
public:
    GMouseEventManager(GGame *gGame);

    void PushEvent(GMouseEvent event);

protected:
    virtual void run();

    virtual void mouseDoubleClickNext(GMouseEvent* event );
    virtual void mouseMoveNext(GMouseEvent* event );
    virtual void mousePressNext(GMouseEvent* event );
    virtual void mouseReleaseNext(GMouseEvent* event );

    virtual bool EventHandler();

protected:
    GGame *gGame;
    QQueue<GMouseEvent> queueEvent;
    QMutex mutex;
};

#endif // GMOUSEEVENTMANAGER_H
