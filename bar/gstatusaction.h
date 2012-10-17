#ifndef GSTATUSACTION_H
#define GSTATUSACTION_H

#include "gbaraction.h"

class GStatusBar;

class GStatusAction : public GBarAction
{
    Q_OBJECT
public:
    GStatusAction(GStatusBar *statusBar);
    GStatusAction(GStatusBar *statusBar,QString string);

public slots:

signals:

protected:
    GStatusBar *statusBar;
};

#endif // GSTATUSACTION_H
