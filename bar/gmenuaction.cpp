#include "gmenuaction.h"
#include "gmenu.h"

GMenuAction::GMenuAction(GMenu *menu) : GBarAction(menu,0,0,120,100,10)
{
    this->menu=menu;
    this->font=QFont("Times",17,QFont::Bold);
}

GMenuAction::GMenuAction(GMenu *menu,QString string) : GBarAction(menu,0,0,120,100,10,string)
{
    this->menu=menu;
    this->font=QFont("Times",17,QFont::Bold);
}

void GMenuAction::Triggered(){
    this->menu->HideMenu();
    emit this->triggered();
}
