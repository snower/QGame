#ifndef GMENUACTION_H
#define GMENUACTION_H

#include "gbaraction.h"

class GMenu;

class GMenuAction : public GBarAction
{
    Q_OBJECT
public:
    explicit GMenuAction(GMenu *menu);
    explicit GMenuAction(GMenu *menu,QString string);

protected:
    virtual void Triggered();

signals:
    void triggered();

public slots:

private:
    GMenu *menu;
};

#endif // GMENUACTION_H
