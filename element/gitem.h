#ifndef GITEM_H
#define GITEM_H

#include "gcomponent.h"
#include "gmover.h"

class GItem : public GComponent
{
public:
    GItem(GMover *parent);
    GItem(GItem *parent);

    virtual void PaintNext(QPainter *painter);
    int GetMx();
    int GetMy();
    void SetMx(int x);
    void SetMy(int y);

protected:
    virtual bool isContain(GMouseEvent *event);

protected:
    int mx;
    int my;
};

#endif // GITEM_H
