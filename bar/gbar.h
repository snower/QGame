#ifndef GBAR_H
#define GBAR_H

#include "../element/gmover.h"
#include "../element/glayer.h"
#include "gbaraction.h"

class GGame;

class GBar : public GMover
{
    Q_OBJECT
public:

    enum Position{
        left,center,right
    };

    explicit GBar(GGame *gGame,int x,int y,int width,int height,Position p=left);

    virtual void Triggered();
    void SetLayer(GLayer* layer);
    GLayer* GetLayer();

    void UpdatePosition();
    void AddAction(GBarAction *barAction);

protected:
    virtual void mouseMoveEvent(GMouseEvent* event );
    virtual void mousePressEvent(GMouseEvent* event );

signals:

public slots:

protected:
    GGame *gGame;
    GLayer *layer;
    QPoint oldPoint;
    Position pos;
};

#endif // GBAR_H
