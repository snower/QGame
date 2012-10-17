#ifndef GMOUSEEVENT_H
#define GMOUSEEVENT_H

#include <QMouseEvent>

class GMouseEvent
{
public:
    enum mouseType{
        Press,Release,Move,DoubleClick
    };

    GMouseEvent();
    GMouseEvent(QMouseEvent *event);
    ~GMouseEvent();

public:
    QMouseEvent *event;
    bool isAll;
    mouseType type;
};

#endif // GMOUSEEVENT_H
