#include "gmenu.h"
#include "../ggame.h"

GMenu::GMenu(GGame *gGame) : GBar(gGame,0,gGame->height/2-50,gGame->width,100,GBar::center)
{
    this->layer->nextAction=false;
    this->HideMenu();
}

void GMenu::ShowMenu(){
    this->layer->Show();
    this->layer->nextAction=false;
}

void GMenu::HideMenu(){
    this->layer->Hide();
    this->layer->nextAction=true;
}

void GMenu::Triggered(){
    emit this->triggered();
}
