#ifndef GELEMENT_H
#define GELEMENT_H

class GGame;

#include <QPainter>
#include "../tools/gvector.h"
#include "../mouse/gmouseevent.h"

class GElement : public QObject
{
    Q_OBJECT
public:
    GElement(GGame* gGame);

    bool GetVisible();
    bool GetSuspend();
    bool GetAction();
    void SetVisible(bool is=true);
    void SetSuspend(bool is=false);
    void SetAction(bool is=true);

    virtual void Paint(QPainter *painter);
    virtual void PaintNext(QPainter *painter);

    virtual void mouseDoubleClickNext(GMouseEvent* event );
    virtual void mouseMoveNext(GMouseEvent* event );
    virtual void mousePressNext(GMouseEvent* event );
    virtual void mouseReleaseNext(GMouseEvent* event );

    virtual GVector* GetElements();
    virtual void SetGame(GGame *gGame);
    virtual GGame* GetGame();
    virtual void Append(GElement* element);
    virtual void Insert(GElement* element,int index);
    virtual void Remove(GElement *element);
    virtual void RemoveAll();
    virtual GElement* At(int index);

public slots:
    virtual void Show();
    virtual void Hide();
    virtual void Suspend();
    virtual void Proceed();

signals:

protected:
    virtual void mouseDoubleClickEvent(GMouseEvent* event );
    virtual void mouseMoveEvent(GMouseEvent* event );
    virtual void mousePressEvent(GMouseEvent* event );
    virtual void mouseReleaseEvent(GMouseEvent* event );

public:
     bool visible;
     bool suspend;
     bool action;

protected:
    GVector elements;
    GGame *gGame;
};

#endif // GELEMENT_H
