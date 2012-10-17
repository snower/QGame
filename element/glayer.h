#ifndef GLAYER_H
#define GLAYER_H

#include "gelement.h"

class GLayer : public GElement
{
public:
    GLayer(GGame* gGame);
    GGame* GetGame();

    virtual void Remove(GElement *element);
    virtual void RemoveAll();

public:
    bool nextPaint;
    bool nextAction;
};

#endif // GLAYER_H
