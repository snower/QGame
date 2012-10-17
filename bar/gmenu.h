#ifndef GMENU_H
#define GMENU_H

#include "gbar.h"
#include "gmenuaction.h"

class GMenu : public GBar
{
    Q_OBJECT
public:
    explicit GMenu(GGame *gGame);

protected:
    virtual void Triggered();

public slots:
    void ShowMenu();
    void HideMenu();

signals:
    void triggered();
};

#endif // GMENU_H
