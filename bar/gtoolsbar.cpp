#include "gtoolsbar.h"
#include "../ggame.h"
#include "../tools/gvectoriterator.h"

GToolsBar::GToolsBar(GGame *gGame) : GBar(gGame,0,gGame->height-55,gGame->width,55,GBar::right)
{
}
