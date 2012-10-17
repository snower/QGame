#ifndef GSCREENCACHE_H
#define GSCREENCACHE_H

#include <QThread>
#include <QImage>
#include <QPainter>
#include <QMutex>
#include "glayermanager.h"

class GGame;

class GScreenCache : public QThread
{
    Q_OBJECT
public:
    GScreenCache(int width,int height);
    ~GScreenCache();

    void Paint(QPainter *painter=NULL);
    void SetGame(GGame *gGame=NULL);

protected:
    void Init();
    void run();

protected:
    int width;
    int height;
    QImage *cache;
    GGame *gGame;
    QMutex mutex;
};

#endif // GSCREENCACHE_H
