#include "gstatusbar.h"
#include "../ggame.h"

GStatusBar::GStatusBar(GGame *gGame) : GBar(gGame,0,0,gGame->height,25)
{
    this->layer->SetAction(false);
}
