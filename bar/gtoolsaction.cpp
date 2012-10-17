#include "gtoolsaction.h"
#include "gtoolsbar.h"

GToolsAction::GToolsAction(GToolsBar *toolsBar) : GBarAction(toolsBar,0,0,65,51,4)
{
    this->toolsBar=toolsBar;
    this->font=QFont("Times",7,QFont::Bold);
    this->bgColor=QColor(0,255,255,80);
}

GToolsAction::GToolsAction(GToolsBar *toolsBar,QString string) : GBarAction(toolsBar,0,0,65,51,4,string)
{
    this->toolsBar=toolsBar;
    this->font=QFont("Times",7,QFont::Bold);
    this->bgColor=QColor(0,255,255,80);
}

void GToolsAction::Triggered(){
    emit this->triggered();
}
