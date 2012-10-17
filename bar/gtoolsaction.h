#ifndef GTOOLSACTION_H
#define GTOOLSACTION_H

#include "gbaraction.h"

class GToolsBar;

class GToolsAction : public GBarAction
{
    Q_OBJECT
public:
    GToolsAction(GToolsBar *toolsBar);
    GToolsAction(GToolsBar *toolsBar,QString string);

    virtual void Triggered();

public slots:

signals:
    void triggered();

protected:
    GToolsBar *toolsBar;
};

#endif // GTOOLSACTION_H
