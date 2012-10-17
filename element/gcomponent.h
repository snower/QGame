#ifndef GCOMPONENT_H
#define GCOMPONENT_H

#include "gelement.h"

class GComponent : public GElement
{
public:
    GComponent(GComponent *parent);

    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    void SetX(int x);
    void SetY(int y);
    void SetWidth(int w);
    void SetHeight(int h);

    virtual void mouseDoubleClickNext(GMouseEvent* event );
    virtual void mouseMoveNext(GMouseEvent* event );
    virtual void mousePressNext(GMouseEvent* event );
    virtual void mouseReleaseNext(GMouseEvent* event );

protected:
    virtual bool Control();
    virtual bool ControlNext();
    virtual bool isContain(GMouseEvent *event);

protected:
    int x;
    int y;
    int width;
    int height;
    GComponent *parent;
};

#endif // GCOMPONENT_H
