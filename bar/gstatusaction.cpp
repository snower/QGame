#include "gstatusaction.h"
#include "gstatusbar.h"

GStatusAction::GStatusAction(GStatusBar *statusBar) : GBarAction(statusBar,0,3,30,22,3)
{
    this->statusBar=statusBar;
    this->font=QFont("Times",5,QFont::Bold);
    this->bgColor=QColor(0,255,255,140);
    this->xRadius=1;
    this->yRadius=1;
}

GStatusAction::GStatusAction(GStatusBar *statusBar,QString string) : GBarAction(statusBar,0,3,30,22,3,string)
{
    this->statusBar=statusBar;
    this->font=QFont("Times",5,QFont::Bold);
    this->bgColor=QColor(0,255,255,140);
    this->xRadius=1;
    this->yRadius=1;
}
